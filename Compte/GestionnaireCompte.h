//
// Created by brian on 09/12/2020.
//

#ifndef GOODBASKET_GESTIONNAIRECOMPTE_H
#define GOODBASKET_GESTIONNAIRECOMPTE_H
#include <vector>  //for std::vector
#include <string>  //for std::string
#include "Compte.h"

class GestionnaireCompte {
private:
    std::vector<Compte>comptes;
public:
    GestionnaireCompte();
    const std::vector<Compte> &getComptes() const;

    void setComptes(const std::vector<Compte> &comptes);

    void ajoutCompte(Compte c);

    bool isEmpty();
    std::string toString();
    Compte getCompte(std::string pseudo);
    Compte getCompteId(int id);
    int getId(std::string pseudo);
};


#endif //GOODBASKET_GESTIONNAIRECOMPTE_H
