#pragma once

#include "AbstractChaine.h"

AbstractChaine::AbstractChaine(AbstractChaine* prochain)
: prochain(prochain)
{;}


void AbstractChaine::faireSuivre(Requete requete){
	if(prochain != nullptr)
		prochain->traiter(requete);
}