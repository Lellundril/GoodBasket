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
    Compte(std::string, std::string);

    const std::string &getNomUtilisateur() const;

    void setNomUtilisateur(const std::string &nomUtilisateur);

    const std::string &getMotDePasse() const;

    void setMotDePasse(const std::string &motDePasse);

    bool verifierMotDePasse(std::string);
};

#endif //GOODBASKET_COMPTE_H
