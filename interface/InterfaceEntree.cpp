//
// Created by brian on 09/12/2020.
//

#include "InterfaceEntree.h"
#include <iostream>
#include <Outils/EntreeClavier.h>

InterfaceEntree::InterfaceEntree() {
    interface = Interface();
    idCompteCo = -1;
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

    gestionnaireCompte.ajoutCompte(Compte(idType,nom,prenom,pseudo,email,mdp));

    std::cout << "Votre compte a ete cree";
    std::cout << std::endl;
    interface.setChoixAction(0); //Retour au menu
    interface.setChoixCompte(-1);
}

// Présente et donne à l'utilisateur l'accès aux différentes interactions avec le système
void InterfaceEntree::menuChoixCompte() {
    interface.setChoixCompte(0);
    // Liste des choix d'actions
    std::cout << ".......................\n";
    std::cout << "Entrez votre choix:  \n";
    // Choix disponibles si déconnecté
    std::cout << "1. Creer un compte consommateur\n";
    std::cout << "2. Creer un compte producteur\n";
    std::cout << "3. Creer un compte gestionnaire\n";
    //Choix disponibles tout le temps
    std::cout << "-1. Retour";
    std::cout << ".........................." << std::endl;
    interface.setChoixCompte(entrerChoixNumerique());
}

// Exécute les fonctions selon la valeur de la variable de choix (choisi pas l'utilisateur ou donné par certaines fonctions)
void InterfaceEntree::traiterChoixCompte() {
    switch (interface.getChoixCompte()) {
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
    while (interface.getChoixCompte() != -1){
        traiterChoixCompte();
    }
}

///////////////////////////// GENERAL ///////////////////////////

/**
 * Fonction affichant un menu de choix listant tout ce que l'utilisateur peut faire.
 * Ce menu change en fonction des circonstances. Par exemple, un utilisateur connecté avec
 * un compte Consommateur n'aura pas les mêmes choix que s'il est connecté à un compte Point de Collecte.
 */
// Présente et donne à l'utilisateur l'accès aux différentes interactions avec le système
void InterfaceEntree::menuChoix() {
    interface.setChoixAction(0);
    // Liste des choix d'actions
    std::cout << ".......................\n";
    std::cout << "Entrez votre choix:  \n";
    // Choix disponibles si déconnecté
    std::cout << "1. Se connecter\n";
    std::cout << "2. Creer un compte\n";
    //Choix disponibles tout le temps
    std::cout << "99. Afficher tous les comptes\n"; //DEBUG
    std::cout << "-1. Quitter";
    std::cout << ".........................." << std::endl;
    interface.setChoixAction(entrerChoixNumerique());
}

/**
 * Fonction traitant la valeur de @var choixAction et exécutant des fonctions selon celle-ci.
 * @see choixAction
 */
// Exécute les fonctions selon la valeur de la variable de choix (choisi pas l'utilisateur ou donné par certaines fonctions)
void InterfaceEntree::traiterChoix() {
    switch (interface.getChoixAction()) {
        case 1:
            connecterCompte();
            break;
        case 2:
            boucleCreationCompte();
            break;
        case 3:
            seDeconnecter();
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
    if (!gestionnaireCompte.isEmpty()){ // Si aucun compte n'est connu du Gestionnaire, on renseigne l'utilisateur et rien de plus
        std::cout << "Connectez vous a votre compte" << std::endl;
        std::cout << "Nom d'utilisateur:  ";
        std::cin >> pseudo;
        std::cout << std::endl;
        try{// Block try/catch qui arrêtera la fonction si le nom de compte entré n'est pas connu du Gestionnaire
            Compte c = gestionnaireCompte.getCompte(pseudo);
            std::cout << "Mot de passe:  ";
            std::cin >> mdp;
            std::cout << std::endl;
            if (c.verifierMotDePasse(mdp)){ // Vérification du mot de passe entré. S'il est correct, l'utilisateur est connecté, sinon on arrête la procédure net (pour l'instant)
                interface.setConnecte(true);
                idCompteCo = gestionnaireCompte.getId(pseudo);
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
    interface.setChoixAction(0); // Permet le renvoie au menu
}

/**
 * Fonction permettant à l'utilisateur de se déconnecter du Compte auquel il est connecté.
 */
// Déconnecte l'utilisateur de son compte
void InterfaceEntree::seDeconnecter() {
    std::cout << "Deconnexion..." << std::endl;
    interface.setConnecte(false);
    interface.setChoixAction(0);
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
    std::cout << gestionnaireCompte.toString() << std::endl;
    interface.setChoixAction(0);
}

const Interface &InterfaceEntree::getAnInterface() const {
    return interface;
}

void InterfaceEntree::boucleInterfaceEntree() {
    while (getAnInterface().getChoixAction() != -1){
        traiterChoix();
    }
    std::cout << "ADIOS L'AMI\n" << std::endl;
    quitter();
}

void InterfaceEntree::lienCompteEntree() {
    switch(gestionnaireCompte.getCompteId(idCompteCo).getId()){
        case CONSO:
            //boucleInterfaceConso();
            break;
        case PROC:
            //boucleInterfaceProc();
            break;
        case RESPO:
            //boucleInterfaceRespo();
            break;
    }
}





