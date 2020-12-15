//
// Created by Lellundril on 21/11/2020.
//

#include <iostream>
#include <sstream>
#include "BaseDeDonnee/EcrireBDD.h"

int main() {
    std::cout << "Bienvenue sur GoodBasket" << std::endl;
    EcrireBDD e;
    std::string temp = "{10,20,30,40,50}";
    std::cout << temp.substr(1,temp.size()-2) << std::endl;
}