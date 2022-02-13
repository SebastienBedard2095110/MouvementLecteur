#pragma once

#include <Adafruit_PN532.h>

#include "AbstractChaine.h"

class LecteurNFC : public AbstractChaine {
private:
	Adafruit_PN532 nfc;
	char clef[20];

public:
	LecteurNFC(AbstractChaine* prochain);
	void traiter(Requete requete) override;
};