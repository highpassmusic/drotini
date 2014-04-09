#ifndef LEDS_H
#define LEDS_H

#define STEP 0
#define KEY 16
#define SHIFT 29
#define MUTE 30
#define DISPLAY 31

// TODO: figure out how to best write these out persistently

class Leds {
    // Each color is stores as an 8-bit value in 3-3-2 format
    static char colors[32];
  public:
    Leds();
    ~Leds();
    void setColor(int, char);
    char approximateColor(int, int, int);
};

#endif