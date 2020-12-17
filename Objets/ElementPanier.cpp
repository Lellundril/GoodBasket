//
// Created by brian on 14/12/2020.
//

#include "ElementPanier.h"

/**
 * Getter
 * @return valeur
 */
const std::string &ElementPanier::getId() const {
    return id;
}

/**
 * Setter
 * @param Nouvelle valeur
 */
void ElementPanier::setId(const std::string &id) {
    ElementPanier::id = id;
}

/**
 * Getter
 * @return valeur
 */
const std::string &ElementPanier::getIdProduit() const {
    return id_produit;
}

/**
 * Setter
 * @param Nouvelle valeur
 */
void ElementPanier::setIdProduit(const std::string &idProduit) {
    id_produit = idProduit;
}

/**
 * Getter
 * @return valeur
 */
const std::string &ElementPanier::getQuantitePrise() const {
    return quantite_prise;
}

/**
 * Setter
 * @param Nouvelle valeur
 */
void ElementPanier::setQuantitePrise(const std::string &quantitePrise) {
    quantite_prise = quantitePrise;
}

/**
 * Constructeur vide
 */
ElementPanier::ElementPanier() {

}

/**
 *  Constructeur à partir des infos
 * @param id : nouveau id
 * @param id_produit : nouveau id
 * @param quantite_prise : nouvell quantite
 */
ElementPanier::ElementPanier(std::string id, std::string id_produit, std::string quantite_prise) {
    this->id = id;
    this->id_produit = id_produit;
    this->quantite_prise = quantite_prise;
}

/**
 * Constructeur qui fouille dans la BDD à la recherche
 * @param id de recherche
 */
ElementPanier::ElementPanier(std::string id) {
    std::vector<std::string> res = ReadBDD::FindFichierElementPanier(id);
    this->id = res.at(0);
    this->id_produit = res.at(1);
    this->quantite_prise = res.at(2);
}

/**
 * Conevrtit l'objet dans les normes de la BDD
 * @return string en ligne
 */
std::string ElementPanier::toBDD() {
    std::string nouv;
    nouv.append(this->id);
    nouv.append("<");
    nouv.append(this->id_produit);
    nouv.append("<");
    nouv.append(this->quantite_prise);
    return nouv;
}
