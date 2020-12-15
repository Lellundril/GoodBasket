//
// Created by brian on 14/12/2020.
//

#ifndef GOODBASKET_PANIER_H
#define GOODBASKET_PANIER_H

#include "General.h"
#include "BaseDeDonnee/EcrireBDD.h"

class Panier {
private :
    std::string id, email;
    std::vector<std::string> elements;
public :
    Panier();
    Panier(std::string id, std::string email, std::vector<std::string> elements);
    Panier(std::string id);

    const std::string &getId() const;

    void setId(const std::string &id);

    const std::string &getEmail() const;

    void setEmail(const std::string &email);

    const std::vector<std::string> &getElements() const;

    void setElements(const std::vector<std::string> &elements);
};


#endif //GOODBASKET_PANIER_H
