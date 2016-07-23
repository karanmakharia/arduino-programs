#define pot A0 //pin A0 is also pin 14
int led = 9;

int val=0,val1=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

val=analogRead(pot);
Serial.println(val);
val1=map(val,0,1023,0,255);

analogWrite(led,val1);
delay(100);
}
