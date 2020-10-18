#ifndef DelBase_h
#define DelBase_h

#define DEFAULT_BLINKING_INTERVAL 250
#define DEFAULT_BRIGHTNESS 100.0
#include "Arduino.h"

/******************************************************************************
* Definitions
******************************************************************************/
class DelBase
{
public:
    DelBase();

    void set(bool);
    bool get();

    void setBlinking(bool);
    bool getBlinking();

    void setBrightness(float);
    float getBrightness();

    void setBlinkingInterval(unsigned long);
    unsigned long getBlinkingInterval();

    void refresh();

protected:
    virtual void changeState(bool,float){};
 

private:
    unsigned long _blinkInterval;
    bool _value;
    bool _blinking;
    float _brightness;
};
#endif
