#include "ComptePayant.h"
#include "CompteCourant.h"
#include "MAD.h"
#include "Compte.h"

ComptePayant::ComptePayant() 
{
}

void ComptePayant::debiter(MAD somme)
{
	this->Compte::solde.debiter(somme * 1.05);
	this->Compte::ajouterOperation(Operation::Operation(somme, this->Compte::numCompte, "Debit"));
}

void ComptePayant::crediter(MAD somme)
{
	this->Compte::solde.crediter(somme * 0.95);
	this->Compte::ajouterOperation(Operation::Operation(somme, this->Compte::numCompte, "Crédit"));
}

void ComptePayant::display(void) const
{
	this->Compte::consulter();
}

void ComptePayant::transferer(Compte* com, MAD somme)
{
	this->debiter(somme);
	com->crediter(somme);
}
