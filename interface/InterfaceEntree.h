//
// Created by brian on 09/12/2020.
//

#ifndef GOODBASKET_INTERFACEENTREE_H
#define GOODBASKET_INTERFACEENTREE_H

#include "Interface.h"
#include "Compte/GestionnaireCompte.h"
#include "Conso/InterfaceConso.h"
#include "Proc/InterfaceProc.h"
#include "Respo/InterfaceRespo.h"
#include "Model.h"

class InterfaceEntree{
private:
    Model model;
public:
    InterfaceEntree(Model m);
    void menuChoix();
    void menuChoixCompte();
    void traiterChoixCompte();
    void traiterChoix();
    void creerCompte(int id);
    void connecterCompte();
    void seDeconnecter();
    void afficherTousLesComptes();
    void quitter();

    void boucleInterfaceEntree();
    void boucleCreationCompte();
    void lienCompteEntree();


    const Model &getModel() const;

    void setModel(const Model &model);
};

#endif //GOODBASKET_INTERFACEENTREE_H
