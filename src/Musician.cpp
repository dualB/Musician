#include "Musician.h"

Musician::Musician(uint8_t address) : Del(address)
{
	stop();
}

bool Musician::setTempo(int tempo)
{
	return _melody.setTempo(tempo);
}
unsigned int Musician::getTempo()
{
	return _melody.getTempo();
	;
}

void Musician::refresh()
{
	unsigned long now = millis();
	if (_playing && !_pausing)
	{

		if (now > _startTime + _duree)
		{

			if (_melody.hasNext())
			{
				_melody.next();
				_startTime = millis();
				_duree = _melody.getDuration();
				changeBuzzer(_melody.getFrequency(), map(_melody.getLoudness(), DEFAULT_MINIMUM_LOUDNESS, DEFAULT_MAXIMUM_LOUDNESS, 0, 100));
			}
			else
			{
				stop();
			}
		}
	}
	else
	{
		noTone();
	}
}

void Musician::setPlaying(bool playing)
{
	if (playing)
	{
		play();
	}
	else
	{
		stop();
	}
}

bool Musician::isPlaying()
{
	return _playing;
}

void Musician::play()
{
	if (_playing == false)
	{
		_melody.restart();
		_startTime = millis();
		_duree = 0;
	}
	_playing = true;
	_pausing = false;
}
void Musician::setPause(bool value)
{
	_pausing = value;
}
bool Musician::getPause()
{
	return _pausing;
}
void Musician::stop()
{
	_playing = false;
	_pausing = false;
}
void Musician::setScore(char *score)
{
	_melody.setScore(score);
}

void Musician::noTone()
{
	changeState(false, getBrightness());
}

void Musician::changeBuzzer(double frequency, double brightness)
{

#ifdef ESP_PLATFORM
	setBrightness(brightness);
	if (getChannel() >= 0)
	{
		if (frequency > 0)
		{
			ledcWriteTone(getChannel(), frequency);
			changeState(true, getBrightness());
		}
		else
		{
			//ledcWriteTone(getChannel(), 1);
			changeState(false, getBrightness());
		}
	}
#else
	analogWrite(getAddress(), frequency > 0 ? (brightness * 2.55) : 0.0);
#endif
}
