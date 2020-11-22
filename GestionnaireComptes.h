//
// Created by Lellundril on 21/11/2020.
//

#ifndef GOODBASKET_GESTIONNAIRECOMPTES_H
#define GOODBASKET_GESTIONNAIRECOMPTES_H


#include <vector>
#include <map>
#include "Compte.h"

class GestionnaireComptes {
private:
    std::map<std::string, Compte*> comptes;
public:
    GestionnaireComptes();

    void ajouterCompte(Compte*);
    Compte* getCompte(std::string);

    bool estVide();

    std::string toString();
};


#endif //GOODBASKET_GESTIONNAIRECOMPTES_H
