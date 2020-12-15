//
// Created by brian on 14/12/2020.
//

#ifndef GOODBASKET_COMPTE_H
#define GOODBASKET_COMPTE_H

#include <string>
#include "BaseDeDonnee/EcrireBDD.h"

class Compte {
private:

    std::string email,mdp,pseudo,nom,prenom,type;

public:

    Compte(std::string nom,std::string prenom,std::string pseudo,std::string email,std::string mdp,std::string type);

    Compte();

    Compte(std::string email);

    const std::string &getEmail() const;

    void setEmail(const std::string &email);

    const std::string &getMdp() const;

    void setMdp(const std::string &mdp);

    const std::string &getPseudo() const;

    void setPseudo(const std::string &pseudo);

    const std::string &getNom() const;

    void setNom(const std::string &nom);

    const std::string &getPrenom() const;

    void setPrenom(const std::string &prenom);

    const std::string &getType() const;

    void setType(const std::string &type);

    bool estConso();

    bool estProd();

    bool estRespo();
};


#endif //GOODBASKET_COMPTE_H
