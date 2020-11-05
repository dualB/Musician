#include "Melody.h"
#include "Musician.h"

#define PIN_BUZZER 8

Musician musician(PIN_BUZZER);

/*
 * Since the memory of smaller microcontrolers is limited, 
 * you habe to un-comment the melody you want to try, one at a time
 * 
*/

//Wolfgang Amadeus Mozart, Eine kleine Nachtmusik (KV 525)
Melody melody("g<<r-d- | g<< r-d-(g<dg<b)-d<*r | c*<<r-a-c*<<r-a- |(c*<af#<a)-d<r ", 140);

//John Williams, The Imperial March (Darth Vader's theme)
//Melody melody(" (ggg e,-. b,-- | g e,-. b,-- g+ (ddde,-.)* b,--  | g, e,-. b,-- g+");

//Scale with ascending loudness
//Melody melody("c>>> d>> e>f g< a<< b<<< c*<<<<", 240);

//Valid choice kind-of sound
//Melody melody(" (cgc*)**---");

//Invalid choice kind-of sound
//Melody melody(" (cg_)__");

//Frere Jacques
//Melody melody("(cdec)x2   (efgr)x2   ((gagf)-ec)x2     (c g_ c+)x2");

//Au Clair de la Lune
//Melody melody(" ( (cccde+dr  ceddc+.r)x2  dddd (a+ar)_ dc(b a g+.r)_ cccde+dr ceddc+.r )*");

// John Sebastian Bach, The Musical Offering Theme
//Melody melody(" (((ce,ga,b_)+rg(f#fee,.)+  dd,c (ba-g-)_ c f e,+d+c+))>>+", 240);

void setup()
{
  musician.setMelody(&melody);
  musician.setBreath(1);            //milliseconds of silence at the end of notes
  musician.setLoudnessLimit(0, 16); //Depending on your hardware
}

void loop()
{
  musician.refresh();

  if (!musician.isPlaying())
  {
    delay(1000);
    musician.play();
  }
}