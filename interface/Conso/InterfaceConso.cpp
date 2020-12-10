//
// Created by brian on 09/12/2020.
//

#include <iostream>
#include <Outils/EntreeClavier.h>
#include "InterfaceConso.h"

InterfaceConso::InterfaceConso(Model m){
    model = Model(m);
}

void InterfaceConso::traiterChoixIntConso(){
    switch (model.getInterface()->getChoixConso1()) {
        case 1:
            findPCAll();
            break;
        case -1:
            seePanier();
            break;
        case -2:
            seeProfil();
            break;
        case -3:
            deconexion();
            break;
        default: // Si l'utilisateur entre un choix  inexistant, réaffiche le menu
            std::cout << "Entrez un choix valide parmi ceux affiches\n" << std::endl;
            return;
    }
};

void InterfaceConso::boucleInterfaceConso() {
    std::cout << "VOICI L'AFFICHAGE POUR UN COMPTE CONSO\n" << std::endl;
    while (model.getInterface()->getChoixConso1() != -3){
        model.getInterface()->setChoixConso1(0);
        menuChoixIntConso();
        traiterChoixIntConso();
    }
    std::cout << "ADIOS L'AMI\n" << std::endl;
}

//////////////////////////////// GETTER AND SETTER ///////////////////////



//////////////////////////////// ACTION ///////////////////////

void InterfaceConso::findPCAll() {
    std::cout << "TOUS LES PCs" << std::endl;
}

void InterfaceConso::seePanier() {
    std::cout << "TON PANIER" << std::endl;
}

void InterfaceConso::seeProfil() {
    std::cout << "TON PROFIL" << std::endl;
}

void InterfaceConso::deconexion() {
    std::cout << "DECONNEXION..." << std::endl;
}
