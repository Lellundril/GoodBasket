//
// Created by Lellundril on 21/11/2020.
//

#include <iostream>
#include <sstream>

#include "interface/InterfaceEntree.h"

int main(){
    std::cout << "Bienvenue sur GoodBasket" << std::endl;
    Model m = Model();
    std::cout << &m << std::endl;
    // Tant que l'utilisateur n'a pas voulu sortir, on traite la variable de choix
   InterfaceEntree(m).boucleInterfaceEntree();
}