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

int currentnum = 0;
int buttonstate = HIGH;
int buttonstate2 = HIGH;
int digcount = 1;

int enablearray[4] = {D1, D2, D3, D4};
int segarray[7] = {12, 8, 5, 3, 2, 11, 6};
int array0[7] = {1, 1, 1, 1, 1, 1, 0};
int array1[7] = {0, 1, 1, 0, 0, 0, 0};
int array2[7] = {1, 1, 0, 1, 1, 0, 1};
int array3[7] = {1, 1, 1, 1, 0, 0, 1};
int array4[7] = {0, 1, 1, 0, 0, 1, 1};
int array7[7] = {1, 1, 1, 0, 0, 0, 0};
int array5[7] = {1, 0, 1, 1, 0, 1, 1};
int array6[7] = {1, 0, 1, 1, 1, 1, 1};
int array8[7] = {1, 1, 1, 1, 1, 1, 1};
int array9[7] = {1, 1, 1, 1, 0, 1, 1};


void print(int array[]) {
    for (int y = 0; y < 7; y++) {
        digitalWrite(segarray[y], array[y]);
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

void place_value_calc(int num) {
    int num1 = (num / 1000) % 10;
    int num2 = (num / 100) % 10;
    int num3 = (num / 10) % 10;
    int num4 = num % 10;
    int digits_of_number[4];
    digits_of_number[0] = num1;
    digits_of_number[1] = num2;
    digits_of_number[2] = num3;
    digits_of_number[3] = num4;
    for (int index = 0; index < 4; index++) {
        for (int l = 0; l < 7; l++){
            digitalWrite(segarray[l], LOW);
        }
        digitalWrite(D1, HIGH);
        digitalWrite(D2, HIGH);
        digitalWrite(D3, HIGH);
        digitalWrite(D4, HIGH);
        digitalWrite(enablearray[index], LOW);
        draw(digits_of_number[index]);
        delay(4);
    }
    
}

void setup() {
    for (int x = 2; x < 14; x++) {
        pinMode(x, OUTPUT);
    }
    pinMode(A0, INPUT_PULLUP);
    pinMode(A1, INPUT_PULLUP);
}

void loop() {
    int buttonreading = digitalRead(A0);
    int buttonreading2 = digitalRead(A1);
    if (buttonreading != buttonstate) {
        buttonstate = buttonreading;
        if (buttonstate == LOW) {
            currentnum++;
            if (currentnum == 10000) {
                currentnum = 0;
            }
        }
    }
    if (buttonreading2 != buttonstate2) {
        buttonstate2 = buttonreading2;
        if (buttonstate2 == LOW) {
            currentnum -= 1;
            if (currentnum == -1) {
                currentnum = 9999;
            }
        }
    }
    place_value_calc(currentnum);
    
}