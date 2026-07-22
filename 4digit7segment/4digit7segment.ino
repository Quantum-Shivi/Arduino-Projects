//const int E = 9;
//const int D = 8;
//const int C = 7;
//const int DP = 6;
//const int B = 5;
//const int A = 4;
//const int F = 3;
//const int G = 2;

const int E = 2;
const int D = 3;
const int DP = 4;
const int C = 5;
const int G = 6;
const int D4 = 7;
const int B = 8;
const int D3 = 9;
const int D2 = 10;
const int F = 11;
const int A = 12;
const int D1 = 13;

void setup() {
    for (int x = 2; x < 14; x++) {
        pinMode(x, OUTPUT);
    }
}

void loop() {
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(DP, HIGH);
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, LOW);
    digitalWrite(D4, HIGH);
}