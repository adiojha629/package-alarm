int led = 13;
int speakerPin = 10;   
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  pinMode(speakerPin, OUTPUT); 
  digitalWrite(led,LOW);
  //Serial1.begin(9600);
  Serial.begin(9600);
  while(!Serial);
  //while(!Serial1);
  //Serial.println("Input 1 to turn on led and 2 to turn off");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    int state = Serial.parseInt();
    if(state == 1)
    {
      digitalWrite(13, HIGH);
      play('F', 2); 
      Serial.println("Command Completed LED turned ON");
    }
    if(state == 2)
    {
      digitalWrite(13,LOW);
      //play('F', 2); 
      Serial.println("Command Completed LED turned OFF");
    }
  }
}

void play( char note, int beats)
{
  int numNotes = 14;  // number of notes in our note and frequency array (there are 15 values, but arrays start at 0)

  //Note: these notes are C major (there are no sharps or flats)

  //this array is used to look up the notes
  char notes[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C', 'D', 'E', 'F', 'G', 'A', 'B', ' '};
  //this array matches frequencies with each letter (e.g. the 4th note is 'f', the 4th frequency is 175)
  int frequencies[] = {131, 147, 165, 175, 196, 220, 247, 262, 294, 330, 349, 392, 440, 494, 0};

  int currentFrequency = 0;    //the frequency that we find when we look up a frequency in the arrays
  int beatLength = 150;   //the length of one beat (changing this will speed up or slow down the tempo of the song)

  //look up the frequency that corresponds to the note
  for (int i = 0; i < numNotes; i++)  // check each value in notes from 0 to 14
  {
    if (notes[i] == note)             // does the letter passed to the play function match the letter in the array?
    {
      currentFrequency = frequencies[i];   // Yes! Set the current frequency to match that note
    }
  }

  //play the frequency that matched our letter for the number of beats passed to the play function
  tone(speakerPin, currentFrequency, beats * beatLength);
  delay(beats * beatLength);  //wait for the length of the tone so that it has time to play
  delay(50);                  //a little delay between the notes makes the song sound more natural

}
