//
// Created by Lellundril on 22/11/2020.
//

#ifndef GOODBASKET_POINTDECOLLECTE_H
#define GOODBASKET_POINTDECOLLECTE_H


#include "Compte.h"

/**
 * @brief La classe PointDeCollecte définit un Compte de type "point de collecte".
 *
 * @author Guillaume LETZELTER
 */
class PointDeCollecte : public Compte{
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
    PointDeCollecte(const std::string &nomUtilisateur, const std::string &motDePasse);

    /**
     * Fonction renvoyant vrai car le Compte est un compte Point De Collecte.
     * @return vrai.
     */
    bool estPDC() override;

    std::string getTypeString() override;
};


#endif //GOODBASKET_POINTDECOLLECTE_H
