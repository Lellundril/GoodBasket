//
// Created by brian on 14/12/2020.
//

#ifndef GOODBASKET_SEMAPHORE_H
#define GOODBASKET_SEMAPHORE_H


class Semaphore {
private :
    int id_produit;
    int id_page;
    int id_pc;
    int id_pages_proposees_pc;
    int id_cycle;
    int id_panier;
    int id_element_panier;
public:
    Semaphore();

    int getIdProduit();
    int getIdPage();
    int getIdPc();
    int getIdPagesProposeesPc();
    int getIdCycle();
    int getIdPanier();
    int getIdElementPanier();

    void setIdProduit(int idProduit);
    void setIdPage(int idPage);
    void setIdPc(int idPc);
    void setIdPagesProposeesPc(int idPagesProposeesPc);
    void setIdCycle(int idCycle);
    void setIdPanier(int idPanier);
    void setIdElementPanier(int idElementPanier);
};


#endif //GOODBASKET_SEMAPHORE_H
