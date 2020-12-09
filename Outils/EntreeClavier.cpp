//
// Created by brian on 09/12/2020.
//

#include <iostream>
#include <limits>
#include "EntreeClavier.h"

/**
 * Fonction renvoyant un nombre entier renvoyé par l'utilisateur.
 * @return un nombre donné par l'utilisateur.
 */
// Récupère une entrée numérique seulement
int entrerChoixNumerique() {
    int varChoix = 0;
    std::cout << "- Entrez votre choix -" << std::endl;
    std::cin >> varChoix;

    //Si l'entrée n'est pas un nombre
    while(!std::cin) // ou si (cin.fail())
    {
        std::cin.clear(); // reset failbit
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignorer l'entrée incorrecte
        // Ensuite, redemander une entrée
        std::cout << "Vous devez entrez un chiffre : " << std::endl;
        std::cin >> varChoix;
    }
    return varChoix;
}
