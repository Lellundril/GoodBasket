//
// Created by brian on 09/12/2020.
//

#include "InterfaceEntree.h"
#include <iostream>

InterfaceEntree::InterfaceEntree(Model m) {
    model = Model(m);
}

///////////////////////////////// CREATION COMPTE ///////////////////////////
/**
* Fonction permettant à l'utilisateur de créer un Compte.
*/
// Permet à l'utilisateur de créer un comtpe avec un nom et un mot de passe. Le compte une fois créé est stocké par le gestionnaire de comptes
void InterfaceEntree::creerCompte(int idType) {
    std::string pseudo, mdp, email,nom,prenom;

    std::cout << "Entrez un e-mail\n";
    std::cin >> email;
    std::cout << "Entrez un nom d'utilisateur\n";
    std::cin >> pseudo;
    std::cout << "Entrez un mot de passe\n";
    std::cin >> mdp;
    std::cout << "Entrez votre NOM\n";
    std::cin >> nom;
    std::cout << "Entrez votre prenom\n";
    std::cin >> prenom;
    model.getGestionCompte()->ajoutCompte(Compte(idType,nom,prenom,pseudo,email,mdp));
    std::cout << "Votre compte a ete cree";
    std::cout << std::endl;
    model.getInterface()->setChoixAction(0); //Retour au menu
    model.getInterface()->setChoixCompte(-1);
}



// Exécute les fonctions selon la valeur de la variable de choix (choisi pas l'utilisateur ou donné par certaines fonctions)
void InterfaceEntree::traiterChoixCompte() {
    switch (model.getInterface()->getChoixCompte()) {
        case 1:
            std::cout << "COMPTE CONSO\n" << std::endl;
            creerCompte(CONSO);
            break;
        case 2:
            std::cout << "COMPTE PROC\n" << std::endl;
            creerCompte(PROC);
            break;
        case 3:
            std::cout << "COMPTE GEST\n" << std::endl;
            creerCompte(RESPO);
            break;
        case -1:
            //quitterPlateforme();
            break;
        default: // Si l'utilisateur entre un choix  inexistant, réaffiche le menu
            std::cout << "Entrez un choix valide parmi ceux affiches\n" << std::endl;
            menuChoix();
            break;
    }
}


void InterfaceEntree::boucleCreationCompte() {
    menuChoixCompte();
    while (model.getInterface()->getChoixCompte() != -1){
        traiterChoixCompte();
    }
}

///////////////////////////// GENERAL ///////////////////////////
/**
 * Fonction traitant la valeur de @var choixAction et exécutant des fonctions selon celle-ci.
 * @see choixAction
 */
// Exécute les fonctions selon la valeur de la variable de choix (choisi pas l'utilisateur ou donné par certaines fonctions)
void InterfaceEntree::traiterChoix() {
    std::cout << &model << std::endl;
    switch (model.getInterface()->getChoixAction()) {
        case 1:
            connecterCompte();
            break;
        case 2:
            boucleCreationCompte();
            break;
        case 99:
            afficherTousLesComptes();
            break;
        case -1:
            //quitterPlateforme();
            break;
        default: // Si l'utilisateur entre un choix  inexistant, réaffiche le menu
            std::cout << "Entrez un choix valide parmi ceux affiches\n" << std::endl;
            menuChoix();
            break;
    }
}

/**
 * Fonction permettant à l'utilisateur de se connecter à un compte (existant dans le gestionnaire).
 */
// Permet à l'utilisateur de se connecter à un compte si celui-ci existe et si il renseigne le bon mot de passe
void InterfaceEntree::connecterCompte() {
    std::string pseudo, mdp;
    if (!model.getGestionCompte()->isEmpty()){ // Si aucun compte n'est connu du Gestionnaire, on renseigne l'utilisateur et rien de plus
        std::cout << "Connectez vous a votre compte" << std::endl;
        std::cout << "Nom d'utilisateur:  ";
        std::cin >> pseudo;
        std::cout << std::endl;
        try{// Block try/catch qui arrêtera la fonction si le nom de compte entré n'est pas connu du Gestionnaire
            Compte *c = model.getGestionCompte()->getCompte(pseudo);
            std::cout << "Mot de passe:  ";
            std::cin >> mdp;
            std::cout << std::endl;
            if (c->verifierMotDePasse(mdp)){ // Vérification du mot de passe entré. S'il est correct, l'utilisateur est connecté, sinon on arrête la procédure net (pour l'instant)
                model.getInterface()->setConnecte(true);
                model.setCompteConnecte(*c);
                std::cout << "Bienvenue, " << pseudo << "\n" << std::endl;
                lienCompteEntree();
            }
            else{
                std::cout << "Mot de passe incorrect" << std::endl;
            }
        }
        catch (const char* msg) {
            std::cerr << msg << std::endl;
        }
    }
    else{
        std::cout << "Aucun compte n'est enregistre" << std::endl;
    }
    model.getInterface()->setChoixAction(0); // Permet le renvoie au menu
}

/**
 * Fonction permettant à l'utilisateur de se déconnecter du Compte auquel il est connecté.
 */
// Déconnecte l'utilisateur de son compte
void InterfaceEntree::seDeconnecter() {
    std::cout << "Deconnexion..." << std::endl;
    model.getInterface()->setConnecte(false);
    model.getInterface()->setChoixAction(0);
}

/**
 * Fonction nettoyant toutes les données de la session et quittant l'application.
 */
// Permet de quitter l'application "correctement"
void InterfaceEntree::quitter() {
    std::cout << "A bientot !" << std::endl;
    exit(0);
}

/**
 * Affiche tous les comptes connus du gestionnaire de Comptes de la Console.
 */
// Affiche tous les mots de passe sous la forme:
void InterfaceEntree::afficherTousLesComptes() {
    std::cout << model.getGestionCompte()->toString() << std::endl;
    model.getInterface()->setChoixAction(0);
}

void InterfaceEntree::boucleInterfaceEntree() {
    while (model.getInterface()->getChoixAction() != -1){
        traiterChoix();
    }
    quitter();
}

void InterfaceEntree::lienCompteEntree() {
    switch(model.getCompteConnecte()->getId()){
        case CONSO:
            InterfaceConso(model).boucleInterfaceConso();
            break;
        case PROC:
            //boucleInterfaceProc();
            break;
        case RESPO:
            //boucleInterfaceRespo();
            break;
    }
}

///////////////////// GETTER AND SETTER //////////////////////







