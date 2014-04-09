#include "Display.h"

Display::Display(int e_pin, int rs_pin, int data_pins_start) {
    this->e_pin = e_pin;
    this->rs_pin = rs_pin;
    for (int i = 0; i < 8; i++) {
        data_pins[i] = data_pins_start + i;
    }
    mode = ROW;
    bar_text_status = 0x00;

    leds = new Leds();
}

Display::~Display() {
    delete leds;
}

void Display::init() {

}

void Display::write(char* line1, char* line2) {

}

void Display::instruction(char instr) {
    for (int i = 0; i < 8; i++) {
        digitalWrite(data_pins[i] + instr & 0x01
    }
}

void Display::setMode(int mode) {
    this->mode = mode;
}

void Display::setText(int placement, char* text) {

}

void Display::setBar(int placement, int amount) {

}

void Display::setColor(int r, int g, int b) {
    char color = leds->approximateColor(r, g, b);
    leds->setColor(DISPLAY, color);
}