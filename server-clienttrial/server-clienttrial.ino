#include <WiFi.h>
#include <WebServer.h>
#include <AsyncTCP.h>


#define WIFI_SSID "SSID"
#define WIFI_PASSWORD "PASSWORD"

 IPAddress ip;
 AsyncServer server(8888); // Create a web server object that listens on port 8888
 AsyncClient* connectedClient = nullptr; // Create a WiFiClient object to handle incoming connections

 //callback function to handle incoming data from the client
void DataReceived(void* arg, AsyncClient* client, void* data, size_t len) {
    Serial.write((uint8_t*)data, len);
}

 //callback function
void clientConnected(void* arg, AsyncClient* client) {
    Serial.println("Client connected");
    client->write("Client connected to ESP32 server");

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

void setup() {
    delay(5000);
    Serial.begin(9600);

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
    //read from serial and send to client
    String usermessage = Serial.readString();
    usermessage.trim();
    if (usermessage.length() > 0) {
        Serial.println("Sending message: " + usermessage);
        sendMessageToClient(usermessage);
    }
}