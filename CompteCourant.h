#pragma once
#include "Compte.h"
#include "MAD.h"
class CompteCourant :
    public Compte
{
private:
    MAD decouvert;
public:
    CompteCourant();
    CompteCourant(MAD, MAD);
    void crediter(MAD) override;
    void debiter(MAD) override;
    void display(void) const override;
    void transferer(Compte *, MAD) override;
};

