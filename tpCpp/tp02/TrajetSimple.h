/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface du module <TrajetSimple> (fichier TrajetSimple.h) -------------------
#if ! defined ( TrajetSimple_H )
#define TrajetSimple_H

//------------------------------------------------------------------------
// Rôle du module <TrajetSimple>
//
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

class TrajetSimple : public Trajet {
    public:
//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//
//---------------------------------------------------- Constructor and Destructor

    TrajetSimple(char * dep = "Saint-Egreve", char * arrivee = "Grenoble", char * mt = "Hyppogriffe");
    virtual ~TrajetSimple ();


};
#endif // TrajetSimple_H


