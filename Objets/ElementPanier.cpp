//
// Created by brian on 14/12/2020.
//

#include "ElementPanier.h"

const std::string &ElementPanier::getId() const {
    return id;
}

void ElementPanier::setId(const std::string &id) {
    ElementPanier::id = id;
}

const std::string &ElementPanier::getIdProduit() const {
    return id_produit;
}

void ElementPanier::setIdProduit(const std::string &idProduit) {
    id_produit = idProduit;
}

const std::string &ElementPanier::getQuantitePrise() const {
    return quantite_prise;
}

void ElementPanier::setQuantitePrise(const std::string &quantitePrise) {
    quantite_prise = quantitePrise;
}

ElementPanier::ElementPanier() {

}

ElementPanier::ElementPanier(std::string id, std::string id_produit, std::string quantite_prise) {
    this->id = id;
    this->id_produit = id_produit;
    this->quantite_prise = quantite_prise;
}

ElementPanier::ElementPanier(std::string id) {
    std::vector<std::string> res = EcrireBDD::FindFichierElementPanier(id);
    this->id = res.at(0);
    this->id_produit = res.at(1);
    this->quantite_prise = res.at(2);
}
