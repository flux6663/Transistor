/*        Programme pour la commande d'un ventilateur
grace a un bouton et un transistor

Date    : 09/01/2025
Auteur  : MARTIN Mathis
Rev.    : 1.0
*/
///////////////////////////////////////////////////////////////
#include <Arduino.h>
#include "commandeMoteur.h"

#define BOUTON_APPUYER true

void setup()
{
    initialiserMoteur();
    initialiserBouton();
}

void loop()
{
    if (etatBouton() == BOUTON_APPUYER)
    {
        allumerMoteur();
    }
    else
    {
        eteindreMoteur();
    }
}