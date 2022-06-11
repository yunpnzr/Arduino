#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <time.h>

const int led[]={4,6,8};
const int ldr=A1;
const int potensio=A2;
const int trig=12;
const int echo=13;
const int sensor=A0;
const int buzzer=3;
int i,celcius;
int cahaya;
long durasi,jarak;
int nilaiSensor,vout;
byte derajat=B11011111;

void setup() {
  for(i=0;i<=3;i++){
    pinMode(led[i], OUTPUT);
  }
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(sensor, INPUT);
  pinMode(buzzer, OUTPUT);
  lcd.begin(16,2);
  lcd.backlight();
  Serial.begin(9600); 
  cahaya=analogRead(ldr);
  Serial.println(cahaya);
}

void loop() {
  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
    delayMicroseconds(1);
  digitalWrite(trig, HIGH);
    delayMicroseconds(1);
  digitalWrite(trig, LOW);
  pinMode(echo, INPUT);
  durasi=pulseIn(echo, HIGH);
  jarak=(durasi/2)/29.1;

  if (jarak<=50){
    lcd.setCursor(3,0);
      lcd.print("ADA TAMU");
    lcd.setCursor(0,1);
      lcd.print("BUKA PINTUNYA!");
      
    digitalWrite(buzzer, HIGH);
    for(i=0;i<=3;i++){
      digitalWrite(led[i], HIGH);
    }
      delay(500);
    digitalWrite(buzzer, LOW);
    for(i=0;i<=3;i++){
      digitalWrite(led[i], LOW);
    }
      delay(100);
      
    digitalWrite(buzzer, HIGH);
    for(i=0;i<=3;i++){
      digitalWrite(led[i], HIGH);
    }
      delay(500);
    digitalWrite(buzzer, LOW);
    for(i=0;i<=3;i++){
      digitalWrite(led[i], LOW);
    }
      delay(100); 

    digitalWrite(buzzer, HIGH);
    for(i=0;i<=3;i++){
      digitalWrite(led[i], HIGH);
    }
      delay(500);
    digitalWrite(buzzer, LOW);
    for(i=0;i<=3;i++){
      digitalWrite(led[i], LOW);
    }
      delay(100);

    digitalWrite(buzzer, HIGH);
    for(i=0;i<=3;i++){
      digitalWrite(led[i], HIGH);
    }
      delay(500);
    digitalWrite(buzzer, LOW);
    for(i=0;i<=3;i++){
      digitalWrite(led[i], LOW);
    }
      delay(100);

    digitalWrite(buzzer, HIGH);
    for(i=0;i<=3;i++){
      digitalWrite(led[i], HIGH);
    }
      delay(500);
    digitalWrite(buzzer, LOW);
    for(i=0;i<=3;i++){
      digitalWrite(led[i], LOW);
    }
      delay(100);
  }
      
  if (jarak>=50){
    nilaiSensor=analogRead(sensor);
    vout=nilaiSensor/20.479;
    Serial.println(celcius);
  
    lcd.setCursor(0,0);
    lcd.print("Jarak");
    lcd.setCursor(8,0);
    lcd.print(jarak);
    lcd.setCursor(14,0);
    lcd.print("cm");
    lcd.setCursor(0,1);
    lcd.print("Suhu");
    lcd.setCursor(9,1);
    lcd.print(vout);
    lcd.setCursor(14,1);
    lcd.print((char)223);
    lcd.setCursor(15,1);
    lcd.print("C");
    delay(500);
    lcd.clear();
  }
}
