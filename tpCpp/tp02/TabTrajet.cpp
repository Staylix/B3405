/*************************************************************************
                           TabTrajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TabTrajet> (fichier TabTrajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TabTrajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TabTrajet::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

    void TabTrajet::add ( const Trajet & t )
    {
        if (this->max <= this->utilise)
        {
            realloc(this);
        }
        this->listTrajet[this->utilise] = t;
        this->utilise++;
        return;
    }

    void TabTrajet::realloc()
    {

        Trajet** newList = new (Trajet*)[this->max*2];
        
        this->max = this->max * 2;
    }

//------------------------------------------------- Surcharge d'opérateurs
TabTrajet & TabTrajet::operator = ( const TabTrajet & unTabTrajet )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
TabTrajet::TabTrajet ( const TabTrajet & unTabTrajet )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TabTrajet>" << endl;
#endif
} //----- Fin de TabTrajet (constructeur de copie)


TabTrajet::TabTrajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TabTrajet>" << endl;
#endif
} //----- Fin de TabTrajet


TabTrajet::~TabTrajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TabTrajet>" << endl;
#endif
    delete [] listTrajet;
} //----- Fin de ~TabTrajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

