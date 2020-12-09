//
// Created by brian on 09/12/2020.
//

#include "Compte.h"
#include "CompteConso.h"
#include "CompteProc.h"
#include "CompteRespo.h"

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

            break;
        case PROC:

            break;
        case RESPO:

            break;
    }
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
    Compte::id = id;
}

/*bool Compte::estRespo() {
    return false;
}

bool Compte::estProc() {
    return false;
}

bool Compte::estConso() {
    return false;
}*/
