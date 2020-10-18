#ifndef Musician_h
#define Musician_h

#include "Melody.h"
#include "HardwareBase.h"
#include "TimeBase.h"

#define DEFAULT_MINIMUM_LOUDNESS 0
#define DEFAULT_MAXIMUM_LOUDNESS 4

/******************************************************************************
* Definitions
******************************************************************************/
class Musician : public TimeBase
{

public:
	Musician(uint8_t);

	void setMelody(Melody *);
	bool updateMelody();
	void restartMelody();
	void noSound();

	void setInstrumentLimit(int,int);

private:
	HardwareBase _hardwareBase;
	Melody *_melody;
	void noTone();

	bool _playing;
	bool _pausing;
	unsigned long _startTime;
	unsigned long _duree;
	int _min,_max;
};

#endif
