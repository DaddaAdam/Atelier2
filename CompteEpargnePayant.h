#pragma once
#include "ComptePayant.h"
#include "CompteEpargne.h"

class CompteEpargnePayant :
    public ComptePayant, public CompteEpargne
{

public:
    CompteEpargnePayant();
    void crediter(MAD) override;
    void debiter(MAD) override;
    void display(void) const;
    void transferer(Compte*, MAD) override;
};

