int AC_LOAD=3;
int dimming=128;

void setup() {
  pinMode(AC_LOAD,OUTPUT);
  attachInterrupt(0,zero_crosss_int,RISING);
  // put your setup code here, to run once:

}
void zero_crosss_int()
{
  int dimtime=(75*dimming);
  delayMicroseconds(dimtime);
  digitalWrite(AC_LOAD,HIGH);
  delayMicroseconds(10);
  digitalWrite(AC_LOAD,LOW);
}

void loop() {
  for(int i=5;i<=128;i++)
  {
  dimming=i;
  delay(30);
  }
    for(int i=128;i>=5;i--)
  {
  dimming=i;
  delay(30);
  }
  // put your main code here, to run repeatedly:

}
