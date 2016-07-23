int pir=2,led=3,i=0;
void setup() {
  Serial.begin(9600);
  pinMode(pir,INPUT);
  pinMode(led,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  int pirState=digitalRead(pir);
  if(pirState==1)
  {
    digitalWrite(led,HIGH);
    for(i=0;i<60;i++)
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
  digitalWrite(led,LOW);
  // put your main code here, to run repeatedly:

}
