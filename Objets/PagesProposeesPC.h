//
// Created by brian on 15/12/2020.
//

#ifndef GOODBASKET_PAGESPROPOSEESPC_H
#define GOODBASKET_PAGESPROPOSEESPC_H

#include "General.h"
#include "BaseDeDonnee/ReadBDD.h"

class PagesProposeesPC {
private:
    std::string id,id_page,est_valide;
public:
    PagesProposeesPC();
    PagesProposeesPC(std::string id, std::string id_page, std::string est_valide);
    PagesProposeesPC(std::string id);

    const std::string &getId() const;

    void setId(const std::string &id);

    const std::string &getIdPage() const;

    void setIdPage(const std::string &idPage);

    const std::string &getEstValide() const;

    void setEstValide(const std::string &estValide);

    std::string toBDD();
};


#endif //GOODBASKET_PAGESPROPOSEESPC_H
