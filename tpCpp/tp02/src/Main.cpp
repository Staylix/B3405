#include <iostream>

#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Trajet.h"
#include "TabTrajet.h"
#include "Catalogue.h"
//----------TESTS
#include "TestUnit.h"


#define MAX 100

using namespace std;

static void print_option() {
  cout << "\t1 - Ajouter un trajet simple au catalogue" << endl;
  cout << "\t2 - Ajouter un trajet composé au catalogue" << endl;
  cout << "\t3 - Afficher le catalogue" << endl;
  cout << "\t4 - Chercher un voyage direct" << endl;
  cout << "\t5 - Chercher un voyage avec correspondance éventuelle" << endl;
  cout << "\t0 - Quitter" << endl << endl;
}

int main()
{
  test();

/*
  Catalogue *MonCatalogue = new Catalogue();


  cout << "Bonjour et bienvenu dans votre agence de voyage !" << endl;
  cout << "Que voulez vous faire ?" << endl << endl;
  print_option();

  unsigned int choix = 10;
  unsigned int nbTrajets;
  char * depart = new char[MAX];
  char * arrivee = new char[MAX];
  char * moyen = new char[MAX];


  cin >> choix;
  while (choix != 0)
  {
    if (choix == 1)
    {
      cout << "Veulliez indiquer le départ, l'arrivée et le moyen de transport de votre trajet :" << endl;
      cin >> depart;
      cin >> arrivee;
      cin >> moyen;
      const TrajetSimple * trajet = new const TrajetSimple(depart, arrivee, moyen);
      MonCatalogue->AjouterTrajet(trajet);
      cout << "Trajet ajouté !" << endl;
    }
    if (choix == 2)
    {
      cout << "Combien de trajets simples composent votre trajet ?" << endl;
      cin >> nbTrajets;
      TabTrajet * tab = new TabTrajet();
      cout << "Veulliez indiquer le départ, l'arrivée et le moyen de transport de chaque étape :" << endl;
      for (unsigned int i = 0; i < nbTrajets; i++)
      {
          cin >> depart;
          cin >> arrivee;
          cin >> moyen;
          const TrajetSimple * sousTrajet = new const TrajetSimple(depart, arrivee, moyen);
          tab->Add(sousTrajet);
      }
      const TrajetCompose * trajet = new const TrajetCompose(*tab);
      MonCatalogue->AjouterTrajet(trajet);
      //delete tab;                                                           // TO Check
      cout << "Trajet ajouté !" << endl;
    }
    if (choix == 3)
    {
      MonCatalogue->Afficher();
    }
    if (choix == 4)
    {
      cout << "Veulliez indiquer le départ et l'arrivée de votre voyage :" << endl;
      cin >> depart;
      cin >> arrivee;
      MonCatalogue->RechercherSimple(depart, arrivee);
      cout << "A vous de choisir !" << endl;
    }
    if (choix == 5)
    {
        cout << "Veulliez indiquer le départ et l'arrivée de votre voyage :" << endl;
        cin >> depart;
        cin >> arrivee;
        MonCatalogue->RechercherAvancee(depart, arrivee);
        cout << "A vous de choisir !" << endl;
    }

    cout << endl << "Maintenant, que voulez vous faire ?" << endl << endl;
    print_option();

    cin >> choix;
  }   // Fin du while

  cout << "Good bye and have a nice trip ! ;)" << endl;

  delete MonCatalogue;
*/
  return 0;
}
