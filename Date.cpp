#include "Date.h"
#include <iostream>
#include <ctime>
using namespace std;

//Sans parametres: on initialise à la date d'aujourd'hui
Date::Date(void)
{
	int temp;
	time_t current;
	time(&current);

	this->annee = 1970 + current / 31557600;

	temp = current - (this->annee-1970) * 31557600;


	this->mois = temp / 2628000;

	this->jour = (temp - this->mois * 2628000) / 86400;
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
