//
// Created by Lellundril on 21/11/2020.
//

#ifndef GOODBASKET_COMPTE_H
#define GOODBASKET_COMPTE_H

#include <string>

class Compte{
protected:
    std::string nomUtilisateur;
    std::string motDePasse;
public:
    Compte(){};

    Compte(const std::string &nomUtilisateur, const std::string &motDePasse);

    const std::string &getNomUtilisateur() const;

    void setNomUtilisateur(const std::string &nomUtilisateur);

    const std::string &getMotDePasse() const;

    void setMotDePasse(const std::string &motDePasse);

    bool verifierMotDePasse(std::string);

    //Vrai si l'utilisateur est Consommateur
    virtual bool estConsommateur();
    //Vrai si l'utilisateur est Producteur
    virtual bool estProducteur();
    //Vrai si l'utilisateur est PointDeCollecte
    virtual bool estPDC();

    virtual std::string getTypeString(){
        return "Compte";
    }
};

#endif //GOODBASKET_COMPTE_H
