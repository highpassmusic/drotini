#include "Leds.h"

Leds::Leds() { }

Leds::~Leds() { }

void Leds::setColor(int index, char value) {
    colors[index] = value;
}

char Leds::approximateColor(int r, int g, int b) {
    char red, green, blue;
    red   = (char)(r / 32);
    green = (char)(g / 32);
    blue  = (char)(b / 64);

    return (red << 5) + (green << 2) + blue;
}