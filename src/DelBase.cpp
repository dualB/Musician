#include "DelBase.h"

DelBase::DelBase()
{
  _value = false;

  _blinking = false;
  _blinkInterval = DEFAULT_BLINKING_INTERVAL;
  _brightness = DEFAULT_BRIGHTNESS;
}

void DelBase::set(bool value)
{
  _value = value;
}
bool DelBase::get()
{
  return _value;
}
void DelBase::setBlinking(bool state)
{
  _blinking = state;
}
bool DelBase::getBlinking()
{
  return _blinking;
}

void DelBase::setBrightness(float value)
{
  if (value < 0.0)
  {
    _brightness = 0.0;
  }
  else if (value > 100.0)
  {
    _brightness = 100.0;
  }
  else
  {
    _brightness = value;
  }

}

float DelBase::getBrightness()
{
  return _brightness;
}

void DelBase::setBlinkingInterval(unsigned long interval)
{
  _blinkInterval = interval == 0 ? 1 : interval;
}
unsigned long DelBase::getBlinkingInterval()
{
  return _blinkInterval;
}

void DelBase::refresh()
{
  if (_value)
  {
    if (_blinking)
    {
      changeState(((millis() % (_blinkInterval * 2)) > _blinkInterval), _brightness);
    }
    else
    {
      changeState(true, _brightness);
    }
  }
  else
  {
    changeState(false, _brightness);
  }
}
