// ------------------------------------------------------------
// Project: [yaz_1.0.1]
// Author: Taha Traidi
// Copyright (C) 2025 Taha Traidi
// All Rights Reserved. Unauthorized use, reproduction, or
// distribution of this code is strictly prohibited.
// Contact: [taha.traidi.tt@gmail.com]
// ------------------------------------------------------------
#ifndef CST816S_H
#define CST816S_H

#include <Arduino.h>

#define CST816S_ADDRESS     0x15

enum GESTURE {
  NONE = 0x00,
  SWIPE_UP = 0x01,
  SWIPE_DOWN = 0x02,
  SWIPE_LEFT = 0x03,
  SWIPE_RIGHT = 0x04,
  SINGLE_CLICK = 0x05,
  DOUBLE_CLICK = 0x0B,
  LONG_PRESS = 0x0C

};

struct data_struct {
  byte gestureID; // Gesture ID
  byte points;  // Number of touch points
  byte event; // Event (0 = Down, 1 = Up, 2 = Contact)
  int x;
  int y;
  uint8_t version;
  uint8_t versionInfo[3];
};



class CST816S {

  public:
    CST816S(int sda, int scl, int rst, int irq);
    void begin(int interrupt = RISING);
    void sleep();
    bool available();
    data_struct data;
    String gesture();

  void read_touch();
  private:
    int _sda;
    int _scl;
    int _rst;
    int _irq;
    bool _event_available;

    void IRAM_ATTR handleISR();
    // void read_touch();

    uint8_t i2c_read(uint16_t addr, uint8_t reg_addr, uint8_t * reg_data, uint32_t length);
    uint8_t i2c_write(uint8_t addr, uint8_t reg_addr, const uint8_t * reg_data, uint32_t length);
};

#endif