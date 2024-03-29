/*
 * Date: Sun, 09/11/2019
 * Desc: Test simple webserver with port 8012
 * Info: Default mode is STA
 *       Print out MAC address, Toggle led 16
 */

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(8012);
uint8_t pin_led = 16;
char* ssid = "your_ssid";
char* password = "your_pass";

void setup()
{
  pinMode(pin_led, OUTPUT);
  WiFi.begin(ssid,password);
  Serial.begin(115200);
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.print("MAC Address: ");
  Serial.println(WiFi.macAddress());

  server.on("/",[](){server.send(200,"text/plain","Hello World!");});
  server.on("/toggle",toggleLED);
  server.begin();
}

void loop()
{
  server.handleClient();
}

void toggleLED()
{
  digitalWrite(pin_led,!digitalRead(pin_led));
  server.send(204,"");
}
