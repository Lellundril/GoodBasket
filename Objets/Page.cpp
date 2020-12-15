//
// Created by brian on 14/12/2020.
//

#include "Page.h"

const std::string &Page::getId() const {
    return id;
}

void Page::setId(const std::string &id) {
    Page::id = id;
}

const std::string &Page::getEmail() const {
    return email;
}

void Page::setEmail(const std::string &email) {
    Page::email = email;
}

const std::vector<std::string> &Page::getElements() const {
    return elements;
}

void Page::setElements(const std::vector<std::string> &elements) {
    Page::elements = elements;
}

Page::Page() {

}

Page::Page(std::string id, std::string email, std::vector<std::string> elements) {
    this->id = id;
    this->email = email;
    this->elements = elements;
}

Page::Page(std::string id) {
    std::vector<std::string> res = EcrireBDD::FindFichierPage(id);
    this->id = res.at(0);
    this->email = res.at(1);
    std::string temp = res.at(2);
    ManipString::DecoupeString(temp.substr(1,temp.size()-2),&this->elements,';' );
}
