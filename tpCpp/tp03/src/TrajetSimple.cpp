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
char * TrajetSimple::getDepart() const
{
  return depart;
}

char * TrajetSimple::getArrivee() const
{
  return arrivee;
}

char * TrajetSimple::getMoyen() const
{
  return moyen;
}

void TrajetSimple::Afficher() const
{
  cout << depart << " --> " << arrivee << " en " << moyen << endl;
}

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple (char *dep, char * arr, char * mt)
{
#if MAP
  cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
  depart = new char[strlen(dep)+1];
  arrivee = new char[strlen(arr)+1];
  moyen = new char[strlen(mt)+1];
  if (depart == nullptr || arrivee == nullptr || moyen == nullptr)
  {
    cerr << "Erreur lors de l'alloc des attributs du TrajetSimple" << endl;
  }
  strcpy(depart, dep);
  strcpy(arrivee ,arr);
  strcpy(moyen, mt);
}

TrajetSimple::~TrajetSimple ()
{
#if MAP
  cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
  delete [] depart;
  delete [] arrivee;
  delete [] moyen;
}
