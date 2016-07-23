#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
  lcd.begin(16,2);
  pinMode(9,OUTPUT);
  pinMode(10,INPUT);
  pinMode(8,INPUT);// put your setup code here, to run once:
  
}
float c=0.5;
float temp;
int bs=0;
void loop() {
  bs=digitalRead(8);
  if(bs==HIGH)
  {
    delay(300);
  c=c+0.5;
  }
  if(c==0.5)
  {
  lcd.setCursor(0,0);
  lcd.print("Set Timer 30 min");
  lcd.setCursor(0,1);
  lcd.print("RE  -30  +30  GO");
  }
  
  if(c>0.5)
  {
    temp=c-((int)(c));
     if(temp==0.5)
    {
      
      lcd.setCursor(0,0);
      lcd.print("Set Timer ");
      lcd.print((int)(c));
      lcd.print(".5");
      lcd.print("Hrs  ");
      lcd.setCursor(0,1);
      lcd.print("RE  -30  +30  GO");
    }
    else
    {
      Serial.print("working");
     lcd.setCursor(0,0);
     lcd.print("Set Timer ");
     lcd.print((int)(c));
     if(c==1)
     lcd.print(" Hr  ");
     else
     lcd.print(" Hrs  ");
     lcd.setCursor(0,1);
     lcd.print("RE  -30  +30  GO");
    }
    lcd.setCursor(10,0);
  }
  // put your main code here, to run repeatedly:

}
