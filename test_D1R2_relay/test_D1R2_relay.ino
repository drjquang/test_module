/*
 * Date: Sun, 09/11/2019
 * Desc: Test simple webserver with port 8012 on Wemos D1R2
 * Info: Default mode is STA
 *       Toggle pin D7, D6, D5 (relay shield, cannot use D4)
 */

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(8012);
uint8_t relay_1 = D7;
uint8_t relay_2 = D6;
uint8_t relay_3 = D5;
//uint8_t relay_4 = D4; // cannot use D4
char* ssid = "espard";
char* password = "abc132de";

void setup()
{
  // initialize I/O as OUTPUT, HIGH_ACTIVE
  pinMode(relay_1, OUTPUT);
  pinMode(relay_2, OUTPUT);
  pinMode(relay_3, OUTPUT);
  //pinMode(relay_4, OUTPUT);
  delay(2000);
  digitalWrite(relay_1, LOW);
  digitalWrite(relay_2, LOW);
  digitalWrite(relay_3, LOW);
  //digitalWrite(relay_4, LOW);
  // initialize WiFi connection, Station mode
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
  server.on("/toggle_1",toggle_relay_1);
  server.on("/toggle_2",toggle_relay_2);
  server.on("/toggle_3",toggle_relay_3);
  //server.on("/toggle_4",toggle_relay_4);
  server.begin();
}

void loop()
{
  server.handleClient();
}

void toggle_relay_1()
{
  digitalWrite(relay_1,!digitalRead(relay_1));
  server.send(204,"");
}
void toggle_relay_2()
{
  digitalWrite(relay_2,!digitalRead(relay_2));
  server.send(204,"");
}
void toggle_relay_3()
{
  digitalWrite(relay_3,!digitalRead(relay_3));
  server.send(204,"");
}
//void toggle_relay_4()
//{
//  digitalWrite(relay_4,!digitalRead(relay_4));
//  server.send(204,"");
//}
