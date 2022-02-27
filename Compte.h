#pragma once

class Client;
#include <list>
#include "Client.h"
#include "MAD.h"
#include "Operation.h"


using namespace std;

class Compte
{
protected:
	static int nbrComptes;
	int numCompte;
	Client* prop;
	MAD solde;
	list<Operation> listeOperations;

public:
	Compte();
	void assignerProprietaire(Client *);
	virtual void display(void) const = 0;
	virtual void crediter(MAD) = 0;
	virtual void debiter(MAD) = 0;
	virtual void transferer(Compte *, MAD) = 0;
	void consulter(void) const;
	void ajouterOperation(const Operation);
};

