//
// Created by brian on 14/12/2020.
//

#include "PC.h"

/**
 * Getter
 * @return valeur
 */
const std::string &PC::getId() const {
    return id;
}

/**
 * Setter
 * @param Nouvelle valeur
 */
void PC::setId(const std::string &id) {
    PC::id = id;
}

/**
 * Getter
 * @return valeur
 */
const std::string &PC::getIdCycle() const {
    return id_cycle;
}

/**
 * Setter
 * @param Nouvelle valeur
 */
void PC::setIdCycle(const std::string &idCycle) {
    id_cycle = idCycle;
}

/**
 * Getter
 * @return valeur
 */
const std::string &PC::getAdresse() const {
    return adresse;
}

/**
 * Setter
 * @param Nouvelle valeur
 */
void PC::setAdresse(const std::string &adresse) {
    PC::adresse = adresse;
}

/**
 * Getter
 * @return valeur
 */
const std::string &PC::getCodePostal() const {
    return code_postal;
}

/**
 * Setter
 * @param Nouvelle valeur
 */
void PC::setCodePostal(const std::string &codePostal) {
    code_postal = codePostal;
}

/**
 * Getter
 * @return valeur
 */
const std::string &PC::getEmail() const {
    return email;
}

/**
 * Setter
 * @param Nouvelle valeur
 */
void PC::setEmail(const std::string &email) {
    PC::email = email;
}

/**
 * Getter
 * @return valeur
 */
const std::vector<std::string> &PC::getElements() const {
    return elements;
}

/**
 * Setter
 * @param Nouvelle valeur
 */
void PC::setElements(const std::vector<std::string> &elements) {
    PC::elements = elements;
}

/**
 * Constructeur vide
 */
PC::PC() {

}

/**
 * Constructeur à partir des infos
 * @param id : nouveau id
 * @param id_cycle : nouveau id
 * @param adresse : nouvelle adresse
 * @param code_postal : nouveau code postal
 * @param email : nouveau mail
 * @param elements : nopuveau vector
 */
PC::PC(std::string id, std::string id_cycle, std::string adresse, std::string code_postal, std::string email,
       std::vector<std::string> elements) {
    this->id =id;
    this->id_cycle = id_cycle;
    this->adresse = adresse;
    this->code_postal = code_postal;
    this->email = email;
    this->elements = elements;
}

/**
 * Constructeur qui fouille dans la BDD à la recherche
 * @param id de recherche
 */
PC::PC(std::string id) {
    std::vector<std::string> res = ReadBDD::FindFichierPc(id);
    this->id = res.at(0);
    this->id_cycle = res.at(1);
    this->adresse = res.at(2);
    this->code_postal = res.at(3);
    this->email = res.at(4);
    std::string temp = res.at(5);
    ManipString::DecoupeString(temp.substr(1,temp.size()-2),&this->elements,';' );
}

/**
 * Conevrtit l'objet dans les normes de la BDD
 * @return string en ligne
 */
std::string PC::toBDD() {
    //id_pc<id_cycle<adresse<code_postal<email<{id_pages_proposees_pc;id_pages_proposees_pc;id_pages_proposees_pc}

    std::string nouv;
    nouv.append(this->id);
    nouv.append("<");
    nouv.append(this->id_cycle);
    nouv.append("<");
    nouv.append(this->adresse);
    nouv.append("<");
    nouv.append(this->code_postal);
    nouv.append("<");
    nouv.append(this->email);
    nouv.append("<{");
    for(int i=0; i<this->elements.size(); i++){
        nouv.append(this->elements.at(i));
        if(i+1 != this->elements.size()){
            nouv.append(";");
        }
    }
    nouv.append("}");
    return nouv;
}
