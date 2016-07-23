int timesTosend=1;
int count=0;
char phone_no[]="9324479670";  //phone number
void setup()
{
Serial.begin(9600);  //Open Serial connection at baud 9600
delay(2000);
Serial.println("AT+CMGF=1"); //set GSM to text mode
delay(200);
}
void loop()
{
while(count<timesTosend){
delay(1500);
Serial.print("AT+CMGS=\"");
Serial.print(phone_no);
Serial.println("\"");
while (Serial.read()!='>');
{
Serial.print("Test Message from Arduino GSM...HELLO..!!!");  //SMS body
delay(500);
Serial.write(0x1A);  // sends ctrl+z end of message
    Serial.write(0x0D);  // Carriage Return in Hex
Serial.write(0x0A);  // Line feed in Hex
//The 0D0A pair of characters is the signal for the end of a line and beginning of another.
delay(5000);
}
count++;
}
}
