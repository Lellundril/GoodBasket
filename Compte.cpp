//
// Created by Lellundril on 21/11/2020.
//

#include "Compte.h"

//Créer un comtpe avec un nom d'utilisateur et un mot de passe
Compte::Compte(std::string nom, std::string mdp) {
    nomUtilisateur = nom;
    motDePasse = mdp;
}

// Vérifie la validité du mot de passe. Vrai si correct, faux sinon
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
