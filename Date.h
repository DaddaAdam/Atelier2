#pragma once
class Date
{
private:
	int jour, mois, annee;

public:
	Date(void);
	Date(int, int, int);
	void display(void) const;
};

