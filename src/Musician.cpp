#include "Musician.h"

#ifdef ESP_PLATFORM
Musician::Musician(int address, int channel) : _hardwareBase(address, channel)
#else
Musician::Musician(int address) : _hardwareBase(address)
#endif
{
	setInstrumentLimit(DEFAULT_MINIMUM_LOUDNESS, DEFAULT_MAXIMUM_LOUDNESS);
}

void Musician::setMelody(Melody *melody)
{
	_melody = melody;
}

void Musician::setMelody(char *score, unsigned int tempo)
{
	_melody = new Melody(score, tempo);
}

Melody *Musician::getMelody()
{
	return _melody;
}

void Musician::noSound()
{
	_hardwareBase.noSound();
}

unsigned long Musician::getNextDuration()
{
	if (_melody != nullptr)
	{
		return _melody->getDuration();
	}
	return 0;
}

void Musician::setBreath(unsigned int breathDuration)
{
	_breathDuration = breathDuration;
}

unsigned int Musician::getBreath()
{
	return _breathDuration;
}

void Musician ::setInstrumentLimit(int min, int max)
{
	_min = min;
	_max = max;
}
bool Musician::updateMelody()
{
	if (_melody != nullptr)
	{
		if (_melody->hasNext())
		{
			_melody->next();
			_hardwareBase.changeState(_melody->getFrequency(), map(_melody->getLoudness(), -4, 4, _min, _max));
			return true;
		}
	}
	return false;
}
void Musician::restartMelody()
{
	if (_melody != nullptr)
	{
		_melody->restart();
	}
}
