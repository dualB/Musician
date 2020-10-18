#include "Musician.h"

Musician::Musician(uint8_t address) : _hardwareBase(address)
{
	setInstrumentLimit(DEFAULT_MINIMUM_LOUDNESS, DEFAULT_MAXIMUM_LOUDNESS);
}

void Musician::setMelody(Melody *melody)
{
	_melody = melody;
}

void Musician::noSound()
{
	_hardwareBase.noSound();
}

void Musician ::setInstrumentLimit(int min, int max)
{
	_min = min;
	_max = max;
}
bool Musician::updateMelody()
{
	if (_melody->hasNext())
	{
		_melody->next();
		_hardwareBase.changeState(_melody->getFrequency(), map(_melody->getLoudness(), -4, 4, _min, _max));
	}
}
void Musician::restartMelody()
{
	_melody->restart();
}
