// ------------------------------------------------------------
// Project: [yaz_1.0.1]
// Author: Taha Traidi
// Copyright (C) 2025 Taha Traidi
// All Rights Reserved. Unauthorized use, reproduction, or
// distribution of this code is strictly prohibited.
// Contact: [taha.traidi.tt@gmail.com]
// ------------------------------------------------------------
#include <lvgl.h>
#include <TFT_eSPI.h>
#include "CST816S.h"
#include "ui.h"
#include "pin_def.h"
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <DallasTemperature.h>
#include <OneWire.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLEClient.h>  
#include <BLEAdvertising.h>
#include <BLE2902.h>
#include <driver/adc.h> 
#include "esp_timer.h"
#include "time.h"
#include "driver/rtc_io.h"
#include "esp_sleep.h"
#include "driver/gpio.h"

// Global variables for timekeeping
RTC_DATA_ATTR static struct timeval timer_left ;
RTC_DATA_ATTR static struct timeval timer_right;
RTC_DATA_ATTR static int64_t elapsed_time_left = 0;
RTC_DATA_ATTR static int64_t elapsed_time_right = 0;
// BLE UUIDs  
#define SERVICE_UUID "4fafc201-1fb5-459e-8fcc-c5c9c331914b" // UUID for the Service
#define TEMPERATURE_CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a9" // UUID for the temperature value
#define BATTERY_CHARACTERISTIC_UUID "17d60c3e-8dbd-4c97-ba2f-05ec56b433df" // UUID for the battery value
#define LEFT_CHARACTERISTIC_UUID "3f20ae4a-e0d1-497f-8327-7c23bc96b4b8" // UUID for how many insulin injections have been injected (left)
#define RIGHT_CHARACTERISTIC_UUID "8a50f26c-9e6d-47b6-89a1-c8943c2de65d" // UUID for how many insulin injections have been injected (right)
#define RIGHT_SR_COLOR_CHARACTERISTIC_UUID "0fbd36dc-1b1c-4ec5-9e6b-e2b6fb191aa3" // UUID for the color of the right syringe
#define LEFT_SR_COLOR_CHARACTERISTIC_UUID "6456e3d2-1bb7-44ed-9b87-0817f10ff72b" // UUID for the color of the left syringe
#define RIGHT_REMAINING_INJ_CHARACTERISTIC_UUID "bd223a50-3c0e-42c9-9912-f2a5a74828b1" // UUID for the right remaining injections
#define LEFT_REMAINING_INJ_CHARACTERISTIC_UUID "c5c4a137-47da-4da9-891d-f2bb1f14965a" // UUID for the left remaining injections
#define LEFT_SYRINGE_PRESENCE_CHARACTERISTIC_UUID "6e400001-b5a3-f393-e0a9-e50e24dcca9e" // UUID for the presence of the left syringe
#define RIGHT_SYRINGE_PRESENCE_CHARACTERISTIC_UUID "6e400002-b5a3-f393-e0a9-e50e24dcca9e" // UUID for the presence of the right syringe
#define LEFT_TIME_CHARACTERISTIC_UUID "f3a1b2c3-d4e5-6789-abcd-0123456789ef"  // UUID for the elapsed time of left syringe
#define RIGHT_TIME_CHARACTERISTIC_UUID "a9876543-21fe-dcba-0987-654321fedcba"  //UUID for the elapsed time of right syringe

OneWire oneWire(temp_sensor); // OneWire instance for DS18B20 sensors
DallasTemperature sensors(&oneWire);  // DallasTemperature instance for DS18B20 sensors
//Task handle for temperature task and syringe detection updates
TaskHandle_t temperature_TaskHandle = NULL; 
TaskHandle_t battery_update_TaskHandle = NULL;
TaskHandle_t sr_update_TaskHandle = NULL;
//Task functions declare 
void temperatureTask(void *parameter);
void battery_update_Task(void* parameter);

RTC_DATA_ATTR uint16_t brightness_level = 50;
RTC_DATA_ATTR uint8_t left_dose_level = 0;
RTC_DATA_ATTR uint8_t right_dose_level = 0;
RTC_DATA_ATTR uint16_t left_syringe_level = 0;
RTC_DATA_ATTR uint16_t right_syringe_level = 0;
RTC_DATA_ATTR uint8_t right_total_inj = 0;
RTC_DATA_ATTR uint8_t left_total_inj = 0;
RTC_DATA_ATTR uint8_t left_remaining_inj = 0;
RTC_DATA_ATTR uint8_t left_inj = 0;
RTC_DATA_ATTR uint8_t right_inj = 0;
RTC_DATA_ATTR uint8_t right_remaining_inj = 0;
RTC_DATA_ATTR int timeout = 60000;
RTC_DATA_ATTR uint8_t left_color = 0;
RTC_DATA_ATTR uint8_t right_color = 0;
RTC_DATA_ATTR bool conf_complete = false;
RTC_DATA_ATTR bool start_left_timer = false;
RTC_DATA_ATTR bool start_right_timer = false;
bool restart_left_timer = false;
bool restart_right_timer = false;
bool orange = false;
bool blue = false;
bool grey = false;
bool conf_same_color = false;
bool conf_same_level = false;
bool conf_same_dose = false;

float lastTemperature = 0.0;  // Variable to store last temperature reading
int bat_percentage = 0; // Battery percentage
unsigned long lastTouchTime = 0; // Variable to store last time

// Display configurations
static const uint16_t screenWidth = 240;
static const uint16_t screenHeight = 240;
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[screenWidth * screenHeight / 10];

TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight); /* TFT instance */
CST816S touch(6, 7, 13, 5); // sda, scl, rst, irq

bool deviceConnected = false;
bool oldDeviceConnected = false;
// Bluetooth Low Energy (BLE) configuration
BLEServer* pServer = NULL;
BLECharacteristic* pTemperatureCharacteristic = NULL;
BLECharacteristic* pBatteryCharacteristic = NULL;
BLECharacteristic* pLeftCharacteristic = NULL;
BLECharacteristic* pRightCharacteristic = NULL;
BLECharacteristic* pRightColorCharacteristic = NULL;
BLECharacteristic* pLeftColorCharacteristic = NULL;
BLECharacteristic* pLeftRemainingInjCharacteristic = NULL;
BLECharacteristic* pRightRemainingInjCharacteristic = NULL;
BLECharacteristic* pLeftPresenceCharacteristic = NULL;
BLECharacteristic* pRightPresenceCharacteristic = NULL;
BLECharacteristic* pLeftTimeCharacteristic = NULL;
BLECharacteristic* pRightTimeCharacteristic = NULL;

class MyServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
        deviceConnected = true;
        if(conf_complete){
        Serial.println("Client connected");
        lv_obj_set_style_img_recolor(ui_Image4, lv_color_hex(0x7BFD97), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    void onDisconnect(BLEServer* pServer) {
        deviceConnected = false;
        if(conf_complete){
          Serial.println("Client disconnected");
          lv_obj_set_style_img_recolor(ui_Image4, lv_color_hex(0xfd0c0d), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
};

/* Display flushing */
void my_disp_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p) {
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);
    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    tft.pushColors((uint16_t *)&color_p->full, w * h, true);
    tft.endWrite();
    lv_disp_flush_ready(disp_drv);
}

/* Read the touchpad */
void my_touchpad_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data) {
    bool touched = touch.available();
    if (!touched) {
        data->state = LV_INDEV_STATE_REL;
    } else {
        data->state = LV_INDEV_STATE_PR;
        data->point.x = touch.data.x;
        data->point.y = touch.data.y;
        lastTouchTime = millis(); // Update last touch time
    }
}

void setup() {
    Serial.begin(115200);
    pinMode(left_sensor , INPUT);
    pinMode(right_sensor , INPUT);
    pinMode(temp_sensor , INPUT);
    pinMode(hall_left , INPUT);
    pinMode(hall_right , INPUT);
    pinMode(STAT_PIN , INPUT);
    pinMode(BAT_ADC , INPUT);
    analogReadResolution(12);  // Set ADC to 12-bit resolution (0-4095)
    analogSetAttenuation(ADC_11db);
    adcAttachPin(BAT_ADC);     // Attach ADC to the battery pin
    // Initialize LVGL
    lv_init();
    tft.begin();          /* TFT init */
    tft.setRotation(0);   /* Landscape orientation */
    touch.begin();
    TFT_SET_BL(brightness_level);
    tft.fillScreen(TFT_BLACK);
    // Initialize the display buffer
    lv_disp_draw_buf_init(&draw_buf, buf, NULL, screenWidth * screenHeight / 10);
    /* Initialize the display driver */
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);
    /* Initialize the input device driver */
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touchpad_read;
    lv_indev_drv_register(&indev_drv);
    // Initialize UI
    ui_init();
    lv_task_handler();
    // Initialize BLE
    BLEDevice::init("YAZ Prototype");
    pServer = BLEDevice::createServer();
    pServer->setCallbacks(new MyServerCallbacks());
    BLEService *pService = pServer->createService(SERVICE_UUID);
    pTemperatureCharacteristic = pService->createCharacteristic(
                                         TEMPERATURE_CHARACTERISTIC_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_NOTIFY
                                       );
    pTemperatureCharacteristic->addDescriptor(new BLE2902());

    pBatteryCharacteristic = pService->createCharacteristic(
                                         BATTERY_CHARACTERISTIC_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_NOTIFY
                                       );
    pBatteryCharacteristic->addDescriptor(new BLE2902());

    pLeftCharacteristic = pService->createCharacteristic(
                                         LEFT_CHARACTERISTIC_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_NOTIFY
                                       );
    pLeftCharacteristic->addDescriptor(new BLE2902());

    pRightCharacteristic = pService->createCharacteristic(
                                         RIGHT_CHARACTERISTIC_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_NOTIFY
                                       );
    pRightCharacteristic->addDescriptor(new BLE2902());

    pRightColorCharacteristic = pService->createCharacteristic(
                                         RIGHT_SR_COLOR_CHARACTERISTIC_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_NOTIFY
    );
    pRightColorCharacteristic->addDescriptor(new BLE2902());

    pLeftColorCharacteristic = pService->createCharacteristic(
                                        LEFT_SR_COLOR_CHARACTERISTIC_UUID,
                                        BLECharacteristic::PROPERTY_READ |
                                        BLECharacteristic::PROPERTY_NOTIFY
    );
    pLeftColorCharacteristic->addDescriptor(new BLE2902());
    pRightRemainingInjCharacteristic = pService->createCharacteristic(
                                        RIGHT_REMAINING_INJ_CHARACTERISTIC_UUID,
                                        BLECharacteristic::PROPERTY_READ |
                                        BLECharacteristic::PROPERTY_NOTIFY
    );
    pRightRemainingInjCharacteristic->addDescriptor(new BLE2902());
    pLeftRemainingInjCharacteristic = pService->createCharacteristic(
                                        LEFT_REMAINING_INJ_CHARACTERISTIC_UUID,
                                        BLECharacteristic::PROPERTY_READ |
                                        BLECharacteristic::PROPERTY_NOTIFY
    );
    pLeftRemainingInjCharacteristic->addDescriptor(new BLE2902());
    pRightPresenceCharacteristic = pService->createCharacteristic(
                                        RIGHT_SYRINGE_PRESENCE_CHARACTERISTIC_UUID,
                                        BLECharacteristic::PROPERTY_READ |
                                        BLECharacteristic::PROPERTY_NOTIFY
    );
    pRightPresenceCharacteristic->addDescriptor(new BLE2902());
    pLeftPresenceCharacteristic = pService->createCharacteristic(
                                        LEFT_SYRINGE_PRESENCE_CHARACTERISTIC_UUID,
                                        BLECharacteristic::PROPERTY_READ |
                                        BLECharacteristic::PROPERTY_NOTIFY
    );
    pLeftPresenceCharacteristic->addDescriptor(new BLE2902());
    pLeftTimeCharacteristic = pService->createCharacteristic(
                                        LEFT_TIME_CHARACTERISTIC_UUID,
                                        BLECharacteristic::PROPERTY_READ |
                                        BLECharacteristic::PROPERTY_NOTIFY
    );
    pLeftTimeCharacteristic->addDescriptor(new BLE2902());
    pRightTimeCharacteristic = pService->createCharacteristic(
                                        RIGHT_TIME_CHARACTERISTIC_UUID,
                                        BLECharacteristic::PROPERTY_READ |
                                        BLECharacteristic::PROPERTY_NOTIFY
    );
    pRightTimeCharacteristic->addDescriptor(new BLE2902());
    pService->start();
    pServer->getAdvertising()->start();
    Serial.println("Waiting a client connection to notify...");
     // Create a task for reading temperature
    xTaskCreatePinnedToCore(
        temperatureTask,        // Task function
        "Temperature Task",     // Name of the task
        2048,                   // Stack size (bytes)
        NULL,                   // Parameter passed to the task
        1,                      // Task priority
        &temperature_TaskHandle, // Task handle
        1                       // CPU core
    );
    // Create a task for Battery percentage updates
    xTaskCreatePinnedToCore(
        battery_update_Task,        // Task function
        "Battery update Task",     // Name of the task
        2048,                   // Stack size (bytes)
        NULL,                   // Parameter passed to the task
        1,                      // Task priority
        &battery_update_TaskHandle, // Task handle
        1                       // CPU core
    );
    // Create a task for syringe injection updates
    xTaskCreatePinnedToCore(
        sr_update_Task,        // Task function
        "Syringe update Task",     // Name of the task
        2048,                   // Stack size (bytes)
        NULL,                   // Parameter passed to the task
        2,                      // Task priority
        &sr_update_TaskHandle, // Task handle
        1                       // CPU core
    );

}

void temperatureTask(void *parameter){
  int temperature;
        while (1) {
        temperature = (int) lastTemperature;
        sensors.requestTemperatures();  
        lastTemperature = sensors.getTempCByIndex(0);
        char temp[10];
        snprintf(temp, sizeof(temp), "%.0f%°C", lastTemperature);
        lv_label_set_text(ui_TEMPlabel, temp);
        lv_arc_set_value(ui_temperatureArc, temperature);
        if (lastTemperature <= 20.00) {
        lv_obj_set_style_arc_color(ui_temperatureArc, lv_color_hex(0x295031), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_arc_color(ui_temperatureArc, lv_color_hex(0x41B65A), LV_PART_INDICATOR | LV_STATE_DEFAULT);
        lv_obj_set_style_img_recolor(ui_TEMPimage, lv_color_hex(0x41B65A), LV_PART_MAIN | LV_STATE_DEFAULT);
        } else if (lastTemperature > 20.00 && lastTemperature <= 25.00){
        lv_obj_set_style_arc_color(ui_temperatureArc, lv_color_hex(0x685B25), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_arc_color(ui_temperatureArc, lv_color_hex(0xE7C93A), LV_PART_INDICATOR | LV_STATE_DEFAULT);
        lv_obj_set_style_img_recolor(ui_TEMPimage, lv_color_hex(0xE7C93A), LV_PART_MAIN | LV_STATE_DEFAULT);
        } else if(lastTemperature > 25.00){
        lv_obj_set_style_arc_color(ui_temperatureArc, lv_color_hex(0x730505), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_arc_color(ui_temperatureArc, lv_color_hex(0xF43031), LV_PART_INDICATOR | LV_STATE_DEFAULT);
        lv_obj_set_style_img_recolor(ui_TEMPimage, lv_color_hex(0xF43031), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        vTaskDelay(1000 / portTICK_PERIOD_MS);  
    }
}

void battery_update_Task(void* parameter) {
    char bat[10];
    while (1) {
        int sum_adc = 0;
        const int num_samples = 50;  // Number of samples for averaging

        // Take multiple ADC readings and sum them
        for (int i = 0; i < num_samples; i++) {
            sum_adc += analogReadMilliVolts(BAT_ADC); // Using analogReadMilliVolts for accurate reading
            vTaskDelay(10 / portTICK_PERIOD_MS);  // Small delay between readings
        }

        // Calculate average ADC value
        float avg_millivolts = sum_adc / (float)num_samples;
        float vbat = (avg_millivolts * 3.0 / 1000.0) / 0.94095 ; // Apply measurement offset correction
        Serial.println(vbat);

        // USB Detection (Ignore readings above 4.2V)
        bool usb_plugged = (vbat >= 4.2);

        // Clamp voltage to valid range
        if (vbat > 4.2) vbat = 4.2;
        //if (vbat < 3.2) vbat = 3.2;

        // Calculate battery percentage correctly
        int batteryPercentage = ((vbat - 2.9) / (4.07 - 2.9)) * 100;

        // Ensure percentage is within valid range
        batteryPercentage = constrain(batteryPercentage, 0, 100);
        bat_percentage = batteryPercentage;

        // Display battery status
        if (usb_plugged) {
            lv_label_set_text(ui_BATlabel, "Ch..");
            lv_obj_set_style_img_recolor(ui_BATimage, lv_color_hex(0x41B65A), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_color(ui_batteryArc, lv_color_hex(0x295031), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_color(ui_batteryArc, lv_color_hex(0x41B65A), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_arc_set_value(ui_batteryArc, 100);
        } else {
            // Update battery UI
            snprintf(bat, sizeof(bat), "%d%%", batteryPercentage);
            lv_label_set_text(ui_BATlabel, bat);
            lv_arc_set_value(ui_batteryArc, batteryPercentage);

            // Set color based on percentage
            if (batteryPercentage <= 20) {
                lv_obj_set_style_img_recolor(ui_BATimage, lv_color_hex(0xF43031), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(ui_batteryArc, lv_color_hex(0x730505), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(ui_batteryArc, lv_color_hex(0xF43031), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            } else if (batteryPercentage <= 50) {
                lv_obj_set_style_img_recolor(ui_BATimage, lv_color_hex(0xE7C93A), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(ui_batteryArc, lv_color_hex(0x685B25), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(ui_batteryArc, lv_color_hex(0xE7C93A), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            } else {
                lv_obj_set_style_img_recolor(ui_BATimage, lv_color_hex(0x41B65A), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(ui_batteryArc, lv_color_hex(0x295031), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(ui_batteryArc, lv_color_hex(0x41B65A), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            }
        }

        vTaskDelay(3000 / portTICK_PERIOD_MS);  // Update every 3 seconds
    }
}


void sr_update_Task(void *parameter) {
    char left[10];
    char right[10];
    int left_sen_value;
    int right_sen_value;
    int left_present = 0;
    int right_present= 0;       
    int counted_left = 0;  
    int counted_right =0;          
    unsigned long start_time_left = 0;
    unsigned long start_time_right = 0;
    while (1) {

        if (analogRead(left_sensor) < 4095) {
            lv_obj_clear_flag(ui_Image10, LV_OBJ_FLAG_HIDDEN);
        } else {
            lv_obj_add_flag(ui_Image10, LV_OBJ_FLAG_HIDDEN); 
        }

        if (analogRead(right_sensor) < 4095) {
            lv_obj_clear_flag(ui_Image12, LV_OBJ_FLAG_HIDDEN);
        } else {
            lv_obj_add_flag(ui_Image12, LV_OBJ_FLAG_HIDDEN); 
        }
        // Continuously read the sensor value
        left_sen_value = analogRead(left_sensor);
        right_sen_value = analogRead(right_sensor);

        ////////////////////////////// LEFT PART ////////////////////////////////// 

        // If sensor == 4095, reset the cycle
        if (left_sen_value == 4095){
            left_present = 1;     // Mark sensor as high (present)
            counted_left = 0;          // Reset counted flag
            start_time_left = 0;       // Reset timer
        }
        
        // If sensor is below 4095 and it hasn't counted yet
        if (left_sen_value < 4095 && left_present == 1 && counted_left == 0) {
            if (start_time_left == 0) {
                // Start the timer the first time sensor goes low
                start_time_left = millis();
            }

            // Check if 5 seconds have passed while sensor is low
            if (millis() - start_time_left >= 5000) {
                left_inj += 1;     // Increment count
                restart_left_timer = true;
                start_left_timer = true;
                lv_arc_set_value(ui_leftArc, left_remaining_inj);
                sprintf(left,"%d",left_inj);
                lv_label_set_text(ui_LEFTlabel, left);  // Update UI label
                lv_label_set_text(ui_LEFTlabel2, left);  // Update UI label
                counted_left = 1;       // Mark as counted
                left_present = 0;  // Reset sensor presence for next cycle
            }
        }

        /////////////////////// RIGHT PART /////////////////////////////////////////

           // If sensor == 4095, reset the cycle
        if (right_sen_value == 4095) {
            right_present = 1;     // Mark sensor as high (present)
            counted_right = 0;          // Reset counted flag
            start_time_right = 0;       // Reset timer
        }
        
        // If sensor is below 4095 and it hasn't counted yet
        if (right_sen_value < 4095 && right_present == 1 && counted_right == 0) {
            if (start_time_right == 0) {
                // Start the timer the first time sensor goes low
                start_time_right = millis();
            }

            // Check if 5 seconds have passed while sensor is low
            if (millis() - start_time_right >= 5000) {
                right_inj += 1;     // Increment count
                restart_right_timer = true;
                start_right_timer = true;
                lv_arc_set_value(ui_rightArc, right_remaining_inj);
                sprintf(right,"%d",right_inj);
                lv_label_set_text(ui_RIGHTlabel, right);  // Update UI label
                lv_label_set_text(ui_RIGHTlabel2, right);  // Update UI label
                counted_right = 1;       // Mark as counted
                right_present = 0;  // Reset sensor presence for next cycle
            }
        } 
        if(left_color == 1){
          lv_obj_set_style_img_recolor(ui_Image2, lv_color_hex(0xFE6D19), LV_PART_MAIN | LV_STATE_DEFAULT);
        } else if(left_color == 2){
          lv_obj_set_style_img_recolor(ui_Image2, lv_color_hex(0x2095f6), LV_PART_MAIN | LV_STATE_DEFAULT);
        } else if (left_color == 3){
          lv_obj_set_style_img_recolor(ui_Image2, lv_color_hex(0xC5C5C5), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
          if(right_color == 1){
          lv_obj_set_style_img_recolor(ui_Image3, lv_color_hex(0xFE6D19), LV_PART_MAIN | LV_STATE_DEFAULT);
        } else if(right_color == 2){
          lv_obj_set_style_img_recolor(ui_Image3, lv_color_hex(0x2095f6), LV_PART_MAIN | LV_STATE_DEFAULT);
        } else if (right_color == 3){
          lv_obj_set_style_img_recolor(ui_Image3, lv_color_hex(0xC5C5C5), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        vTaskDelay(500 / portTICK_PERIOD_MS);  // Delay to avoid tight looping

    }
}

void TFT_SET_BL(uint8_t Value) {
    pinMode(BL, OUTPUT);
    if (Value < 0 || Value > 100) {
        printf("TFT_SET_BL Error \r\n");
    } else {
        analogWrite(BL, Value * 2.55);
    }
}

uint16_t calculate_level(uint16_t level){
  uint16_t _level = (level * 300) / 100;
  return _level;
}

uint8_t calculate_total_injections(uint16_t syringe_level , uint8_t dose){
  uint8_t _total_inj = syringe_level / dose;
  return _total_inj;
}

unsigned long start_time = 0;
char temp[10];
char batt[10];
char left[10];
char right[10];
char left_remaining[10];
char right_remaining[10];
char* elapsed_left;
char* elapsed_right;

void loop(){

  if(!conf_complete)
{
  lv_obj_t *current_screen = lv_scr_act();
      if (current_screen == ui_DoseSC) { 
        if (right_dose_level == 0) {
            _ui_state_modify(ui_Button15, LV_STATE_DISABLED, _UI_MODIFY_STATE_ADD);
            _ui_state_modify(ui_Button16, LV_STATE_DISABLED, _UI_MODIFY_STATE_ADD);
        } else {
            _ui_state_modify(ui_Button15, LV_STATE_DISABLED, _UI_MODIFY_STATE_REMOVE);
            _ui_state_modify(ui_Button16, LV_STATE_DISABLED, _UI_MODIFY_STATE_REMOVE);
        }
    }
    if(left_dose_level == 0){
      _ui_state_modify(ui_Button22, LV_STATE_DISABLED, _UI_MODIFY_STATE_ADD);
    } else {
      _ui_state_modify(ui_Button22, LV_STATE_DISABLED, _UI_MODIFY_STATE_REMOVE);
    }
}

  if(restart_left_timer){
    start_timer_left();
    start_left_timer = true;
    restart_left_timer = false;
  } 
  if(restart_right_timer){
    start_timer_right();
    start_right_timer = true;
    restart_right_timer = false;
  }

  if(start_left_timer){
    calculate_elapsed_time_left();
    elapsed_left = calculate_elapsed_time_left();
  }
  if(start_right_timer){
    calculate_elapsed_time_right();
    elapsed_right = calculate_elapsed_time_right();
  }

  if(conf_complete){
  right_total_inj = calculate_total_injections(right_syringe_level , right_dose_level);
  left_total_inj = calculate_total_injections(left_syringe_level , left_dose_level);
  right_remaining_inj = right_total_inj - right_inj;
  left_remaining_inj = left_total_inj - left_inj;
  if(right_remaining_inj <= 5){
    lv_obj_set_style_arc_color(ui_rightArc2, lv_color_hex(0x730505), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui_rightArc2, lv_color_hex(0xF43031), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui_rightArc, lv_color_hex(0x730505), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui_rightArc, lv_color_hex(0xF43031), LV_PART_INDICATOR | LV_STATE_DEFAULT);
  } else {
    lv_obj_set_style_arc_color(ui_rightArc2, lv_color_hex(0x295031), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui_rightArc2, lv_color_hex(0x41B65A), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui_rightArc, lv_color_hex(0x295031), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui_rightArc, lv_color_hex(0x41B65A), LV_PART_INDICATOR | LV_STATE_DEFAULT);
  }
    if(left_remaining_inj <= 5){
    lv_obj_set_style_arc_color(ui_leftArc2, lv_color_hex(0x730505), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui_leftArc2, lv_color_hex(0xF43031), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui_leftArc, lv_color_hex(0x730505), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui_leftArc, lv_color_hex(0xF43031), LV_PART_INDICATOR | LV_STATE_DEFAULT);
  } else {
    lv_obj_set_style_arc_color(ui_leftArc2, lv_color_hex(0x295031), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui_leftArc2, lv_color_hex(0x41B65A), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui_leftArc, lv_color_hex(0x295031), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui_leftArc, lv_color_hex(0x41B65A), LV_PART_INDICATOR | LV_STATE_DEFAULT);
  }
  }

  if(conf_complete){
        if (!deviceConnected && oldDeviceConnected) {
        delay(500);
        pServer->startAdvertising();
        Serial.println("Start advertising");
        oldDeviceConnected = deviceConnected;
    }
    if(deviceConnected){
       if(start_time == 0){
        start_time = millis();
       }
      if(millis() - start_time >= 3000)
      {
      snprintf(temp, sizeof(temp), "%.0f", lastTemperature);
      snprintf(left, sizeof(left), "%d", left_inj);
      snprintf(right, sizeof(right), "%d", right_inj);
      snprintf(left_remaining, sizeof(left_remaining) , "%d" , left_remaining_inj);
      snprintf(right_remaining, sizeof(right_remaining) , "%d" , right_remaining_inj);
      snprintf(batt , sizeof(batt) , "%d" , bat_percentage);

        pTemperatureCharacteristic->setValue(temp); // Set value as a string
        pTemperatureCharacteristic->notify();
        Serial.println(" temp data sent");

        pLeftCharacteristic->setValue(left); // Set value as a string
        pLeftCharacteristic->notify();
        Serial.println(" left data sent");

        pRightCharacteristic->setValue(right); // Set value as a string
        pRightCharacteristic->notify();
        Serial.println(" right data sent");

        if(analogRead(BAT_ADC) > 1550){
        pBatteryCharacteristic->setValue("Mis en CH"); // Set value as a string
        pBatteryCharacteristic->notify();
        Serial.println(" bat data sent");
        } else {
        pBatteryCharacteristic->setValue(batt); // Set value as a string
        pBatteryCharacteristic->notify();
        Serial.println(" bat data sent");
        }

        pLeftRemainingInjCharacteristic->setValue(left_remaining);
        pLeftRemainingInjCharacteristic->notify();
        Serial.println("left remaining inj sent");

        pRightRemainingInjCharacteristic->setValue(right_remaining);
        pRightRemainingInjCharacteristic->notify();
        Serial.println("right remaining inj sent");

        if(left_color == 1){
          pLeftColorCharacteristic->setValue("orange");
          pLeftColorCharacteristic->notify();
          Serial.println("left color sent");
        } else if (left_color == 2){
          pLeftColorCharacteristic->setValue("blue");
          pLeftColorCharacteristic->notify();
          Serial.println("left color sent");
        } else if(left_color == 3){
          pLeftColorCharacteristic->setValue("grey");
          pLeftColorCharacteristic->notify();
          Serial.println("left color sent");
        }

        if(right_color == 1){
          pRightColorCharacteristic->setValue("orange");
          pRightColorCharacteristic->notify();
          Serial.println("right color sent");
        } else if(right_color == 2){
          pRightColorCharacteristic->setValue("blue");
          pRightColorCharacteristic->notify();
          Serial.println("right color sent");
        } else if(right_color == 3){
          pRightColorCharacteristic->setValue("grey");
          pRightColorCharacteristic->notify();
          Serial.println("right color sent");
        }

        if(analogRead(left_sensor) < 4095){
          pLeftPresenceCharacteristic->setValue("left syringe is present");
          pLeftPresenceCharacteristic->notify();
          Serial.println("left syringe status sent");
        } else {
          pLeftPresenceCharacteristic->setValue("left syringe is not present !");
          pLeftPresenceCharacteristic->notify();
          Serial.println("left syringe status sent");
        } 

        if(analogRead(right_sensor) < 4095){
          pRightPresenceCharacteristic->setValue("right syringe is present");
          pRightPresenceCharacteristic->notify();
          Serial.println("right syringe status sent");
      } else {
          pRightPresenceCharacteristic->setValue("right syringe is not present !");
          pRightPresenceCharacteristic->notify();
          Serial.println("right syringe status sent");
      }
      if(start_left_timer){
        pLeftTimeCharacteristic->setValue(std::string(elapsed_left));
        pLeftTimeCharacteristic->notify();
        Serial.println("left elapsed time sent");
      }
        if(start_right_timer){
        pRightTimeCharacteristic->setValue(std::string(elapsed_right));
        pRightTimeCharacteristic->notify();
        Serial.println("right elapsed time sent");
      }
        start_time = millis();
      }

    }
    if (deviceConnected && !oldDeviceConnected) {
        oldDeviceConnected = deviceConnected;
        start_time = 0;
    }
}

        if(millis() - lastTouchTime >= 15000){
          TFT_SET_BL(15);
        } else{
          TFT_SET_BL(brightness_level);
        }
        if (millis() - lastTouchTime >= 30000) {
        deep_sleep();
    }
  lv_timer_handler(); /* Call LVGL tasks */
  delay(5);
}

void deep_sleep() {
    for (int br = 15; br > 0; br -= 1) {
        TFT_SET_BL(br); // Set brightness to gradually decrease
        delay(20); // Delay for smoother dimming
    }
    // External wakeup Pins
    esp_sleep_enable_ext0_wakeup(GPIO_NUM_5, 0);
    esp_sleep_enable_ext1_wakeup((1ULL << hall_left) | (1ULL << hall_right), ESP_EXT1_WAKEUP_ANY_HIGH);
    esp_deep_sleep_start();
}

// Function to start the timer
void start_timer_left() {
    gettimeofday(&timer_left, NULL); // Get the start time
    Serial.printf("Timer started at: %ld seconds\n", timer_left.tv_sec);
}
void start_timer_right() {
    gettimeofday(&timer_right, NULL); // Get the start time
    Serial.printf("Timer started at: %ld seconds\n", timer_right.tv_sec);
}

char* calculate_elapsed_time_left() {
    static char timeStr[10];  // Buffer to store formatted time
    struct timeval current_time;
    gettimeofday(&current_time, NULL); // Get the current time

    elapsed_time_left = (current_time.tv_sec - timer_left.tv_sec); // Calculate elapsed time in seconds

    // Convert elapsed time to hours and minutes
    int hours = (elapsed_time_left / 3600) % 24;
    int minutes = (elapsed_time_left % 3600) / 60;

    // Format as "XH : XM"
    sprintf(timeStr, "%dH : %dM", hours, minutes);
    lv_label_set_text(ui_Label19 ,timeStr);
    return timeStr;
}

char* calculate_elapsed_time_right() {
    static char timeStr[10];  // Buffer to store formatted time
    struct timeval current_time;
    gettimeofday(&current_time, NULL); // Get the current time

    elapsed_time_right = (current_time.tv_sec - timer_right.tv_sec); // Calculate elapsed time in seconds

    // Convert elapsed time to hours and minutes
    int hours = (elapsed_time_right / 3600) % 24;
    int minutes = (elapsed_time_right % 3600) / 60;

    // Format as "XH : XM"
    sprintf(timeStr, "%dH : %dM", hours, minutes);
    lv_label_set_text(ui_Label14 ,timeStr);
    return timeStr;
}



