//
// Created by brian on 10/12/2020.
//

#include <iostream>
#include "InterfaceFindPCAll.h"

InterfaceFindPCAll::InterfaceFindPCAll(Model m) {
    model = m;
}

void InterfaceFindPCAll::menuChoixIntFindPCAll() {

}

void InterfaceFindPCAll::traiterChoixIntFindPCAll() {

}

void InterfaceFindPCAll::boucleInterfaceFindPCAll() {
    std::cout << "VOICI L'AFFICHAGE POUR LES PC" << std::endl;
    while (model.getInterface()->getChoixConso2() != 0){
        model.getInterface()->setChoixConso1(0);
        menuChoixIntFindPCAll();
        traiterChoixIntFindPCAll();
    }
    std::cout << "ADIOS L'AMI\n" << std::endl;
}

