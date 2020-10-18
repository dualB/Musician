#ifndef Musician_h
#define Musician_h

#include "Melody.h"
#include "Del.h"

#define DEFAULT_MINIMUM_LOUDNESS -4
#define DEFAULT_MAXIMUM_LOUDNESS 4

/******************************************************************************
* Definitions
******************************************************************************/
class Musician: private Del
{

public:
	Musician(uint8_t);

	void refresh();

	void play();
	void setPlaying(bool);
	bool isPlaying();
	void stop();

	void setPause(bool);
	bool getPause();
	
	bool setTempo(int);
	unsigned int getTempo();

	void setLoudness(float);
	float getLoudness();

	void setScore(char *);


protected:
    void changeBuzzer(double freq, double brightness);

private:
	Melody _melody;
	void noTone();

	bool _playing;
	bool _pausing;
	unsigned long _startTime;
	unsigned long _duree;
	
	
};

#endif
