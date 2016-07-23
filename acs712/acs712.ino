float sample=0.00;
int count=0;
void setup() {
 Serial.begin(9600);
pinMode(0,OUTPUT); 
digitalWrite(0,HIGH);
pinMode(1,OUTPUT);
}

void loop() {
delay(1000); 
  for(int i=0;i<150;i++)
{
sample += analogRead(A1); //read the current from sensor
delay(2);
}
sample=sample/150;  
float val =(5.0*sample)/1024.0;
float actualval =val-2.5; // offset voltage is 2.5v
float amps =actualval*10;
Serial.print("Avalue=");
Serial.print(sample);
Serial.print("\t");
Serial.print("Amps=");
Serial.println(amps);

if(sample<=516&&count>3)
{
digitalWrite(0,LOW);
digitalWrite(1,HIGH);
delay(800);
digitalWrite(1,LOW);
}
count++;
}
