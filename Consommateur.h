//
// Created by Lellundril on 22/11/2020.
//

#ifndef GOODBASKET_CONSOMMATEUR_H
#define GOODBASKET_CONSOMMATEUR_H


#include "Compte.h"

/**
 * @brief La classe Consommateur définit un Compte de type "consommateur".
 *
 * @author Guillaume LETZELTER
 */
class Consommateur : public Compte{
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
    Consommateur(const std::string &nomUtilisateur, const std::string &motDePasse);

    /**
     * Fonction renvoyant vrai car le Compte est un compte Consommateur.
     * @return vrai
     */
    bool estConsommateur() override;

    std::string getTypeString() override;
};


#endif //GOODBASKET_CONSOMMATEUR_H
