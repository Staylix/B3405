#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Trajet.h"
#include "TabTrajet.h"
#include "Catalogue.h"

#include <iostream>

void test()
{
  //A catalog
  Catalogue *c1 = new Catalogue();

  //TrajetSimples
  const Trajet * pTS1 = new TrajetSimple((char *)"Lyon", (char *)"Paris", (char *)"Voiture");
  const Trajet * pTS2 = new TrajetSimple((char *)"Grenoble", (char *)"Lyon", (char *)"Voiture");
  const Trajet * pTS3 = new TrajetSimple((char *)"Grenoble", (char *)"Saint-Etienne", (char *)"Voiture");
  const Trajet * pTS4 = new TrajetSimple((char *)"Saint-Etienne", (char *)"Paris", (char *)"Voiture");
  const Trajet * pTS5 = new TrajetSimple((char *)"Saint-Etienne", (char *)"Lyon", (char *)"Voiture");

  //TrajetCompose
  /*const Trajet * pTS6 = new TrajetSimple((char *)"Lyon", (char *)"Marseille", (char *)"Voiture");
  const Trajet * pTS7 = new TrajetSimple((char *)"Marseille", (char *)"Paris", (char *)"Voiture");
  TabTrajet tt; 
  tt.Add(pTS6);
  tt.Add(pTS7);

  const Trajet * pTC1 = new TrajetCompose(tt);
  c1->AjouterTrajet(pTC1);*/

  c1->AjouterTrajet(pTS1);
  c1->AjouterTrajet(pTS2);
  c1->AjouterTrajet(pTS3);
  c1->AjouterTrajet(pTS4);
  c1->AjouterTrajet(pTS5);

  c1->Afficher();

  c1->RechercherAvancee((const char *)"Grenoble", (const char *)"Paris");

  delete c1;
}
