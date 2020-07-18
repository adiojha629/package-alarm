#include <ESP8266WiFi.h>
char* ssid = "";
char* password = "";
int counter = 0;
void setup() 
{
  Serial.begin(9600);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(1000);
    Serial.println("1");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println("1");
    counter = counter + 1;
    if(counter == 20)
    {
      counter = 0;
      for(int i = 0; i<20; i++){
        Serial.println("2");
        delay(1000);
      }
    }
    delay(1000);
  }
  else
  {
    Serial.println("1");
  }
}
