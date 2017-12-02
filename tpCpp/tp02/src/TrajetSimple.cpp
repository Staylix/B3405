//-------------Realisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp)

using namespace std;
#include <iostream>
#include <string.h>

#include "TrajetSimple.h"

/******************
 * Public methods *
 ******************/

char * TrajetSimple::getDepart() const {
#if MAP
  cout << "getDepart de TrajetSimple" << endl;
#endif
  return depart;
}

char * TrajetSimple::getArrivee() const {
  return arrivee;
}

void TrajetSimple::Afficher() const {
  cout << depart << " ---> " << arrivee << " en " << moyen << endl;
}

/************************************
 * Constructor(s) and Destructor(s) *
 ************************************/
TrajetSimple::TrajetSimple (char *dep, char * arr, char * mt)
{
#if MAP
  cout << "Appel au constructeur de TrajetSimple" << endl;
#endif

  depart = new char[strlen(dep)+1];
  arrivee = new char[strlen(arr)+1];
  moyen = new char[strlen(mt)+1];

  if(depart == NULL || arrivee == NULL || moyen == NULL)
  {
    cerr << "Erreur lors de l'alloc des attrib d'un new TrajetSimple" << endl;
  }

  strcpy(depart, dep);
  strcpy(arrivee ,arr);
  strcpy(moyen, mt);
}

TrajetSimple::~TrajetSimple () {
#if MAP
  cout << "Appel au destructeur de TrajetSimple" << endl;
#endif
  delete [] depart;
  delete [] arrivee;
  delete [] moyen;
}
