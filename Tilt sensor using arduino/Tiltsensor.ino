//Tilt sensor using Arduino

void setup()
{
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
 pinMode(4,INPUT);
}
void loop()
{
if(digitalRead(4)==1)
{
digitalWrite(2,HIGH);
 digitalWrite(3,HIGH);
delay(300);

digitalWrite(2,LOW);
digitalWrite(3,LOW);
delay(300);
}
}
