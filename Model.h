//
// Created by lellundril on 08/12/2020.
//

#ifndef GOODBASKET_MODEL_H
#define GOODBASKET_MODEL_H

#include "Ancien/Compte/GestionnaireCompte.h"
#include "Ancien/Compte/Compte.h"
#include "Ancien/interface/Interface.h"

class Model {
private:
    GestionnaireCompte gestionnaireCompte;
    Compte compteConnecte;
    Interface interface;
public:
    Model();
    GestionnaireCompte *getGestionCompte();
    void setGestionCompte(GestionnaireCompte g);
    Compte *getCompteConnecte();
    void setCompteConnecte(Compte c);
    Interface *getInterface();
    void setInterface(Interface i);
};


#endif //GOODBASKET_MODEL_H
