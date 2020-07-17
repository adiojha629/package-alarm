

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

//Firebase settings
#define FIREBASE_HOST "ESP Test.firebaseio.com"
#define FIREBASE_AUTH "pttqmWyAp4nSbvbfOporVCC4g4kna5MIAADke5sv"

//Wi-Fi settings
#define WIFI_SSID "OjhaTower"
#define WIFI_PASSWORD "6083857103"

// The amount of time the ultrassonic wave will be travelling for
long duration = 0;
// Define the distance variable
double distance = 0;
void setup()
{

    // Connect to Wi-Fi
    Serial.print("Wi-Fi...");
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting...");
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(500);
    }
    Serial.println();
    Serial.print("Connected to: ");
    Serial.println(WiFi.localIP());

    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

    Serial.begin(9600);
}

void loop()
{

    getDistance();
    // Prints the distance value to the serial monitor
    Serial.print("Distance: ");
    Serial.println(distance);
  
    delay(500);
}

void getDistance()
{
    duration = 1000;

    // Calculating the distance, in centimeters, using the formula described in the first section.
    distance = duration * 0.034 / 2;
  
    // Sends the distance value to Firebase
    Firebase.setFloat("distance", distance);
}
