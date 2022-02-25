#include "MAD.h"
#include <iostream>

MAD::MAD(void)
{
	this->montant = 0.0;
}

MAD::MAD(double montant)
{
	this->montant = montant;
}

void MAD::crediter(const double nouveau)
{
	this->montant += nouveau;
}

void MAD::crediter(const MAD somme)
{
	this->montant += somme.montant;
}

void MAD::debiter(const MAD somme)
{
	this->montant -= somme.montant;
}

void MAD::debiter(const double somme)
{
	this->montant -= somme;
}

void MAD::display(void) const
{
	std::cout << this->montant << " DH" << std::endl;
}

bool MAD::isDebitable(const MAD somme, const MAD decouvert) const
{
	return this->montant - somme.montant >= decouvert.montant;
}
