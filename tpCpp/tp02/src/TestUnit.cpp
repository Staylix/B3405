#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Trajet.h"
#include "TabTrajet.h"
#include "Catalogue.h"


void test()
{
  //A catalog
  Catalogue *c1 = new Catalogue();

  //TrajetSimples
  const TrajetSimple * pTS1 = new TrajetSimple((char *)"Lyon", (char *)"Paris", (char *)"Voiture");
  const TrajetSimple * pTS2 = new TrajetSimple((char *)"Grenoble", (char *)"Lyon", (char *)"Voiture");
  const TrajetSimple * pTS3 = new TrajetSimple((char *)"Grenoble", (char *)"Sant-Etienne", (char *)"Voiture");
  const TrajetSimple * pTS4 = new TrajetSimple((char *)"Saint-Etienne", (char *)"Paris", (char *)"Voiture");
  const TrajetSimple * pTS5 = new TrajetSimple((char *)"Saint-Etienne", (char *)"Lyon", (char *)"Voiture");

  //TrajetCompose
  const TrajetSimple * pTS6 = new TrajetSimple((char *)"Lyon", (char *)"Marseille", (char *)"Voiture");
  const TrajetSimple * pTS7 = new TrajetSimple((char *)"Marseille", (char *)"Paris", (char *)"Voiture");
  TabTrajet tt; 
  tt.Add(pTS6);
  tt.Add(pTS7);

  const TrajetCompose * pTC1 = new TrajetCompose(tt);


  c1->AjouterTrajet(pTS1);
  c1->AjouterTrajet(pTS2);
  c1->AjouterTrajet(pTS3);
  c1->AjouterTrajet(pTS4);
  c1->AjouterTrajet(pTS5);
  c1->AjouterTrajet(pTC1);

  c1->Afficher();


  delete c1;
}
