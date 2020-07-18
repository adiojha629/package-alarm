int led = 13;
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
  //Serial1.begin(9600);
  Serial.begin(9600);
  while(!Serial);
  //while(!Serial1);
  Serial.println("Input 1 to turn on led and 2 to turn off");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    int state = Serial.parseInt();
    if(state == 1)
    {
      digitalWrite(13, HIGH);
      Serial.println("Command Completed LED turned ON");
    }
    if(state == 2)
    {
      digitalWrite(13,LOW);
      Serial.println("Command Completed LED turned OFF");
    }
  }
}
