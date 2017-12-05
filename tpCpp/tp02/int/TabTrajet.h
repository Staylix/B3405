/*************************************************************************
                    TabTrajet.h  -   Interface de TabTrajet.cpp
                                     Un tableau Dynamique de Trajet*
                           -------------------
    début                : 15/11/2017
    auteurs              : B3405 - Etienne et Grégoire
*************************************************************************/

//---------- Interface du module <TabTrajet> (fichier TabTrajet.h) -------
#if ! defined ( TabTrajet_H )
#define TabTrajet_H

//------------------------------------------------------------------------
// Rôle du module <TabTrajet>
// Stocke un tableau dynamique de Trajet *
//      Se réalloue automatiquement
//      Gère l'ajout de TrajetSimple
//      Dispose de Geters pour sa taille et ses trajets par indice
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"


class TabTrajet {
public:

//---------------------------------------------------- Fonctions publiques
    void Add ( const Trajet * t );
    // Contrat :
    //      Ajoute à la fin du tableau le pointeur de trajet passé en paramètre
    // Mode d'emploi:
    //      t un Trajet alloué, non deleted avant la fin de vie du TabTrajet

    const Trajet * Get ( unsigned int i ) const;
    // Contrat :
    //      Renvoi le pointeur de trajet positionné à la i-ème case du tableau,
    //      nullptr si i >= utilise
    // Mode d'emploi:
    //      i est un int positif inférieur à la taille de TabTrajet

    unsigned int GetUtilise() const;
    // Contrat :
    //      Renvoi le nombre de trajet contenu de le tableau

//-------------------------------------------- Constructeur et Destructeur
    TabTrajet();
    virtual ~TabTrajet();
    // Contrat :
    //      Fais appelle au destructeur adéquat sur chaque
    //      Trajet qui le compose, puis détruit le tableau

protected:
    unsigned int max;
    unsigned int utilise;
    const Trajet** listTrajet;
    void realloc ();
    // Contrat :
    //      Double la taille du tableau listTrajet contenant les Trajet *

};
#endif // TabTrajet_H
