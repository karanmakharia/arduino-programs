#include <IRremote.h>
#define tsop 4
#define bulb 5
#define button 6
#define led1 8
#define led2 9
#define led3 10
#define led4 11

int calibrationTime = 30;        

//the time when the sensor outputs a low impulse
long unsigned int lowIn;         

//the amount of milliseconds the sensor has to be low 
//before we assume all motion has stopped
long unsigned int pause = 5000;  

boolean lockLow = true;
boolean takeLowTime;  

int pirPin = 3;    //the digital pin connected to the PIR sensor's output

String voice;

IRrecv irrecv(tsop);
decode_results results;
 
int count=0;
void setup() {
  // put your setup code here, to run once:
pinMode(pirPin, INPUT);
  digitalWrite(pirPin, LOW);
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
   Serial.println(count);
 }
 }
 else
 {
   count=0;
 }
 Serial.println(count);
 delay(10);
if(count==0)
clap();

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

void clap()
{
 digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW); 
  
     if(digitalRead(pirPin) == HIGH){
       digitalWrite(bulb, HIGH);   //the led visualizes the sensors output pin state
       if(lockLow){  
         //makes sure we wait for a transition to LOW before any further output is made:
         lockLow = false;            
         Serial.println("---");
         Serial.print("motion detected at ");
         Serial.print(millis()/1000);
         Serial.println(" sec"); 
         delay(50);
         }         
         takeLowTime = true;
       }

     if(digitalRead(pirPin) == LOW){       
       digitalWrite(bulb, LOW);  //the led visualizes the sensors output pin state

       if(takeLowTime){
        lowIn = millis();          //save the time of the transition from high to LOW
        takeLowTime = false;       //make sure this is only done at the start of a LOW phase
        }
       //if the sensor is low for more than the given pause, 
       //we assume that no more motion is going to happen
       if(!lockLow && millis() - lowIn > pause){  
           //makes sure this block of code is only executed again after 
           //a new motion sequence has been detected
           lockLow = true;                        
           Serial.print("motion ended at ");      //output
           Serial.print((millis() - pause)/1000);
           Serial.println(" sec");
           delay(50);
           }
       }
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
   if(results.value==2737486129)
    digitalWrite(bulb,HIGH);
    
    delay(300);
   if(results.value==3768077238)
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


