#include "Buttons.h"

uint32_t Buttons::button_states = 0;

Buttons::Buttons(int clock_pin, int latch_pin, int data_pin) { 
    this->clock_pin = clock_pin;
    this->latch_pin = latch_pin;
    this->data_pin  = data_pin;

    pinMode(latch_pin, OUTPUT);
    pinMode(clock_pin, OUTPUT);
    pinMode(data_pin,   INPUT);

    getState();
    leds = new Leds();
}

Buttons::~Buttons() { 
    delete leds;
}

int Buttons::shift() {
    digitalWrite(clock_pin, 1);
    delayMicroseconds(1);
    digitalWrite(clock_pin, 0);
    delayMicroseconds(1);
    return digitalRead(data_pin);
}

void Buttons::getState() {
    // Latch the registers
    digitalWrite(clock_pin, 0);
    digitalWrite(latch_pin, 1);
    delayMicroseconds(20);
    digitalWrite(latch_pin, 0);

    // Shift it into a 32 bit integer
    button_states = 0;
    for (int i = 0; i < 32; i++) {
        button_states += shift() << i;
    }
}

uint32_t Buttons::getKeyMask(int key) {
    return (uint32_t)pow((float)2, (float)key);
}

uint32_t Buttons::getStepMask(int step) {
    return (uint32_t)pow((float)2, (float)(step + 16));
}

bool Buttons::isMuteDown() {
    return button_states & MUTE_MASK;
}

bool Buttons::isShiftDown() {
    return button_states & SHIFT_MASK;
}

bool Buttons::isStepDown(int step) {
    return button_states & getStepMask(step);
}

bool Buttons::isStepDown() {
    return button_states & ANY_STEP_MASK;
}

bool Buttons::isKeyDown(int key) {
    return button_states & getKeyMask(key);
}

bool Buttons::isKeyDown() {
    return button_states & ANY_KEY_MASK;
}

void Buttons::setMuteColor(int r, int g, int b) {
    char color = leds->approximateColor(r, g, b);
    leds->setColor(MUTE, color);
}

void Buttons::setShiftColor(int r, int g, int b) {
    char color = leds->approximateColor(r, g, b);
    leds->setColor(SHIFT, color);
}

void Buttons::setStepColor(int step, int r, int g, int b) {
    char color = leds->approximateColor(r, g, b);
    leds->setColor(STEP + step, color);
}

void Buttons::setKeyColor(int key, int r, int g, int b) {
    char color = leds->approximateColor(r, g, b);
    leds->setColor(KEY + key, color);
}
