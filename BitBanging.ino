
void BitBang(int inp_byt) {
    for (int counter = 0; counter < 8; counter++) {
        digitalWrite(13, (inp_byt >> counter) & 1);
        delay(500);
    }
}

void setup() {
    Serial.begin(9600);
    pinMode(13, OUTPUT);
}

void loop() {
    BitBang(0b10101010);
    delay(500);
}