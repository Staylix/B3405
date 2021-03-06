/*************************************************************************
                    TestUnit.cpp  -  Implémente le test
                             -------------------
    début                : 15/11/2017
    auteurs              : B3405 - Etienne et Grégoir
*************************************************************************/

using namespace std;
#include <iostream>
#include <fstream>
#include <typeinfo>

#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Trajet.h"
#include "TabTrajet.h"
#include "Catalogue.h"

void test()
{
  // Catalogue
  //Catalogue *c1 = new Catalogue();

  // Trajets Simples
  const TrajetSimple * pTS1 = new TrajetSimple("Lyon", "Paris", "Voiture");

  ofstream o("text.txt", ios::out | ios::app);
  pTS1->Ecrire(o);
  o.close();

  delete pTS1;

  /*
  const Trajet * pTS2 = new TrajetSimple("Grenoble", "Lyon", "Voiture");
  const Trajet * pTS3 = new TrajetSimple("Grenoble", "Saint-Etienne", "Voiture");
  const Trajet * pTS4 = new TrajetSimple("Saint-Etienne", "Paris", "Voiture");
  const Trajet * pTS5 = new TrajetSimple("Saint-Etienne", "Lyon", "Voiture");
  const TrajetSimple* ts1 = new const TrajetSimple("Saint Egreve", "Grenoble", "Hypogriffe");
  const TrajetSimple* ts2 = new const TrajetSimple("Grenoble", "Lyon", "Hypogriffe");
  const TrajetSimple* ts3 = new const TrajetSimple("Paris", "Grenoble", "Vélo");

  c1->AjouterTrajet(pTS1);
  c1->AjouterTrajet(pTS2);
  c1->AjouterTrajet(pTS3);
  c1->AjouterTrajet(pTS4);
  c1->AjouterTrajet(pTS5);
  c1->AjouterTrajet(ts1);
  c1->AjouterTrajet(ts2);
  c1->AjouterTrajet(ts3);


  // Trajets Composés
  const Trajet * pTS6 = new TrajetSimple("Lyon", "Marseille", "Voiture");
  const Trajet * pTS7 = new TrajetSimple("Marseille", "Paris", "Voiture");
  TabTrajet * tt = new TabTrajet();
  tt->Add(pTS6);
  tt->Add(pTS7);
  const Trajet * pTC1 = new TrajetCompose(tt);

  const TrajetSimple* tc1T1 = new const TrajetSimple("Grenoble", "Charavines", "Speed-Riding");
  const TrajetSimple* tc1T2 = new const TrajetSimple("Charavines", "Lyon", "BlaBlaCar");
  TabTrajet* tc1Tab = new TabTrajet();
  tc1Tab->Add(tc1T1);
  tc1Tab->Add(tc1T2);
  const TrajetCompose * tc1 = new TrajetCompose(tc1Tab);

  const TrajetSimple* tc2T1 = new const TrajetSimple("Saint Egreve", "Valfrejus", "BlaBlaCar");
  const TrajetSimple* tc2T2 = new const TrajetSimple("Valfrejus", "Lyon", "Hypogriffe");
  TabTrajet* tc2Tab = new TabTrajet();
  tc2Tab->Add(tc2T1);
  tc2Tab->Add(tc2T2);
  const TrajetCompose * tc2 = new TrajetCompose(tc2Tab);

  c1->AjouterTrajet(pTC1);
  c1->AjouterTrajet(tc1);
  c1->AjouterTrajet(tc2);


  // Méthodes
  c1->Afficher();

  c1->RechercherSimple("Saint Egreve","Lyon");
  c1->RechercherAvancee("Saint Egreve","Lyon");
  c1->RechercherAvancee((const char *)"Grenoble", (const char *)"Paris");

  delete c1;*/
}
