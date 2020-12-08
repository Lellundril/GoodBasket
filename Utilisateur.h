//
// Created by lellundril on 08/12/2020.
//

#ifndef GOODBASKET_UTILISATEUR_H
#define GOODBASKET_UTILISATEUR_H

#include <string>

/**
 * @brief La classe Utilisateur est la classe définissant un compte d'un utilisateur.
 *
 * @author Guillaume LETZELTER
 */
class Utilisateur {
protected:
    /**
     * @brief Le nom d'utilisateur de l'Utilisateur est un chaîne de caractères C++.
     */
    std::string nomUtilisateur;
    /**
     * @brief Le mot de passe de l'Utilisateur est un chaîne de caractères C++.
     */
    std::string motDePasse;
    /**
     * @brief l'adresse e-mail de l'Utilisateur est une chaîne de caractères C++
     */
    std::string email;

    /**
     * @brief Booléen qui détermine si l'Utilisateur est un administrateur ou non.
     */
    bool admin;

    /**
     * @brief Booléen qui détermine si l'Utilisateur est un gérant de PointDeCollecte ou non.
     */
    bool pdc;

    /**
    * @brief Booléen qui détermine si l'Utilisateur est un producteur ou non.
    */
    bool producteur;

public:
    ///@brief Le constructeur par défaut ne fait rien.
    Utilisateur(){};

    /**
     * @brief Le constructeur permet de remplir les champs de la classe en
     * fonctions des paramètres passés.
     *
     * Ce constructeur est protégé pour que la Classe Compte reste abstraite:
     * seules ses classes filles peuvent être instanciées.
     *
     * @param nomUtilisateur le nom d'utilisateur de l'Utilisateur.
     * @param motDePasse le mot de passe de l'Utilisateur.
     *
     * @see nomUtilisateur, motDePasse.
     */
    Utilisateur(const std::string &nomUtilisateur, const std::string &motDePasse, const std::string &email);

    /// @brief Le destructeur ne fait rien, mais doit être défini comme abstrait
    virtual ~Utilisateur(){}

    /**
     * Cette fonction donne le nom d'utilisateur de l'Utilisateur.
     * @return le nom d'utilisateur de l'Utilisateur (dans une chaînes de caractères C++).
     *
     * @see nomUtilisateur.
     */
    const std::string &getNomUtilisateur() const;

    /**
     * Cette fonction permet de fixer le nom d'utilisateur de l'Utilisateur (inutilisée car nom constant).
     * @param nomUtilisateur le nouveau nom d'utilisateur.
     *
     * @see nomUtilisateur.
     */
    void setNomUtilisateur(const std::string &nomUtilisateur);

    /**
     * Cette fonction donne le mot de passe de l'Utilisateur.
     * @return le mot de passe du compte.
     *
     * @see motDePasse.
     */
    const std::string &getMotDePasse() const;

    /**
     * Cette fonction permet de fixer le mot de passe de l'Utilisateur.
     * @param motDePasse  le nouveau mot de passe.
     *
     * @see motDePasse.
     */
    void setMotDePasse(const std::string &motDePasse);

    /**
     * Cette fonction donne l'e-mail de l'utilisateur.
     * @return l'e-mail de l'Utilisateur.
     *
     * @see email.
     */
    const std::string &getEmail() const;

    /**
     * Cette fonction permet de fixer l'e-mail de l'Utilisateur.
     * @param email  Le nouvel e-mail.
     *
     * @see email
     */
    void setEmail(const std::string &email);

    /**
     * Cette fonction permet de vérifier si le mot de passe donné en paramètre est bien celui de l'Utilisateur.
     * @return vrai si le mot de passe correspond, faux sinon.
     */
    bool verifierMotDePasse(std::string);

    /**
     * Fonction permettant d'identifier si le Compte est un Compte Administrateur.
     * @return vrai si c'est un Administrateur, faux sinon.
     */
    bool estAdmin();
    /**
     * Fonction permettant d'identifier si le Compte est un Compte Producteur.
     * @return vrai si c'est un Producteur, faux sinon.
     */
    bool estProducteur();
    /**
     * Fonction permettant d'identifier si le Compte est un Compte Point de Collecte.
     * @return vrai si c'est un Point de Collecte, faux sinon.
     */
    bool estPDC();

    /**
     * Fonction permettant de fixer le booléen "admin" permettant de savoir si l'Utilisateur est un administrateur ou non.
     * @param admin  la nouvelle valeur du booléen
     *
     * @see admin
     */
    void setAdmin(bool admin);

    /**
     * Fonction permettant de fixer le booléen "pdc" permettant de savoir si l'Utilisateur est gérant de Point de Collecte ou non.
     * @param admin  la nouvelle valeur du booléen
     *
     * @see pdc
     */
    void setPdc(bool );

    /**
     * Fonction permettant de fixer le booléen "producteur" permettant de savoir si l'Utilisateur est un producteur ou non.
     * @param admin  la nouvelle valeur du booléen
     *
     * @see producteur
     */
    void setProducteur(bool producteur);
};


#endif //GOODBASKET_UTILISATEUR_H
