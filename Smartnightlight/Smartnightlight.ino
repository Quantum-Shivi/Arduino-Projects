void setup() {
    pinMode(13, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int lightstate = analogRead(A0);
    if (lightstate >= 500) {
        digitalWrite(13, LOW);
    }
    else {
        digitalWrite(13, HIGH);
    }
}