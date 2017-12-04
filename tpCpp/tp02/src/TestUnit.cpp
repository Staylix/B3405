using namespace std;
#include <iostream>

#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Trajet.h"
#include "TabTrajet.h"
#include "Catalogue.h"


void test()
{
  // Catalogue
  Catalogue *c1 = new Catalogue();


  // Trajets Simples
  const Trajet * pTS1 = new TrajetSimple((char *)"Lyon", (char *)"Paris", (char *)"Voiture");
  const Trajet * pTS2 = new TrajetSimple((char *)"Grenoble", (char *)"Lyon", (char *)"Voiture");
  const Trajet * pTS3 = new TrajetSimple((char *)"Grenoble", (char *)"Saint-Etienne", (char *)"Voiture");
  const Trajet * pTS4 = new TrajetSimple((char *)"Saint-Etienne", (char *)"Paris", (char *)"Voiture");
  const Trajet * pTS5 = new TrajetSimple((char *)"Saint-Etienne", (char *)"Lyon", (char *)"Voiture");
  const TrajetSimple* ts1 = new const TrajetSimple((char *)"Saint Egreve", (char *)"Grenoble", (char *)"Hypogriffe");
  const TrajetSimple* ts2 = new const TrajetSimple((char *)"Grenoble", (char *)"Lyon", (char *)"Hypogriffe");
  const TrajetSimple* ts3 = new const TrajetSimple((char *)"Paris", (char *)"Grenoble", (char *)"Vélo");

  c1->AjouterTrajet(pTS1);
  c1->AjouterTrajet(pTS2);
  c1->AjouterTrajet(pTS3);
  c1->AjouterTrajet(pTS4);
  c1->AjouterTrajet(pTS5);
  c1->AjouterTrajet(ts1);
  c1->AjouterTrajet(ts2);
  c1->AjouterTrajet(ts3);



  // Trajets Composés
  const Trajet * pTS6 = new TrajetSimple((char *)"Lyon", (char *)"Marseille", (char *)"Voiture");
  const Trajet * pTS7 = new TrajetSimple((char *)"Marseille", (char *)"Paris", (char *)"Voiture");
  TabTrajet * tt = new TabTrajet();
  tt->Add(pTS6);
  tt->Add(pTS7);
  const Trajet * pTC1 = new TrajetCompose(tt);

  const TrajetSimple* tc1T1 = new const TrajetSimple((char *)"Grenoble", (char *)"Charavines", (char *)"Speed-Riding");
  const TrajetSimple* tc1T2 = new const TrajetSimple((char *)"Charavines", (char *)"Lyon", (char *)"BlaBlaCar");
  TabTrajet* tc1Tab = new TabTrajet();
  tc1Tab->Add(tc1T1);
  tc1Tab->Add(tc1T2);
  const TrajetCompose * tc1 = new TrajetCompose(tc1Tab);

  const TrajetSimple* tc2T1 = new const TrajetSimple((char *)"Saint Egreve", (char *)"Valfrejus", (char *)"BlaBlaCar");
  const TrajetSimple* tc2T2 = new const TrajetSimple((char *)"Valfrejus", (char *)"Lyon", (char *)"Hypogriffe");
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

  delete c1;
}
