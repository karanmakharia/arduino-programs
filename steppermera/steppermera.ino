#include <Stepper.h>
int steps=200;
int enable =8;
Stepper motor(steps, 10,11,12,13);
void setup() {
  pinMode(enable,OUTPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:
motor.setSpeed(60);
digitalWrite(enable, LOW);
}
int count=1;
void loop() {
    digitalWrite(enable,HIGH);
  motor.step(steps);
  delay(500);
  digitalWrite(enable, LOW);
  digitalWrite(enable, HIGH);
  motor.step(-steps);
  delay(500);
  
}
  // put your main code here, to run repeatedly:


