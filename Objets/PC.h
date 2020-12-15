//
// Created by brian on 14/12/2020.
//

#ifndef GOODBASKET_PC_H
#define GOODBASKET_PC_H

#include "General.h"
#include "BaseDeDonnee/EcrireBDD.h"

class PC {
private :
    std::string id, id_cycle, adresse, code_postal, email;
    std::vector<std::string> elements;
public:
    PC();
    PC(std::string id,std::string id_cycle,std::string adresse,std::string code_postal,std::string email,std::vector<std::string> elements);
    PC(std::string id);

    const std::string &getId() const;

    void setId(const std::string &id);

    const std::string &getIdCycle() const;

    void setIdCycle(const std::string &idCycle);

    const std::string &getAdresse() const;

    void setAdresse(const std::string &adresse);

    const std::string &getCodePostal() const;

    void setCodePostal(const std::string &codePostal);

    const std::string &getEmail() const;

    void setEmail(const std::string &email);

    const std::vector<std::string> &getElements() const;

    void setElements(const std::vector<std::string> &elements);
};


#endif //GOODBASKET_PC_H
