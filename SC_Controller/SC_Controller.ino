#include "pitches.h"
#include "tunes.h"

#define speaker 7

#define greenLED 3
#define redLED 2
#define button 6

#define dutyCycle 5
#define stoplightDelay 50
#define stoplightDelay 50

int ranVal;

int resetSignal = 0;
int points = 0;

char message = ' ';
char Signal = ' ';

//TODO: 
//impliment PWM for LEDs to lower brightness
//impliment UART communication
//impliment input reactions


void setup() {
  // put your setup code here, to run once:
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  //int brightness = map(dutyCycle, 0, 100, 0, 255);

  resetSignal = digitalRead(button);
  

  if(resetSignal)
  {
    Serial.println("reset");
  }

  ranVal = random(2);

  if(ranVal){
    Signal = 'G';
  }else{
    Signal = 'R';
  }

  //analogWrite(greenLED, brightness);
   

  // for(int i=0;i<100;i++){
  //   analogWrite(3, OFF);
  //   delay(10);
  // }

  if(Signal == 'G'){
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
  }
  
  if(Signal == 'R') { 
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
  }

  while(!Serial.available()) {}

  message = Serial.read();

  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, LOW);

  delay(1000);

  if(message == Signal){
    digitalWrite(greenLED, HIGH);
    playgoodtone();
    digitalWrite(greenLED, LOW);
    delay(500);
    points++;
  }else{
    digitalWrite(redLED, HIGH);
    playbadtone();
    digitalWrite(redLED, LOW);
    delay(500);
    points = 0;
  }

  Serial.print("points: ");
  Serial.println(points);

}