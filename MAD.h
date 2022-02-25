#pragma once
class MAD
{
private:
	double montant;

public:
	MAD(void);
	MAD(double);
	void crediter(const double);
	void crediter(const MAD);
	void debiter(const MAD);
	void debiter(const double);
	void display(void) const;
	bool isDebitable(const MAD, const MAD) const;
};

