#include <LiquidCrystal.h>
#define alcs A0 
#define buzzer 10
float alc =0;
int red = 13;
int yellow = 12; 
int green = 11; 
const int rs = 9, en = 8, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(alcs,INPUT);
  pinMode(red,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(buzzer,OUTPUT);
  lcd.setCursor(0,0);
  lcd.print("Alcoholimetro");
  lcd.setCursor(4,1);
  lcd.print("Bienvendio");
  delay (1000);
  lcd.clear();
}
void loop() {
  alc=analogRead(alcs);
  alc=(alc/1023)*100;
  lcd.setCursor(0,1);
  lcd.print("Nivel:"); 
  lcd.setCursor(9,1);
  lcd.print(alc);
  lcd.print("%");
       
  if (alc>=45){
    digitalWrite(green,LOW);
    digitalWrite(red,HIGH);
    digitalWrite(yellow,LOW);
    digitalWrite(buzzer,HIGH);
    lcd.setCursor(0,0);
    lcd.print("Estado:");
    lcd.setCursor(7,0);
    lcd.print("Alto");
    delay(100);
    lcd.clear();
  }
  else if(alc>=21)
  {
    digitalWrite(green,LOW);
    digitalWrite(red,LOW);
    digitalWrite(yellow,HIGH);
    digitalWrite(buzzer,LOW);
    lcd.setCursor(0,0);
  lcd.print("Estado:");
  lcd.setCursor(8,0);
  lcd.print("Moderado");
  delay(100);
  lcd.clear();
  }
  else
  {
    lcd.setCursor(0,0);
    lcd.print("Estado:");
    lcd.setCursor(8,0);
    lcd.print("Normal");
    delay(100);
    lcd.clear();
    digitalWrite(green,HIGH);
    digitalWrite(red,LOW);
    digitalWrite(yellow,LOW);
    digitalWrite(buzzer,LOW);
    
  }
}
