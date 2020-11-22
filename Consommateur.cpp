//
// Created by Lellundril on 22/11/2020.
//

#include "Consommateur.h"

bool Consommateur::estConsommateur() {
    return true;
}

Consommateur::Consommateur(const std::string &nomUtilisateur, const std::string &motDePasse) : Compte(nomUtilisateur,
                                                                                                      motDePasse) {}

std::string Consommateur::getTypeString() {
    return "Consommateur";
}


