#ifndef HardwareBase_h
#define HardwareBase_h

#define DEFAULT_BRIGHTNESS 100.0
#include "Arduino.h"

#ifdef ESP_PLATFORM

#define DEFAULT_CHANNEL 0

#define PWM_MAX_CHANNEL 16
#define PWM_FREQUENCY 5000 //Fréquence du PWM
#define PWM_RESOLUTION 8   //Résolution 8 bits; duty cycle de 0 à 255
#define PWM_MAXIMUM_FACTOR 2.55

#endif
/******************************************************************************
* Definitions
******************************************************************************/
class HardwareBase
{
public:
#ifdef ESP_PLATFORM
    HardwareBase(int address, int channel);
#else
    HardwareBase(int address);
#endif
    void changeState(unsigned int, int);
    void noSound();
    int getAddress();

protected:
private:
    int _address;
#ifdef ESP_PLATFORM
    int _channel;
#endif
};
#endif
