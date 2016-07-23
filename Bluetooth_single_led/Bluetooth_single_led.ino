int bulb=13;
void setup() {
Serial.begin(9600);
pinMode(bulb,OUTPUT);
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available()>0)
   {     
      int data= Serial.read(); // reading the data received from the bluetooth module
      switch(data)
      {
        case 'a': LEDON();break; // when a is pressed on the app on your smart phone
        case 'c': LEDOFF();break; // when b is pressed on the app on your smart phone
        default : break;
      }
   }
   delay(50);
}

void LEDON() // function when 'a' is pressed
{
  Serial.println("LED ON!");
  digitalWrite(bulb,HIGH); // onboard led on
}

void LEDOFF() // function when 'b' is presse
{
  Serial.println("LED OFF"); // onboard led off
  digitalWrite(bulb,LOW); 
}

