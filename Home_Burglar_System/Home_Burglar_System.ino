#define trigPin 11
#define echoPin 10

char phone_no[]="8793849065";

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

}

void loop() {
  long duration,distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance=(duration/2)/29.1;
  if(distance<50)
  {
    Serial.println(distance);
    Serial.println("AT");
    delay(1000);
    Serial.print("ATD");
    Serial.print(phone_no);
    Serial.println(";");
    delay(10000);
    Serial.println("ATH");
  }
  Serial.print(distance);
  Serial.print("CM");
  delay(100);
  // put your main code here, to run repeatedly:

}
