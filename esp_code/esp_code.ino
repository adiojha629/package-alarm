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
    Serial.print("*");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(WiFi.status() != WL_CONNECTED)
  {
    Serial.println("1");
  }
  if(WiFi.status() == WL_CONNECTED)
  {
     Serial.println("2");
  }
}
