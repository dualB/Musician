**La version en français est disponible plus bas.**

# Musician library

## Use
Must be used with the  [Melody](https://github.com/dualB/Melody) library.

## Constructors and methods
```cpp
Musician(uint8_t pin);
```
We specify the pin to which the * buzzer * is connected.

---
```cpp
void setMelody(Melody* melody)
Melody*t getMelody()
```

This method allows you to read and modify the Melody object which will be played by the musician. The address of the object must be passed.

```cpp
 void refresh()
```
This method must be placed at the start of the loop (): it allows you to update the state of the Musicians without blocking the execution of the rest of the loop.

---
```cpp
bool play()
```

This method starts the playing of the melody.

---
```cpp
bool stop()
```
This method stops the playing of the melody.

---
```cpp
void setPlaying(bool value)
bool isPlaying()
```
This method allows you to read and modify the active state of the musician (whether it's playing or not).
setPlaying(true) has the same effect as play().
setPlaying(false) has the same effect as stop().

---
```cpp
void setPause(bool value)
bool getPause()
```
This method allows you to read and modify the pause state of the musician. When paused, the active state is still true (getPlaying () returns TRUE), but the musician is on hold before playing the next note.
---
```cpp
void setLoudnessLimit(int min, int max)
```
This method allows you to modify the hardware limits to be used for the loudness scale. A MELO scale mapping matches the value -4 to the minimum, and the value +4 to the maximum.
	
---
```cpp
void setBreath(unsigned int duration)
unsigned int getBreath()
```
This method makes it possible to read and modify the duration of the breath, that is to say the time which is subtracted at the end of each note read, in order to allow a small period of latency between each note. This is useful for preventing consecutive identical notes from being heard as one long note.


# Librairie Musician

## Utilisation
Doit être utilisé avec la librairie [Melody](https://github.com/dualB/Melody)

## Constructeurs et méthodes
```cpp
Musician(uint8_t pin);
```
On spécifie la broche sur laquelle est connectée le *buzzer*.

## Méthodes disponibles
---
```cpp
void setMelody(Melody* melody)
Melody*t getMelody()
```
Cette méthode permet de lire et modifier l'objet Melody qui sera joué par le musicien. L'addresse de l'objet doit être passé.


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
void setLoudnessLimit(int min, int max)
```
Cette méthode permet de modifier les limites matérielles à utiliser pour l'échelle d'intensité sonore. Un mappage de l'échelle MELO fait correspondre la valeur -4 au minimum, et la valeur +4 au maximum.
	
---
```cpp
void setBreath(unsigned int duration)
unsigned int getBreath()
```
Cette méthode permet de lire et modifier la durée de la respiration, c'est-à-dire le temps qui est retranché à la fin de chaque note lue, afin de permettre une petite période de latence entre chaque note. Cela a pour utilité d'empêcher que des notes identiques consécutives soient entendues comme étant une seule longue note.
