#define trigPin1 10
#define echoPin1 9
#define trigPin2 3
#define echoPin2 2

#define led1 11
#define led2 7
void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
//pinMode (led1, OUTPUT);
//pinMode(led2, OUTPUT);
}

void sensor1()
{
long duration1,distance1;
digitalWrite(trigPin1, HIGH);
delayMicroseconds(1000);
digitalWrite(trigPin1, LOW);
duration1=pulseIn(echoPin1,HIGH);
distance1=(duration1/2)/29.1;

if(distance1<11)
digitalWrite(led1, HIGH);
else
digitalWrite(led1, LOW);

Serial.print(distance1);
Serial.print("CM");
Serial.print("\t");
}

void sensor2()
{
long duration2,distance2;
digitalWrite(trigPin2, HIGH);
delayMicroseconds(1000);
digitalWrite(trigPin2, LOW);
duration2=pulseIn(echoPin2,HIGH);
distance2=(duration2/2)/29.1;

if(distance2<11)
digitalWrite(led2, HIGH);
else
digitalWrite(led2, LOW);

Serial.print(distance2);
Serial.println("CM");

}
void loop() {
sensor1();
sensor2();
delay(100);
  // put your main code here, to run repeatedly:

}
