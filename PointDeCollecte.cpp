//
// Created by Lellundril on 22/11/2020.
//

#include "PointDeCollecte.h"

bool PointDeCollecte::estPDC() {
    return true;
}

PointDeCollecte::PointDeCollecte(const std::string &nomUtilisateur, const std::string &motDePasse) : Compte(
        nomUtilisateur, motDePasse) {}

std::string PointDeCollecte::getTypeString() {
    return "Point de collecte";
}
