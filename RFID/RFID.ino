/*
 * ----------------------------------------------------------------------------
 * This sketch uses the MFRC522 library ; see https://github.com/miguelbalboa/rfid
 * for further details and other examples.
 * 
 * NOTE: The library file MFRC522.h has a lot of useful info. Please read it.
 * 
 * This sketch show a simple locking mechanism using the RC522 RFID module.
 * ----------------------------------------------------------------------------
 * Typical pin layout used:
 * -----------------------------------------------------------------------------------------
 *             MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
 *             Reader/PCD   Uno           Mega      Nano v3    Leonardo/Micro   Pro Micro
 * Signal      Pin          Pin           Pin       Pin        Pin              Pin
 * -----------------------------------------------------------------------------------------
 * RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
 * SPI SS      SDA(SS)      10            53        D10        10               10
 * SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
 * SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
 * SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
 *
 */
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9           // Configurable, see typical pin layout above
#define SS_PIN          10          // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

String read_rfid;
String ok_rfid_1="54a3c9be";
//String ok_rfid_2="ffffffff"; //add as many as you need.
int lock=7; //Which pin the lock will be on if using a relay or solenoid or similar 

//Use the lines below if you plan on using a servo as a locking mechanism.
/*#include <Servo.h> 
Servo myservo;  // create servo object to control a servo 
int posClosed = 0;    // variable to store the servo position for locked
int posOpen = 360;    //same for open...
 */

/*
 * Initialize.
 */
void setup() {
    Serial.begin(9600);         // Initialize serial communications with the PC
    while (!Serial);            // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
    SPI.begin();                // Init SPI bus
    mfrc522.PCD_Init();         // Init MFRC522 card

    //Choose which lock below:
    pinMode(lock, OUTPUT);
  pinMode(8,OUTPUT);
   // myservo.attach(2);  // attaches the servo on pin 2 to the servo object 
}

/*
 * Helper routine to dump a byte array as hex values to Serial.
 */
void dump_byte_array(byte *buffer, byte bufferSize) {
    read_rfid="";
    for (byte i = 0; i < bufferSize; i++) {
        read_rfid=read_rfid + String(buffer[i], HEX);
    }
}

void open_lock() {
  //Use this routine when working with Relays and Solenoids etc.
  digitalWrite(lock, HIGH);
  delay(2000);
  digitalWrite(lock,LOW);
  
  //Use this routine when working with Servos.
  /*myservo.write(360); 
  delay(2000);
  myservo.write(0);*/
}
void close_lock(){
  digitalWrite(8, HIGH);
  delay(2000);
  digitalWrite(8,LOW);


}
void loop() {

      // Look for new cards
    if ( ! mfrc522.PICC_IsNewCardPresent())
        return;

    // Select one of the cards
    if ( ! mfrc522.PICC_ReadCardSerial())
        return;

    dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
    Serial.println(read_rfid);
    if (read_rfid==ok_rfid_1) {
      //ok, open the door.
      open_lock();
    }
    else
    {
    close_lock();
    }
    //Add below as many "keys" as you want
    //if (read_rfid==ok_rfid_2) {
      //also ok, open the door
    //  open_lock();
    //}
    // else not needed. Anything else is not ok, and will not open the door...
}

