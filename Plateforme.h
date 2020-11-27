//
// Created by Lellundril on 21/11/2020.
//

#ifndef GOODBASKET_PLATEFORME_H
#define GOODBASKET_PLATEFORME_H

#include "GestionnaireComptes.h"

/**
 * @brief La classe Plateforme est la classe centrale de l'application.
 * C'est par cette classe que toutes les opérations sont effectuées.
 *
 * @author Guillaume LETZELTER
 */
class Plateforme{
private:
    ///@brief Cette variable booléenne permet de savoir si l'utilisateur actuel est connecté à un Compte.
    bool connecte;
    ///@brief Cette variable stocke le Compte auquel l'utilisateur est connecté.
    Compte* compteConnecte;
    ///@brief Cette variable contrôle quels fonctions de l'application vont être executées. Souvent choisie par l'utilisateur.
    int choixAction;
    ///@brief Il s'agit du gestionnaire de Comptes de l'application.
    GestionnaireComptes gestionnaireComptes;

public:

    /**
     * @brief Le constructeur initialise toutes les données de la Plateforme
     */
    Plateforme();

    /**
     * @brief Le destructeur nettoie toutes les données.
     */
    ~Plateforme();

    /**
     * @brief Fonction permettant de démarrer la boucle du programme.
     */
    void demarrer();

    /**
     * Fonction testant si l'utilisateur est connecté à un Compte.
     * @return vrai si il est connecté, faux sinon.
     */
    bool estConnecte();

    /**
     * Fonction affichant un menu de choix listant tout ce que l'utilisateur peut faire.
     * Ce menu change en fonction des circonstances. Par exemple, un utilisateur connecté avec
     * un compte Consommateur n'aura pas les mêmes choix que s'il est connecté à un compte Point de Collecte.
     */
    void menuChoix();

    /**
     * Fonction traitant la valeur de @var choixAction et exécutant des fonctions selon celle-ci.
     * @see choixAction
     */
    void traiterChoix();

    /**
     * Fonction renvoyant un nombre entier renvoyé par l'utilisateur.
     * @return un nombre donné par l'utilisateur.
     */
    int entrerChoixNumerique();

    /**
     * Affiche tous les comptes connus du gestionnaire de Comptes de la Plateforme.
     */
    void afficherTousLesComptes();

    //Fonctions Comptes
    /**
     * Fonction permettant à l'utilisateur de créer un Compte.
     */
    void creerCompte();

    /**
     * Fonction permettant à l'utilisateur de se connecter à un compte (existant dans le gestionnaire).
     */
    void connecterCompte();

    /**
     * Fonction permettant à l'utilisateur de se déconnecter du Compte auquel il est connecté.
     */
    void seDeconnecter();

    //Fonctions Consommateur
    /**
     * Fonction permettant au Consommateur de consulter la liste des Points de Collecte disponibles.
     */
    void consulterListePDC();

    /**
     * Fonction permettant au Consommateur de consulter un Point De Collecte sélectionné.
     * @param index l'indice du Point de collecte sélectionné
     */
    void consulterPDC(int index);

    /**
     * Fonction permettant au Consommateur de consulter ses paniers.
     */
    void consulterPaniers();

    /**
     * Fonction permettant au Consommateur de consulter les Point de Collectes auxquels il est abonnés.
     */
    void consulterAbonnements();

    //Fonction Producteur
    /**
     * Fonction permettant au producteur de consulter ses pages-vitrines.
     */
    void consulterPagesVitrines();

    /**
     * Fonction permettant au producteur de définir la page-vitrine qui sera mise en avant.
     */
    void definirPageVitrine();

    /**
     * Fonction permettant au producteur de créer une nouvelle Page-Vitrine.
     */
    void creerPageVitrine();

    /**
     * Fonction permettant au producteur d'ajouter un produit dans la Page-Vitrine.
     */
    void ajouterProduit();

    /**
     * Fonction permettant au producteur de supprimer un produit de la Page-Vitrine.
     */
    void supprimerPrdouit();

    /**
     * Fonction permettant au producteur de modifier un produit (quantité, prix) de la Page-Vitrine.
     */
    void modifierProduit();

    /**
     * Fonction permettant au producteur de supprimer une Page-Vitrine.
     */
    void supprimerPageVitrine();

    //Fonction PDC
    /**
     * Fonction permettant au Point de Collecte de consulter la liste des producteurs.
     */
    void consulterProducteurs();

    /**
     * Fonction permettant au Point de Collecte de démarrer un cycle de vente.
     */
    void lancerCycleVente();

    /**
     * Fonction permettant au Point de Collecte d'arrêter un cycle de vente.
     */
    void arreterCycleVente();


    /**
     * Fonction renvoyant l'utilisateur au menu principal.
     */
    void retourMenu();

    /**
     * Fonction nettoyant toutes les données de la session et quittant l'application.
     */
    void quitterPlateforme();
};

#endif //GOODBASKET_PLATEFORME_H
