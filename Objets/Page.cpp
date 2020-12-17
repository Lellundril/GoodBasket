//
// Created by brian on 14/12/2020.
//

#include "Page.h"

/**
 * Getter
 * @return valeur
 */
const std::string &Page::getId() const {
    return id;
}

/**
 * Setter
 * @param Nouvelle valeur
 */
void Page::setId(const std::string &id) {
    Page::id = id;
}

/**
 * Getter
 * @return valeur
 */
const std::string &Page::getEmail() const {
    return email;
}

/**
 * Setter
 * @param Nouvelle valeur
 */
void Page::setEmail(const std::string &email) {
    Page::email = email;
}

/**
 * Getter
 * @return valeur
 */
const std::vector<std::string> &Page::getElements() const {
    return elements;
}

/**
 * Setter
 * @param Nouvelle valeur
 */
void Page::setElements(const std::vector<std::string> &elements) {
    Page::elements = elements;
}

/**
 * Constructeur vide
 */
Page::Page() {

}

/**
 * Constructeur à partir des infos
 * @param id : nouveau id
 * @param email : nouveau eamil
 * @param elements : nouveau vector
 */
Page::Page(std::string id, std::string email, std::vector<std::string> elements) {
    this->id = id;
    this->email = email;
    this->elements = elements;
}

/**
 * Constructeur qui fouille dans la BDD à la recherche
 * @param id de recherche
 */
Page::Page(std::string id) {
    std::vector<std::string> res = ReadBDD::FindFichierPage(id);
    this->id = res.at(0);
    this->email = res.at(1);
    std::string temp = res.at(2);
    ManipString::DecoupeString(temp.substr(1,temp.size()-2),&this->elements,';' );
}

/**
 * Conevrtit l'objet dans les normes de la BDD
 * @return string en ligne
 */
std::string Page::toBDD() {
    std::string nouv;
    nouv.append(this->id);
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
