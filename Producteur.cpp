//
// Created by Lellundril on 22/11/2020.
//

#include "Producteur.h"

bool Producteur::estProducteur() {
    return true;
}

Producteur::Producteur(const std::string &nomUtilisateur, const std::string &motDePasse) : Compte(nomUtilisateur,
                                                                                                  motDePasse) {}

std::string Producteur::getTypeString() {
    return "Producteur";
}
