#pragma once
#include "Compte.h"
#include "CompteCourant.h"
#include "MAD.h"
class CompteEpargne :
    public Compte
{
private:
    double tauxInteret;
    CompteCourant* source;
public:
    CompteEpargne();
    void crediter(MAD) override;
    void debiter(MAD) override;
    void assignerSource(CompteCourant*);
    void modifierTauxInteret(const double);
    void display(void) const;
    void transferer(Compte*, MAD) override;
    void calculInteret(void);
};

