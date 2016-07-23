#include <SoftwareSerial.h>
#include <TinyGPS.h>


TinyGPS gps;
SoftwareSerial ss(4, 3);  //TX=4pin, RX=3pin

static void smartdelay(unsigned long ms);
//static void print_float(float val, float invalid, int len, int prec);


void setup() {
  Serial.begin(115200);
  Serial.println("Latitude Longitude");
  ss.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  float flat, flon;
  gps.f_get_position(&flat, &flon);
  //print_float(flat, TinyGPS::GPS_INVALID_F_ANGLE, 10, 6);
  Serial.print(flat, 6);
  Serial.print("\t");
  Serial.print(flon, 6);
  //print_float(flon, TinyGPS::GPS_INVALID_F_ANGLE, 11, 6);
  Serial.println();
  smartdelay(1000);
  // put your main code here, to run repeatedly:
}

static void print_float(float val, float invalid, int len, int prec)
{
  if (val == invalid)
  {
    while (len-- > 1)
      Serial.print('*');
    Serial.print(' ');
  }
  else
  {
    Serial.print(val, prec);
    int vi = abs((int)val);
    int flen = prec + (val < 0.0 ? 2 : 1); // . and -
    flen += vi >= 1000 ? 4 : vi >= 100 ? 3 : vi >= 10 ? 2 : 1;
    for (int i=flen; i<len; ++i)
      Serial.print(' ');
  }
  smartdelay(0);
}

static void smartdelay(unsigned long ms)
{
  unsigned long start = millis();
  do 
  {
    while (ss.available())
      gps.encode(ss.read());
  } while (millis() - start < ms);
}


