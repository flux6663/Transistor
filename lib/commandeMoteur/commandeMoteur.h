#ifndef _COMMANDEMOTEUR_H__
#define __COMMANDEMOTEUR_H__

#include <Arduino.h>

#define BROCHE_MOTEUR 18
#define BROCHE_POTENTIOMETRE 39
#define BROCHE_BOUTON 27
#define CANAL_MLI_0 0

void initialiserBouton(uint8_t brocheBouton = BROCHE_BOUTON);
void initialiserPotentiometre(uint8_t brochePotentiometre = BROCHE_POTENTIOMETRE);
void initialiserMoteur(uint8_t brocheMoteur = BROCHE_MOTEUR);
void initialiserMoteur(uint8_t brocheMoteur, uint8_t canal);

boolean etatBouton();
uint8_t consignePotentiometre();

void allumerMoteur();
void eteindreMoteur();
void vitesseMoteur(uint8_t consigne);

#endif