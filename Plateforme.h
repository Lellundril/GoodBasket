//
// Created by Lellundril on 21/11/2020.
//

#ifndef GOODBASKET_PLATEFORME_H
#define GOODBASKET_PLATEFORME_H

#include "GestionnaireComptes.h"

class Plateforme{
private:
    bool connecte;
    Compte* compteConnecte;
    int choixAction;
    GestionnaireComptes gestionnaireComptes;

public:
    Plateforme();
    ~Plateforme();

    //Fonctions générales
    void demarrer();
    //Vrai si l'utilisateur est connecté à un compte
    bool estConnecte();
    //Vrai si l'utilisateur est Consommateur
    bool estConsommateur();
    //Vrai si l'utilisateur est Producteur
    bool estProducteur();
    //Vrai si l'utilisateur est PointDeCollecte
    bool estPDC();

    //Affiche et donne accès aux différentes interactions possibles
    void menuChoix();
    void traiterChoix();
    void afficherTousLesComptes();

    //Fonction compte
    void creerCompte();
    void connecterCompte();
    void seDeconnecter();

    //Fonction Consommateur
    void consulterListePDC();
    void consulterPDC(int index);
    void consulterPaniers();
    void consulterAbonnements();

    //Fonction Producteur
    void consulterPagesVitrines();
    void definirPageVitrine();
    void creerPageVitrine();
    void ajouterProduit();
    void supprimerPrdouit();
    void modifierProduit();
    void supprimerPageVitrine();

    //Fonction PDC
    void consulterFournisseurs();
    void lancerCycleVente();
    void arreterCycleVente();


    //Fonction de retour au Menu principale
    void retourMenu();

    //Fonction quitter
    void quitterPlateforme();
};

#endif //GOODBASKET_PLATEFORME_H
