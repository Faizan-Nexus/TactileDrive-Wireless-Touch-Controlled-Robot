#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11);  // RX, TX

// Motor control pins
int in1 = 2, in2 = 3;
int in3 = 4, in4 = 5;

// PWM speed pins
int ENA = 6;   // Left motor speed
int ENB = 9;   // Right motor speed

// Default speed (0–255)
int speedValue = 150;

void setup() {
  Serial.begin(9600);
  BT.begin(9600);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  Serial.println("SLAVE READY - Waiting for command...");
}

// Motor movement functions
void setSpeed(int spd) {
  speedValue = constrain(spd, 0, 255);
  analogWrite(ENA, speedValue);
  analogWrite(ENB, speedValue);
  Serial.print("Speed Set To: ");
  Serial.println(speedValue);
}

void Forward() {
  setSpeed(speedValue);
  digitalWrite(in1,HIGH); digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH); digitalWrite(in4,LOW);
  Serial.println("Car Moving Forward");
}

void Backward() {
  setSpeed(speedValue);
  digitalWrite(in1,LOW);  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);  digitalWrite(in4,HIGH);
  Serial.println("Car Moving Backward");
}

void Left() {
  setSpeed(speedValue);
  digitalWrite(in1,LOW);  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH); digitalWrite(in4,LOW);
  Serial.println("Car Turning Left");
}

void Right() {
  setSpeed(speedValue);
  digitalWrite(in1,HIGH); digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);  digitalWrite(in4,HIGH);
  Serial.println("Car Turning Right");
}

void StopCar() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(in1,LOW); digitalWrite(in2,LOW);
  digitalWrite(in3,LOW); digitalWrite(in4,LOW);
  Serial.println("Car Stopped");
}

void loop() {

  if (BT.available()) {
    char cmd = BT.read();
    Serial.print("Received Command: ");
    Serial.println(cmd);

    switch (cmd) {
      case 'F': Forward(); break;
      case 'B': Backward(); break;
      case 'L': Left(); break;
      case 'R': Right(); break;

      // Speed commands
      case '1': setSpeed(80);  break;  // Slow
      case '2': setSpeed(150); break;  // Medium
      case '3': setSpeed(220); break;  // Fast
      case '4': setSpeed(255); break;  // Full Speed
      
      default: Serial.println("Invalid Command"); break;
    }
  }
  else {
    StopCar();
  }

}
