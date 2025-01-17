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

/**
 * Fonction : initialiserBouton
 * -------------------
 * initialisé bouton
 *
 * @param brocheBouton  Broche du bouton (défaut : 18)
 */
void initialiserBouton(uint8_t brocheBouton)
{
    pinMode(brocheBouton, INPUT_PULLUP);
    attachInterrupt(brocheBouton, actionBouton_ISR, FALLING);
    _brocheBouton = brocheBouton;
}

/**
 * Fonction : initialiserPotentiometre
 * -------------------
 * initialisé potentiometre
 *
 * @param brochePotentiometre  Broche du potentiometre (défaut : 39)
 */
void initialiserPotentiometre(uint8_t brochePotentiometre)
{
    pinMode(_brochePotentiometre, INPUT);
    _brochePotentiometre = brochePotentiometre;
}

/**
 * Fonction : initialiserMoteur
 * -------------------
 * initialisé moteur en commutation
 *
 * @param brocheMoteur  Broche du moteur (défaut : 18)
 */
void initialiserMoteur(uint8_t brocheMoteur)
{
    pinMode(brocheMoteur, OUTPUT);
}

/**
 * Fonction : initialiserMoteur
 * -------------------
 * Surcharge
 * initialisé moteur avec variation de vitesse
 *
 * @param brocheMoteur  Broche du moteur
 * @param canal         Canal PWM
 */
void initialiserMoteur(uint8_t brocheMoteur, uint8_t canal)
{
    ledcAttachPin(brocheMoteur, 0);
    ledcSetup(canal, 5000, 12);
    _brocheMoteur = brocheMoteur;
    _canal = canal;
}

/**
 * Fonction : allumerMoteur
 * -------------------
 * Allumer le moteur
 */
void allumerMoteur()
{
    digitalWrite(_brocheMoteur, HIGH);
}

/**
 * Fonction : eteindreMoteur
 * -------------------
 * Eteindre le moteur
 */
void eteindreMoteur()
{
    digitalWrite(_brocheMoteur, LOW);
}

/**
 * Fonction : consignePotentiometre
 * -------------------
 * Lire la consigne du potentiometre
 *
 * @return uint8_t : consigne du potentiometre (0 - 100%)
 */
uint8_t consignePotentiometre()
{
    uint8_t consigne = (analogRead(_brochePotentiometre) * 100) / 4096;
    return consigne;
}

/**
 * Fonction : etatBouton
 * -------------------
 * Lire l'état du bouton
 *
 * @return boolean : Vrais si appuyer
 */
boolean etatBouton()
{
    return _etatBouton;
}

/**
 * Fonction : vitesseMoteur
 * -------------------
 * Faire varier la vitesse du moteur en fonction d'une consigne
 *
 * @param consigne  Consigne de vitesse (0 - 100%)
 */
void vitesseMoteur(uint8_t consigne)
{
    uint16_t vitesse = (consigne * 4096) / 100;
    ledcWrite(_canal, vitesse);
}