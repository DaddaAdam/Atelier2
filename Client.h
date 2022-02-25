#pragma once

class Compte;
#include <iostream>
#include "Compte.h"
#include <list>

using namespace std;
class Client
{
private:
	static int nbrClients;
	int matricule;
	string nom;
	string prenom;
	list<Compte*> listeComptes;
public:
	Client(string, string);
	void ajouterCompte(Compte*);
	void display(void) const;
	~Client();
};

