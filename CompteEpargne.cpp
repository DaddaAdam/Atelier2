#include "CompteEpargne.h"
#include "MAD.h"
#include "Operation.h"
#include "Compte.h"
#include <iostream>
using namespace std;

CompteEpargne::CompteEpargne()
{
	this->tauxInteret = 5.0;
	this->source = nullptr;
}

void CompteEpargne::assignerSource(CompteCourant* src)
{
	this->source = src;
}

void CompteEpargne::modifierTauxInteret(const double taux)
{
	if (taux < 0 || taux > 100)
	{
		cout << "ERREUR: Le taux d'interets doit se situer dans l'intervalle [0, 100]" << endl;
		return;
	}
	this->tauxInteret = taux;
}

void CompteEpargne::display(void) const
{
	cout << "Numero: " << this->numCompte << endl;
	cout << "Appartenant à: "; this->prop->display();
	cout << "Disposant d'un solde de: "; this->solde.display();
	cout << "Le taux d'interet est actuellement a: " << this->tauxInteret << endl;
}

void CompteEpargne::crediter(MAD somme)
{
	this->solde.crediter(somme);
	this->ajouterOperation(Operation::Operation(somme, this->numCompte, "Credit"));
}

void CompteEpargne::debiter(MAD somme)
{
	if (somme <= this->solde * 0.5) {
		this->ajouterOperation(Operation::Operation(somme, this->numCompte, "Debit"));

		this->solde.debiter(somme);
	}
	else
		cout << "ERREUR: La somme a retirer doit etre inferieure à 50% du solde." << endl;
}

void CompteEpargne::transferer(Compte* c, MAD somme)
{
	if (somme <= this->solde * 0.5) {
		this->debiter(somme);
		c->crediter(somme);
	}
}

void CompteEpargne::calculInteret(void)
{
	MAD montant(this->solde * this->tauxInteret);

	cout << "Ancien solde avant application taux interets: "; this->solde.display();

	Operation calcul(montant, this->numCompte, "Calcul taux interet");

	this->ajouterOperation(calcul);
	this->crediter(montant);
}
