/* Connections 
Vcc - Arduino 5v
Gnd - Arduino gnd
Tx - Arduino Rx (Digital pin 0) 
Rx - Arduino Tx (Digital pin 1)
*/

//REMOVE RX TX connections while uploading the program to arduino, in case you get any error
//The function of button B and C in bluebot app is interchanged. So if you press B it sends the ascii value of C and viceversa.
void setup() {
  Serial.begin(9600);
  Serial.println("Connection Successful !");
  pinMode(13,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  if(Serial.available()>0)
   {
      int data= Serial.read();
      switch(data)
      {  
        //Toggle buttons A-H;
        case 'a': digitalWrite(13,HIGH);break;
        case 'b': ledoff();break; // call a function if you have multiple lines of code
        case 'c': break;
        case 'd': break;
      
        // Arrow and centre button code.  Insert code before break.
        case 'U': break;
        case 'D': break;
        case 'L': break;
        case 'R': break;
        case 'C': break;
        default : break;
      }
    }
    delay(50);
}

void ledoff()
{
digitalWrite(13,LOW);
}
