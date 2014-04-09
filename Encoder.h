#ifndef ENCODER_H
#define ENCODER_H

#include <Arduino.h>

#define PIN_A 0
#define PIN_B 1

typedef struct state {
    int mask;
    struct state* next;
    struct state* prev;
};

class Encoder {
    volatile int position;
    static   struct state **state_wheel;
    volatile struct state **_state;

    int pin_a, pin_b;
    int relative_state();
  public:
    Encoder(int, int);
    ~Encoder();
    void setPins(int, int);
    void readPins();
    int getPosition();
    int setPosition(int);
    int getPin(int);
    
    static void init();
};

#endif
