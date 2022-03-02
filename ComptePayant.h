#pragma once
#include "Compte.h"
#include "CompteCourant.h"
class ComptePayant :
    public Compte, public CompteCourant
{
public:
    ComptePayant();
    void debiter(MAD) override;
    void crediter(MAD) override;
    void display(void) const override;
    void transferer(Compte*, MAD) override;
};

