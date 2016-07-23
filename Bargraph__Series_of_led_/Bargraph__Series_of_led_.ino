/*
led1 - 2
led2 - 3
led3 - 4
*/

#define led1 2
#define led2 3
#define led3 4

void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(led1,HIGH);
  delay(300);
  digitalWrite(led2,HIGH);
  delay(300);
  digitalWrite(led3,HIGH);
  delay(300);
  digitalWrite(led3,LOW);
  delay(300);
  digitalWrite(led2,LOW);
  delay(300);
  digitalWrite(led1,LOW);
  delay(300);
  
  // put your main code here, to run repeatedly:
}
