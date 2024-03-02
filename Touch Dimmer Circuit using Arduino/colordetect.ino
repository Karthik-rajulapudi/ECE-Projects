//Arduino code for color detection
int led = 3;
int sen=8;
int val=0;
void setup() {
    pinMode(sen,INPUT);
    pinMode(led,OUTPUT);
    digitalWrite(sen,LOW);
    digitalWrite(led,LOW);
}

void loop() {
while(digitalRead(sen)==LOW);
while(digitalRead(sen)==HIGH)
{
while(digitalRead(sen)==HIGH)
{
if(val<=255)
{
analogWrite(led,val); val++;
delay(15);
}
}
delay(1000);
while(digitalRead(sen)==HIGH)
{
if(val>=0)
{
analogWrite(led,val); val--; delay(15);
}
}
}
}

