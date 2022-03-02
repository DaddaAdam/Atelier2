#include "ComptePayant.h"
#include "CompteCourant.h"
#include "MAD.h"
#include "Compte.h"

ComptePayant::ComptePayant() //: Compte::Compte(), CompteCourant::CompteCourant()
{
}

void ComptePayant::debiter(MAD somme)
{
	this->Compte::solde.debiter(somme * 1.05);
	this->Compte::ajouterOperation(Operation::Operation(somme, this->Compte::numCompte, "Debit"));
}

void ComptePayant::crediter(MAD somme)
{
	this->Compte::solde.crediter(somme * 1.05);
	this->Compte::ajouterOperation(Operation::Operation(somme, this->Compte::numCompte, "Crédit"));
}

void ComptePayant::display(void) const
{
	this->CompteCourant::display();
}

void ComptePayant::transferer(Compte* com, MAD somme)
{
	this->CompteCourant::transferer(com, somme * 1.05);
}
