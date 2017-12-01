/*************************************************************************
                           Catalogue.h  -  Interface de Catalogue.cpp
                                           La seule classe auquel le Main a accès
                             -------------------
    début                : 15/11/2017
    copyright            : (C) $YEAR$ par Greg & Etienne
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface du module <Catalogue> (fichier Catalogue.h) -------------------
#if ! defined ( Catalogue_H )
#define Catalogue_H

//------------------------------------------------------------------------
// Rôle du module <Catalogue>
// Gere le catalogue, Ajouter des trajets, Afficher le catalogue, Rechercher les parcours
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "TabTrajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

class Catalogue {
//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//
public:

    void Afficher() const;
    // Mode d'emploi :
    //      Affiche le catalogue des Trajets

    void AjouterTrajet(const Trajet * T);
    // Contrat :
    //      Lis l'entrée standard
    //      Cree l'objet adequat: TrajetSimple ou TrajetCompose
    //      et l'ajoute au catalogue

    void RechercherSimple(char *, char *) const;
    // Mode d'emploi :
    //      Lis l'entrée standard pour récupérer la ville de départ et celle d'arrivée
    //      Affiche les parcours correspondant à la demande utilisateur si possible

    void RechercherAvancee(char *, char *) const;
    // Mode d'emploi :
    //      Lis l'entrée standard pour récupérer la ville de départ et celle d'arrivée
    //      Affiche les parcours correspondant multiples à la demande utilisateur si possible

//---------------------------------------------------- Constructor and Desctructor

    Catalogue();
    virtual ~Catalogue();

protected:
    TabTrajet * catalog;

};
#endif // Catalogue_H
