#include <WiFi.h>
#include <WebServer.h>

#define ssid "LampWifi"
#define password "12345678"

#define blueLedPin 5
#define LedPin1 22
#define LedPin2 18
#define LampPin 23

IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);
WebServer server(80);

bool LEDStatus = LOW;
bool LED1Status = LOW;
bool LED2Status = LOW;
bool LampStatus = LOW;

void setup()
{
    Serial.begin(115200);
    pinMode(blueLedPin,OUTPUT);
    pinMode(LedPin1,OUTPUT);
    pinMode(LedPin2,OUTPUT);
    pinMode(LampPin,OUTPUT);

    WiFi.softAP(ssid,password);
    WiFi.softAPConfig(local_ip,gateway,subnet);
    delay(1000);

    server.on("/",handle_OnConnect);
    server.on("/yellow",handle_YellowON);
    server.on("/magneta",handle_LED1ON);
    server.on("/white",handle_LED2ON);
    server.on("/lamp",handle_LAMPON);
    server.on("/off",handle_ledoff);
    server.onNotFound(handle_NotFound);
    server.begin();
    Serial.println("HTTP SERVER STARTED");
}
String getHTML()
{
String htmlcode = "<!DOCTYPE html> <html>\n";
htmlcode +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
htmlcode += "<title>LED Control</title>\n";
htmlcode += "</head>\n";
htmlcode +="<body>\n";
htmlcode +="<h1>Muhammad Faizan Asim Web Server</h1>\n";
htmlcode +="<h3>Page to Control Your Lamp</h3>\n";
if (LEDStatus) {
htmlcode += "<p>LED Status: ON</p><a href=\"/off\">Turn it OFF All</a>\n";
}
else{
htmlcode +="<p>LED Status: OFF</p><a href=\"/yellow\">Turn it yellow</a>\n";
}
if (LED1Status) {
htmlcode += "<p>LED Status: ON</p><a href=\"/off\">Turn OFF All</a>\n";
}
else{
htmlcode +="<p>LED Status: OFF</p><a href=\"/magneta\">Turn it Magneta</a>\n";
}
if (LED2Status) {
htmlcode += "<p>LED Status: ON</p><a href=\"/off\">Turn OFF All</a>\n";
}
else{
htmlcode +="<p>LED Status: OFF</p><a href=\"/white\">Turn it White</a>\n";
}
if (LampStatus) {
htmlcode += "<p>LED Status: ON</p><a href=\"/off\">Turn OFF All</a>\n";
}
else{
htmlcode +="<p>LED Status: OFF</p><a href=\"/lamp\">Turn On Lamp</a>\n";
}
htmlcode += "</body>\n";
htmlcode += "</html>\n";
return htmlcode;
}
void handle_OnConnect()
{
  LEDStatus = LOW;
LED1Status = LOW;
LED2Status = LOW;
LampStatus = LOW;

  Serial.println("LED STATUS: OFF");
  server.send(200,"text/html",getHTML());
}
void handle_YellowON()
{
LEDStatus = HIGH;
LED1Status = LOW;
LED2Status = LOW;
LampStatus = LOW;
  Serial.println("LED STATUS: ON");
  server.send(200,"text/html",getHTML());
}
void handle_LED1ON()
{
  LEDStatus = LOW;
LED1Status = HIGH;
LED2Status = LOW;
LampStatus = LOW;
  Serial.println("LED STATUS: ON");
  server.send(200,"text/html",getHTML());
}
void handle_LED2ON()
{
  LEDStatus = LOW;
LED2Status = HIGH;
LED1Status = LOW;
LampStatus = LOW;
  Serial.println("LED STATUS: ON");
  server.send(200,"text/html",getHTML());
}
void handle_LAMPON()
{
  LEDStatus = LOW;
LED1Status = LOW;
LED2Status = LOW;
LampStatus = HIGH;
  Serial.println("LED STATUS: ON");
  server.send(200,"text/html",getHTML());
}
void handle_ledoff()
{
    LEDStatus = LOW;
LED1Status = LOW;
LED2Status = LOW;
LampStatus = LOW;
  Serial.println("LED STATUS: OFF");
  server.send(200,"text/html",getHTML());
}
void loop()
{
    server.handleClient();
    if(LEDStatus)
    {
      digitalWrite(blueLedPin,HIGH);
      
    }
    else
    {
      digitalWrite(blueLedPin,LOW);
      
    }
    if(LED1Status)
    {
      digitalWrite(LedPin1,HIGH);
      
    }
    else
    {
      digitalWrite(LedPin1,LOW);
      
    }
    if(LED2Status)
    {
      digitalWrite(LedPin2,HIGH);
      
    }
    else
    {
      digitalWrite(LedPin2,LOW);
      
    }
    if(LampStatus)
    {
      digitalWrite(LampPin,HIGH);
      
    }
    else
    {
      digitalWrite(LampPin,LOW);
      
    }
}

void handle_NotFound()
{
  server.send(404,"text/plain","Not Found");
}

