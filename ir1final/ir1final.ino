#include <IRremote.h>

int light=8;
int fan=9;
int plug=10;
//int whatever=;

int RECV_PIN = 6;
IRrecv irrecv(RECV_PIN);
decode_results results;
int c1=0,c2=0,c3=0,c4=0;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(light,OUTPUT);
  pinMode(fan,OUTPUT);
  pinMode(plug,OUTPUT);
  //pinMode(5,OUTPUT);
} 
 
  void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    delay(30);
       if(results.value==2737486129)
       {
         if(c1==0)
         {digitalWrite(light,HIGH);
         digitalWrite(fan,HIGH);
         digitalWrite(plug,HIGH);
          c1=1;
         }
          else
         {digitalWrite(light,LOW);
         digitalWrite(fan,LOW);
         digitalWrite(plug,LOW);
         c1=0;
         }
       }
       if(results.value==338831067)
       {
         if(c2==0)
         {
         digitalWrite(light,HIGH);
         c2=1;
       }
         else
         {
         digitalWrite(light,LOW);
         c2=0;
       }
     }
     if(results.value==924466310)
       {
         if(c3==0)
         {digitalWrite(fan,HIGH);
          c3=1;
         }
          else
         {digitalWrite(fan,LOW);
         c3=0;
         }
       }
       if(results.value==970202566)
       {
         if(c4==0)
         {digitalWrite(plug,HIGH);
          c4=1;
         }
          else
         {digitalWrite(plug,LOW);
         c4=0;
         }
       }
       delay(200);
    irrecv.resume(); // Receive the next value
  }
}

