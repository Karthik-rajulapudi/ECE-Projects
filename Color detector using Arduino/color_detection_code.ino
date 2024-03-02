#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2); //RS,EN,D4,D5,D6,D7
const int s0 = 8;
const int s1 = 9;
const int s2 = 10;
const int s3 = 11;
const int out = 12;
int r = 0;
int g = 0;
int b = 0;
 void setup()
{
 Serial.begin(9600);
 lcd.begin(16, 2);
 pinMode(s0, OUTPUT);
 pinMode(s1, OUTPUT);
 pinMode(s2, OUTPUT);
 pinMode(s3, OUTPUT);
 pinMode(out, INPUT);
 digitalWrite(s0, HIGH);
 digitalWrite(s1, HIGH);
}
 void loop()
{
 lcd.setCursor(0, 0);
 lcd.print(" Color Detected ");
 color();
 Serial.print("R :");
 Serial.print(r, DEC);
 Serial.print(" G : ");
 Serial.print(g, DEC);
 Serial.print(" B : ");
 Serial.print(b, DEC);
 if ((r<= 15)&&(g<=15)&&(b<=15))
 {
 Serial.println(" - (White Color)");
 lcd.setCursor(0, 1);
 lcd.print(" White Color ");
 delay(500);
 }
 else if ((r>=100)&&(g>=100)&&(b>=100))
 {
 Serial.println(" - (Black Color)");
 lcd.setCursor(0, 1);
 lcd.print(" Black Color ");
 delay(500);
 }
 else if ((r>=12 && r<= 18)&&(g>=16&&g<=22)&&(b>=25))
 {
 Serial.println(" - (Yellow Color)");
 lcd.setCursor(0, 1);
 lcd.print(" Yellow Color ");
 delay(500);
}
else if ((r>=12 && r<= 21)&&(g>=25)&&(b>=25))
 {
 Serial.println(" - (Orange Color)");
 lcd.setCursor(0, 1);
 lcd.print(" Orange Color ");
 delay(500);
 }

 else if (b < r && b < g)
 {
 Serial.println(" - (Blue Color)");
 lcd.setCursor(0, 1);
 lcd.print(" Blue Color ") ;
 delay(500);
 }
 else if (g < r && g < b)
 {
 Serial.println(" - (Green Color)");
 lcd.setCursor(0, 1);
 lcd.print(" Green Color ");
 delay(500);
 }
 else if (r < b && r < g)
 {
 Serial.println(" - (Red Color)");
 lcd.setCursor(0, 1);
 lcd.print(" RED Color ");
 delay(500);
 }
 else{
 Serial.println();
 lcd.setCursor(0, 1);
 lcd.print(" Can't Identify");
 delay (500);
 }
}
 void color()
{
 digitalWrite(s2, LOW);
 digitalWrite(s3, LOW);
 r = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
 digitalWrite(s3, HIGH);
 b = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
 digitalWrite(s2, HIGH);
 g= pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
}
