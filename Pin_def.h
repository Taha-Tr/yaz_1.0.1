// ------------------------------------------------------------
// Project: [yaz_1.0.1]
// Author: Taha Traidi
// Copyright (C) 2025 Taha Traidi
// All Rights Reserved. Unauthorized use, reproduction, or
// distribution of this code is strictly prohibited.
// Contact: [taha.traidi.tt@gmail.com]
// ------------------------------------------------------------
#define BAT_ADC 1          // ADC1 Channel 0 to read battery voltage and convert it to percentage
#define STAT_PIN 9        // GPIO pin connected to STAT
#define TP_INT  5          // Pin to use as external wakeup for the touch screen 
#define BL  2              // Backlight pin
#define left_sensor 16        // Left obstacle detection sensor
#define right_sensor 15       // Right obstacle detection sensor
#define temp_sensor 17     // DS18B20 pin, a digital temperature sensor
#define hall_left 21       // left hall sensor for door opening and closing detection and external wakeup
#define hall_right 18      // right hall sensor for door opening and closing detection and external wakeup