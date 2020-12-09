//
// Created by brian on 09/12/2020.
//

#include <iostream>
#include "Interface.h"

Interface::Interface(){
    choixAction = 0;
    choixCompte = 0;
    choixConso1 = 0;
    choixProc1 = 0;
    choixRespo1 = 0;
    connecte = false;
}

int Interface::getChoixAction() const {
    return choixAction;
}

void Interface::setChoixAction(int choixActio) {
    choixAction = choixActio;
}

int Interface::getChoixCompte() const {
    return choixCompte;
}

void Interface::setChoixCompte(int choixCompt) {
    choixCompte = choixCompt;
}

bool Interface::isConnecte() const {
    return connecte;
}

void Interface::setConnecte(bool connect) {
    connecte = connect;
}
