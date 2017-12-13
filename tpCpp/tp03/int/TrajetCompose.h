/*************************************************************************
                    TrajetCompose.h  -  Interface de TrajetCompose.cpp
                             -------------------
    début                : 15/11/2017
    auteurs              : B3405 - Etienne et Grégoire
*************************************************************************/

//---------- Interface du module <TrajetCompose> (fichier TrajetCompose.h)
#if ! defined ( TrajetCompose_H )
#define TrajetCompose_H

//------------------------------------------------------------------------
// Rôle du module <TrajetCompose>
// Manipule les trajets composés :
//      Création et destruction de trajets composés
//      Geter de depart et arrivée
//      Affichage du trajet
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "TabTrajet.h"


class TrajetCompose : public Trajet {
public:
//---------------------------------------------------- Fonctions publiques
    virtual char * getDepart() const;
    virtual char * getArrivee() const;
    // Contrat :
    //      Renvoie le départ ou l'arrivée du trajet appelant la méthode

    virtual void Afficher() const;
    // Contrat :
    //      Affiche le trajet appelant la méthode

//--------------------------------------------- Constructor and Destructor
    TrajetCompose(TabTrajet * t);
    // Contrat :
    //      Crée un TrajetCompose à partie d'un TabTrajet composé de
    //      TrajetSimple
    // Mode d'emploi :
    //      t un TabTrajet alloué dynamiquement, non deleted avant la
    //      fin de vie du TrajetCompose courant

    virtual ~TrajetCompose ();

protected:
    TabTrajet *t;

};
#endif // TrajetCompose_H
