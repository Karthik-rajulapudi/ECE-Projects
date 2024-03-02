//Arduino code to configure NodeMCU

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Servo.h>
#include "index.h";
#define LED 2
#define ServoPin 14   //D5 is GPIO14
//WiFi Connection configuration
const char *ssid = "WIFI123";
const char *password = "123456789";
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
ESP8266WebServer server(80);
void handleServo(){
  String POS = server.arg("servoPOS");
  int pos = POS.toInt();
  myservo.write(pos);   // tell servo to go to position
  delay(15);
  Serial.print("Servo Angle:");
  Serial.println(pos);
  digitalWrite(LED,!(digitalRead(LED))); //Toggle LED
  server.send(200, "text/plane","");
}
void handleRoot() {
 String s = MAIN_page; //Read HTML contents
 server.send(200, "text/html", s); //Send web page
}
//================================================//            Setup
//================================================
void setup() {
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  pinMode(LED,OUTPUT);
  myservo.attach(ServoPin); // attaches the servo on GIO2 to the servo object
  //Connect to wifi Network
  WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println("");
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("192.168.43.225");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
  //Initialize Webserver
  server.on("/",handleRoot);
  server.on("/setPOS",handleServo); //Sets servo position from Web request
  server.begin();
}
//================================================
//     LOOP
//================================================
void loop() {
 server.handleClient();
}
//================================================
