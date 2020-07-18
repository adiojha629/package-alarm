#include <ESP8266WiFi.h>

char* ssid = "";
char* password = "";
void setup() 
{
  Serial.begin(9600);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(1000);
    Serial.println("Connecting...");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println("We are connected");
    delay(1000);
  }
  else
  {
    Serial.println("NOT Connected");
  }
}
