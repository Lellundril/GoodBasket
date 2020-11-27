//
// Created by Lellundril on 21/11/2020.
//

#include "Compte.h"

Compte::Compte(const std::string &nomUtilisateur, const std::string &motDePasse) : nomUtilisateur(nomUtilisateur),
                                                                                   motDePasse(motDePasse) {}


bool Compte::verifierMotDePasse(std::string mdp) {
    return motDePasse.compare(mdp) == 0;
}

const std::string &Compte::getNomUtilisateur() const {
    return nomUtilisateur;
}

void Compte::setNomUtilisateur(const std::string &nomUtilisateur) {
    Compte::nomUtilisateur = nomUtilisateur;
}

const std::string &Compte::getMotDePasse() const {
    return motDePasse;
}

void Compte::setMotDePasse(const std::string &motDePasse) {
    Compte::motDePasse = motDePasse;
}

bool Compte::estConsommateur() {
    return false;
}

bool Compte::estProducteur() {
    return false;
}

bool Compte::estPDC() {
    return false;
}

std::string Compte::getTypeString() {
    return "Compte";
}
