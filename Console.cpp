//
// Created by Lellundril on 21/11/2020.
//

#include <iostream>
#include <sstream>
#include <BaseDeDonnee/WriteBDD.h>
#include "BaseDeDonnee/ReadBDD.h"

int main() {
    std::cout << "Bienvenue sur GoodBasket" << std::endl;
    WriteBDD w;
    ReadBDD e;

    /*Compte :

    email<nom<prenom<type<mdp<pseudo

    Cycle :

    id_cycle<{id_page;id_page;id_page}<duree_restante<est_ouvert

    Produit :

    id_produit<nom_produit<prix<quantite<est_kilo<image

    Element Panier :

    id_element_panier<id_produit<quantite_prise

    Page :

    id_page<email<{id_produit;id_produit;id_produit}

    Pc :
    id_pc<id_cycle<adresse<code_postal<email<{id_pages_proposees_pc;id_pages_proposees_pc;id_pages_proposees_pc}

    Pages Proposées pc :

    id_pages_proposees_pc<id_page<est_valide*/

    Compte c = Compte("Bertran","PIPOT","pseudo1","aaa@test.com","mdp123.","CONSO");
    Compte c2 = Compte("Jean","BEAU","pseudo2","bb@test.com","mdp123.","CONSO");
    Compte c3 = Compte("Luce","BIGA","pseudo3","ccc@test.com","mdp123.","PROC");
    Compte c4 = Compte("Marie","OLLON","pseudo4","ddd@test.com","mdp123.","PROC");
    Compte c5 = Compte("Salie","VRIVAUT","pseudo5","eee@test.com","mdp123.","RESPO");
    Compte c6 = Compte("Mario","BROS","pseudo6","fff@test.com","mdp123.","RESPO");

   std::cout << " CREATION FAITE" << std::endl;
    w.FichierCompteAjout(c);
    w.FichierCompteAjout(c2);
    w.FichierCompteAjout(c3);
     w.FichierCompteAjout(c4);
     w.FichierCompteAjout(c5);
     w.FichierCompteAjout(c6);

     std::vector<std::string> vector1;
     vector1.push_back("0");
     vector1.push_back("1");
     std::vector<std::string> vector2;
     vector2.push_back("2");
     vector2.push_back("3");
     vector2.push_back("4");
     std::vector<std::string> vector3;
     vector3.push_back("5");
     vector3.push_back("6");
     vector3.push_back("7");
     vector3.push_back("8");
     std::vector<std::string> vector4;
     vector4.push_back("9");
     std::vector<std::string> vector5;
     vector5.push_back("10");
     vector5.push_back("11");
     vector5.push_back("12");
     vector5.push_back("13");

     Page pa = Page(std::to_string(e.getSema().getIdPage()),"ccc@test.com",vector1);
     Page pa2 = Page(std::to_string(e.getSema().getIdPage()),"ccc@test.com",vector2);
     Page pa3 = Page(std::to_string(e.getSema().getIdPage()),"ccc@test.com",vector3);
     Page pa4 = Page(std::to_string(e.getSema().getIdPage()),"ddd@test.com",vector4);
     Page pa5 = Page(std::to_string(e.getSema().getIdPage()),"ddd@test.com",vector5);

     w.FichierPageAjout(pa);
     w.FichierPageAjout(pa2);
     w.FichierPageAjout(pa3);
     w.FichierPageAjout(pa4);
     w.FichierPageAjout(pa5);

     ElementPanier ep = ElementPanier(std::to_string(e.getSema().getIdElementPanier()),"2","8");
     ElementPanier ep2 = ElementPanier(std::to_string(e.getSema().getIdElementPanier()),"4","2");
     ElementPanier ep3 = ElementPanier(std::to_string(e.getSema().getIdElementPanier()),"8","1");
     ElementPanier ep4 = ElementPanier(std::to_string(e.getSema().getIdElementPanier()),"9","7");
     ElementPanier ep5 = ElementPanier(std::to_string(e.getSema().getIdElementPanier()),"11","10");

     w.FichierElementPanierAjout(ep);
     w.FichierElementPanierAjout(ep2);
     w.FichierElementPanierAjout(ep3);
     w.FichierElementPanierAjout(ep4);
     w.FichierElementPanierAjout(ep5);

     std::vector<std::string> vector6;
     vector6.push_back("0");
     vector6.push_back("1");
     vector6.push_back("2");
     std::vector<std::string> vector7;
     vector7.push_back("3");
     vector7.push_back("4");

     Panier pan = Panier(std::to_string(e.getSema().getIdPanier()),"aaa@test.com",vector6);
     Panier pan2 = Panier(std::to_string(e.getSema().getIdPanier()),"bbb@test.com",vector7);

     w.FichierPanierAjout(pan);
     w.FichierPanierAjout(pan2);

     PagesProposeesPC pppc = PagesProposeesPC(std::to_string(e.getSema().getIdPagesProposeesPc()),"0","true");
     PagesProposeesPC pppc2 = PagesProposeesPC(std::to_string(e.getSema().getIdPagesProposeesPc()),"1","false");
     PagesProposeesPC pppc3 = PagesProposeesPC(std::to_string(e.getSema().getIdPagesProposeesPc()),"2","true");
     PagesProposeesPC pppc4 = PagesProposeesPC(std::to_string(e.getSema().getIdPagesProposeesPc()),"3","false");
     PagesProposeesPC pppc5 = PagesProposeesPC(std::to_string(e.getSema().getIdPagesProposeesPc()),"4","true");

     w.FichierPagesProposeesPcAjout(pppc);
     w.FichierPagesProposeesPcAjout(pppc2);
     w.FichierPagesProposeesPcAjout(pppc3);
     w.FichierPagesProposeesPcAjout(pppc4);
     w.FichierPagesProposeesPcAjout(pppc5);

     std::vector<std::string> vector8;
     vector8.push_back("0");
     vector8.push_back("2");
     std::vector<std::string> vector9;
     vector9.push_back("4");

     Cycle cy = Cycle(std::to_string(e.getSema().getIdCycle()),"3","true",vector8);
     Cycle cy2 = Cycle(std::to_string(e.getSema().getIdCycle()),"1","true",vector9);

     w.FichierCycleAjout(cy);
     w.FichierCycleAjout(cy2);

     std::vector<std::string> vector10;
     vector10.push_back("0");
     vector10.push_back("1");
     vector10.push_back("2");
     std::vector<std::string> vector11;
     vector11.push_back("4");
     vector11.push_back("5");

     PC pc = PC(std::to_string(e.getSema().getIdPc()),"0","3 rue de quelque part","54500","eee@test.com",vector10);
     PC pc2 = PC(std::to_string(e.getSema().getIdPc()),"1","15 avenue riche","74200","fff@test.com",vector11);

     w.FichierPcAjout(pc);
     w.FichierPcAjout(pc);
 }