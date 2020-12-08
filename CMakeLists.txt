cmake_minimum_required(VERSION 3.17)
project(GoodBasket)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(GoodBasket
        GestionnaireUtilisateurs.cpp
        GestionnaireUtilisateurs.h
        Console.cpp
        Produit.cpp
        Produit.h
        Utilisateur.cpp
        Utilisateur.h)
