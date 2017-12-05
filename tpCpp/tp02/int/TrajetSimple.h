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
// Manipule les trajets composés :
//      Création et destruction de trajets simples
//      Geter de depart et arrivée
//      Affichage du trajet
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

class TrajetSimple : public Trajet {
    public:
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//
//---------------------------------------------------- Constructor and Destructor

    TrajetSimple(char * dep, char * arrivee, char * mt);
    // Contrat :
    //      Construit un TrajetSimple à partir des arguments qui seront copiés
    //      en profondeur dans le constructeur
    virtual ~TrajetSimple ();


//---------------------------------------------------- Fonctions publiques

    virtual char * getDepart() const;
    virtual char * getArrivee() const;
    // Contrat :
    //      Renvoie le départ ou l'arrivée du trajet appelant la méthode

    virtual void Afficher() const;
    // Contrat :
    //      Affiche le trajet appelant la méthode

    protected:
      char * depart;
      char * arrivee;
      char * moyen;

};
#endif // TrajetSimple_H
