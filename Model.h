//
// Created by lellundril on 08/12/2020.
//

#ifndef GOODBASKET_MODEL_H
#define GOODBASKET_MODEL_H

#include "Compte/GestionnaireCompte.h"
#include "Compte/Compte.h"
#include "interface/Interface.h"

class Model {
private:
    GestionnaireCompte gestionnaireCompte;
    Compte compteConnecte;
    Interface interface;
public:
    Model();
    GestionnaireCompte getGestionCompte() const;
    void setGestionCompte(GestionnaireCompte g);
    Compte getCompteConnecte() const;
    void setCompteConnecte(Compte c);
    Interface getInterface() const;
    void setInterface(Interface i);
};


#endif //GOODBASKET_MODEL_H
