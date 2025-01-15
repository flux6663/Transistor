#ifndef _COMMANDEMOTEUR_H__
#define __COMMANDEMOTEUR_H__

#include <Arduino.h>

#define BROCHE_MOTEUR 18
#define BROCHE_BOUTON 27

void initialiserBouton(uint8_t brocheBouton = BROCHE_BOUTON);
void initialiserMoteur(uint8_t brocheMoteur = BROCHE_MOTEUR); // broche par défaut 18

void allumerMoteur();
void eteindreMoteur();
boolean etatBouton();

#endif