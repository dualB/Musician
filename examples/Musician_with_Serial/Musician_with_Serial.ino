/*
  Musician with Serial

  With the Serial monitor, you can send a string using the MELO notation, and the musician will play it.

  More information on the MELO notation here : https://github.com/dualB/Melody

  by Claude Bouchard
  November 2020
*/
#include "Melody.h"
#include "Musician.h"

#define SERIAL_BAUDRATE 115200
#define PIN_BUZZER 12

//The constructor depends on the architecture you use
#ifdef ESP_PLATFORM
  #define CHANNEL 9
  Musician musician(PIN_BUZZER, CHANNEL);
#else
  Musician musician(PIN_BUZZER);
#endif

void setup()
{
  Serial.begin(SERIAL_BAUDRATE);
  musician.setBreath(1);            //milliseconds of silence at the end of notes
  musician.setLoudnessLimit(0, 16); //Depending on your hardware
}

void loop()
{
  musician.refresh();

  if (Serial.available())
  {

    String melo = Serial.readString();
    Melody *melody = new Melody(melo);

    musician.setMelody(melody);
    musician.play();
  }
}