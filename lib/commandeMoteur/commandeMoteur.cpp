#include "commandeMoteur.h"
#include <Arduino.h>

uint8_t _brocheMoteur;
uint8_t _brocheBouton;

boolean _etatBouton = false;

void IRAM_ATTR actionBouton_ISR()
{

    static unsigned long currentTime = 0;
    static unsigned long previousTime = 0;
    currentTime = millis();

    if ((currentTime - previousTime) > 300)
    {
        _etatBouton = !_etatBouton;
        previousTime = currentTime;
    }
}

void initialiserBouton(uint8_t brocheBouton)
{
    pinMode(brocheBouton, INPUT_PULLUP);
    attachInterrupt(brocheBouton, actionBouton_ISR, FALLING);
    _brocheBouton = brocheBouton;
}

void initialiserMoteur(uint8_t brocheMoteur)
{
    pinMode(brocheMoteur, OUTPUT);
    _brocheMoteur = brocheMoteur;
}

void allumerMoteur()
{
    digitalWrite(_brocheMoteur, HIGH);
}

void eteindreMoteur()
{
    digitalWrite(_brocheMoteur, LOW);
}

boolean etatBouton()
{
    return _etatBouton;
}