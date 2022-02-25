#include "Client.h"
#include <iostream>
#include "Compte.h"

using namespace std;

int Client::nbrClients = 0;

Client::Client(std::string nom, std::string prenom)
{
	this->matricule = ++nbrClients;
	this->nom = nom;
	this->prenom = prenom;

}

void Client::ajouterCompte(Compte* compte)
{
	this->listeComptes.push_back(compte);
}

void Client::display(void) const
{
	cout << "Client numéro: " << this->matricule << endl;
	cout << "Nom: " << this->nom << " Prenom: " << this->prenom << endl;
}

Client::~Client()
{
	this->listeComptes.clear();
}
