/*
 * Date: Wed, 06/11/2019
 * Desc: Test 4-relay shield on Arduino Uno (micro USB)
 *       Serial command to turn on and off relay
 * Info: Check whether Uno can supply enough power for 4 relays
 *       Power-up, Do 4 relays work as the same time?
 */
#define relay_1 7
#define relay_2 6
#define relay_3 5
#define relay_4 4

char received_char;
void setup() {
  // initialize delay to settle down the board
  delay(2000);
  // initialize serial port
  Serial.begin(9600);      // Uno Xtal=16MHz
  // initialize I/O mode: OUTPUT and LOW (HIGH will activate relay)
  pinMode(relay_1, OUTPUT);
  pinMode(relay_2, OUTPUT);
  pinMode(relay_3, OUTPUT);
  pinMode(relay_4, OUTPUT);
  digitalWrite(relay_1, LOW);
  digitalWrite(relay_2, LOW);
  digitalWrite(relay_3, LOW);
  digitalWrite(relay_4, LOW);
}

void loop() {
  // receive char from serial port
  if (Serial.available() > 0) {
    received_char = Serial.read();
    if (received_char == '1') {
      digitalWrite(relay_1, HIGH);
      Serial.println("Relay 1 = ON");
    } else if (received_char == '2') {
      digitalWrite(relay_2, HIGH);
      Serial.println("Relay 2 = ON");
    } else if (received_char == '3') {
      digitalWrite(relay_3, HIGH);
      Serial.println("Relay 3 = ON");
    } else if (received_char == '4') {
      digitalWrite(relay_4, HIGH);
      Serial.println("Relay 4 = ON");
    } else if (received_char == 'a') {
      digitalWrite(relay_1, LOW);
      Serial.println("Relay 1 = OFF");
    } else if (received_char == 'b') {
      digitalWrite(relay_2, LOW);
      Serial.println("Relay 2 = OFF");
    } else if (received_char == 'c') {
      digitalWrite(relay_3, LOW);
      Serial.println("Relay 3 = OFF");
    } else if (received_char == 'd') {
      digitalWrite(relay_4, LOW);
      Serial.println("Relay 4 = OFF");
    } else {
      Serial.println("An error has occured.");
    }    
    Serial.flush();
  } 
}
