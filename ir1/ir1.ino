#include <IRremote.h>

int RECV_PIN = 4;
int ledpin = 5;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(ledpin,OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    delay(30);
   if(results.value==2737486129)
    digitalWrite(ledpin,HIGH);
    
    delay(300);
   if(results.value==3768077238)
    digitalWrite(ledpin,LOW);
    irrecv.resume(); // Receive the next value
  }
}
