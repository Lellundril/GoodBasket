//
// Created by brian on 14/12/2020.
//

#include "Compte.h"

Compte::Compte(std::string nom,std::string prenom,std::string pseudo,std::string email,std::string mdp,std::string type) {
    this->nom = nom;
    this->prenom = prenom;
    this->pseudo = pseudo;
    this->email = email;
    this->mdp = mdp;
    this->type = type;
}

Compte::Compte() {
}

Compte::Compte(std::string email) {
std::vector<std::string> res = ReadBDD::FindFichierCompte(email);
    this->email = res.at(0);
    this->nom = res.at(1);
    this->prenom = res.at(2);
    this->type = res.at(3);
    this->mdp = res.at(4);
    this->pseudo = res.at(5);
}

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

const std::string &Compte::getType() const{
    return type;
}

void Compte::setType(const std::string &type) {
    Compte::type = type;
}

bool Compte::estConso() {
    if(type == "CONSO"){
        return true;
    }
    return false;
}

bool Compte::estProd() {
    if(type == "PROC"){
        return true;
    }
    return false;
}

bool Compte::estRespo() {
    if(type == "RESPO"){
        return true;
    }
    return false;
}

std::string Compte::toBDD(){
    std::string nouv;
    nouv.append(this->email);
    nouv.append("<");
    nouv.append(this->nom);
    nouv.append("<");
    nouv.append(this->prenom);
    nouv.append("<");
    nouv.append(this->type);
    nouv.append("<");
    nouv.append(this->mdp);
    nouv.append("<");
    nouv.append(this->pseudo);
    return nouv;
}
