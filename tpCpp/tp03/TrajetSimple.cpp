/*************************************************************************
                            TrajetSimple.cpp
                             -------------------
    début                : 15/11/2017
    auteurs              : B3405 - Etienne et Grégoire
*************************************************************************/

//----- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp)

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string.h>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
string TrajetSimple::getDepart() const
{
  return depart;
}

string TrajetSimple::getArrivee() const
{
  return arrivee;
}

string TrajetSimple::getMoyen() const
{
  return moyen;
}

void TrajetSimple::Afficher() const
{
  cout << depart << " --> " << arrivee << " en " << moyen << endl;
}

void TrajetSimple::Ecrire(ofstream & os) const
{
    os << "TS" << endl;
    os << depart << endl;
    os << arrivee << endl;
    os << moyen << endl;
}
void TrajetSimple::Ecrire(ofstream & os, string type) const
{
    if (type == "TS")
    {
        os << "TS" << endl;
        os << depart << endl;
        os << arrivee << endl;
        os << moyen << endl;
    }
}

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple (string dep, string arr, string mt)
{
#if MAP
  cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
  depart = dep;
  arrivee = arr;
  moyen = mt;
}

TrajetSimple::~TrajetSimple ()
{
#if MAP
  cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
}
