cmake_minimum_required(VERSION 3.17)
project(GoodBasket)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(GoodBasket
        Outils/Semaphore.h
        Outils/Semaphore.cpp
        Outils/ManipString.cpp
        Outils/ManipString.h
        Objets/Compte.cpp
        Objets/Compte.h
        Objets/Produit.cpp
        Objets/Produit.h
        Objets/PC.cpp
        Objets/PC.h
        Objets/Page.cpp
        Objets/Page.h
        Objets/Cycle.cpp
        Objets/Cycle.h
        Objets/Panier.cpp
        Objets/Panier.h
        Objets/ElementPanier.cpp
        Objets/ElementPanier.h
        Objets/PagesProposeesPC.cpp
        Objets/PagesProposeesPC.h
        BaseDeDonnee/ReadBDD.cpp
        BaseDeDonnee/ReadBDD.h
        Console.cpp
        General.h Objets/GeneralObjet.h BaseDeDonnee/WriteBDD.cpp BaseDeDonnee/WriteBDD.h)


