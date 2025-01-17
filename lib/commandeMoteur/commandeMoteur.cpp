#include "commandeMoteur.h"
#include <Arduino.h>

uint8_t _brocheMoteur;
uint8_t _brocheBouton;
uint8_t _brochePotentiometre;
uint8_t _canal;

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

void initialiserPotentiometre(uint8_t brochePotentiometre)
{
    pinMode(_brochePotentiometre, INPUT);
    _brochePotentiometre = brochePotentiometre;
}

void initialiserMoteur(uint8_t brocheMoteur)
{
    pinMode(brocheMoteur, OUTPUT);
}

void initialiserMoteur(uint8_t brocheMoteur, uint8_t canal)
{
    ledcAttachPin(brocheMoteur, 0);
    ledcSetup(canal, 5000, 12);
    _brocheMoteur = brocheMoteur;
    _canal = canal;
}

void allumerMoteur()
{
    digitalWrite(_brocheMoteur, HIGH);
}

void eteindreMoteur()
{
    digitalWrite(_brocheMoteur, LOW);
}

uint8_t consignePotentiometre()
{
    uint8_t consigne = (analogRead(_brochePotentiometre) * 100) / 4096;
    return consigne;
}

boolean etatBouton()
{
    return _etatBouton;
}

void vitesseMoteur(uint8_t consigne)
{
    uint16_t vitesse = (consigne * 4096) / 100;
    ledcWrite(_canal, vitesse);
}