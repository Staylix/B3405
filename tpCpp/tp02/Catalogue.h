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
// Gere le catalogue, Ajouter des trajets, Afficher le catalogue, rechercher les parcours
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées

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

    void AjouterTrajet();
    // Contrat :
    //      Lis l'entrée standard
    //      Cree l'objet adequat: TrajetSimple ou TrajetCompose
    //      et l'ajoute au catalogue

    void Afficher() const;
    // Mode d'emploi :
    //      Affiche le catalogue des Trajets

    void Rechercher() const;
    // Mode d'emploi :
    //      Lis l'entrée standard pour récupérer la ville de départ et celle d'arrivée
    //      Affiche les parcours correspondant à la demande utilisateur si possible

//---------------------------------------------------- Constructor and Desctructor

    Catalogue();
    virtual ~Catalogue();

};
#endif // Catalogue_H

