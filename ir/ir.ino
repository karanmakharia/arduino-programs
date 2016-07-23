#include <IRremote.h>

int RECV_PIN = 11;
int ledpin = 13;
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
    Serial.print("Protocol: ");
    Serial.println(results.decode_type, DEC);
    Serial.println(results.value,DEC);
    delay(1000);
    if(results.value==849793071
)
    digitalWrite(ledpin,HIGH);
    else
    digitalWrite(ledpin,LOW);
    irrecv.resume(); // Receive the next value
  }
}
