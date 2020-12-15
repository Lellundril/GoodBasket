cmake_minimum_required(VERSION 3.17)
project(GoodBasket)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(GoodBasket
        Console.cpp
        Outils/Semaphore.h
        Outils/Semaphore.cpp
        BaseDeDonnee/EcrireBDD.cpp
        BaseDeDonnee/EcrireBDD.h
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
        General.h
        Objets/PagesProposeesPC.cpp
        Objets/PagesProposeesPC.h)
