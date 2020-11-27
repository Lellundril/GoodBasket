//
// Created by Lellundril on 21/11/2020.
//

#ifndef GOODBASKET_COMPTE_H
#define GOODBASKET_COMPTE_H

#include <string>

/**
 * @brief La classe Compte est la classe mère de chaque type de compte.
 *
 * @author Guillaume LETZELTER
 */
class Compte{
protected:
    /**
     * @brief Le nom d'utilisateur du Compte est un chaîne de caractères C++.
     */
    std::string nomUtilisateur;
    /**
     * @brief Le mot de passe du Compte est un chaîne de caractères C++.
     */
    std::string motDePasse;

    ///@brief Le constructeur par défaut ne fait rien.
    Compte(){};

    /**
     * @brief Le constructeur permet de remplir les champs de la classe en
     * fonctions des paramètres passés.
     *
     * Ce constructeur est protégé pour que la Classe Compte reste abstraite:
     * seules ses classes filles peuvent être instanciées.
     *
     * @param nomUtilisateur le nom d'utilisateur du compte.
     * @param motDePasse le mot de passe du compte.
     *
     * @see nomUtilisateur, motDePasse.
     */
    Compte(const std::string &nomUtilisateur, const std::string &motDePasse);
public:
    /// @brief Le destructeur ne fait rien, mais doit être défini comme abstrait
    virtual ~Compte(){}

    /**
     * Cette fonction donne le nom d'utilisateur du compte.
     * @return le nom d'utilisateur du compte (dans une chaînes de caractères C++).
     *
     * @see nomUtilisateur.
     */
    const std::string &getNomUtilisateur() const;

    /**
     * Cette fonction permet de fixer le nom d'utilisateur du compte (inutilisée car nom constant).
     * @param nomUtilisateur le nouveau nom d'utilisateur.
     *
     * @see nomUtilisateur.
     */
    void setNomUtilisateur(const std::string &nomUtilisateur);

    /**
     * Cette fonction donne le mot de passe du compte.
     * @return le mot de passe du compe.
     *
     * @see motDePasse.
     */
    const std::string &getMotDePasse() const;

    /**
     * Cette fonction permet de fixer le mot de passe du compte.
     * @param motDePasse  le nouveau mot de passe.
     *
     * @see motDePasse.
     */
    void setMotDePasse(const std::string &motDePasse);

    /**
     * Cette fonction permet de vérifier si le mot de passe donné en paramètre est bien celui du Compte.
     * @return vrai si le mot de passe correspond, faux sinon.
     */
    bool verifierMotDePasse(std::string);

    /**
     * Fonction abstraite permettant d'identifier si le Compte est un Compte Consommateur.
     * @return vrai si c'est un Consommateur, faux sinon.
     */
    virtual bool estConsommateur();
    /**
     * Fonction abstraite permettant d'identifier si le Compte est un Compte Producteur.
     * @return vrai si c'est un Producteur, faux sinon.
     */
    virtual bool estProducteur();
    /**
     * Fonction abstraite permettant d'identifier si le Compte est un Compte Point de Collecte.
     * @return vrai si c'est un Point de Collecte, faux sinon.
     */
    virtual bool estPDC();

    /**
     * Cette fonction abstraite renvoie le type du compte sous forme de chaîne de caractère C++.
     * @return
     */
    virtual std::string getTypeString();
};

#endif //GOODBASKET_COMPTE_H
