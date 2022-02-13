#pragma once

#include "Requete.h"

class AbstractChaine {
private:
	AbstractChaine* prochain;

protected:
	void faireSuivre(Requete requete);

public:
	AbstractChaine(AbstractChaine* prochain);


	virtual void traiter(Requete requete) = 0;
};