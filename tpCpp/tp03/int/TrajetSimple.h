/*************************************************************************
                    TrajetSimple.h  -  Interface de TrajetSimple.cpp
                             -------------------
    début                : 15/11/2017
    auteurs              : B3405 - Etienne et Grégoire
*************************************************************************/

//------------ Interface du module <TrajetSimple> (fichier TrajetSimple.h)
#if ! defined ( TrajetSimple_H )
#define TrajetSimple_H

//------------------------------------------------------------------------
// Rôle du module <TrajetSimple>
// Manipule les trajets composés :
//      Création et destruction de trajets simples
//      Geter de depart et arrivée
//      Affichage du trajet
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"


class TrajetSimple : public Trajet {
public:

//---------------------------------------------------- Fonctions publiques
    virtual string getDepart() const;
    virtual string getArrivee() const;
    virtual string getMoyen() const;
    // Contrat :
    //      Renvoie le départ ou l'arrivée du trajet appelant la méthode

    virtual void Afficher() const;
    // Contrat :
    //      Affiche le trajet appelant la méthode

    virtual void Ecrire(ofstream & os) const;
    virtual void Ecrire(ofstream & os, string type) const;
//--------------------------------------------- Constructor and Destructor
    TrajetSimple(string dep, string arrivee, string mt);
    // Contrat :
    //      Construit un TrajetSimple à partir des arguments qui seront
    //      copiés en profondeur par le constructeur
    virtual ~TrajetSimple ();

protected:
    string depart;
    string arrivee;
    string moyen;

};
#endif // TrajetSimple_H
