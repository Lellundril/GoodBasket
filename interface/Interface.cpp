//
// Created by brian on 09/12/2020.
//

#include <iostream>
#include "Interface.h"

Interface::Interface(){
    choixAction = 0;
    choixCompte = 0;
    choixConso1 = 0;
    choixConso2 = 0;
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

int Interface::getChoixProc1() const {
    return choixProc1;
}

void Interface::setChoixProc1(int choixProc1) {
    Interface::choixProc1 = choixProc1;
}

int Interface::getChoixConso1() const {
    return choixConso1;
}

void Interface::setChoixConso1(int choixConso1) {
    Interface::choixConso1 = choixConso1;
}

int Interface::getChoixRespo1() const {
    return choixRespo1;
}

void Interface::setChoixRespo1(int choixRespo1) {
    Interface::choixRespo1 = choixRespo1;
}

bool Interface::getConnecte() const{
    return connecte;
}

int Interface::getChoixConso2() const{
    return choixConso2;
}

void Interface::setChoixRespo2(int choixRespo2) {
    this->choixConso2 = choixRespo2;
}
