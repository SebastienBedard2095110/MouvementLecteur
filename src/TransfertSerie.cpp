#pragma once

#include <Arduino.h>

#include "TransfertSerie.h"



TransfertSerie::TransfertSerie(int RX, int TX, int monitorSpeed, AbstractChaine* prochain)
	: AbstractChaine(prochain),
		RX(RX),
		TX(TX)
{
	Serial.begin(monitorSpeed);
}

void TransfertSerie::traiter(Requete requete) {
	const uint8_t* data = (uint8_t*) &requete;
	Serial.write(data, sizeof(Requete) );
	faireSuivre(requete);
}
