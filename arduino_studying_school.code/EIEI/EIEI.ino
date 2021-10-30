
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#include "Wire.h"
#define DS1307_I2C_ADDRESS 0x68 // the I2C address of Tiny RTC
byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
// Convert normal decimal numbers to binary coded decimal
byte decToBcd(byte val)
{
return ( (val/10*16) + (val%10) );
}
// Convert binary coded decimal to normal decimal numbers
byte bcdToDec(byte val)
{
return ( (val/16*10) + (val%16) );
}
// Function to set the currnt time, change the second&minute&hour to the right time
void setDateDs1307()
{
second =00;
minute = 39;
hour = 14;
dayOfWeek = 3;
dayOfMonth =29;
month =1;
year= 20;
Wire.beginTransmission(DS1307_I2C_ADDRESS);
Wire.write(decToBcd(0));
Wire.write(decToBcd(second)); // 0 to bit 7 starts the clock
Wire.write(decToBcd(minute));
Wire.write(decToBcd(hour)); // If you want 12 hour am/pm you need to set
// bit 6 (also need to change readDateDs1307)
Wire.write(decToBcd(dayOfWeek));
Wire.write(decToBcd(dayOfMonth));
Wire.write(decToBcd(month));
Wire.write(decToBcd(year));
Wire.endTransmission();
}
// Function to gets the date and time from the ds1307 and prints result
void getDateDs1307()
{
// Reset the register pointer
Wire.beginTransmission(DS1307_I2C_ADDRESS);
Wire.write(decToBcd(0));
Wire.endTransmission();
Wire.requestFrom(DS1307_I2C_ADDRESS, 7);
second = bcdToDec(Wire.read() & 0x7f);
minute = bcdToDec(Wire.read());
hour = bcdToDec(Wire.read() & 0x3f); // Need to change this if 12 hour am/pm
dayOfWeek = bcdToDec(Wire.read());
dayOfMonth = bcdToDec(Wire.read());
month = bcdToDec(Wire.read());
year = bcdToDec(Wire.read());
Serial.print(hour, DEC);
Serial.print(":");
Serial.print(minute, DEC);
Serial.print(":");
Serial.print(second, DEC);
Serial.print(" ");
Serial.print(month, DEC);
Serial.print("/");
Serial.print(dayOfMonth, DEC);
Serial.print("/");
Serial.print(year,DEC);
Serial.print(" ");
Serial.println();
//Serial.print("Day of week:");
}
void setup() {
Wire.begin();
Serial.begin(19200);
//setDateDs1307(); //Set current time;
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  
}
void loop()
{
delay(2000);
getDateDs1307();//get the time data from tiny RTC
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print("TIME ");
  if(hour < 10)
  lcd.print("0");
lcd.print(hour, DEC);
lcd.print(":");
if(minute < 10)
  lcd.print("0");
lcd.print(minute, DEC);
lcd.print(":");
if(second < 10)
  lcd.print("0");
lcd.print(second, DEC);
lcd.print(" ");
lcd.setCursor(0,0);
lcd.print("DATE ");
if(month < 10)
  lcd.print("0");
lcd.print(month, DEC);
lcd.print("/");
if(dayOfMonth < 10)
  lcd.print("0");
lcd.print(dayOfMonth, DEC);
lcd.print("/");
if(year < 10)
  lcd.print("0");
lcd.print(year,DEC);
lcd.print(" ");

//Serial.print("Day of week:");

}
