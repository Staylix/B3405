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
// Stocke un tableau dynamique de Trajet *
//      Se réalloue automatiquement
//      Gère l'ajout de TrajetSimple
//      Dispose de Geters pour sa taille et ses trajets par indice
//
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
    // Contrat :
    //      Ajoute à la fin du tableau le pointeur de trajet passé en paramètre

    const Trajet * Get ( unsigned int i ) const;
    // Contrat :
    //      Renvoi le pointeur de trajet positionné à la i-ème case du tableau

    unsigned int GetUtilise() const;
    // Contrat :
    //      Renvoi le nombre de trajet contenu de le tableau

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
