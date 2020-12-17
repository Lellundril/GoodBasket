//
// Created by brian on 14/12/2020.
//

#include "Panier.h"

const std::string &Panier::getId() const {
    return id;
}

void Panier::setId(const std::string &id) {
    Panier::id = id;
}

const std::string &Panier::getEmail() const {
    return email;
}

void Panier::setEmail(const std::string &email) {
    Panier::email = email;
}

const std::vector<std::string> &Panier::getElements() const {
    return elements;
}

void Panier::setElements(const std::vector<std::string> &elements) {
    Panier::elements = elements;
}

Panier::Panier() {

}

Panier::Panier(std::string id, std::string email, std::vector<std::string> elements) {
    this->id= id;
    this->email = email;
    this->elements = elements;
}

Panier::Panier(std::string id) {
    std::vector<std::string> res = ReadBDD::FindFichierPanier(id);
    this->id= res.at(0);
    this->email = res.at(1);
    std::string temp = res.at(2);
    ManipString::DecoupeString(temp.substr(1,temp.size()-2),&this->elements,';' );
}

std::string Panier::toBDD() {
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
