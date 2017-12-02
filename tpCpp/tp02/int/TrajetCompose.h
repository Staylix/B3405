/*************************************************************************
                           TrajetCompose  -  description
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
//
//
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
    // Mode d'emploi :
    //      Renvoie le départ ou l'arrivée

    virtual void Afficher() const;
    // Mode d'emploi :
    //      Affiche le Trajet

//---------------------------------------------------- Constructor and Destructor

    TrajetCompose(TabTrajet & t);
    virtual ~TrajetCompose ();

    protected:
      TabTrajet *t;


};
#endif // TrajetCompose_H


