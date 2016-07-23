char phone_no[]="9324479670";

void setup() {
Serial.begin(9600);
delay(2000);
Serial.println("AT");
delay(1000);
Serial.print("ATD");
Serial.print(phone_no);
Serial.println(";");
delay(20000);
Serial.println("ATH");

  // put your setup code here, to run once:

}

void loop() {
  if(Serial.available()>0)
  {
  Serial.write(Serial.read());
  }
  // put your main code here, to run repeatedly:

}
