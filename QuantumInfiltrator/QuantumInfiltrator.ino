#include <WiFi.h>
#include <WebServer.h>
#include <AsyncTCP.h>



#define WIFI_SSID "SSID"
#define WIFI_PASSWORD "PASSWORD"

hw_timer_t * MyTimer = NULL;
int origin = 0;
volatile int spy_progress = 0;
volatile bool breach = false;
int prevmillis = 0;
IPAddress ip;
AsyncServer server(8888); // Create a web server object that listens on port 8888
AsyncClient* connectedClient = nullptr; // Create a WiFiClient object to handle incoming connections


int rollQuantumDice() {
    // Set the percent_fail to the current spy_progress
    int percent_fail = spy_progress;
    // Calculate the percent_success as 100 - percent_fail
    int percent_success = 100 - percent_fail;
    // Seed the random number generator with a random value from analog pin 32
    randomSeed(analogRead(32));

    int roll = random(101); // Generate a random number between 0 and 100
    if (roll <= percent_fail) {
        connectedClient->write("Radar:FAIL\n");
        connectedClient->write(("WARNING: PERIMETER BREACHED - INFILTRATOR AT " + String(spy_progress) + "%\n").c_str());
        Serial.println("Radar:FAIL");
        Serial.println("WARNING: PERIMETER BREACHED - INFILTRATOR AT " + String(spy_progress) + "%");
        origin = spy_progress; // Store the current spy_progress in origin
    }
    else {
        connectedClient->write("Radar:SUCCESS\n");
        connectedClient->write(("INFILTRATOR DETECTED - INFILTRATOR PROGRESS RESTORED TO " + String(origin) + "%\n").c_str());
        Serial.println("Radar:SUCCESS");
        Serial.println("INFILTRATOR DETECTED - INFILTRATOR PROGRESS RESTORED TO " + String(origin) + "%");
        spy_progress = origin; // Reset spy_progress to the origin value
    }
    return roll; // Added return to match function declaration type
}


 //callback function to handle incoming data from the client
void DataReceived(void* arg, AsyncClient* client, void* data, size_t len) {
    //Serial.write((uint8_t*)data, len);
    if (millis() - prevmillis > 500) { // Check if 500 milliseconds have passed since the last radar was fired
        prevmillis = millis();
        client->write("Radar fired\n");
        //Roll the quantum dice with probabilities and send the result to the client
        rollQuantumDice();
    }
}

 //callback function
void clientConnected(void* arg, AsyncClient* client) {
    Serial.println("Client connected");
    client->write("Client connected to ESP32 server\n");

    client->onData(DataReceived, nullptr);

    // Store the connected client
    connectedClient = client;
}



void sendMessageToClient(String message) {
    // Send the message to the client
    if (connectedClient != nullptr && connectedClient->connected()) {
        connectedClient->write(message.c_str());
    }
    else {
        Serial.println("No client connected or client disconnected.");
    }

}

void printAlert() {
    Serial.println("INFILTRATOR SUCCESSFULLY INFILTRATED - SYSTEM BREACHED");
    connectedClient->write("INFILTRATOR SUCCESSFULLY INFILTRATED - SYSTEM BREACHED\n");
}

void ARDUINO_ISR_ATTR onTimerHandler() {
   spy_progress += 2;
    if (spy_progress >= 100) {
        breach = true;
    }
}

void setup() {
    delay(5000);
    Serial.begin(9600);
    //Timer setup for spy_progress increment
    MyTimer = timerBegin(1000000);
    timerAttachInterrupt(MyTimer, &onTimerHandler);
    timerAlarm(MyTimer, 1000000, true, 0);

    // Connecting Esp32 to home network
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    // Wait until the ESP32 is connected to the Wi-Fi network
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }
    Serial.println("\nConnected!");

    // store/print IP address
    ip = WiFi.localIP();
    Serial.println(ip);

    //Open port 8888 for incoming connections
    server.onClient(clientConnected, nullptr);
    server.begin();

    // Waits and listens for incoming connections on port 8888
}


void loop() {
    //check if breach flag is set
    if (breach) {
        Serial.println("INFILTRATOR SUCCESSFULLY INFILTRATED - SYSTEM BREACHED");
        connectedClient->write("INFILTRATOR SUCCESSFULLY INFILTRATED - SYSTEM BREACHED\n");
        breach = false; // Reset the breach flag after printing the alert
    }

    //read from serial and send to client
    String usermessage = Serial.readString();
    usermessage.trim();
    if (usermessage == "ping radar") {
        rollQuantumDice();
    }
}