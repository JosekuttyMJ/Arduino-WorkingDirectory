/*
 * TimeRTC.pde
 * example code illustrating Time library with Real Time Clock.
 * 
 */

#include <Time.h>  
#include <Wire.h>  
#include <DS1307RTC.h>  // a basic DS1307 library that returns time as a time_t
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup()  {
   lcd.begin(16,2);
   
  Serial.begin(9600);
  while (!Serial) ; // wait until Arduino Serial Monitor opens
  setSyncProvider(RTC.get);   // the function to get the time from the RTC
  if(timeStatus()!= timeSet) 
     Serial.println("Unable to sync with the RTC");
  else
     Serial.println("RTC has set the system time"); 
lcd.print("RTC has set time")  ;
delay(1000);
lcd.clear();
 lcd.print("Cheking the time...")  ;
 delay(1000);
}

void loop()
{
  if (timeStatus() == timeSet) {
    digitalClockDisplay();
  } else {
    Serial.println("The time has not been set.  Please run the Time");
    Serial.println("TimeRTCSet example, or DS1307RTC SetTime example.");
    Serial.println();
    delay(4000);
  }
  delay(1000);
}

void digitalClockDisplay(){
  // digital clock display of the time
 
  Serial.print(hour());
  lcd.clear();
   lcd.print("TIME:")  ;
 lcd.print(hour())  ;
  printDigits(minute());
  lcd.print(":")  ;
 lcd.print(minute())  ;
  printDigits(second());
  lcd.print(":")  ;
  lcd.print(second());
  lcd.setCursor(0, 1);
   lcd.print("Date:")  ;
  Serial.print(":");
  lcd.print(day());
  lcd.print(":");
  lcd.print(month());
  lcd.print(":");
  lcd.print(year()); 
 
}

void printDigits(int digits){
  // utility function for digital clock display: prints preceding colon and leading 0
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
}

