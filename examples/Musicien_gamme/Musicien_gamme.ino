/* Nom du programme : gamme.ino
 * Auteur : Claude Bouchard
 * Date : septembre 2020
 * Description : Cet exemple montre comment jouer des notes de musician
 * sur une broche numérique d'une plaquette ESP32. 
 * 
 * 
 * Pour tester ce programme, il est essentiel d'utiliser un "buzzer" et non pas
 * un piezo. De plus, le "buzzer" doit être piloté par une transitor afin
 * de ne pas endommager la sortie numérique du ESP32. Selon le "buzzer" 
 * utilisé, il est nécessaire de contrôler le courant dans ce dernier en utilisant
 * une résistance série. 
 * 
 * Ce programme a été testé avec un "buzzer" CEM-1203(42) branché via un transistor 
 * IRLU014 et une résistance série de 51 Ohms. Il ne faut pas oublier de brancher 
 * une diode de roue libre 1N4001 aux bornes du "buzzer". Le tout doit être alimenté 
 * à 3.3V
 */

//Appel de la bibliothèque Musicianqui contient les fonctions pour jouer des notes.
#include <Musician.h>

//Numéro de la broche sur laquelle est contrôlé le "buzzer".
const uint8_t BROCHE_BUZZER = 12;
//Déclaration de l'instance musiciandu type Musician
Musician musician(BROCHE_BUZZER);


void setup() {
  //Initialise le port de communication série à 115200 bps pour être conforme
  //à la vitesse de transmission des messages du RTOS du ESP32 :
  Serial.begin(115200);

  musician.setScore("c c# d d# e f f# g g# a a# b (c c# d d# e r)* c (b b, a a, g a b)_ c+ r+  c>>>>c>>>c>>c>cc<c<<c<<<c<<<");

}

void loop() {

  musician.refresh(); //Permet d'actualiser l'état du musician. CETTE MÉTHODE EST OBLIGATOIRE EN DÉBUT DE LOOP(), IDÉALEMENT.
  
  if (!musician.isPlaying()){ //Lorsque le musicianne joue plus:
    musician.play(); //Faire jouer le musician.
  }

}