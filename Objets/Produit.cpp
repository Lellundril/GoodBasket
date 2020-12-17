//
// Created by brian on 14/12/2020.
//

#include "Produit.h"

Produit::Produit() {

}

Produit::Produit(std::string id, std::string nom_produit, std::string prix, std::string quantite, std::string est_kilo,
                 std::string image) {
    this->id = id;
    this->nom_produit = nom_produit;
    this->prix = prix;
    this->quantite = quantite;
    this->est_kilo = est_kilo;
    this->image = image;
}

Produit::Produit(std::string id) {
    std::vector<std::string> res = ReadBDD::FindFichierProduit(id);
    this->id = res.at(0);
    this->nom_produit = res.at(1);
    this->prix = res.at(2);
    this->quantite = res.at(3);
    this->est_kilo = res.at(4);
    this->image = res.at(5);
}

const std::string &Produit::getId() const {
    return id;
}

void Produit::setId(const std::string &id) {
    Produit::id = id;
}

const std::string &Produit::getNomProduit() const {
    return nom_produit;
}

void Produit::setNomProduit(const std::string &nomProduit) {
    nom_produit = nomProduit;
}

const std::string &Produit::getPrix() const {
    return prix;
}

void Produit::setPrix(const std::string &prix) {
    Produit::prix = prix;
}

const std::string &Produit::getQuantite() const {
    return quantite;
}

void Produit::setQuantite(const std::string &quantite) {
    Produit::quantite = quantite;
}

const std::string &Produit::getEstKilo() const {
    return est_kilo;
}

void Produit::setEstKilo(const std::string &estKilo) {
    est_kilo = estKilo;
}

const std::string &Produit::getImage() const {
    return image;
}

void Produit::setImage(const std::string &image) {
    Produit::image = image;
}

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
