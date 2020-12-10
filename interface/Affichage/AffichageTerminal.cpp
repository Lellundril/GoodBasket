//
// Created by brian on 09/12/2020.
//

#include <interface/InterfaceEntree.h>
#include <iostream>
#include "AffichageTerminal.h"
#include <Outils/EntreeClavier.h>

// Présente et donne à l'utilisateur l'accès aux différentes interactions avec le système
void InterfaceEntree::menuChoixCompte() {
    model.getInterface()->setChoixCompte(0);
    // Liste des choix d'actions
    std::cout << ".......................\n";
    std::cout << "Entrez votre choix:  \n";
    std::cout << ".......................\n";
    // Choix disponibles si déconnecté
    std::cout << "1. Creer un compte consommateur\n";
    std::cout << "2. Creer un compte producteur\n";
    std::cout << "3. Creer un compte gestionnaire\n";
    //Choix disponibles tout le temps
    std::cout << "-1. Retour\n";
    std::cout << ".........................." << std::endl;
    model.getInterface()->setChoixCompte(entrerChoixNumerique());
    std::cout << model.getInterface()->getChoixCompte() << std::endl;
}

/**
 * Fonction affichant un menu de choix listant tout ce que l'utilisateur peut faire.
 * Ce menu change en fonction des circonstances. Par exemple, un utilisateur connecté avec
 * un compte Consommateur n'aura pas les mêmes choix que s'il est connecté à un compte Point de Collecte.
 */
// Présente et donne à l'utilisateur l'accès aux différentes interactions avec le système
void InterfaceEntree::menuChoix() {
    model.getInterface()->setChoixAction(0);
    // Liste des choix d'actions
    std::cout << ".......................\n";
    std::cout << "Entrez votre choix:  \n";
    std::cout << ".......................\n";
    // Choix disponibles si déconnecté
    std::cout << "1. Se connecter\n";
    std::cout << "2. Creer un compte\n";
    //Choix disponibles tout le temps
    std::cout << "99. Afficher tous les comptes\n"; //DEBUG
    std::cout << "-1. Quitter\n";
    std::cout << ".........................." << std::endl;
    model.getInterface()->setChoixAction(entrerChoixNumerique());
    std::cout << model.getInterface()->getChoixAction() << std::endl;
}

void InterfaceConso::menuChoixIntConso() {
    // Liste des choix d'actions
    std::cout << ".......................\n";
    std::cout << "Entrez votre choix:  \n";
    std::cout << ".......................\n";
    // Choix disponibles si déconnecté
    std::cout << "1. Chercher un point de collecte \n";
    std::cout << "2. \n";
    //Choix disponibles tout le temps
    std::cout << "-1. Voir son panier\n";
    std::cout << "-2. Voir son profil\n";
    std::cout << "-3. Se deconnecter\n";
    std::cout << ".........................." << std::endl;
    model.getInterface()->setChoixConso1(entrerChoixNumerique());
    std::cout << model.getInterface()->getChoixConso1() << std::endl;
}