#include "CompteEpargnePayant.h"

CompteEpargnePayant::CompteEpargnePayant()
{
}

void CompteEpargnePayant::crediter(MAD somme)
{
	this->ComptePayant::crediter(somme);
}

void CompteEpargnePayant::debiter(MAD somme)
{
	this->ComptePayant::debiter(somme);
}

void CompteEpargnePayant::display(void) const
{
	this->ComptePayant::display();
	this->CompteEpargne::display();
}

void CompteEpargnePayant::transferer(Compte* c, MAD somme)
{
	this->CompteEpargne::transferer(c, somme * 1.05);
}
