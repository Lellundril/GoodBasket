//
// Created by lellundril on 08/12/2020.
//

#include "Model.h"

Model::Model(){
    compteConnecte = Compte();
    interface = Interface();
}

GestionnaireCompte Model::getGestionCompte() const {
    return gestionnaireCompte;
}

void Model::setGestionCompte(GestionnaireCompte g) {
    gestionnaireCompte = g;
}

Compte Model::getCompteConnecte() const{
    return compteConnecte;
}

void Model::setCompteConnecte(Compte c) {
    compteConnecte = c;
}

Interface Model::getInterface() const{
    return interface;
}

void Model::setInterface(Interface i) {
    interface = i;
}
