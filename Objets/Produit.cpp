//
// Created by brian on 14/12/2020.
//

#include "Produit.h"

/**
 * Constructeur vide
 */
Produit::Produit() {

}

/**
 * Constructeur à partir des infos
 * @param id : nouveau id
 * @param nom_produit : nouveau nom
 * @param prix : nouveau prix
 * @param quantite : nouvelle quantite
 * @param est_kilo : nouveau bool
 * @param image : nouveau url de l'image
 */
Produit::Produit(std::string id, std::string nom_produit, std::string prix, std::string quantite, std::string est_kilo,
                 std::string image) {
    this->id = id;
    this->nom_produit = nom_produit;
    this->prix = prix;
    this->quantite = quantite;
    this->est_kilo = est_kilo;
    this->image = image;
}

/**
 * Constructeur qui fouille dans la BDD à la recherche
 * @param id de recherche
 */
Produit::Produit(std::string id) {
    std::vector<std::string> res = ReadBDD::FindFichierProduit(id);
    this->id = res.at(0);
    this->nom_produit = res.at(1);
    this->prix = res.at(2);
    this->quantite = res.at(3);
    this->est_kilo = res.at(4);
    this->image = res.at(5);
}

/**
 * Getter
 * @return valeur
 */
const std::string &Produit::getId() const {
    return id;
}

/**
 * Setter
 * @param Nouvelle valeur
 */
void Produit::setId(const std::string &id) {
    Produit::id = id;
}

/**
 * Getter
 * @return valeur
 */
const std::string &Produit::getNomProduit() const {
    return nom_produit;
}

/**
 * Setter
 * @param Nouvelle valeur
 */
void Produit::setNomProduit(const std::string &nomProduit) {
    nom_produit = nomProduit;
}

/**
 * Getter
 * @return valeur
 */
const std::string &Produit::getPrix() const {
    return prix;
}

/**
 * Setter
 * @param Nouvelle valeur
 */
void Produit::setPrix(const std::string &prix) {
    Produit::prix = prix;
}

/**
 * Getter
 * @return valeur
 */
const std::string &Produit::getQuantite() const {
    return quantite;
}

/**
 * Setter
 * @param Nouvelle valeur
 */
void Produit::setQuantite(const std::string &quantite) {
    Produit::quantite = quantite;
}

/**
 * Getter
 * @return valeur
 */
const std::string &Produit::getEstKilo() const {
    return est_kilo;
}

/**
 * Setter
 * @param Nouvelle valeur
 */
void Produit::setEstKilo(const std::string &estKilo) {
    est_kilo = estKilo;
}

/**
 * Getter
 * @return valeur
 */
const std::string &Produit::getImage() const {
    return image;
}

/**
 * Setter
 * @param Nouvelle valeur
 */
void Produit::setImage(const std::string &image) {
    Produit::image = image;
}

/**
 * Conevrtit l'objet dans les normes de la BDD
 * @return string en ligne
 */
std::string Produit::toBDD() {

    //id_produit<nom_produit<prix<quantite<est_kilo<image

    std::string nouv;
    nouv.append(this->id);
    nouv.append("<");
    nouv.append(this->nom_produit);
    nouv.append("<");
    nouv.append(this->prix);
    nouv.append("<");
    nouv.append(this->quantite);
    nouv.append("<");
    nouv.append(this->est_kilo);
    nouv.append("<");
    nouv.append(this->image);
    return nouv;
}
