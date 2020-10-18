# Librairie Musician

## Utilisation

```cpp
#include <Musician.h>

const uint8_t PIN_BUZZER = 12;

Musician musician(PIN_BUZZER);


void setup() {

  musician.setScore("c d e f g a c*");
  musician.setTempo(120);
  musician.setLoundness(100);

  musician.play();
}

void loop() {
  musician.refresh();
}

```

## Constructeurs
```cpp
Musician(uint8_t pin);
```
On spécifie la broche sur laquelle est connectée le *buzzer*.

## Méthodes disponibles
```cpp
 void refresh()
```
Cette méthode doit être placée en début de boucle loop(): elle permet de mettre à jour l'état du Musiciansans bloquer l'exécution du reste de la boucle.

---
```cpp
bool play()
```
Cette méthode permet de démarrer la musique.

---
```cpp
bool stop()
```
Cette méthode permet d'arrêter la musique.

---
```cpp
void setPlaying(bool value)
bool isPlaying()
```
Cette méthode permet de lire et modifier l'état actif du musician(s'il joue ou non).
setPlaying(true) a le même effet que play(). 
setPlaying(false) a le même effet que stop(). 

---
```cpp
void setPause(bool value)
bool getPause()
```
Cette méthode permet de lire et modifier l'état de pause du musician. Lorsqu'il est en pause, l'état actif est toujours vrai (getPlaying() retourne TRUE), mais le musicianest en attente avant de jouer la prochaine note.

---
```cpp
void setTempo(int value)
int getTempo()
```
Cette méthode permet de lire et modifier le tempo de la musique, qui correspond au nombre de temps musicaux durant une minute. Par exemple, un tempo de 120 signifie qu'il y aura 120 notes de 1 temps joué durant 1 minute - ou que chaque note durera 0.5 seconde.
