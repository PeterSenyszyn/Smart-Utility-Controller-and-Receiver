#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11);

char character;
String data = "";

int RED_PIN = 2;
int BLUE_PIN = 3;
int GREEN_PIN = 4;

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
  
  pinMode(RED_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
}

void loop() {
  while (mySerial.available())
  {
    character = mySerial.read();
  
    data = "";
    data.concat(character);
  }
  
  if (data == "1")
    setColor(255, 0, 0);
  
  else if (data == "2")
    setColor(0, 255, 0);
  
  else if (data == "3")
    setColor(128, 0, 128);
  
  else if (data == "4")
    setColor(0, 0, 255);
  
  else if (data == "5")
    setColor(255, 255, 0);
  
  else if (data == "6")
    setColor(255, 20, 147);
  
  else if (data == "7")
    setColor(160, 160, 160);
  
  else
    setColor(0, 0, 0);
}

void setColor(int red, int green, int blue)
{
  analogWrite(RED_PIN, 255 - red);
  analogWrite(GREEN_PIN, 255 - green);
  analogWrite(BLUE_PIN, 255 - blue); 
}
