#pragma once

#include "AbstractChaine.h"


class TransfertSerie : public AbstractChaine {
private:
	int RX;
	int TX;

public:
	TransfertSerie(int RX, int TX, int monitorSpeed, AbstractChaine* prochain);
	 void traiter(Requete requete) override;
};