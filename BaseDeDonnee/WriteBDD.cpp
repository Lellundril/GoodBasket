//
// Created by brian on 16/12/2020.
//

#include "WriteBDD.h"

void WriteBDD::AjoutCommunFichier(std::string nomFichier, std::string nouv, std::vector<std::string> x ){
    std::ofstream monFlux;
    std::string ligne;
    monFlux.open(nomFichier.c_str(),std::ios::out);

    if(monFlux.is_open())  //On teste si tout est OK
    {
        for(int i = 0; i<x.size(); i++){
            std::cout << x.at(i) << std::endl;
            monFlux << x.at(i) << std::endl;
        }
        monFlux << nouv << std::endl;
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

void WriteBDD::FichierCompteAjout(Compte c){
    std::cout << "ola" << std::endl;
    std::vector<std::string> x = ReadBDD::ReccupInfoFichierSuppr(R"(Ressources\BDD\Compte.txt)",99999);
    std::cout << "ola" << std::endl;
    std::string nouv = c.toBDD();
    std::cout << "ola" << std::endl;
    std::string nomFichier(ReadBDD::getAbsolutePath(R"(Ressources\BDD\Compte.txt)"));
    std::cout << "ola" << std::endl;
    AjoutCommunFichier(nomFichier,nouv,x);
}

void WriteBDD::FichierCycleAjout(Cycle c){
    std::vector<std::string> x = ReadBDD::ReccupInfoFichierSuppr(R"(Ressources\BDD\Cycle.txt)",99999);
    std::string nouv = c.toBDD();
    std::string nomFichier(ReadBDD::getAbsolutePath(R"(Ressources\BDD\Cycle.txt)"));
    AjoutCommunFichier(nomFichier,nouv,x);
}

void WriteBDD::FichierElementPanierAjout(ElementPanier e){
    std::vector<std::string> x = ReadBDD::ReccupInfoFichierSuppr(R"(Ressources\BDD\Element_panier.txt)",99999);
    std::string nouv = e.toBDD();
    std::string nomFichier(ReadBDD::getAbsolutePath(R"(Ressources\BDD\Element_panier.txt)"));
    AjoutCommunFichier(nomFichier,nouv,x);
}

void WriteBDD::FichierPageAjout(Page p){
    std::vector<std::string> x = ReadBDD::ReccupInfoFichierSuppr(R"(Ressources\BDD\Page.txt)",99999);
    std::string nouv = p.toBDD();
    std::string nomFichier(ReadBDD::getAbsolutePath(R"(Ressources\BDD\Page.txt)"));
    AjoutCommunFichier(nomFichier,nouv,x);
}

void WriteBDD::FichierPagesProposeesPcAjout(PagesProposeesPC p){
    std::vector<std::string> x = ReadBDD::ReccupInfoFichierSuppr(R"(Ressources\BDD\Pages_proposees_pc.txt)",99999);
    std::string nouv = p.toBDD();
    std::string nomFichier(ReadBDD::getAbsolutePath(R"(Ressources\BDD\Pages_proposees_pc.txt)"));
    AjoutCommunFichier(nomFichier,nouv,x);
}

void WriteBDD::FichierPanierAjout(Panier p){
    std::vector<std::string> x = ReadBDD::ReccupInfoFichierSuppr(R"(Ressources\BDD\Panier.txt)",99999);
    std::string nouv = p.toBDD();
    std::string nomFichier(ReadBDD::getAbsolutePath(R"(Ressources\BDD\Panier.txt)"));
    AjoutCommunFichier(nomFichier,nouv,x);
}

void WriteBDD::FichierPcAjout(PC p){
    std::vector<std::string> x = ReadBDD::ReccupInfoFichierSuppr(R"(Ressources\BDD\Pc.txt)",99999);
    std::string nouv = p.toBDD();
    std::string nomFichier(ReadBDD::getAbsolutePath(R"(Ressources\BDD\Pc.txt)"));
    AjoutCommunFichier(nomFichier,nouv,x);
}

void WriteBDD::FichierProduitAjout(Produit p){
    std::vector<std::string> x = ReadBDD::ReccupInfoFichierSuppr(R"(Ressources\BDD\Produit.txt)",99999);
    std::string nouv = p.toBDD();
    std::string nomFichier(ReadBDD::getAbsolutePath(R"(Ressources\BDD\Produit.txt)"));
    AjoutCommunFichier(nomFichier,nouv,x);
}

