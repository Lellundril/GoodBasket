//
// Created by brian on 09/12/2020.
//

#ifndef GOODBASKET_INTERFACEENTREE_H
#define GOODBASKET_INTERFACEENTREE_H

#include "Interface.h"
#include "Compte/GestionnaireCompte.h"

class InterfaceEntree{
private:
    int idCompteCo;
    Interface interface;
    GestionnaireCompte gestionnaireCompte;
public:
    InterfaceEntree();
    void menuChoix();
    void menuChoixCompte();
    void traiterChoixCompte();
    void traiterChoix();
    void creerCompte(int id);
    void connecterCompte();
    void seDeconnecter();
    void afficherTousLesComptes();
    const Interface &getAnInterface() const;
    void quitter();

    void boucleInterfaceEntree();
    void boucleCreationCompte();
    void lienCompteEntree();
};

#endif //GOODBASKET_INTERFACEENTREE_H
