/*************************************************************************
                           TabTrajet.h  -   Interface de TabTrajet.cpp
                                            Un tableau Dynamique de Trajet *
                           -------------------
    début                : 15/11/2017
    copyright            : (C) $YEAR$ par Greg & Etienne
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface du module <TabTrajet> (fichier TabTrajet.h) -------------------
#if ! defined ( TabTrajet_H )
#define TabTrajet_H

//------------------------------------------------------------------------
// Rôle du module <TabTrajet>
// Stocke un tableau dynamique de Trajet * et se réalloue automatiquement
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées

#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

class TabTrajet {
//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//
public:

    void Add ( const Trajet * t );
    // Mode d'emploi :
    //      Ajoute à la fin du tableau le pointeur de l'élément passé en paramètre

    const Trajet * Get ( unsigned int i ) const;
    // Mode d'emploi :
    //      Renvoi l'objet positionné à la i-ème case du tableau

    unsigned int GetUtilise() const;

    TabTrajet ( const TabTrajet & unTabTrajet );            // Constructeur de copie
    TabTrajet();                                            // Constructeur
    virtual ~TabTrajet();

protected:
    unsigned int max;
    unsigned int utilise;
    const Trajet** listTrajet;

private:
    void realloc ();

};
#endif // TabTrajet_H
