//
// Created by brian on 16/12/2020.
//

#include "WriteBDD.h"

std::vector<std::string> WriteBDD::ReccupInfoFichierAjout(std::string url){
    std::cout << "temp" << std::endl;
    std::string nomFichier(ReadBDD::getAbsolutePath(url));
    std::ifstream monFlux;
    std::vector<std::string> x;
    std::string ligne;
    monFlux.open(nomFichier.c_str(),std::ios::in);
    if(monFlux.is_open())  //On teste si tout est OK
    {
        while (getline (monFlux, ligne)) {
            if(!ligne.empty()){
                x.push_back(ligne);
            }
        }
        return x;
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

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
    std::vector<std::string> x = ReccupInfoFichierAjout(R"(Ressources\BDD\Compte.txt)");
    std::cout << "ola" << std::endl;
    std::string nouv = c.toBDD();
    std::cout << "ola" << std::endl;
    std::string nomFichier(ReadBDD::getAbsolutePath(R"(Ressources\BDD\Compte.txt)"));
    std::cout << "ola" << std::endl;
    AjoutCommunFichier(nomFichier,nouv,x);
}

void WriteBDD::FichierCycleAjout(Cycle c){
    std::vector<std::string> x = ReccupInfoFichierAjout(R"(Ressources\BDD\Cycle.txt)");
    std::string nouv = c.toBDD();
    std::string nomFichier(ReadBDD::getAbsolutePath(R"(Ressources\BDD\Cycle.txt)"));
    AjoutCommunFichier(nomFichier,nouv,x);
}

void WriteBDD::FichierElementPanierAjout(ElementPanier e){
    std::vector<std::string> x = ReccupInfoFichierAjout(R"(Ressources\BDD\Element_panier.txt)");
    std::string nouv = e.toBDD();
    std::string nomFichier(ReadBDD::getAbsolutePath(R"(Ressources\BDD\Element_panier.txt)"));
    AjoutCommunFichier(nomFichier,nouv,x);
}

void WriteBDD::FichierPageAjout(Page p){
    std::vector<std::string> x = ReccupInfoFichierAjout(R"(Ressources\BDD\Page.txt)");
    std::string nouv = p.toBDD();
    std::string nomFichier(ReadBDD::getAbsolutePath(R"(Ressources\BDD\Page.txt)"));
    AjoutCommunFichier(nomFichier,nouv,x);
}

void WriteBDD::FichierPagesProposeesPcAjout(PagesProposeesPC p){
    std::vector<std::string> x = ReccupInfoFichierAjout(R"(Ressources\BDD\Pages_proposees_pc.txt)");
    std::string nouv = p.toBDD();
    std::string nomFichier(ReadBDD::getAbsolutePath(R"(Ressources\BDD\Pages_proposees_pc.txt)"));
    AjoutCommunFichier(nomFichier,nouv,x);
}

void WriteBDD::FichierPanierAjout(Panier p){
    std::vector<std::string> x = ReccupInfoFichierAjout(R"(Ressources\BDD\Panier.txt)");
    std::string nouv = p.toBDD();
    std::string nomFichier(ReadBDD::getAbsolutePath(R"(Ressources\BDD\Panier.txt)"));
    AjoutCommunFichier(nomFichier,nouv,x);
}

void WriteBDD::FichierPcAjout(PC p){
    std::vector<std::string> x = ReccupInfoFichierAjout(R"(Ressources\BDD\Pc.txt)");
    std::string nouv = p.toBDD();
    std::string nomFichier(ReadBDD::getAbsolutePath(R"(Ressources\BDD\Pc.txt)"));
    AjoutCommunFichier(nomFichier,nouv,x);
}

void WriteBDD::FichierProduitAjout(Produit p){
    std::vector<std::string> x = ReccupInfoFichierAjout(R"(Ressources\BDD\Produit.txt)");
    std::string nouv = p.toBDD();
    std::string nomFichier(ReadBDD::getAbsolutePath(R"(Ressources\BDD\Produit.txt)"));
    AjoutCommunFichier(nomFichier,nouv,x);
}

//////////////////////////////////////////////////////

void WriteBDD::suppr(std::string nomFichier) {
    std::ofstream monFlux;
    std::string ligne;
    monFlux.open(nomFichier.c_str(),std::ios::out);

    if(monFlux.is_open())  //On teste si tout est OK
    {
        monFlux.close();
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

void WriteBDD::supprAll() {
    std::string nomFichier(ReadBDD::getAbsolutePath(R"(Ressources\BDD\Produit.txt)"));
    suppr(nomFichier);
    nomFichier = ReadBDD::getAbsolutePath(R"(Ressources\BDD\Pc.txt)");
    suppr(nomFichier);
    nomFichier = ReadBDD::getAbsolutePath(R"(Ressources\BDD\Panier.txt)");
    suppr(nomFichier);
    nomFichier = ReadBDD::getAbsolutePath(R"(Ressources\BDD\Pages_proposees_pc.txt)");
    suppr(nomFichier);
    nomFichier = ReadBDD::getAbsolutePath(R"(Ressources\BDD\Page.txt)");
    suppr(nomFichier);
    nomFichier = ReadBDD::getAbsolutePath(R"(Ressources\BDD\Element_panier.txt)");
    suppr(nomFichier);
    nomFichier = ReadBDD::getAbsolutePath(R"(Ressources\BDD\Cycle.txt)");
    suppr(nomFichier);
    nomFichier = ReadBDD::getAbsolutePath(R"(Ressources\BDD\Compte.txt)");
    suppr(nomFichier);
}

