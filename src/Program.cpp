#include <Arduino.h>


#include "Program.h"
#include "LecteurNFC.h"
#include "TransfertSerie.h"

Program::Program() {
	Serial.begin(MONITOR_SPEED);
	while ( ! Serial ) { ; }

	TransfertSerie* serie = new TransfertSerie(BORNE_RX, BORNE_TX, MONITOR_SPEED, nullptr);
	LecteurNFC* lecteur = new LecteurNFC(serie);

	tete = lecteur;
}


void Program::loop() {
	Requete requete = {0};
	tete->traiter(requete);
}
