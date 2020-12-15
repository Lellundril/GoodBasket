//
// Created by brian on 14/12/2020.
//
#include "Semaphore.h"

Semaphore::Semaphore(){
    id_produit = 0;
    id_page = 0;
    id_pc = 0;
    id_pages_proposees_pc = 0;
    id_cycle = 0;
    id_panier = 0;
    id_element_panier = 0;
}

int Semaphore::getIdProduit(){
    id_produit++;
    return id_produit-1;
}

int Semaphore::getIdPage(){
    id_page++;
    return id_page-1;
}

int Semaphore::getIdPc(){
    id_pc++;
    return id_pc-1;
}

int Semaphore::getIdPagesProposeesPc(){
    id_pages_proposees_pc++;
    return id_pages_proposees_pc-1;
}

int Semaphore::getIdCycle(){
    id_cycle++;
    return id_cycle-1;
}

int Semaphore::getIdPanier(){
    id_panier++;
    return id_panier-1;
}

int Semaphore::getIdElementPanier(){
    id_element_panier++;
    return id_element_panier-1;
}

void Semaphore::setIdProduit(int idProduit) {
    id_produit = idProduit;
}

void Semaphore::setIdPage(int idPage) {
    id_page = idPage;
}

void Semaphore::setIdPc(int idPc) {
    id_pc = idPc;
}

void Semaphore::setIdPagesProposeesPc(int idPagesProposeesPc) {
    id_pages_proposees_pc = idPagesProposeesPc;
}

void Semaphore::setIdCycle(int idCycle) {
    id_cycle = idCycle;
}

void Semaphore::setIdPanier(int idPanier) {
    id_panier = idPanier;
}

void Semaphore::setIdElementPanier(int idElementPanier) {
    id_element_panier = idElementPanier;
}