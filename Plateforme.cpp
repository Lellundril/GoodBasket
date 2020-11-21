//
// Created by Lellundril on 21/11/2020.
//

#include <iostream>
#include <limits>
#include <sstream>
#include "Plateforme.h"

Plateforme::Plateforme() {
    connecte = false;
    compteConnecte = nullptr;
    choixAction = 0;
    gestionnaireComptes = GestionnaireComptes();
}

Plateforme::~Plateforme() {

}

void Plateforme::demarrer() {
    std::cout << "Bienvenue sur GoodBasket" << std::endl;
    // Tant que l'utilisateur n'a pas voulu sortir, on traite la variable de choix
    while (choixAction != -1){
        traiterChoix();
    }
}

bool Plateforme::estConnecte() {
    return connecte;
}

bool Plateforme::estConsommateur() {
    return false;
}

bool Plateforme::estProducteur() {
    return false;
}

bool Plateforme::estPDC() {
    return false;
}

// Présente et donne à l'utilisateur l'accès aux différentes interactions avec le système
void Plateforme::menuChoix() {
    if (connecte){ // Si l'utilisateur est connecté, on lui informe, et avec quel compte
        std::cout << "Vous etes connecte avec " << compteConnecte->getNomUtilisateur();
    }
    // Liste des choix d'actions
    std::cout<<".......................\n";
    std::cout<<"Entrez votre choix:  \n";
    std::cout<<"1. Se connecter\n";
    std::cout<<"2. Creer un compte\n";
    std::cout<<"3. Afficher tous les comptes\n";
    std::cout<<"-1. Quitter";
    std::cout<<".........................."<<std::endl;
    std::cin >> choixAction;

    //Si l'entrée n'est pas un nombre
    while(!std::cin) // ou si (cin.fail())
    {
        std::cin.clear(); // reset failbit
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignorer l'entrée incorrecte
        // Ensuite, redemander une entrée
        std::cout << "Vous devez entrez un nombre" << std::endl;
        std::cin >> choixAction;
    }
}

// Éxecute les fonctions selon la valeur de la variable de choix (choisi pas l'utilisateur ou donné par certaines fonctions)
void Plateforme::traiterChoix() {
    switch (choixAction) {
        case 1:
            connecterCompte();
            break;
        case 2:
            creerCompte();
            connecterCompte();
            break;
        case 3:
            afficherTousLesComptes();
            break;
        case -1:
            quitterPlateforme();
            break;
        default:
            menuChoix();
            break;
    }
}

// Permet à l'utilisateur de créer un comtpe avec un nom et un mot de passe. Le compte une fois créé est stocké par le gestionnaire de comptes
void Plateforme::creerCompte() {
    std::string nom, mdp;
    std::cout << "Entrez un nom d'utilisateur\n";
    std::cin >> nom;
    std::cout << "Entrez un mot de passe\n";
    std::cin >> mdp;
    gestionnaireComptes.ajouterCompte(Compte(nom, mdp));
    std::cout << "Votre compte a ete cree";
    std::cout << std::endl;
    choixAction = 2;
}

// Permet à l'utilisateur de se connecter à un compte si celui-ci existe et si il renseigne le bon mot de passe
void Plateforme::connecterCompte() {
    std::string nom, mdp;
    if (!gestionnaireComptes.estVide()){ // Si aucun compte n'est connu du Gestionnaire, on renseigne l'utilisateur et rien de plus
        std::cout << "Connectez vous a votre compte" << std::endl;
        std::cout << "Nom d'utilisateur: ";
        std::cin >> nom;
        std::cout << std::endl;
        try{// Block try/catch qui arrêtera la fonction si le nom de compte entré n'est pas connu du Gestionnaire
            Compte* c = gestionnaireComptes.getCompte(nom);
            std::cout << "Mot de passe: ";
            std::cin >> mdp;
            std::cout << std::endl;
            if (c->verifierMotDePasse(mdp)){ // Vérification du mot de passe entré. S'il est correct, l'utilisateur est connecté, sinon on arrête la procédure net (pour l'instant)
                connecte = true;
                compteConnecte = c;
                std::cout << "Bienvenue, " << nom << " !" << std::endl;
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
        std::cout << "Aucun compte n'est disponible" << std::endl;
    }
    choixAction = 0; // Permet le renvoie au menu
}

void Plateforme::seDeconnecter() {

}

void Plateforme::consulterListePDC() {

}

void Plateforme::consulterPDC(int index) {

}

void Plateforme::consulterPaniers() {

}

void Plateforme::consulterAbonnements() {

}

void Plateforme::consulterPagesVitrines() {

}

void Plateforme::definirPageVitrine() {

}

void Plateforme::creerPageVitrine() {

}

void Plateforme::ajouterProduit() {

}

void Plateforme::supprimerPrdouit() {

}

void Plateforme::modifierProduit() {

}

void Plateforme::supprimerPageVitrine() {

}

void Plateforme::consulterFournisseurs() {

}

void Plateforme::lancerCycleVente() {

}

void Plateforme::arreterCycleVente() {

}

void Plateforme::retourMenu() {

}

// Permet de quitter l'application "correctement"
void Plateforme::quitterPlateforme() {
    std::cout << "A bientot !" << std::endl;
    exit(0);
}

// Affiche tous les mots de passe sous la forme "nom ; motDePasse" *à la ligne*
void Plateforme::afficherTousLesComptes() {
    std::cout << gestionnaireComptes.toString() << std::endl;
    choixAction = 0;
}
