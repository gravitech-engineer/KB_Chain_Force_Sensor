/* Dependencies */
#include <Wire.h>
#include "KB_Chain_Force.h"

KB_FORCE::KB_FORCE()
{

}

void KB_FORCE::begin(uint8_t address)
{
  _address = address;
  Wire.begin(4, 5);
}

uint8_t KB_FORCE::readRegister(uint8_t address)
{
  Wire.beginTransmission(_address);
  Wire.write(_address);
  Wire.endTransmission(false);
  Wire.requestFrom(_address, 1);

  return Wire.read();
}

uint16_t KB_FORCE::writeRegister(uint8_t _address, uint8_t data)
{
  _data = data;
  uint8_t a, b;
  Wire.beginTransmission(_address);
  Wire.write(_data);
  Wire.endTransmission(false);
  Wire.requestFrom(_address, 2);
  while (Wire.available()) {
    a = Wire.read();
    b = Wire.read();
  }

  uint16_t raw;
  raw = (a << 8) & 0x3FF;
  raw = b + raw;
  return raw;
//  Serial.println(raw);

}

void KB_FORCE::burstRead(uint8_t baseAddress, uint8_t *buffer, uint8_t length)
{
  Wire.beginTransmission(_address);
  Wire.write(baseAddress);
  Wire.endTransmission(false);
  Wire.requestFrom((uint8_t)_address, length);

  uint8_t idx = 0;
  while (Wire.available()) {
    buffer[idx++] = Wire.read();
  }
}

int KB_FORCE::analogRead(int Ch) {
  uint8_t temp_data;
  int read_analog;
  _ch = Ch;

  switch (_ch)
  {
    case 0:
      /* code */
      temp_data = 0xA1;
      break;
    case 1:
      /* code */
      temp_data = 0xA2;
      break;
    default:
      printf("CH NOT FOUND\n");
      break;
  }

  read_analog = writeRegister(_address, temp_data);
  return read_analog; 
}

