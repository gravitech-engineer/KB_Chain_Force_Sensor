#ifndef __KB_FORCE_H
#define __KB_FORCE_H



#if ARDUINO >= 100
#include "Arduino.h"
#define I2CWRITE(x) Wire.write(x)
#define I2CREAD() Wire.read()
#else
#include "WProgram.h"
#define I2CWRITE(x) Wire.send(x)
#define I2CREAD() Wire.receive()
#endif



/**
   @brief KB_RELAY Arduino class
*/
class KB_FORCE {
  public:
    /**
       Create a new KB_RELAY instance
    */
    KB_FORCE();

    /**
       Start the I2C controller and store the KB_RELAY_Module address
    */
    void begin(uint8_t address);
    uint16_t writeRegister(uint8_t _address, uint8_t data);
    void burstRead(uint8_t baseAddress, uint8_t *buffer, uint8_t length);
    uint8_t readRegister(uint8_t _address);
    int analogRead(int Ch);


  private:
    volatile uint8_t _ch;
    uint8_t _address;
    uint8_t _data;
};
#endif
