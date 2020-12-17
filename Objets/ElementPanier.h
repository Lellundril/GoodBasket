//
// Created by brian on 14/12/2020.
//

#ifndef GOODBASKET_ELEMENTPANIER_H
#define GOODBASKET_ELEMENTPANIER_H

#include "General.h"
#include "BaseDeDonnee/ReadBDD.h"

class ElementPanier {
private:
    std::string id, id_produit, quantite_prise;
public:
    ElementPanier();
    ElementPanier(std::string id,std::string id_produit,std::string quantite_prise);
    ElementPanier(std::string id);

    const std::string &getId() const;

    void setId(const std::string &id);

    const std::string &getIdProduit() const;

    void setIdProduit(const std::string &idProduit);

    const std::string &getQuantitePrise() const;

    void setQuantitePrise(const std::string &quantitePrise);

    std::string toBDD();
};


#endif //GOODBASKET_ELEMENTPANIER_H
