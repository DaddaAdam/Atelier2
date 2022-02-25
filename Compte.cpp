#include "Compte.h"
#include "Client.h"

int Compte::nbrComptes = 0;
Compte::Compte()
{
	this->numCompte = ++nbrComptes;
	this->solde = 0.0;
}

void Compte::assignerProprietaire(Client* cl)
{
	cl->ajouterCompte(this);
	this->prop = cl;
}
