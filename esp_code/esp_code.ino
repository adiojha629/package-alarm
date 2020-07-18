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
  Serial.println("1");
  delay(1000);
  Serial.println("2");
  delay(1000);
}
