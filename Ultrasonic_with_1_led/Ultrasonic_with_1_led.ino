
int echo=2, trig=3;
int distance(int echo, int trig);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
}

void loop() {
  int d;
  d=ultrasonic(echo,trig);
Serial.println(d);
}

int ultrasonic(int echo, int trig)
{
  long duration, distance;
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration / 2) / 29.1;
    return distance;
}

