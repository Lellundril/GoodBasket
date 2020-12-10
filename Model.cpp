//
// Created by lellundril on 08/12/2020.
//

#include "Model.h"

Model::Model(){
    compteConnecte = Compte();
    interface = Interface();
}

GestionnaireCompte *Model::getGestionCompte(){
    return &gestionnaireCompte;
}

void Model::setGestionCompte(GestionnaireCompte g) {
    gestionnaireCompte = g;
}

Compte *Model::getCompteConnecte(){
    return &compteConnecte;
}

void Model::setCompteConnecte(Compte c) {
    compteConnecte = c;
}

void Model::setInterface(Interface i) {
    interface = i;
}

Interface *Model::getInterface() {
    return &interface;
}
