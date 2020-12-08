//
// Created by lellundril on 08/12/2020.
//

#ifndef GOODBASKET_MODEL_H
#define GOODBASKET_MODEL_H


class Model {
    //TODO: Le Modèle connaît le compte connecté ainsi que le gestionnaire d'utilisateurs.
    //TODO: C'est le même Modèle que dans le modèle MVC qu'on a vu (pour Twisk, Model était la classe Monde)
    /*
    private:
    ///@brief Cette variable stocke le Compte auquel l'utilisateur est connecté.
    Compte* compteConnecte;
    ///@brief Cette variable contrôle quels fonctions de l'application vont être executées. Souvent choisie par l'utilisateur.
    int choixAction;
    ///@brief Il s'agit du gestionnaire de Comptes de l'application.
    GestionnaireComptes gestionnaireComptes;
     */

    // PEUT ETRE NON NECESSAIRE
    /**
     * @brief Fonction permettant de démarrer la boucle du programme.
     */
    void demarrer();

    /**
     * Fonction testant si l'utilisateur est connecté à un Compte.
     * @return vrai si il est connecté, faux sinon.
     */
    bool estConnecte();


};


#endif //GOODBASKET_MODEL_H
