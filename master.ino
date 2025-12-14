#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11);  // RX, TX

// Threshold for sensor detection
const int threshold = 0;

void setup() {
  Serial.begin(9600);
  BT.begin(9600);  // HC-05 default baud
  Serial.println("REMOTE CONTROLLER READY");
}

void loop() {
  // Read analog inputs (flex sensors, joystick, or buttons)
  int s0 = digitalRead(2);
  int s1 = digitalRead(3);
  int s2 = digitalRead(4);
  int s3 = digitalRead(5);

  Serial.print("A0: "); Serial.print(s0);
  Serial.print(" | A1: "); Serial.print(s1);
  Serial.print(" | A2: "); Serial.print(s2);
  Serial.print(" | A3: "); Serial.println(s3);

  // Send commands based on sensor input
  bool commandSent = false;

  if (s0 > threshold) { BT.write('F'); Serial.println("FORWARD"); commandSent = true; }
  else if (s1 > threshold) { BT.write('B'); Serial.println("BACKWARD"); commandSent = true; }
  else if (s2 > threshold) { BT.write('L'); Serial.println("LEFT"); commandSent = true; }
  else if (s3 > threshold) { BT.write('R'); Serial.println("RIGHT"); commandSent = true; }

  // If no sensor triggered, send STOP command
  if (!commandSent) {
    BT.write('S');
    Serial.println("STOP");
  }

  delay(50); // small delay for smooth control
}
