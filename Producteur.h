//
// Created by Lellundril on 22/11/2020.
//

#ifndef GOODBASKET_PRODUCTEUR_H
#define GOODBASKET_PRODUCTEUR_H


#include "Compte.h"

class Producteur : public Compte {
private:
public:
    Producteur(const std::string &nomUtilisateur, const std::string &motDePasse);

    bool estProducteur() override;

    std::string getTypeString() override;
};


#endif //GOODBASKET_PRODUCTEUR_H
