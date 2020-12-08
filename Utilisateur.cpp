//
// Created by lellundril on 08/12/2020.
//

#include "Utilisateur.h"

Utilisateur::Utilisateur(const std::string &nomUtilisateur, const std::string &motDePasse, const std::string &email)
        : nomUtilisateur(nomUtilisateur), motDePasse(motDePasse), email(email) {}

bool Utilisateur::verifierMotDePasse(std::string mdp) {
    return motDePasse.compare(mdp) == 0;
}

const std::string &Utilisateur::getNomUtilisateur() const {
    return nomUtilisateur;
}

void Utilisateur::setNomUtilisateur(const std::string &nomUtilisateur) {
    Utilisateur::nomUtilisateur = nomUtilisateur;
}

const std::string &Utilisateur::getMotDePasse() const {
    return motDePasse;
}

void Utilisateur::setMotDePasse(const std::string &motDePasse) {
    Utilisateur::motDePasse = motDePasse;
}

bool Utilisateur::estAdmin() {
    return admin;
}

bool Utilisateur::estProducteur() {
    return producteur;
}

bool Utilisateur::estPDC() {
    return pdc;
}

const std::string &Utilisateur::getEmail() const {
    return email;
}

void Utilisateur::setEmail(const std::string &email) {
    Utilisateur::email = email;
}

void Utilisateur::setAdmin(bool admin) {
    Utilisateur::admin = admin;
}

void Utilisateur::setPdc(bool pdc) {
    Utilisateur::pdc = pdc;
}

void Utilisateur::setProducteur(bool producteur) {
    Utilisateur::producteur = producteur;
}
