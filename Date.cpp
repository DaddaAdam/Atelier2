#include "Date.h"
#include <iostream>
#include <ctime>
using namespace std;

//Sans parametres: on initialise à la date d'aujourd'hui
Date::Date(void)
{
	int temp;
	time_t jour;
	time(&jour);

	int current = (int)jour;

	this->annee = 1970 + current / 31557600;

	temp = current - (this->annee-1970) * 31557600;

	this->mois =  temp / 2628000;

	this->jour =  1 + (temp - this->mois * 2628000) / 86400;

	this->mois++;
}

Date::Date(int jour, int mois, int annee)
{
	this->jour = jour;
	this->mois = mois;
	this->annee = annee;
}

void Date::display(void) const
{
	cout << jour << "/" << mois << "/" << annee << endl;
}
