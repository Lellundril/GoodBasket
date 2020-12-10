//
// Created by brian on 09/12/2020.
//

#ifndef GOODBASKET_INTERFACECONSO_H
#define GOODBASKET_INTERFACECONSO_H

#include "Model.h"

class InterfaceConso{
private:
    Model model;
public:
    InterfaceConso(Model m);
    void boucleInterfaceConso();

    void menuChoixIntConso();
    void traiterChoixIntConso();

    void findPCAll();

    void seePanier();

    void seeProfil();

    void deconexion();
};

#endif //GOODBASKET_INTERFACECONSO_H
