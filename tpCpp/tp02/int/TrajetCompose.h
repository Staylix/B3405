/*************************************************************************
                           TrajetCompose  -  Interface de TrajetCompose
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface du module <TrajetCompose> (fichier TrajetCompose.h) -------------------
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
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

class TrajetCompose : public Trajet {
    public:
//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
    virtual char * getDepart() const;
    virtual char * getArrivee() const;
    // Contrat :
    //      Renvoie le départ ou l'arrivée du trajet appelant la méthode

    virtual void Afficher() const;
    // Contrat :
    //      Affiche le trajet appelant la méthode

//---------------------------------------------------- Constructor and Destructor

    TrajetCompose(TabTrajet & t);
    virtual ~TrajetCompose ();

    protected:
      TabTrajet *t;


};
#endif // TrajetCompose_H
