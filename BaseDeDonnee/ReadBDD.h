//
// Created by brian on 14/12/2020.
//

#ifndef GOODBASKET_READBDD_H
#define GOODBASKET_READBDD_H

#include "Objets/GeneralObjet.h"
#include "General.h"

class ReadBDD {
private:
    Semaphore sema;

    static int LireFichierSuppr(std::string url, int id);

    void CommunProcedureEffacer(std::vector<std::string> x,std::string nomFichier);

    static std::vector<std::string> FindCommunProcedure(std::string email, std::string nomFichier);

    void FichierProduitInit();

    void FichierPcInit();

    void FichierPanierInit();

    void FichierPagesProposeesPcInit();

    void FichierPageInit();

    void FichierElementPanierInit();

    void FichierCycleInit();

    void FichierCompteInit();

    int FichierCommunInit(std::string nomFichier);

    /*
    void FindCommunProcedureSpecialVector(std::string id_suppr,std::string nomFichier,int pos);

    void SupprSpecialAllProduitsResidu(std::string id);

    void SupprSpecialAllCompteResidu(std::string id);

    void SupprSpecialAllPageResidu(std::string id);

    std::string Analyse(std::vector<std::string> x, int pos, std::string id_suppr);

    void FindCommunProcedureSpecialSimple(std::string id_suppr,std::string nomFichier,int pos);
    */

    int LireFichierSupprCompte(std::string url, std::string email);

    std::vector<std::string> ReccupInfoFichierSupprCompte(std::string url, std::string email);

public:

///////////////////////////////////// INIT //////////////////////////////////

    Semaphore &getSema() const;

    ReadBDD();

    static std::vector<std::string> ReccupInfoFichierSuppr(std::string url, int id);

    static std::string getAbsolutePath(const std::string s);

///////////////////////////////////// ERASE //////////////////////////////////

    void FichierProduitEffacer(int id);

    void FichierPcEffacer(int id);

    void FichierPanierEffacer(int id);

    void FichierPagesProposeesPcEffacer(int id);

    void FichierPageEffacer(int id);

    void FichierElementPanierEffacer(int id);

    void FichierCycleEffacer(int id);

    void FichierCompteEffacer(std::string email);

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

#endif //GOODBASKET_READBDD_H
