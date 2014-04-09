#include "Encoder.h"

struct state **Encoder::state_wheel = 
            (struct state**)malloc(sizeof(struct state*));

Encoder::Encoder(int a, int b) {
    position = 0;
    pin_a = 0;
    pin_b = 0;
    setPins(a, b);
}

Encoder::~Encoder() { 
}

void Encoder::readPins() {
    int a, b, signal_state;
    a = digitalRead(pin_a);
    b = digitalRead(pin_b);
    
    signal_state = (a << 1) + b;
    if ((*_state)->next->mask == signal_state) {
        (*_state) = (*_state)->next;
        if (position < 127)
            position++;
        return;
    }
    
    if ((*_state)->prev->mask == signal_state) {
        (*_state) = (*_state)->prev;
        if (position > 0)
            position--;
        return;
    }
}

void Encoder::setPins(int a, int b) {
    pin_a = a;
    pin_b = b;
    
    pinMode(pin_a, INPUT_PULLUP);
    pinMode(pin_b, INPUT_PULLUP);
    
    int signal_state = (digitalRead(pin_a) << 1) +
                        digitalRead(pin_b);
    
    _state = (volatile state**)state_wheel;
    while (signal_state != (*_state)->mask) {
        (*_state) = (*_state)->next;
    }
}

int Encoder::getPosition() {
    return position;
}

int Encoder::setPosition(int position) {
    if (position >= 0 && position <= 127)
        this->position = position;
#ifdef DEBUG
    Serial.println("Error setting encoder position: out of bounds");
#endif
}

int Encoder::getPin(int pin) {
    if (pin == PIN_A) return pin_a;
    if (pin == PIN_B) return pin_b;
    return -1;
}

void Encoder::init() {
    struct state* a = (struct state*)malloc(sizeof(struct state));
    struct state* b = (struct state*)malloc(sizeof(struct state));
    struct state* c = (struct state*)malloc(sizeof(struct state));
    struct state* d = (struct state*)malloc(sizeof(struct state));
    
    a->mask = 1; b->mask = 0; c->mask = 2; d->mask = 3;
    
    a->next = b; b->prev = a;
    b->next = c; c->prev = b;
    c->next = d; d->prev = c;
    d->next = a; a->prev = d;
    
    *state_wheel = a;
}