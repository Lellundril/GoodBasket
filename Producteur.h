//
// Created by Lellundril on 22/11/2020.
//

#ifndef GOODBASKET_PRODUCTEUR_H
#define GOODBASKET_PRODUCTEUR_H


#include "Compte.h"

/**
 * @brief La classe Producteur définit un Compte de type "producteur".
 *
 * @author Guillaume LETZELTER
 */
class Producteur : public Compte {
private:
public:
    /**
     * @brief Le constructeur permet de remplir les champs de la classe en
     * fonctions des paramètres passés.
     *
     * @param nomUtilisateur le nom d'utilisateur du compte.
     * @param motDePasse le mot de passe du compte.
     *
     * @see nomUtilisateur, motDePasse.
     */
    Producteur(const std::string &nomUtilisateur, const std::string &motDePasse);

    /**
     * Fonction renvoyant vrai car le Compte est un compte Producteur.
     * @return vrai.
     */
    bool estProducteur() override;

    std::string getTypeString() override;
};


#endif //GOODBASKET_PRODUCTEUR_H
