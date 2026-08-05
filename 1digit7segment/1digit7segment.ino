const int E = 9;
const int D = 8;
const int C = 7;
const int DP = 6;
const int B = 5;
const int A = 4;
const int F = 3;
const int G = 2;

void setup() {
    pinMode(E, OUTPUT);
    pinMode(D, OUTPUT);
    pinMode(C, OUTPUT);
    pinMode(DP, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(A, OUTPUT);
    pinMode(F, OUTPUT);
    pinMode(G, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(F, LOW);
    digitalWrite(C, LOW);
    digitalWrite(DP, LOW);
}