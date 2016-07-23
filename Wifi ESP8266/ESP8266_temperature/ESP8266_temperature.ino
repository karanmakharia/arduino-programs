/*
Source- http://electronut.in/an-iot-project-with-esp8266/
http://www.instructables.com/id/Getting-Started-with-the-ESP8266-ESP-12/?ALLSTEPS

Connections
Arduino <--> ESP8266
3.3V    <--> VCC,CH_PD,GPIO2   GPIO pins connections are optional.
GND     <--> GND,GPIO15
RX      <--> TX
TX      <--> RX

Temperature sensor at D2
Adapter connected to arduino

If providing 3.3V from external source make sure GND of external source is connected to arduino GND

Change the API key according to thingspeak channel
*/
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

String apiKey="8XUTI5YC4PRHHGXZ"; //API KEY from thingspeak
void setup(){
Serial.begin(115200);
dht.begin();
Serial.println("AT+RST");//Resetting esp8266
}

void loop(){
   
delay(5000);
  int t = dht.readTemperature();
  int f= dht.readTemperature(true);
  int h=dht.readHumidity();
//char buf[16];
//String strTemp=dtostrf(t,4,1,buf);  //FOR FLOAT value
String getStr="GET /update?api_key=";
getStr+=String(apiKey);  
getStr+="&field1="; //temperature in Celsius
getStr+=String(t);
getStr+="&field2="; //temperature in Fahrenheit
getStr+=String(f);
getStr+="&field3="; //Humidity
getStr+=String(h);
getStr+=String("\r\n\r\n"); //carriage return and new line. Takes up 4 spaces in the string.

String cmd="AT+CIPSEND=";
cmd+=String(getStr.length()); //get the length of the string to be sent

Serial.println("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80"); //make connection with server
delay(4000);
Serial.println(cmd); // Send EXACT string length
delay(4000);
Serial.println(getStr); //Send String
delay(1000);
Serial.println(""); //Enter after string is sent. Process complete
delay(60000); // Refresh after every 60 seconds
}
