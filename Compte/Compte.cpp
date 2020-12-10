//
// Created by brian on 09/12/2020.
//

#include <iostream>
#include "Compte.h"

const std::string &Compte::getEmail() const {
    return email;
}

void Compte::setEmail(const std::string &email) {
    Compte::email = email;
}

const std::string &Compte::getMdp() const {
    return mdp;
}

void Compte::setMdp(const std::string &mdp) {
    Compte::mdp = mdp;
}

const std::string &Compte::getPseudo() const {
    return pseudo;
}

void Compte::setPseudo(const std::string &pseudo) {
    Compte::pseudo = pseudo;
}

const std::string &Compte::getNom() const {
    return nom;
}

void Compte::setNom(const std::string &nom) {
    Compte::nom = nom;
}

const std::string &Compte::getPrenom() const {
    return prenom;
}

void Compte::setPrenom(const std::string &prenom) {
    Compte::prenom = prenom;
}



Compte::Compte(int id,std::string nom,std::string prenom,std::string pseudo,std::string email,std::string mdp) {
    this->nom = nom;
    this->prenom = prenom;
    this->pseudo = pseudo;
    this->email = email;
    this->mdp = mdp;
    this->id = id;
    switch (id) {
        case CONSO:
            std::cout <<"COMPTE CONSO"<< std::endl;
            break;
        case PROC:
            std::cout <<"COMPTE PROC"<< std::endl;
            break;
        case RESPO:
            std::cout <<"COMPTE RESPO"<< std::endl;
            break;
        default:
            std::cout <<"ERRRRRRRRRRRRRRRRRRRRRRRRRRROR"<< std::endl;
            break;
    }
}

Compte::Compte() {
}

bool Compte::verifierMotDePasse(std::string passe){
    if(mdp.compare(passe) == 0){
        return true;
    }
    return false;
}

int Compte::getId() const {
    return id;
}

void Compte::setId(int id) {
    this->id = id;
}
