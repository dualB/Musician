#include "Melody.h"
#include "Musician.h"

#define PIN_BUZZER 12

Musician musician(PIN_BUZZER);

//Wolfgang Amadeus Mozart, Eine kleine Nachtmusik (KV 525)
Melody mozartNachtmusik("g<<r-d- | g<< r-d-(g<dg<b)-d<*r | c*<<r-a-c*<<r-a- |(c*<af#<a)-d<r | (gr)- g. (bag | (gag)/3:1 f#)- f#. (ac*f# | ag)- g.  (bag | (gag)/3:1 f#)- f#. (ac*f#)- | ((grgr)-- (gf#ef#)--)>> ((grgr)-- (baga)--)> | (brbr)-- (d*c*bc*)-- d*< r | ((de)+  | (d-c.)-c (c-b_.)-  b_ | (( b-a.)- a (gf#ef# | (grarbr)>)- r )_)> ", 140);

//Scale with ascending loudness
Melody scaleLouder("c>>> d>> e>f g< a<< b<<< c*<<<<", 240);

//Valid choice kind-of sound
Melody validChoice(" (cgc*)**---");

//Invalid choice kind-of sound
Melody invalidChoice(" (cg_)__");

//Frere Jacques
Melody frereJacques("(cdec)x2   (efgr)x2   ((gagf)-ec)x2     (c g_ c+)x2"); //Frère Jacques

//Au Clair de la Lune
Melody auClairDeLaLune(" ( (cccde+dr  ceddc+.r)x2  dddd (a+ar)_ dc(b a g+.r)_ cccde+dr ceddc+.r )*");

// John Sebastian Bach, The Musical Offering Theme
Melody bachMusicalOffering(" (((ce,ga,b_)+rg(f#fee,.)+  dd,c (ba-g-)_ c f e,+d+c+))>>+", 240);

int melodyIndex = 0;

void setup()
{
  musician.setBreath(1); //milliseconds of silence at the end of notes
  musician.setLoudnessLimit(0, 16); //Depending on your hardware
}

void loop()
{
  musician.refresh();

  if (!musician.isPlaying())
  {
    delay(1000);
    switch (melodyIndex)
    {
      case 0:
        musician.setMelody(&mozartNachtmusik);
        break;
      case 1:
        musician.setMelody(&scaleLouder);
        break;
      case 2:
        musician.setMelody(&validChoice);
        break;
      case 3:
        musician.setMelody(&invalidChoice);
        break;
      case 4:
        musician.setMelody(&frereJacques);
        break;
      case 5:
        musician.setMelody(&auClairDeLaLune);
        break;
      case 6:
        musician.setMelody(&bachMusicalOffering);
        break;
    }
    musician.play();
    melodyIndex = (melodyIndex + 1) % 7;
  }
}