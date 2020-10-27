#ifndef Musician_h
#define Musician_h

#include "Melody.h"
#include "HardwareBase.h"
#include "TimeBase.h"

#define DEFAULT_MINIMUM_LOUDNESS 0
#define DEFAULT_MAXIMUM_LOUDNESS 16
#define DEFAULT_BREATH_DURATION 5
/******************************************************************************
* Definitions
******************************************************************************/
class Musician : public TimeBase
{

public:
#ifdef ESP_PLATFORM
	Musician(int, int);
#else
	Musician(int);
#endif
	void setMelody(Melody *);
	Melody *getMelody();
	void setBreath(unsigned int);
	unsigned int getBreath();
	void setLoudnessLimit(int, int);

protected:
	bool updateMelody();
	void restartMelody();
	void noSound();
	unsigned long getNextDuration();

private:
	HardwareBase _hardwareBase;
	Melody *_melody;
	void noTone();

	bool _playing;
	bool _pausing;
	unsigned long _startTime;
	unsigned long _duree;
	unsigned long _breathDuration;
	int _min, _max;
};

#endif
