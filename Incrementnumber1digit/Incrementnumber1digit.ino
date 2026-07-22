const int E = 9;
const int D = 8;
const int C = 7;
const int DP = 6;
const int B = 5;
const int A = 4;
const int F = 3;
const int G = 2;

int pinarray[8] = {2, 3, 4, 5, 6, 7, 8, 9};
int array0[8] = {0, 1, 1, 1, 1, 1, 1, 1};
int array1[8] = {0, 0, 0, 1, 0, 1, 0, 0};
int array2[8] = {1, 0, 1, 1, 0, 0, 1, 1};
int array3[8] = {1, 0, 1, 1, 0, 1, 1, 0};
int array4[8] = {1, 1, 0, 1, 0, 1, 0, 0};
int array5[8] = {1, 1, 1, 0, 0, 1, 1, 0};
int array6[8] = {1, 1, 1, 0, 0, 1, 1, 1};
int array7[8] = {0, 0, 1, 1, 0, 1, 0, 0};
int array8[8] = {1, 1, 1, 1, 1, 1, 1, 1};
int array9[8] = {1, 1, 1, 1, 0, 1, 1, 0};

int currentnum = 0;
int buttonstate = HIGH;


void print(int array[]) {
    for (int x = 0; x < 8; x++) {
        digitalWrite(pinarray[x], array[x]);
    }
}

void draw(int number) {
    switch (number) {
        case 0: print(array0); break;
        case 1: print(array1); break;
        case 2: print(array2); break;
        case 3: print(array3); break;
        case 4: print(array4); break;
        case 5: print(array5); break;
        case 6: print(array6); break;
        case 7: print(array7); break;
        case 8: print(array8); break;
        case 9: print(array9); break; 
    }
}

void setup() {
    pinMode(E, OUTPUT);
    pinMode(D, OUTPUT);
    pinMode(C, OUTPUT);
    pinMode(DP, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(A, OUTPUT);
    pinMode(F, OUTPUT);
    pinMode(G, OUTPUT);
    pinMode(A0, INPUT_PULLUP);
    draw(currentnum);
}


void loop() {
    int buttonreading = digitalRead(A1);
    if (buttonreading != buttonstate) {
        buttonstate = buttonreading;
        if (buttonstate == LOW) {
        currentnum++;
        if (currentnum == 10) {
            currentnum = 0;
        }
        draw(currentnum);
        }
    }
}