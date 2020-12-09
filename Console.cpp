//
// Created by Lellundril on 21/11/2020.
//

#include <iostream>
#include <limits>
#include <sstream>

#include "interface/InterfaceEntree.h"

InterfaceEntree interfaceEntree;

int main(){
    std::cout << "Bienvenue sur GoodBasket" << std::endl;
    // Tant que l'utilisateur n'a pas voulu sortir, on traite la variable de choix
   interfaceEntree.boucleInterfaceEntree();
}