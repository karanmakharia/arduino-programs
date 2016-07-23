#include <IRremote.h>
int pir=3;
#define tsop 4
#define bulb 5
#define button 6
#define led1 8
#define led2 9
#define led3 10
#define led4 11


String voice;

IRrecv irrecv(tsop);
decode_results results;

int count=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(pir,INPUT);
  pinMode (bulb, OUTPUT);
  pinMode(tsop, OUTPUT);
  pinMode(button, INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
 
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {  
int bs=0;
bs= digitalRead(button);
 if(count<4)
 {
 if(bs==HIGH)
 {
   count++;
   delay(500);
 }
 }
 else
 {
   count=0;
 }
 Serial.println(count);
 delay(10);
if (count==0)
pi();

if(count==1)
ir();

if(count==2)
bluetooth();

if(count==3)
audio();

}

void bluetooth()
{
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,LOW);
 if(Serial.available()>0)
   {
     
      int data= Serial.read(); // reading the data received from the bluetooth module
      switch(data)
      {
        case 'a': LEDON();break; // when a is pressed on the app on your smart phone
        case 'c': LEDOFF();break; // when b is pressed on the app on your smart phone
        default : break;
      }
   }
   delay(50);
}

void pi()
{
  digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  
  int pirState=digitalRead(pir);
  if(pirState==1)
  {
    digitalWrite(bulb,HIGH);
    for(int i=0;i<3;i++)
    {
      int pirState=digitalRead(pir);
      if(pirState==1)
      {
      i=0;
      Serial.println("Counter Reset");
      }
      Serial.println(i);
      delay(1000);
    }
  }
  delay(200);
  digitalWrite(bulb,LOW);
  
}

void ir()
{
  digitalWrite(led1,LOW);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    delay(30);
   if(results.value==33441975)
    digitalWrite(bulb,HIGH);
    
    delay(300);
   if(results.value==33446055)
    digitalWrite(bulb,LOW);
    irrecv.resume(); // Receive the next value
  }
}

void audio()
{
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,HIGH);
while (Serial.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable
  char c = Serial.read(); //Conduct a serial read
  if (c == '#') {break;} //Exit the loop when the # is detected after the word
  voice += c; //Shorthand for voice = voice + c
  } 
  if (voice.length() > 0) {
    Serial.println(voice);
//-----------------------------------------------------------------------//   
  //----------Control Multiple Pins/ LEDs----------// 
       if(voice == "*hi") {digitalWrite(bulb,HIGH);}  //Turn Off All Pins (Call Function)
  else if(voice == "*bye"){digitalWrite(bulb,LOW);} //Turn On  All Pins (Call Function)
  else if(voice== "*buy"){digitalWrite(bulb,LOW);}
  // put your main code here, to run repeatedly:
voice=""; //Reset the variable after initiating
}
}
void LEDON() // function when 'a' is pressed
{
  Serial.println("LED ON!");
  digitalWrite(bulb,HIGH); // onboard led on
}

void LEDOFF() // function when 'b' is presse
{
  Serial.println("LED OFF"); // onboard led off
  digitalWrite(bulb,LOW); 
}


