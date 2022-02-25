#pragma once
#include "Compte.h"
#include "MAD.h"
class CompteCourant :
    public Compte
{
private:
    MAD decouvert;
public:
    void display(void) const override;
    void crediter(MAD) override;
    void debiter(MAD) override;
    void transferer(Compte *, MAD) override;
    void consulter(void) const override;
    void ajouterOperation(const Operation) override;
};

