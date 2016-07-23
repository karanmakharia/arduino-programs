//0-echo, 1 -trig , 2-echo, 3 trig... so on,,,
//even = echo, odd=trig

int i=0,j=0;
int echo,trig;
int distance(int echo,int trig);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
for(i=2;i<14;i++)
{
  pinMode(i,INPUT);
  i++;
}
for(j=1;j<12;j++)
{
  pinMode(j,OUTPUT);
  j++;
}

}

void loop() {
  int d1;
  for(int t=2;t<14;t++)
  {
  echo=t;trig=t+1;
  d1=ultrasonic(echo,trig);
  Serial.print(d1);
  Serial.print("  ");
  t++;
  }
  Serial.println();
}
int ultrasonic(int echo, int trig)
{
long duration,distance;
  digitalWrite(trig, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig, LOW);
  duration=pulseIn(echo, HIGH);
  distance=(duration/2)/29.1;
  delay(100);
  return distance;
 
}
