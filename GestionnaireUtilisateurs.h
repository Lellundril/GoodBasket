//
// Created by Lellundril on 21/11/2020.
//

#ifndef GOODBASKET_GESTIONNAIREUTILISATEURS_H
#define GOODBASKET_GESTIONNAIREUTILISATEURS_H


#include <vector>
#include <map>
#include "Utilisateur.h"

/**
 * @brief La classe GestionnaireUtilisateurs permet le stockage et la gestion efficace des multiples Comptes.
 *
 * @author Guillaume LETZELTER
 */
class GestionnaireUtilisateurs {
private:
    ///@brief une map contenant les Comptes, avec comme clé leur nom d'utilisateur.
    std::map<std::string, Utilisateur*> comptes;
public:
    ///@brief Le constructeur par défaut ne fait rien.
    GestionnaireUtilisateurs();

    /**
     * @brief Cette fonction permet d'ajouter un Compte dans le Gestionnaire.
     *
     * @see comptes.
     */
    void ajouterUtilisateur(Utilisateur*);

    /**
     * Cette fonction renvoie le compte correspondant au nom d'utilisateur donné en paramètre.
     * @return le Compte correspondant au nom d'utilisateur entré.
     */
    Utilisateur* getUtilisateur(std::string);

    /**
     * Cette fonction permet de savoir si le Gestionnaire ne connaît aucun Compte
     * @return vrai si il n'y a aucun Compte, faux sinon
     */
    bool estVide();

    /**
     * Cette fonction renvoie une liste de chaque Compte contenu dans le Gestionnaire
     * et ses attributs sous forme de chaîne de caractères C++
     *
     * @return liste de tous les comptes connus du Gestionnaire.
     */
    std::string toString();
};


#endif //GOODBASKET_GESTIONNAIREUTILISATEURS_H
