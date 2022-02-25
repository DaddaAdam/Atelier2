#include "CompteCourant.h"
#include "Operation.h"
#include <iostream>
using namespace std;

void CompteCourant::display(void) const
{
	cout << "Numero: " << this->numCompte << endl;
	cout << "Appartenant à: "; this->prop->display();
	cout << "Disposant d'un solde de: "; this->solde.display();
}

void CompteCourant::crediter(MAD somme)
{
	this->solde.crediter(somme);
}

void CompteCourant::debiter(MAD somme)
{
	this->solde.debiter(somme);
}

void CompteCourant::transferer(Compte* com, MAD somme)
{
	if (this->solde.isDebitable(somme, this->decouvert)) {
		com->crediter(somme);
		this->debiter(somme);

		this->ajouterOperation(Operation::Operation(somme, this->numCompte, "Debit"));
		com->ajouterOperation(Operation::Operation(somme, this->numCompte, "Credit"));
	}
	else {
		cout << "ERREUR: On ne peut pas débiter "; somme.display();
	}
}

void CompteCourant::consulter(void) const
{
	cout << "Solde: "; this->solde.display();
}

void CompteCourant::ajouterOperation(const Operation Op)
{
	this->listeOperations.push_back(Op);
}
