//
// Created by brian on 09/12/2020.
//

#ifndef GOODBASKET_INTERFACE_H
#define GOODBASKET_INTERFACE_H

class Interface{
    private:
        int choixAction;
        int choixCompte;
        int choixProc1;
        int choixConso1;
        int choixRespo1;
        bool connecte;

    public:
        Interface();
        int getChoixAction()const;
        void setChoixAction(int choixAction);
        int getChoixCompte()const;
        void setChoixCompte(int choixCompte);
        bool isConnecte()const;
        void setConnecte(bool connecte);

    int getChoixProc1() const;

    void setChoixProc1(int choixProc1);

    int getChoixConso1() const;

    void setChoixConso1(int choixConso1);

    int getChoixRespo1() const;

    void setChoixRespo1(int choixRespo1);

    bool getConnecte() const;
};


#endif //GOODBASKET_INTERFACE_H
