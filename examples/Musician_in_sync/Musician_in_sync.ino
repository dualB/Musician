/*
  Musician in sync

  The musician can play a melody in sync, blocking while playing until it has finished.
  by Claude Bouchard
  November 2020
*/
#include "Melody.h"
#include "Musician.h"

#define PIN_BUZZER 12

//The constructor depends on the architecture you use
#ifdef ESP_PLATFORM
#define CHANNEL 9
Musician musician(PIN_BUZZER, CHANNEL);
#else
Musician musician(PIN_BUZZER);
#endif

//C scale
Melody melody("cdefgabc*");

void setup()
{
  Serial.begin(115200);
  musician.setMelody(&melody);
}

void loop()
{
  Serial.println("----The musician will start playing.");

  musician.playSync(); //The instruction is blocked until the melody is finished.

  Serial.println("The musician have finished playing.---");

  delay(1000);
}