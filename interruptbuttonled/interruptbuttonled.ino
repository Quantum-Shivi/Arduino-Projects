volatile bool buttonpressed = false;
void setup() {
    pinMode(13, OUTPUT);
    pinMode(A1, INPUT_PULLUP);
    PCICR |= (1 << PCIE1);
    PCMSK1 |= (1 << PC1);
    sei();
    //attachInterrupt(digitalPinToInterrupt(2), ButtonPress, FALLING);
}

void loop() {
    if (buttonpressed == true) {
        digitalWrite(13, HIGH);
        delay(2000);
        buttonpressed = false;
    } 
    else {
        digitalWrite(13, LOW);
    }
}

ISR(PCINT1_vect) {
    if (digitalRead(A1) == LOW) {
        buttonpressed = true;
    }
}