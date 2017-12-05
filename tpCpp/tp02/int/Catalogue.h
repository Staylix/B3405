/*************************************************************************
                    Catalogue.h  -  Interface de Catalogue.cpp
                                    La seule classe auquel le Main a accès
                             -------------------
    début                : 15/11/2017
    auteurs              : B3405 - Etienne et Grégoire
*************************************************************************/

//-------- Interface du module <Catalogue> (fichier Catalogue.h) ---------
#if ! defined ( Catalogue_H )
#define Catalogue_H

//------------------------------------------------------------------------
// Rôle du module <Catalogue>
// Gere le catalogue :
//      Ajouter des trajets
//      Afficher le catalogue
//      Rechercher les parcours (simple ou avancée)
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "TabTrajet.h"


class Catalogue {
//---------------------------------------------------- Fonctions publiques

public:

    void Afficher() const;
    // Contrat :
    //      Affiche le catalogue des Trajets

    void AjouterTrajet(const Trajet * T);
    // Contrat :
    //      Ajoute un trajet (simple ou composé) au catalogue
    //      en utilisant la fonction Add de la classe TabTrajet
    // Mode d'emploi
    //      T est un Trajet alloué dans le tas,
    //      non détruit avant la fin de vie du Catalogue

    void RechercherSimple(const char * dep, const char *arr) const;
    // Contrat :
    //      Affiche les trajets (simples ou composés) dont le départ
    //      et l'arrivée correspondent aux paramètres

    void RechercherAvancee(const char *dep, const char *arr) const;
    // Contrat :
    //      Affiche les parcours réalisables à partir des trajets du
    //      catalogue, dont le départ et l'arrivée correspondent
    //      aux paramètres

//-------------------------------------------- Constructor and Desctructor

    Catalogue();
    virtual ~Catalogue();
    // Mode d'emploi :
    //      Fait appel au destructeur de TabTrajet


protected:
    TabTrajet * catalog;

    int max(int tab[]) const;
    // Contrat :
    //      Renvoie l'entier maximal parmis les éléments
    //      du tableau passé en paramètre

    void AfficherParcours(int utilise[]) const;
    // Contrat :
    //      Affiche le parcours composé des trajets décrits
    //      par le tableau passé en paramètre
    // Mode d'emploi:
    //      utilise est un int[] représentant le parcours à afficher,
    //      les valeurs correspondant à l'ordre d'affichage

    void recure(int utilise[], int numeroTrajet, int trajetPrecedent , const char * arriveeFinale) const;
    // Contrat :
    //      Fonction récursive qui permet de tester tous les parcours
    //      réalisables à partir des trajets du catalogue, partant du
    //      départ demandé et qui appelle l'affichage lorsque le
    //      parcours arrive à destination
    // Mode d'emploi :
    //      utilise : Tableau représentant le parcours courant
    //      numeroTrajet : Numéro du trajet dans le parcours courant
    //      trajetPrecedent : Indice du trajet précédent dans le Catalogue
    //      arriveeFinale : Arrivee demandée par le client
};

#endif // Catalogue_H
