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
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//
//---------------------------------------------------- Constructor and Destructor

    TrajetCompose(TabTrajet t);
    virtual ~TrajetCompose ();


};
#endif // TrajetCompose_H


