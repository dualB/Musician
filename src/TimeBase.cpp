#include "TimeBase.h"

TimeBase::TimeBase() : _playing(false), _pausing(false), _startTime(0), _duree(0)
{
	stop();
}

void TimeBase::refresh()
{
	unsigned long now = millis();
	if (_playing && !_pausing)
	{

		if (now > _startTime + _duree)
		{
			_startTime = millis();

			bool answer = updateMelody();
			if (answer)

			{
				_duree = getNextDuration();
			}
			else
			{
				noSound();
				stop();
			}
		}
		else if (now > _startTime + _duree - getBreath())
		{
			noSound();
		}
	}
	else
	{
		noSound();
	}
}

void TimeBase::setPlaying(bool playing)
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

bool TimeBase::isPlaying()
{
	return _playing;
}

void TimeBase::play()
{
	if (_playing == false)
	{
		restartMelody();
		_startTime = millis();
		_duree = 0;
	}
	_playing = true;
	_pausing = false;
}

void TimeBase::playSync()
{
	TimeBase::play();
	while (TimeBase::isPlaying())
	{
		TimeBase::refresh();
	}
}

void TimeBase::setPause(bool value)
{
	_pausing = value;
}
bool TimeBase::getPause()
{
	return _pausing;
}
void TimeBase::stop()
{
	_playing = false;
	_pausing = false;
}
