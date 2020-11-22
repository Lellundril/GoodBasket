//
// Created by Lellundril on 22/11/2020.
//

#ifndef GOODBASKET_CONSOMMATEUR_H
#define GOODBASKET_CONSOMMATEUR_H


#include "Compte.h"

class Consommateur : public Compte{
private:
public:
    Consommateur(const std::string &nomUtilisateur, const std::string &motDePasse);

    bool estConsommateur() override;

    std::string getTypeString() override;
};


#endif //GOODBASKET_CONSOMMATEUR_H
