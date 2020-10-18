#include "Del.h"

Del::Del(int address) : DelBase()
{
  _address = address;
  

#ifdef ESP_PLATFORM
  static int objectCount = FIRST_CHANNEL;
  if (objectCount < PWM_MAX_CHANNEL)
  {
    _channel = objectCount;
    objectCount++;
    objectCount++;
    ledcSetup(getChannel(), PWM_FREQUENCY, PWM_RESOLUTION);
    ledcAttachPin(_address, getChannel());
    ledcWrite(getChannel(), (int)(getBrightness() * PWM_MAXIMUM_FACTOR)); //duty Cycle de 0
  }
  else
  {
    _channel = -1;
  }
#else
  pinMode(_address, OUTPUT);
#endif
}

int Del::getAddress()
{
  return _address;
}

#ifdef ESP_PLATFORM
int Del::getChannel()
{
  return _channel;
}
#endif

void Del::changeState(bool state, float brightness)
{

#ifdef ESP_PLATFORM

  if (getChannel() >= 0)
  {
    ledcWrite(getChannel(), state ? (int)(getBrightness() * PWM_MAXIMUM_FACTOR) : 0.0);
  }

#else
  analogWrite(_address, state ? (brightness * 2.55) : 0.0);

#endif
}
