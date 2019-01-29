#include "Wire.h"
#include "KB_Chain_Force.h"
#define I2C_ADDRESS 0x2A   //address 0x2A, address 0x2B

KB_FORCE i2c_Force;

void setup() {
  pinMode(17, OUTPUT);
  Serial.begin(115200);
  i2c_Force.begin(I2C_ADDRESS);
}

void loop() {
  int temp_a = 0;
  temp_a = i2c_Force.analogRead(0); //CH 0 & CH 1
  if (temp_a > 0) {
    digitalWrite(17, LOW);
  }  else {
    digitalWrite(17, HIGH);
  }
  delay(250);
}
