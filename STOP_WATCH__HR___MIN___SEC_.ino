#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int count=0,count_1=0,count_2=0;

void Dec2ascii(unsigned char value)
{
  unsigned char x=0;
  
  x=value/10;
  lcd.print(x);
  delay(10);
  
  x=value%10;
  lcd.print(x);
  delay(10);
}

void setup() 
{
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("SRI ELECTRONIC & EMBEDDED SOLUTIONS");
  delay(100);
}

void loop() 
{
  lcd.setCursor(0,1);
  lcd.print("SP WATCH:");
  lcd.setCursor(9,1);
  Dec2ascii(count);
  lcd.setCursor(10,1);
  lcd.print(':');
  lcd.setCursor(11,1);
  Dec2ascii(count_1);
  lcd.setCursor(13,1);
  lcd.print(':'); 
  lcd.setCursor(14,1); 
  Dec2ascii(count_2);
  
  count_2++;
  
  if(count_2>59)
  {
    count_1++;
    delay(10);
    count_2=0;
  }  
  
  if(count_1>59)
  {
    count++;
    delay(10);
    count_1=0;
  }
  delay(1000); 
}
