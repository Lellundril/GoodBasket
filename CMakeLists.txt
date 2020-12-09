cmake_minimum_required(VERSION 3.17)
project(GoodBasket)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(GoodBasket
        Console.cpp
        Produit.cpp
        Produit.h
        interface/Interface.cpp
        interface/Interface.h
        Compte/Compte.cpp
        Compte/Compte.h
        Compte/CompteConso.cpp
        Compte/CompteConso.h
        Compte/CompteProc.cpp
        Compte/CompteProc.h
        Compte/CompteRespo.cpp
        Compte/CompteRespo.h
        Compte/GestionnaireCompte.cpp
        Compte/GestionnaireCompte.h interface/InterfaceEntree.cpp interface/InterfaceEntree.h Outils/EntreeClavier.cpp Outils/EntreeClavier.h interface/Conso/InterfaceConso.cpp interface/Conso/InterfaceConso.h interface/Proc/InterfaceProc.cpp interface/Proc/InterfaceProc.h interface/Respo/InterfaceRespo.cpp interface/Respo/InterfaceRespo.h)
