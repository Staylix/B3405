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

void TabTrajet::Add ( const Trajet * t )
{
  if (this->utilise >= this->max)
  {
      this->realloc();
  }
  this->listTrajet[this->utilise] = t;
  this->utilise++;
  return;
}


const Trajet * TabTrajet::Get ( unsigned int i ) const
{
    if (i >= this->utilise)
    {
        return nullptr;
    }
    return this->listTrajet[i];
}

unsigned int TabTrajet::GetUtilise() const
{
  return this->utilise;
}


//-------------------------------------------- Constructeurs - destructeur
TabTrajet::TabTrajet ( const TabTrajet & unTabTrajet )  //constructeur de copie
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TabTrajet>" << endl;
#endif
    max = unTabTrajet.max;
    utilise = unTabTrajet.utilise;
    listTrajet = new const Trajet*[max];
    for (unsigned int i = 0; i < utilise; i++)
    {
        listTrajet[i] = unTabTrajet.listTrajet[i];
    }
} //----- Fin de TabTrajet (constructeur de copie)


TabTrajet::TabTrajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TabTrajet>" << endl;
#endif
    max = 5;
    utilise = 0;
    listTrajet = new const Trajet*[max];
    for (unsigned int i = 0; i < max; i++)
    {
      listTrajet[i] = nullptr;
    }
} //----- Fin de TabTrajet


TabTrajet::~TabTrajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TabTrajet>" << endl;
#endif
    
    for (unsigned int i = 0; i < utilise; i++)
    {
        if(listTrajet[i] != nullptr)
        {
          delete listTrajet[i];
          listTrajet[i] = nullptr;
        }
    }
    delete [] listTrajet;
} //----- Fin de ~TabTrajet


//------------------------------------------------------------------ PRIVE

void TabTrajet::realloc()
{
    const Trajet** newList = new const Trajet*[max*2];
    for (unsigned int i = 0; i < utilise; i++)
    {
        listTrajet[i] = listTrajet[i];
    }
    listTrajet = newList;
    delete [] listTrajet;
    max = max * 2;
}


//----------------------------------------------------- Méthodes protégées
