#include <LiquidCrystal.h>

LiquidCrystal LedDriver(11, 9, 5, 6, 7, 8);
unsigned long ClockTimer;
int encoderPosition = 0;
const byte interruptPin0 = 0;
const byte interruptPin1 = 0;

void MonitorA() {
  if (digitalRead(2) == digitalRead(3)) {
    encoderPosition ++;
  } else {
    encoderPosition --;
  }
}

void MonitorB() {
  if (digitalRead(2) == digitalRead(3)) {
    encoderPosition --;
  } else {
    encoderPosition ++;
  }
}

void setup() {
  
  pinMode(2, INPUT);
  pinMode(3, INPUT);

  attachInterrupt(0, MonitorA, CHANGE);
  attachInterrupt(1, MonitorB, CHANGE);

  LedDriver.begin(16,2);
  LedDriver.clear();

  ClockTimer = millis();

}

void loop() {
  if (millis() - ClockTimer >= 100) {
    MonitorA();
    MonitorB();
    LedDriver.setCursor(0,0);
    LedDriver.print(encoderPosition);
    ClockTimer += 100;
  }

}
