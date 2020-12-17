//
// Created by brian on 14/12/2020.
//

#include <BaseDeDonnee/ReadBDD.h>
#include "Cycle.h"

/**
 * Constructeur vide
 */
Cycle::Cycle() {

}

/**
 * Constructeur qui fouille dans la BDD à la recherche
 * @param id de recherche
 */
Cycle::Cycle(std::string id) {
    std::vector<std::string> res = ReadBDD::FindFichierCycle(id);
    this->id = res.at(0);
    std::string temp = res.at(1);
    ManipString::DecoupeString(temp.substr(1,temp.size()-2),&this->elements,';' );
    this->duree_restante = res.at(2);
    this->est_ouvert = res.at(3);
}

/**
 *  Constructeur à partir des infos
 * @param id : nouveau id
 * @param duree_restante : nouvelle duree
 * @param est_ouvert : nouveur bool
 * @param elements : nouveau vector
 */
Cycle::Cycle(std::string id, std::string duree_restante, std::string est_ouvert, std::vector<std::string> elements) {
    this->id = id;
    this->duree_restante = duree_restante;
    this->est_ouvert = est_ouvert;
    this->elements = elements;
}

/**
 * Getter
 * @return valeur
 */
const std::string &Cycle::getId() const {
    return id;
}

/**
 * Setter
 * @param Nouvelle valeur
 */
void Cycle::setId(const std::string &id) {
    Cycle::id = id;
}

/**
 * Getter
 * @return valeur
 */
const std::string &Cycle::getDureeRestante() const {
    return duree_restante;
}

/**
 * Setter
 * @param Nouvelle valeur
 */
void Cycle::setDureeRestante(const std::string &dureeRestante) {
    duree_restante = dureeRestante;
}

/**
 * Getter
 * @return valeur
 */
const std::string &Cycle::getEstOuvert() const {
    return est_ouvert;
}

/**
 * Setter
 * @param Nouvelle valeur
 */
void Cycle::setEstOuvert(const std::string &estOuvert) {
    est_ouvert = estOuvert;
}

/**
 * Getter
 * @return valeur
 */
const std::vector<std::string> &Cycle::getElements() const {
    return elements;
}

/**
 * Setter
 * @param Nouvelle valeur
 */
void Cycle::setElements(const std::vector<std::string> &elements) {
    Cycle::elements = elements;
}

/**
 * Conevrtit l'objet dans les normes de la BDD
 * @return string en ligne
 */
std::string Cycle::toBDD() {
    std::string nouv;
    nouv.append(this->id);
    nouv.append("<{");
    for(int i=0; i<this->elements.size(); i++){
        nouv.append(this->elements.at(i));
        if(i+1 != this->elements.size()){
            nouv.append(";");
        }
    }
    nouv.append("}<");
    nouv.append(this->duree_restante);
    nouv.append("<");
    nouv.append(this->est_ouvert);
    return nouv;
}

