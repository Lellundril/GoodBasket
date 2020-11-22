//
// Created by Lellundril on 22/11/2020.
//

#ifndef GOODBASKET_POINTDECOLLECTE_H
#define GOODBASKET_POINTDECOLLECTE_H


#include "Compte.h"

class PointDeCollecte : public Compte{
private:
public:
    PointDeCollecte(const std::string &nomUtilisateur, const std::string &motDePasse);

    bool estPDC() override;

    std::string getTypeString() override;
};


#endif //GOODBASKET_POINTDECOLLECTE_H
