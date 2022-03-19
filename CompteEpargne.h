#pragma once
#include "Compte.h"
#include "CompteCourant.h"
#include "MAD.h"
class CompteEpargne :
    public virtual Compte
{
private:
    double tauxInteret;
    CompteCourant* source;
public:
    CompteEpargne();
    virtual void crediter(MAD) override;
    virtual void debiter(MAD) override;
    void assignerSource(CompteCourant*);
    void modifierTauxInteret(const double);
    virtual void display(void) const;
    virtual void transferer(Compte*, MAD) override;
    void calculInteret(void);
};

