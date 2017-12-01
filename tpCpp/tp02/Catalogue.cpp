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

void Catalogue::RechercherSimple(char * depart, char * arrivee) const      // TODO
{
    for (unsigned int i = 0; i < catalog->GetUtilise(); i++)
    {
        if ( !strcmp(depart, catalog->Get(i)->getDepart) && !strcmp(arrivee, catalog->Get(i)->getArrivee))
        {
            catalog->Get(i)->Afficher();
        }
    }
}

void Catalogue::RechercherAvancee(char * depart, char * arrivee) const     // TODO
{

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
