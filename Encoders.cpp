#include "Encoders.h"

Encoder *Encoders::encoders[NUM_ENCODERS];

void __encoders_int_0() { Encoders::readPin(0); }
void __encoders_int_1() { Encoders::readPin(1); }
void __encoders_int_2() { Encoders::readPin(2); }
void __encoders_int_3() { Encoders::readPin(3); }
void __encoders_int_4() { Encoders::readPin(4); }
void __encoders_int_5() { Encoders::readPin(5); }
void __encoders_int_6() { Encoders::readPin(6); }
void __encoders_int_7() { Encoders::readPin(7); }

Encoders::Encoders() {
    Encoder::init();

    int i;
    for (i = 0; i < NUM_ENCODERS; i++) {
        encoders[i] = new Encoder(  PIN_START + (i * 2), 
                                    PIN_START + (i * 2) + 1);
    }

    attachInterrupt(encoders[0]->getPin(PIN_A), __encoders_int_0, CHANGE);
    attachInterrupt(encoders[0]->getPin(PIN_B), __encoders_int_0, CHANGE);

    attachInterrupt(encoders[1]->getPin(PIN_A), __encoders_int_1, CHANGE);
    attachInterrupt(encoders[1]->getPin(PIN_B), __encoders_int_1, CHANGE);

    attachInterrupt(encoders[2]->getPin(PIN_A), __encoders_int_2, CHANGE);
    attachInterrupt(encoders[2]->getPin(PIN_B), __encoders_int_2, CHANGE);

    attachInterrupt(encoders[3]->getPin(PIN_A), __encoders_int_3, CHANGE);
    attachInterrupt(encoders[3]->getPin(PIN_B), __encoders_int_3, CHANGE);

    attachInterrupt(encoders[4]->getPin(PIN_A), __encoders_int_4, CHANGE);
    attachInterrupt(encoders[4]->getPin(PIN_B), __encoders_int_4, CHANGE);

    attachInterrupt(encoders[5]->getPin(PIN_A), __encoders_int_5, CHANGE);
    attachInterrupt(encoders[5]->getPin(PIN_B), __encoders_int_5, CHANGE);

    attachInterrupt(encoders[6]->getPin(PIN_A), __encoders_int_6, CHANGE);
    attachInterrupt(encoders[6]->getPin(PIN_B), __encoders_int_6, CHANGE);

    attachInterrupt(encoders[7]->getPin(PIN_A), __encoders_int_7, CHANGE);
    attachInterrupt(encoders[7]->getPin(PIN_B), __encoders_int_7, CHANGE);
}

Encoders::~Encoders() {
    int i;
    for (i = 0; i < NUM_ENCODERS; i++) {
        delete encoders[i];
    }
}

int Encoders::getPosition(int e) {
    return encoders[e]->getPosition();
}

void Encoders::readPin(int e) {
    encoders[e]->readPins();
}
