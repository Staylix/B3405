/*************************************************************************
                            TabTrajet.cpp
                             -------------------
    début                : 15/11/2017
    auteurs              : B3405 - Etienne et Grégoire
*************************************************************************/

//----------- Réalisation de la classe <TabTrajet> (fichier TabTrajet.cpp)

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TabTrajet.h"

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
void TabTrajet::Add ( const Trajet * t )
{
    if (this->utilise >= this->max)
    {
        this->realloc();
    }
    for (unsigned int i = 0; i < utilise; i++)
    {
        if (listTrajet[i] == t)
        {
            cout << "Trajet déjà présent dans le catalogue..." << endl;
            return;
        }
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

//-------------------------------------------- Constructeurs - destructeurs
TabTrajet::TabTrajet ( )
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
{
#ifdef MAP
    cout << "Appel au destructeur de <TabTrajet>" << endl;
#endif
    for (unsigned int i = 0; i < max; i++)
    {
        if (listTrajet[i] != nullptr)
        {
            delete listTrajet[i];
        }
    }
    delete [] listTrajet;
} //----- Fin de ~TabTrajet

//------------------------------------------------------------------ PRIVE
//------------------------------------------------------- Méthode protégée
void TabTrajet::realloc()
{
    const Trajet** newList = new const Trajet*[max*2];
    for (unsigned int i = 0; i < utilise; i++)
    {
        newList[i] = listTrajet[i];
    }
    for (unsigned int i = utilise; i < 2*max; i++)
    {
        newList[i] = nullptr;
    }
    const Trajet ** old = listTrajet;
    listTrajet = newList;
    delete [] old;
    max *= 2;
}
