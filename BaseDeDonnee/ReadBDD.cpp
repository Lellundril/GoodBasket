//
// Created by brian on 14/12/2020.
//

#include "ReadBDD.h"

Semaphore ReadBDD::getSema(){
    return sema;
}

///////////////////////////////////// INIT //////////////////////////////////

ReadBDD::ReadBDD() {
    sema = Semaphore();
    std::cout << "1" << std::endl;
    FichierProduitInit();
    std::cout << "2" << std::endl;
    FichierPcInit();
    std::cout << "3" << std::endl;
    FichierPanierInit();
    std::cout << "4" << std::endl;
    FichierPagesProposeesPcInit();
    std::cout << "5" << std::endl;
    FichierPageInit();
    std::cout << "6" << std::endl;
    FichierElementPanierInit();
    std::cout << "7" << std::endl;
    FichierCycleInit();
    std::cout << "8" << std::endl;
    FichierCompteInit();
    std::cout << "9" << std::endl;
}

std::string ReadBDD::getAbsolutePath(const std::string s)
{
    if (s[0] != '/') // relative path
    {
        char buf[PATH_MAX];
        if (::getcwd(buf, PATH_MAX) == 0)
        {
            ::perror("getcwd");
            ::exit(1);
        }
        std::string string = buf ;
        string.erase(string.size()-18, string.size()-1);
        return string + std::string(R"(\)") + s;
    }
    else // absolute path
    {
        return s;
    }
}

void ReadBDD::FichierCompteInit(){
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Compte.txt)"));
    std::ifstream monFlux;
    std::string ligne;
    int max=-1;
    monFlux.open(nomFichier.c_str(),std::ios::in);
    if(monFlux.is_open())  //On teste si tout est OK
    {
        monFlux.close();
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

int ReadBDD::FichierCommunInit(std::string nomFichier){
    std::cout << "A" << std::endl;
    std::ifstream monFlux;
    std::cout << "A" << std::endl;
    std::string ligne;
    std::cout << "A" << std::endl;
    int max=0;
    std::cout << "A" << std::endl;
    monFlux.open(nomFichier.c_str(),std::ios::in);
    std::cout << "A" << std::endl;
    if(monFlux.is_open())  //On teste si tout est OK
    {
        std::cout << "AA" << std::endl;
        while (getline (monFlux, ligne)) {
            std::vector<std::string> x;
            std::cout << "AAA" << std::endl;
            x = ManipString::DecoupeString(ligne,&x,'<');
            std::cout << "AAA" << std::endl;
            if(max < std::stoi(x.at(0))){
                max = std::stoi(x.at(0));
            }
        }
        monFlux.close();
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
    return max+1;
}

void ReadBDD::FichierProduitInit(){
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Produit.txt)"));
    sema.setIdProduit(FichierCommunInit(nomFichier));
}

void ReadBDD::FichierPcInit(){
    std::cout << "a" << std::endl;
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Pc.txt)"));
    std::cout << "a" << std::endl;
    sema.setIdPc(FichierCommunInit(nomFichier));
    std::cout << "a" << std::endl;
}

void ReadBDD::FichierPanierInit(){
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Panier.txt)"));
    sema.setIdPanier(FichierCommunInit(nomFichier));
}

void ReadBDD::FichierPagesProposeesPcInit(){
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Pages_proposees_pc.txt)"));
    sema.setIdPagesProposeesPc(FichierCommunInit(nomFichier));
}

void ReadBDD::FichierPageInit(){
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Page.txt)"));
    sema.setIdPage(FichierCommunInit(nomFichier));
}

void ReadBDD::FichierElementPanierInit(){
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Element_panier.txt)"));
    sema.setIdElementPanier(FichierCommunInit(nomFichier));
}

void ReadBDD::FichierCycleInit(){
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Cycle.txt)"));
    sema.setIdCycle(FichierCommunInit(nomFichier));
}

///////////////////////////////////// ERASE /////////////////////////////////////////////////////////////////////////////////////////

int ReadBDD::LireFichierSuppr(std::string url, int id){
    std::string nomFichier(getAbsolutePath(url));
    std::ifstream monFlux;
    std::string ligne;
    int pos = 0;
    monFlux.open(nomFichier.c_str(),std::ios::in);
    if(monFlux.is_open())  //On teste si tout est OK
    {
        while (getline (monFlux, ligne)) {
            std::cout << ligne << std::endl;
            std::vector<std::string> x;
            x = ManipString::DecoupeString(ligne,&x,'<');
            if( id == std::stoi(x.at(0))){
                return pos;
            }
            pos++;
        }

    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

std::vector<std::string> ReadBDD::ReccupInfoFichierSuppr(std::string url, int id){
    int pos,i = 0;
    pos = ReadBDD::LireFichierSuppr(url,id);
    std::string nomFichier(getAbsolutePath(url));
    std::ifstream monFlux;
    std::vector<std::string> x;
    std::string ligne;
    monFlux.open(nomFichier.c_str(),std::ios::in);
    if(monFlux.is_open())  //On teste si tout est OK
    {
        while (getline (monFlux, ligne)) {
            if(i!=pos){
                x.push_back(ligne);
            }
            i++;
        }
        return x;
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

void ReadBDD::CommunProcedureEffacer(std::vector<std::string> x, std::string nomFichier){
    std::ofstream monFlux;
    std::string ligne;
    monFlux.open(nomFichier.c_str(),std::ios::out);

    if(monFlux.is_open())  //On teste si tout est OK
    {
        for(int i = 0; i<x.size(); i++){
            std::cout << x.at(i) << std::endl;
            monFlux << x.at(i) << std::endl;
        }
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

void ReadBDD::FichierProduitEffacer(int id){
    std::vector<std::string> x = ReccupInfoFichierSuppr(R"(Ressources\BDD\Produit.txt)",id);
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Produit.txt)"));
    CommunProcedureEffacer(x,nomFichier);
}

void ReadBDD::FichierPcEffacer(int id){
    std::vector<std::string> x = ReccupInfoFichierSuppr(R"(Ressources\BDD\Pc.txt)",id);

    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Pc.txt)"));
    CommunProcedureEffacer(x,nomFichier);
}

void ReadBDD::FichierPanierEffacer(int id){
    std::vector<std::string> x = ReccupInfoFichierSuppr(R"(Ressources\BDD\Panier.txt)",id);

    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Panier.txt)"));
    CommunProcedureEffacer(x,nomFichier);
}

void ReadBDD::FichierPagesProposeesPcEffacer(int id){
    std::vector<std::string> x = ReccupInfoFichierSuppr(R"(Ressources\BDD\Pages_proposees_pc.txt)",id);

    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Pages_proposees_pc.txt)"));
    CommunProcedureEffacer(x,nomFichier);
}

void ReadBDD::FichierPageEffacer(int id){
    std::vector<std::string> x = ReccupInfoFichierSuppr(R"(Ressources\BDD\Page.txt)",id);

    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Page.txt)"));
    CommunProcedureEffacer(x,nomFichier);
}

void ReadBDD::FichierElementPanierEffacer(int id){
    std::vector<std::string> x = ReccupInfoFichierSuppr(R"(Ressources\BDD\Element_panier.txt)",id);

    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Element_panier.txt)"));
    CommunProcedureEffacer(x,nomFichier);
}

void ReadBDD::FichierCycleEffacer(int id){
    std::vector<std::string> x = ReccupInfoFichierSuppr(R"(Ressources\BDD\Cycle.txt)",id);

    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Cycle.txt)"));
    CommunProcedureEffacer(x,nomFichier);
}

void ReadBDD::FichierCompteEffacer(int id){
    std::vector<std::string> x = ReccupInfoFichierSuppr(R"(Ressources\BDD\Compte.txt)",id);

    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Compte.txt)"));
    CommunProcedureEffacer(x,nomFichier);
}

///////////////////////////////////// ACCES ///////////////////////////////////////////////////////////////////////////////////////////////

std::vector<std::string> ReadBDD::FindCommunProcedure(std::string id, std::string nomFichier){
    std::ifstream monFlux;
    std::vector<std::string> x;
    std::string ligne;

    monFlux.open(nomFichier.c_str(),std::ios::in);
    if(monFlux.is_open())  //On teste si tout est OK
    {
        while (getline (monFlux, ligne)) {
            ManipString::DecoupeString(ligne,&x,'<');
            if(x.at(0) == id){
                return x;
            }
        }
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

std::vector<std::string> ReadBDD::FindFichierCompte(std::string email){
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Compte.txt)"));
    return FindCommunProcedure(std::move(email),nomFichier);
}

std::vector<std::string> ReadBDD::FindFichierCycle(std::string basicString) {
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Cycle.txt)"));
    return FindCommunProcedure(basicString,nomFichier);
}

std::vector<std::string> ReadBDD::FindFichierElementPanier(std::string basicString) {
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Element_panier.txt)"));
    return FindCommunProcedure(basicString,nomFichier);
}

std::vector<std::string> ReadBDD::FindFichierPage(std::string basicString) {
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Page.txt)"));
    return FindCommunProcedure(basicString,nomFichier);
}

std::vector<std::string> ReadBDD::FindFichierPanier(std::string basicString) {
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Panier.txt)"));
    return FindCommunProcedure(basicString,nomFichier);
}

std::vector<std::string> ReadBDD::FindFichierPc(std::string basicString) {
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Pc.txt)"));
    return FindCommunProcedure(basicString,nomFichier);
}

std::vector<std::string> ReadBDD::FindFichierProduit(std::string basicString) {
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Produit.txt)"));
    return FindCommunProcedure(basicString,nomFichier);
}

std::vector<std::string> ReadBDD::FindFichierPagesProposeesPc(std::string basicString) {
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Pages_proposees_pc.txt)"));
    return FindCommunProcedure(basicString,nomFichier);
}

///////////////////////////////////// ACCES SUPPR SPECIAL//////////////////////////////////////////////////////////////////////////////////////////////

std::string ReadBDD::Analyse(std::vector<std::string> x, int pos, std::string id_suppr){
    std::vector<std::string> y;
    std::string w;
    for(int i=0; i<x.size(); i++){
        if(i==pos){
            std::string temp = x.at(pos);
            ManipString::DecoupeString(temp.substr(1,temp.size()-2),&y,';' );
            w.append("{");
            for(int j=0; j<y.size(); j++){
                if(y.at(j) != id_suppr){
                    w.append(y.at(j));
                    if(!y.at(j+1).empty()){
                        w.append(";");
                    }
                }
            }
            w.append("}");
        }else{
            w.append(x.at(i));
        }
    }
    return w;
}

void ReadBDD::FindCommunProcedureSpecialVector(std::string id_suppr, std::string nomFichier, int pos){
    std::ifstream monFlux;
    std::vector<std::string> x,z;
    std::string ligne,w;

    monFlux.open(nomFichier.c_str(),std::ios::in);
    if(monFlux.is_open())  //On teste si tout est OK
    {
        while (getline (monFlux, ligne)) {
            ManipString::DecoupeString(ligne,&x,'<');
            z.push_back(Analyse(x,pos,id_suppr));
        }
        monFlux.close();
        CommunProcedureEffacer(z,nomFichier);
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

void ReadBDD::FindCommunProcedureSpecialSimple(std::string id_suppr, std::string nomFichier, int pos){
    std::ifstream monFlux;
    std::vector<std::string> x,z;
    std::string ligne,w;

    monFlux.open(nomFichier.c_str(),std::ios::in);
    if(monFlux.is_open())  //On teste si tout est OK
    {
        while (getline (monFlux, ligne)) {
            ManipString::DecoupeString(ligne,&x,'<');
            w="";
            if(x.at(pos) != id_suppr) {
                for (int i = 0; i < x.size(); i++) {
                    w.append(x.at(i));
                }
            }
            z.push_back(w);
        }
        monFlux.close();
        CommunProcedureEffacer(z,nomFichier);
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

void ReadBDD::SupprSpecialAllProduitsResidu(std::string id){
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Page.txt)"));
    int pos = 2;
    FindCommunProcedureSpecialVector(id,nomFichier,pos);
    nomFichier = getAbsolutePath(R"(Ressources\BDD\Element_panier.txt)");
    pos = 1;
    FindCommunProcedureSpecialSimple(id,nomFichier,pos);
}

void ReadBDD::SupprSpecialAllCompteResidu(std::string id){
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Page.txt)"));
    int pos = 1;
    FindCommunProcedureSpecialSimple(id,nomFichier,pos);
    nomFichier = getAbsolutePath(R"(Ressources\BDD\Panier.txt)");
    FindCommunProcedureSpecialSimple(id,nomFichier,pos);
    nomFichier = getAbsolutePath(R"(Ressources\BDD\Pc.txt)");
    pos=4;
    FindCommunProcedureSpecialSimple(id,nomFichier,pos);
}

void ReadBDD::SupprSpecialAllPageResidu(std::string id){
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Pages_proposees_pc.txt)"));
    int pos = 1;
    FindCommunProcedureSpecialSimple(id,nomFichier,pos);
    nomFichier = getAbsolutePath(R"(Ressources\BDD\Cycle.txt)");
    FindCommunProcedureSpecialVector(id,nomFichier,pos);
}
