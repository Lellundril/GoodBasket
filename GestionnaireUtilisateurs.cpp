//
// Created by Lellundril on 21/11/2020.
//

#include <sstream>
#include "GestionnaireUtilisateurs.h"

GestionnaireUtilisateurs::GestionnaireUtilisateurs() {

}

std::string GestionnaireUtilisateurs::toString() {
    std::stringstream str;
    if (estVide()){
        str << "Il n'y a aucun compte  afficher\n";
    }
    else {
        std::map<std::string, Utilisateur*>::iterator it;
        for (it = comptes.begin(); it != comptes.end(); it++) {
            str << "(" << it->second->getNomUtilisateur() << " ; " << it->second->getMotDePasse() << ") : \n";
        }
    }
    return str.str();
}

void GestionnaireUtilisateurs::ajouterUtilisateur(Utilisateur* u) {
    comptes.emplace(u->getNomUtilisateur(), u);
}

bool GestionnaireUtilisateurs::estVide() {
    return comptes.empty();
}

Utilisateur* GestionnaireUtilisateurs::getUtilisateur(std::string nom) {
    std::map<std::string, Utilisateur*>::iterator it;
    it = comptes.find(nom);
    if (it == comptes.end()){
        throw "Compte inexistant";
    }
    return it->second;
}