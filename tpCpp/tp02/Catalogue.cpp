/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


void Catalogue::Afficher() const
{
    for (unsigned int i = 0; i < catalog->GetUtilise(); i++)
    {
        catalog->Get(i)->Afficher();
    }
}

void Catalogue::AjouterTrajet(const Trajet * T)
{
    catalog->Add(T);
}

void Catalogue::RechercherSimple(char * depart, char * arrivee) const
{
    for (unsigned int i = 0; i < catalog->GetUtilise(); i++)
    {
        if ( !strcmp(depart, catalog->Get(i)->getDepart()) && !strcmp(arrivee, catalog->Get(i)->getArrivee()))
        {
            catalog->Get(i)->Afficher();
        }
    }
}

void Catalogue::RechercherAvancee(char * depart, char * arrivee) const     // TODO
{
    int utilise[catalog->GetUtilise()];
    for (unsigned int i = 0; i < catalog->GetUtilise(); i++)
        {
            utilise[i] = 0;
        }

    for (unsigned int i = 0; i < catalog->GetUtilise(); i++)
    {
        if ( !strcmp(depart, catalog->Get(i)->getDepart()) )
        {
            recure(utilise, 1, i, arrivee);
        }
    }
}


void recure(int[] utilise, int numeroTrajet, int trajetPrecedent , char * arriveeFinale)
{
    if ( !strcmp(catalog->Get(trajetPrecedent)->getArrivee(), arriveeFinale) )     // Si on a trouvé un parcours
        AfficherParcours(utilise);
        return;

    for (unsigned int i = 0; i < catalog->GetUtilise(); i++)
    {
        if ( !strcmp(catalog->Get(i)->getDepart(), catalog->Get(trajetPrecedent)->getArrivee()) )
        {
            utilise[i] = numeroTrajet;
            recure(utilise, numeroTrajet + 1, i, arriveeFinale);
            utilise[i] = 0;
        }
    }
}

void AfficherParcours(int[] utilise)        // TODO
{
    indiceMax = max(utilise);
    for (unsigned int j = 1; j <= indiceMax; j++)
    {
        for (unsigned int i = 0; i < catalog->GetUtilise(); i++)
        {
            if (j = utilise[i])
            {
                catalog->Get(i)->Afficher();
            }
        }
    }
    cout << endl;
}

int Catalogue::max(int[] tab)       // On sait que tab (qui sera utilise) est de la taille de catalog
// Cette méthode va servir pour afficher un parcours trouvé
{
    int maxi = 0
    for (unsigned int i = 0; i < catalog->GetUtilise(); i++)
    {
        if (tab[i] > maxi) maxi = tab[i];
    }
    return maxi
}


//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
    catalog = new TabTrajet;
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
    delete catalog;
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//-------------------------- Méthode privée ? A vérifier

const trajet * etape (const trajet * precedent, const trajet * actuel, const trajet * suivant)      // Ligne à supprimer


bool suivant(const trajet * arriveeEtapePrec, char * arriveeFinale)
{
    for (unsigned int i = 0; i < catalog->GetUtilise(); i++)
    {
        if ( !strcmp(arriveeEtapePrec, catalog->Get(i)->getDepart()) )
        {
            if ( !strcmp(arriveeFinale, catalog->Get(i)->getArrivee()) )
            {
                cout
            }
        }
    }
}


//----------------------------------------------------- Méthodes protégées
