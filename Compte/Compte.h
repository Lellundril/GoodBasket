//
// Created by brian on 09/12/2020.
//

#ifndef GOODBASKET_COMPTE_H
#define GOODBASKET_COMPTE_H

#include <string>

const int CONSO = 1;
const int PROC = 2;
const int RESPO = 3;

class Compte {
private:
    std::string email,mdp,pseudo,nom,prenom;
    int id;
public:
    Compte(int id,std::string nom,std::string prenom,std::string pseudo,std::string email,std::string mdp);
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

    bool verifierMotDePasse(std::string passe);

    bool estConso();
    bool estProc();
    bool estRespo();

    int getId() const;

    void setId(int id);
};


#endif //GOODBASKET_COMPTE_H
