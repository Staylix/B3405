/*************************************************************************
                            TrajetCompose.cpp
                             -------------------
    début                : 15/11/2017
    auteurs              : B3405 - Etienne et Grégoire
*************************************************************************/

//--- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp)

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
char * TrajetCompose::getDepart() const
{
    return t->Get(0)->getDepart();
}

char * TrajetCompose::getArrivee() const
{
    unsigned int i = t->GetUtilise();
    return t->Get(i-1)->getArrivee();
}

void TrajetCompose::Afficher() const
{
    cout << getDepart() << " ----> " << getArrivee() << " via :" << endl;
    unsigned int max = t->GetUtilise();
    for (unsigned int i=0; i<max; i++)
    {
        cout << "\t";
        t->Get(i)->Afficher();
    }
    return;
}

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose (TabTrajet * tab)
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
    t = tab;
} //----- Fin de TrajetCompose

TrajetCompose::~TrajetCompose ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
    delete t;
} //----- Fin de ~TrajetCompose
