String colors[9] = {"red", "green", "blue", "black", "white", "yellow", "orange", "purple", "pink"};
void setup() {
    Serial.begin(9600);
}
 
void loop() {
    Serial.println("Enter a command: ");
    while (Serial.available() == 0) {
    }
    String usercommand = Serial.readString();
    usercommand.trim();
    if (usercommand == "color") {
        randomSeed(analogRead(A1));
        int index = random(9);
        Serial.println(colors[index]);
    }
    else if (usercommand == "number") {
        int index = random(1000);
        Serial.println(index);
    }
    delay(1000);
}
