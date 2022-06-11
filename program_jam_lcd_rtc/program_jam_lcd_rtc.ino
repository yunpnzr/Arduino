#include "RTClib.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
RTC_DS3231 rtc;
const int pushbutton1=10;
const int pushbutton2=11;
const int led1=7;
const int led2=8;
int tgl,bln,thn,jam,menit,detik,suhu,tombol1,tombol2;

void setup(){
  Serial.begin(9600);
  pinMode(pushbutton1, INPUT);
  pinMode(pushbutton2, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  lcd.begin(16,2);
  lcd.backlight();
  if(! rtc.begin()){
    Serial.println("RTC Tidak Ditemukan");
    Serial.flush();
    abort();
  }
  rtc.adjust(DateTime(F(__DATE__),F(__TIME__)));
}

void loop(){
  
  DateTime now = rtc.now();
  tgl=now.day(), DEC;
  bln=now.month(), DEC;
  thn=now.year(), DEC;
  jam=now.hour(), DEC;
  menit=now.minute(), DEC;
  detik=now.second(), DEC;
  suhu=rtc.getTemperature();

  tombol1=digitalRead(pushbutton1);
  tombol2=digitalRead(pushbutton2);

  if (tombol1 == 1){
    digitalWrite(led1, HIGH);
    lcd.clear();
    lcd.setCursor(1,0);
      lcd.print("Hari ini:"); 
  }
   
  lcd.clear();
  if (tgl<10){
    lcd.setCursor(0,0);
      lcd.print("0");
    lcd.setCursor(1,0);
      lcd.print(tgl);
  }else{
    lcd.setCursor(0,0);
      lcd.print(tgl);
  }
  lcd.setCursor(2,0);
    lcd.print("/");
  lcd.setCursor(3,0);
    lcd.print(bln);
  lcd.setCursor(5,0);
    lcd.print("/");
  lcd.setCursor(6,0);
    lcd.print(thn);
    if (jam<10){
      lcd.setCursor(0,1);
        lcd.print("0");
      lcd.setCursor(1,1);
        lcd.print(jam);
    } else{
      lcd.setCursor(0,1);
        lcd.print(jam);
    }
  lcd.setCursor(2,1);
    lcd.print(".");
    if (menit<10){
      lcd.setCursor(3,1);
        lcd.print("0");
      lcd.setCursor(4,1);
        lcd.print(menit);
    } else{
      lcd.setCursor(3,1);
        lcd.print(menit);
    }
  lcd.setCursor(5,1);
    lcd.print(".");
    if (detik<10){
      lcd.setCursor(6,1);
        lcd.print("0");
      lcd.setCursor(7,1);
        lcd.print(detik);
    } else{
      lcd.setCursor(6,1);
        lcd.print(detik);
    }
  lcd.setCursor(11,1);
    lcd.print(suhu);
  lcd.setCursor(13,1);
    lcd.print(char(223));
  lcd.setCursor(14,1);
    lcd.print("C");
  delay(1000);
}
