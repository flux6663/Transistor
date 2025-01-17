/*        Programme pour la commande d'un ventilateur
grace a un bouton et un transistor

Date    : 09/01/2025
Auteur  : MARTIN Mathis
Rev.    : 1.0
*/
///////////////////////////////////////////////////////////////
#include <Arduino.h>
#include "commandeMoteur.h"

void setup()
{
    initialiserMoteur(BROCHE_MOTEUR, CANAL_MLI_0);
    initialiserPotentiometre();
}

void loop()
{
    vitesseMoteur(consignePotentiometre());
}