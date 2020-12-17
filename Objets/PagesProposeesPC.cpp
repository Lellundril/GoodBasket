//
// Created by brian on 15/12/2020.
//

#include "PagesProposeesPC.h"

/**
 * Constructeur vide
 */
PagesProposeesPC::PagesProposeesPC() {

}

/**
 *  Constructeur à partir des infos
 * @param id : nouveau id
 * @param id_page : nouveau id
 * @param est_valide : nouveau bool
 */
PagesProposeesPC::PagesProposeesPC(std::string id, std::string id_page, std::string est_valide) {
    this->id = id;
    this->id_page = id_page;
    this->est_valide = est_valide;
}

/**
 * Constructeur qui fouille dans la BDD à la recherche
 * @param id de recherche
 */
PagesProposeesPC::PagesProposeesPC(std::string id) {
    std::vector<std::string> res = ReadBDD::FindFichierPagesProposeesPc(id);
    this->id = res.at(0);
    this->id_page = res.at(1);
    this->est_valide = res.at(2);
}

/**
 * Getter
 * @return valeur
 */
const std::string &PagesProposeesPC::getId() const {
    return id;
}

/**
 * Setter
 * @param Nouvelle valeur
 */
void PagesProposeesPC::setId(const std::string &id) {
    PagesProposeesPC::id = id;
}

/**
 * Getter
 * @return valeur
 */
const std::string &PagesProposeesPC::getIdPage() const {
    return id_page;
}

/**
 * Setter
 * @param Nouvelle valeur
 */
void PagesProposeesPC::setIdPage(const std::string &idPage) {
    id_page = idPage;
}

/**
 * Getter
 * @return valeur
 */
const std::string &PagesProposeesPC::getEstValide() const {
    return est_valide;
}

/**
 * Setter
 * @param Nouvelle valeur
 */
void PagesProposeesPC::setEstValide(const std::string &estValide) {
    est_valide = estValide;
}

/**
 * Conevrtit l'objet dans les normes de la BDD
 * @return string en ligne
 */
std::string PagesProposeesPC::toBDD() {
    std::string nouv;
    nouv.append(this->id);
    nouv.append("<");
    nouv.append(this->id_page);
    nouv.append("<");
    nouv.append(this->est_valide);
    return nouv;
}
