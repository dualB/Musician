#include "HardwareBase.h"

#ifdef ESP_PLATFORM
HardwareBase::HardwareBase(int address, int channel)
{
  _address = address;
  _channel = channel;

  ledcSetup(_channel, PWM_FREQUENCY, PWM_RESOLUTION);
  ledcAttachPin(_address, _channel);
  ledcWrite(_channel, 0); //duty Cycle de 0
}
#else
HardwareBase::HardwareBase(int address)
{
  _address = address;
  pinMode(_address, OUTPUT);
}
#endif

void HardwareBase::noSound()
{
  changeState(0, 0);
}

void HardwareBase::changeState(unsigned int frequency, int loudness)
{

#ifdef ESP_PLATFORM

  ledcWriteTone(_channel, frequency);
  ledcWrite(_channel, frequency > 0 ? loudness : 0.0);

#else
  if (frequency > 0)
  {
    tone(_address, frequency);
  }
  else
  {
    noTone(_address);
  }

#endif
}

int HardwareBase::getAddress()
{
  return _address;
}