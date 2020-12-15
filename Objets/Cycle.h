//
// Created by brian on 14/12/2020.
//

#ifndef GOODBASKET_CYCLE_H
#define GOODBASKET_CYCLE_H


#include <string>
#include <vector>

class Cycle {
private:
    std::string id,duree_restante,est_ouvert;
    std::vector<std::string> elements;
public:
    Cycle();
    Cycle(std::string id);
    Cycle(std::string id, std::string duree_restante, std::string est_ouvert, std::vector<std::string> elements);

    const std::string &getId() const;

    void setId(const std::string &id);

    const std::string &getDureeRestante() const;

    void setDureeRestante(const std::string &dureeRestante);

    const std::string &getEstOuvert() const;

    void setEstOuvert(const std::string &estOuvert);

    const std::vector<std::string> &getElements() const;

    void setElements(const std::vector<std::string> &elements);

};


#endif //GOODBASKET_CYCLE_H
