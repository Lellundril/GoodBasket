//
// Created by brian on 16/12/2020.
//

#ifndef GOODBASKET_WRITEBDD_H
#define GOODBASKET_WRITEBDD_H

#include "General.h"
#include "Objets/GeneralObjet.h"

class WriteBDD {
private:
   // void suppr(std::string nomFichier);

    void AjoutCommunFichier(std::string nomFichier, std::string nouv,std::vector<std::string> x );
public:
    void FichierCompteAjout(Compte c);

    void FichierCycleAjout(Cycle c);

    void FichierElementPanierAjout(ElementPanier e);

    void FichierPageAjout(Page p);

    void FichierPagesProposeesPcAjout(PagesProposeesPC p);

    void FichierPanierAjout(Panier p);

    void FichierPcAjout(PC p);

    void FichierProduitAjout(Produit p);

    std::vector<std::string> ReccupInfoFichierAjout(std::string url);

   // void supprAll();
};


#endif //GOODBASKET_WRITEBDD_H
