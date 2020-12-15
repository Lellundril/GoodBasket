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

int EcrireBDD::FichierCommunInit(std::string nomFichier){
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
        monFlux.close();
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
    return max+1;
}

void EcrireBDD::FichierProduitInit(){
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Produit.txt)"));
    sema.setIdProduit(FichierCommunInit(nomFichier));
}

void EcrireBDD::FichierPcInit(){
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Pc.txt)"));
    sema.setIdPc(FichierCommunInit(nomFichier));
}

void EcrireBDD::FichierPanierInit(){
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Panier.txt)"));
    sema.setIdPanier(FichierCommunInit(nomFichier));
}

void EcrireBDD::FichierPagesProposeesPcInit(){
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Pages_proposees_pc.txt)"));
    sema.setIdPagesProposeesPc(FichierCommunInit(nomFichier));
}

void EcrireBDD::FichierPageInit(){
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Page.txt)"));
    sema.setIdPage(FichierCommunInit(nomFichier));
}

void EcrireBDD::FichierElementPanierInit(){
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Element_panier.txt)"));
    sema.setIdElementPanier(FichierCommunInit(nomFichier));
}

void EcrireBDD::FichierCycleInit(){
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Cycle.txt)"));
    sema.setIdCycle(FichierCommunInit(nomFichier));
}

///////////////////////////////////// ERASE /////////////////////////////////////////////////////////////////////////////////////////

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

void EcrireBDD::CommunProcedureEffacer(std::vector<std::string> x,std::string nomFichier){
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

void EcrireBDD::FichierProduitEffacer(int id){
    std::vector<std::string> x = ReccupInfoFichierSuppr(R"(Ressources\BDD\Produit.txt)",id);
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Produit.txt)"));
    CommunProcedureEffacer(x,nomFichier);
}

void EcrireBDD::FichierPcEffacer(int id){
    std::vector<std::string> x = ReccupInfoFichierSuppr(R"(Ressources\BDD\Pc.txt)",id);

    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Pc.txt)"));
    CommunProcedureEffacer(x,nomFichier);
}

void EcrireBDD::FichierPanierEffacer(int id){
    std::vector<std::string> x = ReccupInfoFichierSuppr(R"(Ressources\BDD\Panier.txt)",id);

    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Panier.txt)"));
    CommunProcedureEffacer(x,nomFichier);
}

void EcrireBDD::FichierPagesProposeesPcEffacer(int id){
    std::vector<std::string> x = ReccupInfoFichierSuppr(R"(Ressources\BDD\Pages_proposees_pc.txt)",id);

    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Pages_proposees_pc.txt)"));
    CommunProcedureEffacer(x,nomFichier);
}

void EcrireBDD::FichierPageEffacer(int id){
    std::vector<std::string> x = ReccupInfoFichierSuppr(R"(Ressources\BDD\Page.txt)",id);

    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Page.txt)"));
    CommunProcedureEffacer(x,nomFichier);
}

void EcrireBDD::FichierElementPanierEffacer(int id){
    std::vector<std::string> x = ReccupInfoFichierSuppr(R"(Ressources\BDD\Element_panier.txt)",id);

    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Element_panier.txt)"));
    CommunProcedureEffacer(x,nomFichier);
}

void EcrireBDD::FichierCycleEffacer(int id){
    std::vector<std::string> x = ReccupInfoFichierSuppr(R"(Ressources\BDD\Cycle.txt)",id);

    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Cycle.txt)"));
    CommunProcedureEffacer(x,nomFichier);
}

void EcrireBDD::FichierCompteEffacer(int id){
    std::vector<std::string> x = ReccupInfoFichierSuppr(R"(Ressources\BDD\Compte.txt)",id);

    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Compte.txt)"));
    CommunProcedureEffacer(x,nomFichier);
}

///////////////////////////////////// AJOUT ///////////////////////////////////////////////////////////////////////////////////////////////
//fichier.seekg(0, ios::end);  //On se déplace à la fin du fichier

/*si l'on souhaite ajouter des informations à la fin d'un fichier pré-existant.
ofstream monFlux("C:/Testcpp/scores.txt“,ios::app);*/



///////////////////////////////////// ACCES ///////////////////////////////////////////////////////////////////////////////////////////////

std::vector<std::string> EcrireBDD::FindCommunProcedure(std::string id,std::string nomFichier){
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

std::vector<std::string> EcrireBDD::FindFichierCompte(std::string email){
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Compte.txt)"));
    return FindCommunProcedure(std::move(email),nomFichier);
}

std::vector<std::string> EcrireBDD::FindFichierCycle(std::string basicString) {
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Cycle.txt)"));
    return FindCommunProcedure(basicString,nomFichier);
}

std::vector<std::string> EcrireBDD::FindFichierElementPanier(std::string basicString) {
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Element_panier.txt)"));
    return FindCommunProcedure(basicString,nomFichier);
}

std::vector<std::string> EcrireBDD::FindFichierPage(std::string basicString) {
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Page.txt)"));
    return FindCommunProcedure(basicString,nomFichier);
}

std::vector<std::string> EcrireBDD::FindFichierPanier(std::string basicString) {
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Panier.txt)"));
    return FindCommunProcedure(basicString,nomFichier);
}

std::vector<std::string> EcrireBDD::FindFichierPc(std::string basicString) {
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Pc.txt)"));
    return FindCommunProcedure(basicString,nomFichier);
}

std::vector<std::string> EcrireBDD::FindFichierProduit(std::string basicString) {
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Produit.txt)"));
    return FindCommunProcedure(basicString,nomFichier);
}

std::vector<std::string> EcrireBDD::FindFichierPagesProposeesPc(std::string basicString) {
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Pages_proposees_pc.txt)"));
    return FindCommunProcedure(basicString,nomFichier);
}

///////////////////////////////////// ACCES SUPPR SPECIAL//////////////////////////////////////////////////////////////////////////////////////////////

std::string EcrireBDD::Analyse(std::vector<std::string> x, int pos, std::string id_suppr){
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

void EcrireBDD::FindCommunProcedureSpecialVector(std::string id_suppr,std::string nomFichier,int pos){
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

void EcrireBDD::FindCommunProcedureSpecialSimple(std::string id_suppr,std::string nomFichier,int pos){
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

void EcrireBDD::SupprSpecialAllProduitsResidu(std::string id){
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Page.txt)"));
    int pos = 2;
    FindCommunProcedureSpecialVector(id,nomFichier,pos);
    nomFichier = getAbsolutePath(R"(Ressources\BDD\Element_panier.txt)");
    pos = 1;
    FindCommunProcedureSpecialSimple(id,nomFichier,pos);
}

void EcrireBDD::SupprSpecialAllCompteResidu(std::string id){
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Page.txt)"));
    int pos = 1;
    FindCommunProcedureSpecialSimple(id,nomFichier,pos);
    nomFichier = getAbsolutePath(R"(Ressources\BDD\Panier.txt)");
    FindCommunProcedureSpecialSimple(id,nomFichier,pos);
    nomFichier = getAbsolutePath(R"(Ressources\BDD\Pc.txt)");
    pos=4;
    FindCommunProcedureSpecialSimple(id,nomFichier,pos);
}

void EcrireBDD::SupprSpecialAllPageResidu(std::string id){
    std::string nomFichier(getAbsolutePath(R"(Ressources\BDD\Pages_proposees_pc.txt)"));
    int pos = 1;
    FindCommunProcedureSpecialSimple(id,nomFichier,pos);
    nomFichier = getAbsolutePath(R"(Ressources\BDD\Cycle.txt)");
    FindCommunProcedureSpecialVector(id,nomFichier,pos);
}
