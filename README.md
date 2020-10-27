# Librairie Musician

## Utilisation
Doit être utilisé avec la librairie [Melody](https://github.com/dualB/Melody)

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

