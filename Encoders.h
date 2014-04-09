#ifndef ENCODERS_H
#define ENCODERS_H

#include <Arduino.h>
#include "Encoder.h"

#define NUM_ENCODERS 8
#define PIN_START 22

class Encoders {
    static Encoder *encoders[NUM_ENCODERS];
  public:
    Encoders();
    ~Encoders();
    int getPin(int);
    int getPosition(int);
    static void readPin(int);
};

#endif