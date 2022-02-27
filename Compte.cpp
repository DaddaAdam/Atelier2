#include "Compte.h"
#include "Client.h"

int Compte::nbrComptes = 0;
Compte::Compte()
{
	this->numCompte = ++nbrComptes;
	this->prop = nullptr;
	this->solde = 0.0;
}

void Compte::assignerProprietaire(Client* cl)
{
	cl->ajouterCompte(this);
	this->prop = cl;
}

void Compte::consulter(void) const
{
	cout << "Solde: "; this->solde.display();
	if (!this->listeOperations.empty()) {
		cout << "Historique des operations: " << endl;

		for (const auto& op : this->listeOperations) {
			op.display();
		}
	}
}

void Compte::ajouterOperation(const Operation Op)
{
	this->listeOperations.push_back(Op);
}
