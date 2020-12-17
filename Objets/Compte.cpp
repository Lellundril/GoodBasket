//
// Created by brian on 14/12/2020.
//

#include "Compte.h"

/**
 * Constructeur à partir des infos
 * @param nom : nouveau nom
 * @param prenom : nouveau prenom
 * @param pseudo : nouveau pseudo
 * @param email : nouveau email
 * @param mdp : nouveau mdp
 * @param type : nouveau type
 */
Compte::Compte(std::string nom,std::string prenom,std::string pseudo,std::string email,std::string mdp,std::string type) {
    this->nom = nom;
    this->prenom = prenom;
    this->pseudo = pseudo;
    this->email = email;
    this->mdp = mdp;
    this->type = type;
}

/**
 * Constructeur vide
 */
Compte::Compte() {
}

/**
 * Constructeur qui fouille dans la BDD à la recherche
 * @param email : id de recherche
 */
Compte::Compte(std::string email) {
std::vector<std::string> res = ReadBDD::FindFichierCompte(email);
    this->email = res.at(0);
    this->nom = res.at(1);
    this->prenom = res.at(2);
    this->type = res.at(3);
    this->mdp = res.at(4);
    this->pseudo = res.at(5);
}

/**
 * Getter
 * @return valeur
 */
const std::string &Compte::getEmail() const {
    return email;
}

/**
 * Setter
 * @param Nouvelle valeur
 */
void Compte::setEmail(const std::string &email) {
    Compte::email = email;
}

/**
 * Getter
 * @return valeur
 */
const std::string &Compte::getMdp() const {
    return mdp;
}

/**
 * Setter
 * @param Nouvelle valeur
 */
void Compte::setMdp(const std::string &mdp) {
    Compte::mdp = mdp;
}

/**
 * Getter
 * @return valeur
 */
const std::string &Compte::getPseudo() const {
    return pseudo;
}

/**
 * Setter
 * @param Nouvelle valeur
 */
void Compte::setPseudo(const std::string &pseudo) {
    Compte::pseudo = pseudo;
}

/**
 * Getter
 * @return valeur
 */
const std::string &Compte::getNom() const {
    return nom;
}

/**
 * Setter
 * @param Nouvelle valeur
 */
void Compte::setNom(const std::string &nom) {
    Compte::nom = nom;
}

/**
 * Getter
 * @return valeur
 */
const std::string &Compte::getPrenom() const {
    return prenom;
}

/**
 * Setter
 * @param Nouvelle valeur
 */
void Compte::setPrenom(const std::string &prenom) {
    Compte::prenom = prenom;
}

/**
 * Getter
 * @return valeur
 */
const std::string &Compte::getType() const{
    return type;
}

/**
 * Setter
 * @param Nouvelle valeur
 */
void Compte::setType(const std::string &type) {
    Compte::type = type;
}

/**
 * Verifie si le compte est conso
 * @return bool
 */
bool Compte::estConso() {
    if(type == "CONSO"){
        return true;
    }
    return false;
}

/**
 * Verifie si le compte est producteur
 * @return bool
 */
bool Compte::estProd() {
    if(type == "PROC"){
        return true;
    }
    return false;
}

/**
 * Verifie si le compte est respo
 * @return bool
 */
bool Compte::estRespo() {
    if(type == "RESPO"){
        return true;
    }
    return false;
}

/**
 * Conevrtit l'objet dans les normes de la BDD
 * @return string en ligne
 */
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
