//
// Created by lellundril on 08/12/2020.
//

#ifndef GOODBASKET_PRODUIT_H
#define GOODBASKET_PRODUIT_H


#include <string>

class Produit {
    /**
     * @brief Identifiant unique du produit
     */
    int id;

    /**
     * @brief Nom du produit : chaîne de caractères C++
     */
    std::string nom;

    /**
     * @brief Prix du produit
     */
    float prix;

    /**
     * @brief Booléen déterminant si le produit se vend à l'unité ou au kilogramme
     */
    bool unitaire;


};


#endif //GOODBASKET_PRODUIT_H
