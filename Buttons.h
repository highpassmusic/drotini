#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>

#define C0       0
#define C_SHARP  1
#define D        2
#define D_SHARP  3
#define E        4
#define F        5
#define F_SHARP  6
#define G        7
#define G_SHARP  8
#define A        9
#define A_SHARP 10
#define B       11
#define C1      12

#define MUTE_MASK    1073741824
#define SHIFT_MASK    536870912
#define ANY_KEY_MASK  536805376
#define ANY_STEP_MASK     65535

class Buttons {
    // State map:
    // <mute> <shift> <keys 0-12> <steps 0-15>
    static uint32_t button_states;
    Leds* leds;
    int clock_pin, latch_pin, data_pin;
    int shift();
    uint32_t getKeyMask(int);
    uint32_t getStepMask(int);
  public:
    Buttons(int, int, int);
    ~Buttons();
    void getState();
    bool isMuteDown();
    bool isShiftDown();
    bool isStepDown(int);
    bool isStepDown();
    bool isKeyDown(int);
    bool isKeyDown();
    void setMuteColor( int, int, int);
    void setShiftColor(int, int, int);
    void setStepColor( int, int, int, int);
    void setKeyColor(  int, int, int, int);
};

#endif