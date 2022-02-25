#pragma once
#include "MAD.h"
#include "Date.h"
#include <iostream>
class Operation
{
private:
	static int nbrOperations;
	int numero;
	std::string nature;
	MAD montant;
	int libelle;
	Date date;

public:
	Operation(MAD, int, std::string);
	void display(void) const;
};

