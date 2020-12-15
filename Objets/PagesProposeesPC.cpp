//
// Created by brian on 15/12/2020.
//

#include "PagesProposeesPC.h"

PagesProposeesPC::PagesProposeesPC() {

}

PagesProposeesPC::PagesProposeesPC(std::string id, std::string id_page, std::string est_valide) {
    this->id = id;
    this->id_page = id_page;
    this->est_valide = est_valide;
}

PagesProposeesPC::PagesProposeesPC(std::string id) {
    std::vector<std::string> res = EcrireBDD::FindFichierPagesProposeesPc(id);
    this->id = res.at(0);
    this->id_page = res.at(1);
    this->est_valide = res.at(2);
}

const std::string &PagesProposeesPC::getId() const {
    return id;
}

void PagesProposeesPC::setId(const std::string &id) {
    PagesProposeesPC::id = id;
}

const std::string &PagesProposeesPC::getIdPage() const {
    return id_page;
}

void PagesProposeesPC::setIdPage(const std::string &idPage) {
    id_page = idPage;
}

const std::string &PagesProposeesPC::getEstValide() const {
    return est_valide;
}

void PagesProposeesPC::setEstValide(const std::string &estValide) {
    est_valide = estValide;
}
