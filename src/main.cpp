#include <Arduino.h>
const int UV_PIN = 7;
const int BLUE_PIN = 8;

void setup() {
  pinMode(UV_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  digitalWrite(UV_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char cmd = Serial.read();
    if (cmd == 'U') digitalWrite(UV_PIN, LOW);      // UV 켜기
    else if (cmd == 'u') digitalWrite(UV_PIN, HIGH);  // UV 끄기
    else if (cmd == 'B') digitalWrite(BLUE_PIN, LOW); // BLUE 켜기
    else if (cmd == 'b') digitalWrite(BLUE_PIN, HIGH);  // BLUE 끄기
    else if (cmd == 'X') {                            // 둘 다 끄기 (안전용)
      digitalWrite(UV_PIN, HIGH);
      digitalWrite(BLUE_PIN, HIGH);
    }
  }
}