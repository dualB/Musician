#ifndef DelBase_h
#define DelBase_h

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
    HardwareBase(int address);

    virtual void changeState(unsigned int, float){};

    void noSound();
    int getAddress();

protected:
private:
    bool _value;
    int _address;
#ifdef ESP_PLATFORM
    int _channel;
#endif
};
#endif
