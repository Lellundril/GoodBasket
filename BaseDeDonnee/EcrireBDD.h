//
// Created by brian on 14/12/2020.
//

#ifndef GOODBASKET_ECRIREBDD_H
#define GOODBASKET_ECRIREBDD_H

#include "Outils/Semaphore.h"
#include "Outils/ManipString.h"

#include <fstream>
#include <iostream>
#include <string>
#include <cstdio>   // perror
#include <climits>  // PATH_MAX
#include <unistd.h> // getcwd()
#include <vector>
#include <Outils/Semaphore.h>

class EcrireBDD {
private:
    Semaphore sema;

    int LireFichierSuppr(std::string url, int id);

    std::vector<std::string> ReccupInfoFichierSuppr(std::string url, int id);

    void FichierProduitInit();

    void FichierPcInit();

    void FichierPanierInit();

    void FichierPagesProposeesPcInit();

    void FichierPageInit();

    void FichierElementPanierInit();

    void FichierCycleInit();

    void FichierCompteInit();

public:

///////////////////////////////////// INIT //////////////////////////////////

    EcrireBDD();

///////////////////////////////////// ERASE //////////////////////////////////

    void FichierProduitEffacer(int id);

    void FichierPcEffacer(int id);

    void FichierPanierEffacer(int id);

    void FichierPagesProposeesPcEffacer(int id);

    void FichierPageEffacer(int id);

    void FichierElementPanierEffacer(int id);

    void FichierCycleEffacer(int id);

///////////////////////////////////// AJOUT //////////////////////////////////



///////////////////////////////////// ACCES //////////////////////////////////

    static std::vector<std::string> FindFichierCompte(std::string email);

    static std::vector<std::string> FindFichierCycle(std::string basicString);

    static std::vector<std::string> FindFichierElementPanier(std::string basicString);

    static std::vector<std::string> FindFichierPage(std::string basicString);

    static std::vector<std::string> FindFichierPanier(std::string basicString);

    static std::vector<std::string> FindFichierPc(std::string basicString);

    static std::vector<std::string> FindFichierProduit(std::string basicString);

    static std::vector<std::string> FindFichierPagesProposeesPc(std::string basicString);
};

#endif //GOODBASKET_ECRIREBDD_H
