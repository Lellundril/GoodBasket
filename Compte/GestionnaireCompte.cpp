//
// Created by brian on 09/12/2020.
//

#include <iostream>
#include "GestionnaireCompte.h"

GestionnaireCompte::GestionnaireCompte(){
}

const std::vector<Compte> &GestionnaireCompte::getComptes() const {
    return comptes;
}

void GestionnaireCompte::setComptes(const std::vector<Compte> &comptes) {
    GestionnaireCompte::comptes = comptes;
}

void GestionnaireCompte::ajoutCompte(Compte c) {
comptes.push_back(c);
}

bool GestionnaireCompte::isEmpty() {
    return getComptes().empty();
}

std::string GestionnaireCompte::toString() {
    std::string s = "";
    int i =0;
    for (std::vector<Compte>::iterator it = comptes.begin() ; it != comptes.end(); ++it){
        std::cout << i << std::endl;
        s = s + "" +it->getNom()+" "+it->getPrenom()+"\n\tmdp : "+it->getMdp()+"\n\tpseudo : "+it->getPseudo()+"\n\temail : "+it->getEmail()+"\n";
        i++;
    }
    return s;
}

Compte *GestionnaireCompte::getCompte(std::string pseudo) {
    int i=0;
    for (std::vector<Compte>::iterator it = comptes.begin() ; it != comptes.end(); ++it){
        if(it->getPseudo().compare(pseudo) == 0){
            return &comptes.at(i);
        }
        i++;
    }
}

Compte GestionnaireCompte::getCompteId(int id) {
    int i=0;
    for (std::vector<Compte>::iterator it = comptes.begin() ; it != comptes.end(); ++it){
        if(i==id){
            return comptes.at(i);
        }
        i++;
    }
}

int GestionnaireCompte::getId(std::string pseudo) {
    int i=0;
    for (std::vector<Compte>::iterator it = comptes.begin() ; it != comptes.end(); ++it){
        if(it->getPseudo().compare(pseudo) == 0){
            return i;
        }
        i++;
    }
}

