//
// Created by Lellundril on 21/11/2020.
//

#include <sstream>
#include "GestionnaireComptes.h"

GestionnaireComptes::GestionnaireComptes() {

}

std::string GestionnaireComptes::toString() {
    std::stringstream str;
    if (estVide()){
        str << "Il n'y a aucun compte  afficher\n";
    }
    else {
        std::map<std::string, Compte*>::iterator it;
        for (it = comptes.begin(); it != comptes.end(); it++) {
            str << "(" << it->second->getNomUtilisateur() << " ; " << it->second->getMotDePasse() << ") : " << it->second->getTypeString() << "\n";
        }
    }
    return str.str();
}

void GestionnaireComptes::ajouterCompte(Compte* c) {
    comptes.emplace(c->getNomUtilisateur(), c);
}

bool GestionnaireComptes::estVide() {
    return comptes.empty();
}

Compte* GestionnaireComptes::getCompte(std::string nom) {
    std::map<std::string, Compte*>::iterator it;
    it = comptes.find(nom);
    if (it == comptes.end()){
        throw "Compte inexistant";
    }
    return it->second;
}