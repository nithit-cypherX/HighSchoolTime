 int num =0;
 int buzzerPin = 6;
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600);
   pinMode(buzzerPin, OUTPUT);
   Serial.print("PLS ENT SUM NUM");
}

void loop() {
    if(Serial.available()>0){
     num =Serial.read()-48;
     Serial.println(num);  
    lcd.setCursor(8,0);
    lcd.print(num);
    tone(buzzerPin,(num+1)*800,500);
    
    }
}
