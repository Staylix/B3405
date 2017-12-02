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



int Catalogue::max(int utilise[]) const       // On sait que tab (qui sera utilise) est de la taille de catalog
// Cette méthode va servir pour afficher un parcours trouvé
{
    int maxi = 0;
    for (unsigned int i = 0; i < catalog->GetUtilise(); i++)
    {
        if (utilise[i] > maxi) maxi = utilise[i];
    }
    return maxi;
}

void Catalogue::AfficherParcours(int utilise[]) const
{
    int indiceMax = this->max(utilise);
    for (int j = 1; j <= indiceMax; j++)
    {
        for (unsigned int i = 0; i < catalog->GetUtilise(); i++)
        {
            if (j == utilise[i])
            {
                catalog->Get(i)->Afficher();
            }
        }
    }
    cout << endl;
}

void Catalogue::recure(int utilise[], int numeroTrajet, int trajetPrecedent , char * arriveeFinale) const
{
    if ( !strcmp(catalog->Get(trajetPrecedent)->getArrivee(), arriveeFinale) )     // Si on a trouvé un parcours
        this->AfficherParcours(utilise);
        return;

    for (unsigned int i = 0; i < catalog->GetUtilise(); i++)
    {
        if ( !strcmp(catalog->Get(i)->getDepart(), catalog->Get(trajetPrecedent)->getArrivee()) )
        {
            utilise[i] = numeroTrajet;
            this->recure(utilise, numeroTrajet + 1, i, arriveeFinale);
            utilise[i] = 0;
        }
    }
}

void Catalogue::RechercherAvancee(char * depart, char * arrivee) const
{
    int * utilise = new int[catalog->GetUtilise()];
    for (unsigned int i = 0; i < catalog->GetUtilise(); i++)
    {
        for (unsigned int i = 0; i < catalog->GetUtilise(); i++)
            {
                utilise[i] = 0;
            }
        if ( !strcmp(depart, catalog->Get(i)->getDepart()) )
        {
            this->recure(utilise, 1, i, arrivee);
        }
    }
    delete [] utilise;
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

//----------------------------------------------------- Méthodes protégées
