//
// Created by brian on 14/12/2020.
//

#include "EcrireBDD.h"

///////////////////////////////////// INIT //////////////////////////////////

EcrireBDD::EcrireBDD() {
    sema = Semaphore();
    FichierProduitInit();
    FichierPcInit();
    FichierPanierInit();
    FichierPagesProposeesPcInit();
    FichierPageInit();
    FichierElementPanierInit();
    FichierCycleInit();
    FichierCompteInit();
}

std::string getAbsolutePath(const std::string s)
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

void EcrireBDD::FichierCompteInit(){
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

void EcrireBDD::FichierProduitInit(){
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Produit.txt)"));
    std::ifstream monFlux;
    std::string ligne;
    int max=-1;
    monFlux.open(nomFichier.c_str(),std::ios::in);
    if(monFlux.is_open())  //On teste si tout est OK
    {
        while (getline (monFlux, ligne)) {
            std::vector<std::string> x;
            x = ManipString::DecoupeString(ligne,&x,'<');
            if(max < std::stoi(x.at(0))){
                max = std::stoi(x.at(0));
            }
        }
        sema.setIdProduit(max+1);
        monFlux.close();
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

void EcrireBDD::FichierPcInit(){
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Pc.txt)"));
    std::ifstream monFlux;
    std::string ligne;
    int max=-1;
    monFlux.open(nomFichier.c_str(),std::ios::in);
    if(monFlux.is_open())  //On teste si tout est OK
    {
        while (getline (monFlux, ligne)) {
            std::cout << ligne << std::endl;
            std::vector<std::string> x;
            x = ManipString::DecoupeString(ligne,&x,'<');
            if(max < std::stoi(x.at(0))){
                max = std::stoi(x.at(0));
            }
        }
        sema.setIdPc(max+1);
        monFlux.close();
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

void EcrireBDD::FichierPanierInit(){
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Panier.txt)"));
    std::ifstream monFlux;
    std::string ligne;
    int max=-1;
    monFlux.open(nomFichier.c_str(),std::ios::in);
    if(monFlux.is_open())  //On teste si tout est OK
    {
        while (getline (monFlux, ligne)) {
            std::cout << ligne << std::endl;
            std::vector<std::string> x;
            x = ManipString::DecoupeString(ligne,&x,'<');
            if(max < std::stoi(x.at(0))){
                max = std::stoi(x.at(0));
            }
        }
        sema.setIdPanier(max+1);
        monFlux.close();
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

void EcrireBDD::FichierPagesProposeesPcInit(){
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Pages_proposees_pc.txt)"));
    std::ifstream monFlux;
    std::string ligne;
    int max=-1;
    monFlux.open(nomFichier.c_str(),std::ios::in);
    if(monFlux.is_open())  //On teste si tout est OK
    {
        while (getline (monFlux, ligne)) {
            std::cout << ligne << std::endl;
            std::vector<std::string> x;
            x = ManipString::DecoupeString(ligne,&x,'<');
            if(max < std::stoi(x.at(0))){
                max = std::stoi(x.at(0));
            }
        }
        sema.setIdPagesProposeesPc(max+1);
        monFlux.close();
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

void EcrireBDD::FichierPageInit(){
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Page.txt)"));
    std::ifstream monFlux;
    std::string ligne;
    int max=-1;
    monFlux.open(nomFichier.c_str(),std::ios::in);
    if(monFlux.is_open())  //On teste si tout est OK
    {
        while (getline (monFlux, ligne)) {
            std::cout << ligne << std::endl;
            std::vector<std::string> x;
            x = ManipString::DecoupeString(ligne,&x,'<');
            if(max < std::stoi(x.at(0))){
                max = std::stoi(x.at(0));
            }
        }
        sema.setIdPage(max+1);
        monFlux.close();
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

void EcrireBDD::FichierElementPanierInit(){
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Element_panier.txt)"));
    std::ifstream monFlux;
    std::string ligne;
    int max=-1;
    monFlux.open(nomFichier.c_str(),std::ios::in);
    if(monFlux.is_open())  //On teste si tout est OK
    {
        while (getline (monFlux, ligne)) {
            std::cout << ligne << std::endl;
            std::vector<std::string> x;
            x = ManipString::DecoupeString(ligne,&x,'<');
            if(max < std::stoi(x.at(0))){
                max = std::stoi(x.at(0));
            }
        }
        sema.setIdElementPanier(max+1);
        monFlux.close();
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

void EcrireBDD::FichierCycleInit(){
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Cycle.txt)"));
    std::ifstream monFlux;
    std::string ligne;
    int max=-1;
    monFlux.open(nomFichier.c_str(),std::ios::in);
    if(monFlux.is_open())  //On teste si tout est OK
    {
        while (getline (monFlux, ligne)) {
            std::cout << ligne << std::endl;
            std::vector<std::string> x;
            x = ManipString::DecoupeString(ligne,&x,'<');
            if(max < std::stoi(x.at(0))){
                max = std::stoi(x.at(0));
            }
        }
        sema.setIdCycle(max+1);
        monFlux.close();
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

///////////////////////////////////// ERASE //////////////////////////////////

int EcrireBDD::LireFichierSuppr(std::string url, int id){
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

std::vector<std::string> EcrireBDD::ReccupInfoFichierSuppr(std::string url, int id){
    int pos,i = 0;
    pos = LireFichierSuppr(url,id);
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

void EcrireBDD::FichierProduitEffacer(int id){
    std::vector<std::string> x = ReccupInfoFichierSuppr(R"(Ressources\BDD\Produit.txt)",id);

    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Produit.txt)"));
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

void EcrireBDD::FichierPcEffacer(int id){
    std::vector<std::string> x = ReccupInfoFichierSuppr(R"(Ressources\BDD\Pc.txt)",id);

    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Pc.txt)"));
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

void EcrireBDD::FichierPanierEffacer(int id){
    std::vector<std::string> x = ReccupInfoFichierSuppr(R"(Ressources\BDD\Panier.txt)",id);

    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Panier.txt)"));
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

void EcrireBDD::FichierPagesProposeesPcEffacer(int id){
    std::vector<std::string> x = ReccupInfoFichierSuppr(R"(Ressources\BDD\Pages_proposees_pc.txt)",id);

    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Pages_proposees_pc.txt)"));
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

void EcrireBDD::FichierPageEffacer(int id){
    std::vector<std::string> x = ReccupInfoFichierSuppr(R"(Ressources\BDD\Page.txt)",id);

    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Page.txt)"));
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

void EcrireBDD::FichierElementPanierEffacer(int id){
    std::vector<std::string> x = ReccupInfoFichierSuppr(R"(Ressources\BDD\Element_panier.txt)",id);

    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Element_panier.txt)"));
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

void EcrireBDD::FichierCycleEffacer(int id){
    std::vector<std::string> x = ReccupInfoFichierSuppr(R"(Ressources\BDD\Cycle.txt)",id);

    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Cycle.txt)"));
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

///////////////////////////////////// AJOUT //////////////////////////////////
//fichier.seekg(0, ios::end);  //On se déplace à la fin du fichier

/*si l'on souhaite ajouter des informations à la fin d'un fichier pré-existant.
ofstream monFlux("C:/Testcpp/scores.txt“,ios::app);*/



///////////////////////////////////// ACCES //////////////////////////////////

std::vector<std::string> EcrireBDD::FindFichierCompte(std::string email){
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Compte.txt)"));
    std::ifstream monFlux;
    std::vector<std::string> x;
    std::string ligne;

    monFlux.open(nomFichier.c_str(),std::ios::in);
    if(monFlux.is_open())  //On teste si tout est OK
    {
        while (getline (monFlux, ligne)) {
            ManipString::DecoupeString(ligne,&x,'<');
            if(x.at(0) == email){
                return x;
            }
        }
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

std::vector<std::string> EcrireBDD::FindFichierCycle(std::string basicString) {
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Cycle.txt)"));
    std::ifstream monFlux;
    std::vector<std::string> x;
    std::string ligne;

    monFlux.open(nomFichier.c_str(),std::ios::in);
    if(monFlux.is_open())  //On teste si tout est OK
    {
        while (getline (monFlux, ligne)) {
            ManipString::DecoupeString(ligne,&x,'<');
            if(x.at(0) == basicString){
                return x;
            }
        }
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

std::vector<std::string> EcrireBDD::FindFichierElementPanier(std::string basicString) {
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Element_panier.txt)"));
    std::ifstream monFlux;
    std::vector<std::string> x;
    std::string ligne;

    monFlux.open(nomFichier.c_str(),std::ios::in);
    if(monFlux.is_open())  //On teste si tout est OK
    {
        while (getline (monFlux, ligne)) {
            ManipString::DecoupeString(ligne,&x,'<');
            if(x.at(0) == basicString){
                return x;
            }
        }
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

std::vector<std::string> EcrireBDD::FindFichierPage(std::string basicString) {
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Page.txt)"));
    std::ifstream monFlux;
    std::vector<std::string> x;
    std::string ligne;

    monFlux.open(nomFichier.c_str(),std::ios::in);
    if(monFlux.is_open())  //On teste si tout est OK
    {
        while (getline (monFlux, ligne)) {
            ManipString::DecoupeString(ligne,&x,'<');
            if(x.at(0) == basicString){
                return x;
            }
        }
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

std::vector<std::string> EcrireBDD::FindFichierPanier(std::string basicString) {
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Panier.txt)"));
    std::ifstream monFlux;
    std::vector<std::string> x;
    std::string ligne;

    monFlux.open(nomFichier.c_str(),std::ios::in);
    if(monFlux.is_open())  //On teste si tout est OK
    {
        while (getline (monFlux, ligne)) {
            ManipString::DecoupeString(ligne,&x,'<');
            if(x.at(0) == basicString){
                return x;
            }
        }
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

std::vector<std::string> EcrireBDD::FindFichierPc(std::string basicString) {
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Pc.txt)"));
    std::ifstream monFlux;
    std::vector<std::string> x;
    std::string ligne;

    monFlux.open(nomFichier.c_str(),std::ios::in);
    if(monFlux.is_open())  //On teste si tout est OK
    {
        while (getline (monFlux, ligne)) {
            ManipString::DecoupeString(ligne,&x,'<');
            if(x.at(0) == basicString){
                return x;
            }
        }
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

std::vector<std::string> EcrireBDD::FindFichierProduit(std::string basicString) {
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Produit.txt)"));
    std::ifstream monFlux;
    std::vector<std::string> x;
    std::string ligne;

    monFlux.open(nomFichier.c_str(),std::ios::in);
    if(monFlux.is_open())  //On teste si tout est OK
    {
        while (getline (monFlux, ligne)) {
            ManipString::DecoupeString(ligne,&x,'<');
            if(x.at(0) == basicString){
                return x;
            }
        }
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

std::vector<std::string> EcrireBDD::FindFichierPagesProposeesPc(std::string basicString) {
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Pages_proposees_pc.txt)"));
    std::ifstream monFlux;
    std::vector<std::string> x;
    std::string ligne;

    monFlux.open(nomFichier.c_str(),std::ios::in);
    if(monFlux.is_open())  //On teste si tout est OK
    {
        while (getline (monFlux, ligne)) {
            ManipString::DecoupeString(ligne,&x,'<');
            if(x.at(0) == basicString){
                return x;
            }
        }
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}
//fs <<