//
// Created by Lellundril on 21/11/2020.
//

#include <iostream>
#include <limits>
#include <sstream>
#include "Utilisateur.h"
#include "GestionnaireUtilisateurs.h"

/**
 * @brief La classe Console est la classe d'affichage sur terminal de l'application.
 * C'est par cette classe que l'utilisateur peut interragir
 *
 * @author Guillaume LETZELTER
 */

int choixAction = 0;
bool connecte = false;
GestionnaireUtilisateurs gestionnaireUtilisateurs;
Utilisateur* compteConnecte = nullptr;

void connecterCompte();
void creerCompte();
void seDeconnecter();
void afficherTousLesComptes();

/**
 * Fonction renvoyant un nombre entier renvoyé par l'utilisateur.
 * @return un nombre donné par l'utilisateur.
 */
// Récupère une entrée numérique seulement
int entrerChoixNumerique() {
    int varChoix;
    std::cin >> varChoix;

    //Si l'entrée n'est pas un nombre
    while(!std::cin) // ou si (cin.fail())
    {
        std::cin.clear(); // reset failbit
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignorer l'entrée incorrecte
        // Ensuite, redemander une entrée
        std::cout << "Vous devez entrez un nombre" << std::endl;
        std::cin >> varChoix;
    }
    return varChoix;
}

// Vrai si l'utilisateur est connecté à un compte, Faux sinon
bool estConnecte() {
    return connecte;
}
/**
 * Fonction affichant un menu de choix listant tout ce que l'utilisateur peut faire.
 * Ce menu change en fonction des circonstances. Par exemple, un utilisateur connecté avec
 * un compte Consommateur n'aura pas les mêmes choix que s'il est connecté à un compte Point de Collecte.
 */
// Présente et donne à l'utilisateur l'accès aux différentes interactions avec le système
void menuChoix() {
    if (connecte){ // Si l'utilisateur est connecté, on lui informe, et avec quel compte
        std::cout << "Vous etes connecte avec " << compteConnecte->getNomUtilisateur();
    }
    else{
        std::cout << "Non connecte";
    }
    // Liste des choix d'actions
    std::cout << ".......................\n";
    std::cout << "Entrez votre choix:  \n";
    // Choix disponibles si déconnecté
    if (!connecte){
        std::cout << "1. Se connecter\n";
        std::cout << "2. Creer un compte\n";
    }// Choix disponibles si connecté
    if (connecte){
        std::cout << "3. Se deconnecter\n";
    }
    //Choix disponibles tout le temps
    std::cout << "99. Afficher tous les comptes\n"; //DEBUG
    std::cout << "-1. Quitter";
    std::cout << ".........................." << std::endl;
    choixAction = entrerChoixNumerique();

    //TODO: FACTORISER CI DESSOUS SI POSSIBLE

    // Empêche l'accès à certains choix selon si l'utilisateur est connecté ou non
    while (connecte && (choixAction == 1 || choixAction == 2)){
        std::cout << "Entrez un choix valide parmi ceux affiches" << std::endl;
        choixAction = entrerChoixNumerique();
    }
    while (!connecte && (choixAction == 3)){
        std::cout << "Entrez un choix valide parmi ceux affiches" << std::endl;
        choixAction = entrerChoixNumerique();
    }
}

/**
 * Fonction traitant la valeur de @var choixAction et exécutant des fonctions selon celle-ci.
 * @see choixAction
 */
// Exécute les fonctions selon la valeur de la variable de choix (choisi pas l'utilisateur ou donné par certaines fonctions)
void traiterChoix() {
    switch (choixAction) {
        case 1:
            connecterCompte();
            break;
        case 2:
            creerCompte();
            break;
        case 3:
            seDeconnecter();
            break;
        case 99:
            afficherTousLesComptes();
            break;
        case -1:
            //quitterPlateforme();
            break;
        default: // Si l'utilisateur entre un choix  inexistant, réaffiche le menu
            menuChoix();
            break;
    }
}

/**
* Fonction permettant à l'utilisateur de créer un Compte.
*/
// Permet à l'utilisateur de créer un comtpe avec un nom et un mot de passe. Le compte une fois créé est stocké par le gestionnaire de comptes
void creerCompte() {
    std::string nom, mdp, email;
    int choixType;

    std::cout << "Entrez un e-mail\n";
    std::cin >> email;
    std::cout << "Entrez un nom d'utilisateur\n";
    std::cin >> nom;
    std::cout << "Entrez un mot de passe\n";
    std::cin >> mdp;

    gestionnaireUtilisateurs.ajouterUtilisateur(new Utilisateur(nom, mdp, email)); //TODO: Faut changer ça, de sorte que le "new" se trouve directement dans la classe Gestionnaire

    std::cout << "Votre compte a ete cree";
    std::cout << std::endl;
    choixAction = 0; //Retour au menu
}

/**
 * Fonction permettant à l'utilisateur de se connecter à un compte (existant dans le gestionnaire).
 */
// Permet à l'utilisateur de se connecter à un compte si celui-ci existe et si il renseigne le bon mot de passe
void connecterCompte() {
    std::string nom, mdp;
    if (!gestionnaireUtilisateurs.estVide()){ // Si aucun compte n'est connu du Gestionnaire, on renseigne l'utilisateur et rien de plus
        std::cout << "Connectez vous a votre compte" << std::endl;
        std::cout << "Nom d'utilisateur:  ";
        std::cin >> nom;
        std::cout << std::endl;
        try{// Block try/catch qui arrêtera la fonction si le nom de compte entré n'est pas connu du Gestionnaire
            Utilisateur* c = gestionnaireUtilisateurs.getUtilisateur(nom);
            std::cout << "Mot de passe:  ";
            std::cin >> mdp;
            std::cout << std::endl;
            if (c->verifierMotDePasse(mdp)){ // Vérification du mot de passe entré. S'il est correct, l'utilisateur est connecté, sinon on arrête la procédure net (pour l'instant)
                connecte = true;
                compteConnecte = c;
                std::cout << "Bienvenue, " << nom << " !" << std::endl;
            }
            else{
                std::cout << "Mot de passe incorrect" << std::endl;
            }
        }
        catch (const char* msg) {
            std::cerr << msg << std::endl;
        }
    }
    else{
        std::cout << "Aucun compte n'est disponible" << std::endl;
    }
    choixAction = 0; // Permet le renvoie au menu
}

/**
 * Fonction permettant à l'utilisateur de se déconnecter du Compte auquel il est connecté.
 */
// Déconnecte l'utilisateur de son compte
void seDeconnecter() {
    std::cout << "Deconnexion..." << std::endl;
    connecte = false;
    compteConnecte = nullptr;
    choixAction = 0;
}

/**
 * Fonction nettoyant toutes les données de la session et quittant l'application.
 */
// Permet de quitter l'application "correctement"
void quitter() {
    std::cout << "A bientot !" << std::endl;
    exit(0);
}

/**
 * Affiche tous les comptes connus du gestionnaire de Comptes de la Console.
 */
// Affiche tous les mots de passe sous la forme:
void afficherTousLesComptes() {
    std::cout << gestionnaireUtilisateurs.toString() << std::endl;
    choixAction = 0;
}


//Fonctions Utilisateur
/**
 * Fonction permettant au Consommateur de consulter la liste des Points de Collecte disponibles.
 */
void consulterListePDC();

/**
 * Fonction permettant au Consommateur de consulter un Point De Collecte sélectionné.
 * @param index l'indice du Point de collecte sélectionné
 */
void consulterPDC(/*parametre pour connaître le PDC choisit*/);

/**
 * Fonction permettant au Consommateur de consulter ses paniers.
 */
void consulterPaniers();

/**
 * Fonction permettant au Consommateur de consulter les Point de Collectes auxquels il est abonnés.
 */
void consulterAbonnements();

//Fonction Producteur
// !!!!!!! Je ne sais pas si on garde l'histoire des pages-vitrine, donc on verra si on définit ses fonctions ou non !!!!!!!
// !!!!!!! On aura sûrement uen variation de ses fonctions dans le cas où on change de système !!!!!!!
/**
 * Fonction permettant au producteur de consulter ses pages-vitrines.
 */
void consulterPagesVitrines();

/**
 * Fonction permettant au producteur de définir la page-vitrine qui sera mise en avant.
 */
void definirPageVitrine();

/**
 * Fonction permettant au producteur de créer une nouvelle Page-Vitrine.
 */
void creerPageVitrine();

/**
 * Fonction permettant au producteur d'ajouter un produit dans la Page-Vitrine.
 */
void ajouterProduit();

/**
 * Fonction permettant au producteur de supprimer un produit de la Page-Vitrine.
 */
void supprimerPrdouit();

/**
 * Fonction permettant au producteur de modifier un produit (quantité, prix) de la Page-Vitrine.
 */
void modifierProduit();

/**
 * Fonction permettant au producteur de supprimer une Page-Vitrine.
 */
void supprimerPageVitrine();
// !!!!!!! Je ne sais pas si on garde l'histoire des pages-vitrine, donc on verra si on définit ses fonctions ou non !!!!!!!



//Fonction PDC
/**
 * Fonction permettant au Point de Collecte de consulter la liste des producteurs.
 */
void consulterProducteurs();

/**
 * Fonction permettant au Point de Collecte de démarrer un cycle de vente.
 */
void lancerCycleVente();

/**
 * Fonction permettant au Point de Collecte d'arrêter un cycle de vente.
 */
void arreterCycleVente();


/**
 * Fonction renvoyant l'utilisateur au menu principal.
 */
void retourMenu();

int main(){
    std::cout << "Bienvenue sur GoodBasket" << std::endl;
    // Tant que l'utilisateur n'a pas voulu sortir, on traite la variable de choix
    while (choixAction != -1){
        traiterChoix();
    }
    quitter();
}