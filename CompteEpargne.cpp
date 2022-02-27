#include "CompteEpargne.h"
#include "MAD.h"
#include "Operation.h"
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
}

void CompteEpargne::debiter(MAD somme)
{
	if (somme <= this->solde * 0.5) {
		this->ajouterOperation(Operation::Operation(this->solde * 0.5, this->numCompte, "Debit"));

		this->source->crediter(this->solde * 0.5);

		this->solde.debiter(this->solde * 0.5);
	}
	else
		cout << "ERREUR: La somme a retirer doit etre inferieure à 50% du solde." << endl;
}

void CompteEpargne::calculInteret(void)
{
	MAD montant(this->solde * this->tauxInteret);

	cout << "Ancien solde avant application taux interets: "; this->solde.display();

	Operation calcul(montant, this->numCompte, "Calcul taux interet");

	this->ajouterOperation(calcul);
	this->crediter(montant);

}
