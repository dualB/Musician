#ifndef TimeBase_h
#define TimeBase_h

#include "Arduino.h"

/******************************************************************************
* Definitions
******************************************************************************/
class TimeBase
{

public:
	TimeBase();

	void refresh();

	void play();
	void setPlaying(bool);
	bool isPlaying();
	void stop();

	void setPause(bool);
	bool getPause();

protected:
	virtual unsigned long getNextDuration() = 0;
	virtual unsigned int getBreath() { return 0; };
	virtual bool updateMelody() = 0;
	virtual void restartMelody() = 0;
	virtual void noSound() = 0;

private:
	bool _playing;
	bool _pausing;
	unsigned long _startTime;
	unsigned long _duree;
};

#endif
