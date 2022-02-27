#include "CompteCourant.h"
#include "Operation.h"
#include "MAD.h"
#include <iostream>
using namespace std;

//Constructeur sans paramètres
CompteCourant::CompteCourant()
{
	this->decouvert = MAD::MAD(800);
	this->solde = MAD::MAD(1000);
}

//Constructeur avec paramètres
CompteCourant::CompteCourant(MAD soldeInit, MAD decouvert)
{
	this->solde = soldeInit;
	this->decouvert = decouvert;
}

//Affichage
void CompteCourant::display(void) const
{
	cout << "Numero: " << this->numCompte << endl;
	cout << "Appartenant à: "; this->prop->display();
	cout << "Disposant d'un solde de: "; this->solde.display();
}

void CompteCourant::crediter(MAD somme)
{
	this->solde.crediter(somme);
	this->ajouterOperation(Operation::Operation(somme, this->numCompte, "Credit"));
}

void CompteCourant::debiter(MAD somme)
{
	this->solde.debiter(somme);
	this->ajouterOperation(Operation::Operation(somme, this->numCompte, "Debit"));
}

void CompteCourant::transferer(Compte* com, MAD somme)
{
	if (this->solde.isDebitable(somme, this->decouvert)) {
		com->crediter(somme);
		this->debiter(somme);
	}
	else {
		cout << "ERREUR: On ne peut pas débiter "; somme.display();
	}
}


