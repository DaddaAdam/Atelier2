// Atelier2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Date.h"
#include "CompteCourant.h"
#include "Client.h"
#include "MAD.h"
#include "CompteEpargne.h"
#include <list>

int main()
{
    CompteCourant c1;
    CompteCourant c2(MAD::MAD(1000), MAD::MAD(800));
    Client* Adam = new Client("Adam", "Dadda");

    c1.assignerProprietaire(Adam);
    c2.assignerProprietaire(Adam);
    c1.crediter(MAD::MAD(5000));
    c1.transferer(&c2, MAD::MAD(2000));
    c1.display();
    c1.consulter();
    std::cout << "*****************************************" << std::endl;
    c2.transferer(&c1, MAD::MAD(6000));
    std::cout << "*****************************************" << std::endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
