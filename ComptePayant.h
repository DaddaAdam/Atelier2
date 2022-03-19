#pragma once
#include "Compte.h"
#include "CompteCourant.h"
class ComptePayant :
    public virtual Compte
{
public:
    ComptePayant();
    virtual void debiter(MAD) override;
    virtual void crediter(MAD) override;
    virtual void display(void) const override;
    virtual void transferer(Compte*, MAD) override;
};

