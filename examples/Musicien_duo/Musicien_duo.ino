/* Nom du programme : musician_duo.ino
   Auteur : Claude Bouchard
   Date : septembre 2020
   Description : Cet exemple montre comment jouer des notes en duo
   sur deux broches numériques d'une plaquette ESP32.


   Pour tester ce programme, il est essentiel d'utiliser deux "buzzers" et non pas
   un piezo. De plus, les "buzzers" doient être pilotés par une transitor afin
   de ne pas endommager la sortie numérique du ESP32. Selon les "buzzers"
   utilisés, il est nécessaire de contrôler le courant dans ce dernier en utilisant
   une résistance série.

   Ce programme a été testé avec deux "buzzers" CEM-1203(42) branchés via un transistor
   IRLU014 et une résistance série de 51 Ohms. Il ne faut pas oublier de brancher
   une diode de roue libre 1N4001 aux bornes du "buzzer". Le tout doit être alimenté
   à 3.3V
*/

//Appel de la bibliothèque Musicianqui contient les fonctions pour jouer des notes.
#include <Musician.h>

//Numéro de la broche sur laquelle est contrôlé les "buzzers".
#define BROCHE_BUZZER_A  12
#define BROCHE_BUZZER_B  15
#define CHANNEL_A 5
#define CHANNEL_B 7

//Déclaration de l'instance des musicians du type Musician
Musician musicianA(BROCHE_BUZZER_A,CHANNEL_A);
Musician musicianB(BROCHE_BUZZER_B,CHANNEL_B);

Melody voiceA("(cdec)x2  (efg+)x2 ((gagf)-ec)x2  (cg_c+)x2",160); //Frère Jacques
Melody voiceB(" (rx8  (cdec)x2  (efg+)x2 ((gagf)-ec)x2  (cg_c+)x2)",160); //Frère Jacques, décalé de 2 mesures

void setup()
{
  musicianA.setMelody(&voiceA);                      
  musicianB.setMelody(&voiceB); 

  musicianA.play();
  musicianB.play();
}

void loop()
{

  musicianA.refresh(); //Permet d'actualiser l'état du musicianA. CETTE MÉTHODE EST OBLIGATOIRE EN DÉBUT DE LOOP(), IDÉALEMENT.
  musicianB.refresh(); //Permet d'actualiser l'état du musicianB. CETTE MÉTHODE EST OBLIGATOIRE EN DÉBUT DE LOOP(), IDÉALEMENT.

}