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

ofstream & TrajetCompose::operator << (ofstream & os, const Trajet * Traj)
{
    os << TC << t->GetUtilise() << endl;
    os << getDepart() << endl;
    os << getArrivee() << endl;
    for (unsigned int i = 0; i < t->GetUtilise(); i++)
    {
        os << Traj->Get(i)->getDepart() << endl;
        os << Traj->Get(i)->getArrivee() << endl;
        os << Traj->Get(i)->getMoyen() << endl;
    }
}
ifstream & TrajetCompose::operator >> (ifstream & is, const Trajet * Traj)
{
    String str;
    int nb;
    is >> str;
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
