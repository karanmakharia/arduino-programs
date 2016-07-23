#include <IRremote.h>
int RECV_PIN = 7;
int light=8;
int fan=9;
int plug=10;
IRrecv irrecv(RECV_PIN);
decode_results results;
int c1=0,c2=0,c3=0,c4=0;
//-----------------------------

//Light
#define trigPin1 3
#define echoPin1 2
#define trigPin2 5
#define echoPin2 4
long duration1=0,distance1=0;
long duration2=0,distance2=0;
int count1=0;
//-----------------------------

void setup()
{
  Serial.begin(9600);
  //IR
  irrecv.enableIRIn(); // Start the receiver
  pinMode(light,OUTPUT);
  pinMode(fan,OUTPUT);
  pinMode(plug,OUTPUT);
  //------------------------
  //LIGHT
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  
}

//LIGHT FUNCTIONS
int sensor1()
{
digitalWrite(trigPin1, LOW);
delayMicroseconds(100);
digitalWrite(trigPin1, HIGH);
delayMicroseconds(100);
digitalWrite(trigPin1, LOW);
duration1=pulseIn(echoPin1,HIGH);
distance1=(duration1/2)/29.1;

/*if(distance1<60)
digitalWrite(led1, HIGH);
else
digitalWrite(led1, LOW);*/
return(distance1);
}

int sensor2()
{
digitalWrite(trigPin1, LOW);
delayMicroseconds(100);
digitalWrite(trigPin2, HIGH);
delayMicroseconds(100);
digitalWrite(trigPin2, LOW);
duration2=pulseIn(echoPin2,HIGH);
distance2=(duration2/2)/29.1;

/*if(distance2<100)
digitalWrite(led2, HIGH);
else
digitalWrite(led2, LOW);*/
return(distance2);
}

//-------------------------------------

void loop() {

  //IR
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    delay(30);
       if(results.value==2737486129)
       {
         if(c1==0)
         {digitalWrite(9,HIGH);
         digitalWrite(9,HIGH);
         digitalWrite(10,HIGH);
          c1=1;
         }
          else
         {digitalWrite(8,LOW);
         digitalWrite(9,LOW);
         digitalWrite(10,LOW);
         c1=0;
         }
       }
       if(results.value==338831067)
       {
         if(c2==0)
         {
         digitalWrite(8,HIGH);
         c2=1;
       }
         else
         {
         digitalWrite(8,LOW);
         c2=0;
       }
     }
     if(results.value==924466310)
       {
         if(c3==0)
         {digitalWrite(9,HIGH);
          c3=1;
         }
          else
         {digitalWrite(9,LOW);
         c3=0;
         }
       }
       if(results.value==970202566)
       {
         if(c4==0)
         {digitalWrite(10,HIGH);
          c4=1;
         }
          else
         {digitalWrite(10,LOW);
         c4=0;
         }
       }
       delay(200);
    irrecv.resume(); // Receive the next value
  }
  //--------------------------------------------
  
  //LIGHT loop
  sensor1();
sensor2();
if((distance1<60) && (distance2>100))
{
 do
 {
   delay(50);
   sensor1();
   sensor2();
    if((distance1>60) && (distance2>100))
    break;
 }
 while(!(distance2<100)); // True or false logic, T&F=T; F&T=T

 if(distance2<100)
 {
   do
   {
     delay(50);
     sensor1();
     sensor2();
   
   }
   while(!(distance1>60 && distance2>100));
   if(distance1>60 && distance2>100)
   {
     count1++;
     Serial.println(count1);
   }
 }
}



//------OUT-------
if((distance1>60) && (distance2<100))
{
 do
 {
   delay(10);
   sensor1();
    //if((distance1>60) && (distance2>100))
    //break;
 }
 while(!(distance1<60)); // True or false logic, T&F=T; F&T=T

 if(distance1<60)
 {
   do
   {
     delay(50);
     sensor1();
     sensor2();
     //if((distance1>60) && (distance2<100))
     //break;
   }
    while(!((distance1>60) && (distance2>100)));
    
    if(distance1>60 && distance2>100)
   {
     count1--;
     if(count1<0)
     count1=0;
     
     Serial.println(count1);
   }
 }
}
if(count1>=1)
digitalWrite(8,HIGH);
else
digitalWrite(8,LOW);

delay(10);
//------------------------------------------

}

