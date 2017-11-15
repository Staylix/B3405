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

    void add ( const Trajet & t );
    // Mode d'emploi :
    //      Ajoute à la fin du tableau la référence de l'élément passé en paramètre

    Trajet & get ( unsigned int i ) const;
    // Mode d'emploi :
    //      Renvoi l'objet positionné à la i-ème case du tableau

    TabTrajet();
    virtual ~TabTrajet();

};
#endif // TabTrajet_H
