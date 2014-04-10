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

    // Initialization of Display
    instruction(0x38);
    instruction(0x0C);
    instruction(0x06);
    instruction(0x01);
}

Display::~Display() {
    delete leds;
} 

void Display::write(char* line1, char* line2) {
    char i = 0;
    instruction(SET_DDRAM);
    do {
        dataCommand(line1[0]);
    } while (line1[i] != '\0');
    instruction(SET_DDRAM | )
}

void Display::instruction(char instr) {
    for (int i = 0; i < 8; i++) {
        digitalWrite(data_pins[i] + instr & 0x01
    }
    digitalWrite(rs_pin, 0);
    digitalWrite(e_pin, 1);
    digitalWrite(e_pin, 0);
}

void Display::dataCommand(char data) {
    for (int i = 0; i < 8; i++) {
        digitalWrite(data_pins[i] + instr & 0x01
    }
    digitalWrite(rs_pin, 1);
    digitalWrite(e_pin, 1);
    digitalWrite(e_pin, 0);
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