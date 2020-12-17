//
// Created by brian on 14/12/2020.
//

#ifndef GOODBASKET_PRODUIT_H
#define GOODBASKET_PRODUIT_H

#include "General.h"
#include "BaseDeDonnee/ReadBDD.h"

class Produit {
private:
    std::string id, nom_produit,prix,quantite,est_kilo,image;
public:
    Produit();
    Produit( std::string id,std::string nom_produit,std::string prix,std::string quantite, std::string est_kilo,std::string image);
    Produit(std::string id);

    const std::string &getId() const;

    void setId(const std::string &id);

    const std::string &getNomProduit() const;

    void setNomProduit(const std::string &nomProduit);

    const std::string &getPrix() const;

    void setPrix(const std::string &prix);

    const std::string &getQuantite() const;

    void setQuantite(const std::string &quantite);

    const std::string &getEstKilo() const;

    void setEstKilo(const std::string &estKilo);

    const std::string &getImage() const;

    void setImage(const std::string &image);

    std::string toBDD();
};


#endif //GOODBASKET_PRODUIT_H
