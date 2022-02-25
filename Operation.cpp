#include "Operation.h"
#include "MAD.h"
#include "Date.h"
#include <iostream>

using namespace std;

int Operation::nbrOperations = 0;
Operation::Operation(MAD somme, int numCompte, string nature)
{
	Date today;

	this->numero = ++nbrOperations;
	this->date = today;
	this->nature = nature;
	this->montant = somme;
	this->libelle = numCompte;
}

void Operation::display(void) const
{
	cout << "Operation numéro: " << this->numero << " , efféctuée le: ";
	this->date.display();
	cout << this->nature << " d'un montant de: "; this->montant.display();
	cout << "Sur le compte numéro: " << this->libelle << endl;

}
