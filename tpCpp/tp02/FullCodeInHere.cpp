/*************************************************************************
                           Catalogue.h  -  Interface de Catalogue.cpp
                                           La seule classe auquel le Main a accès
                             -------------------
    début                : 15/11/2017
    copyright            : (C) $YEAR$ par Greg & Etienne
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface du module <Catalogue> (fichier Catalogue.h) -------------------
#if ! defined ( Catalogue_H )
#define Catalogue_H

//------------------------------------------------------------------------
// Rôle du module <Catalogue>
// Gere le catalogue :
//      Ajouter des trajets
//      Afficher le catalogue
//      Rechercher les parcours (simple ou avancée)
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "TabTrajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types


class Catalogue {
//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//
public:

    void Afficher() const;
    // Contrat :
    //      Affiche le catalogue des Trajets

    void AjouterTrajet(const Trajet * T);
    // Contrat :
    //      Ajoute un trajet (simple ou composé) au catalogue
    //      en utilisant la fonction Add de la classe TabTrajet


    void RechercherSimple(const char *, const char *) const;
    // Contrat :
    //      Affiche les trajets (simples ou composés) dont le départ et l'arrivée
    //      correspondent aux paramètres

    void RechercherAvancee(const char *, const char *) const;
    // Contrat :
    //      Affiche les parcours réalisables à partir des trajets du catalogue,
    //      dont le départ et l'arrivée correspondent aux paramètres

//---------------------------------------------------- Constructor and Desctructor

    Catalogue();                // Constructeur
    virtual ~Catalogue();


protected:
    TabTrajet * catalog;

    int max(int tab[]) const;
    // Contrat :
    //      Renvoie l'entier maximal parmis les éléments du tableau passé en paramètre

    void AfficherParcours(int utilise[]) const;
    // Contrat :
    //      Affiche le parcours composé des trajets décrits par le tableau passé en paramètre

    void recure(int utilise[], int numeroTrajet, int trajetPrecedent , const char * arriveeFinale) const;
    // Mode d'emploi :
    //      utilise : Tableau représentant le parcours courant
    //      numeroTrajet : Numéro du trajet dans le parcours courant
    //      trajetPrecedent : Indice du trajet précédent dans le Catalogue
    //      arriveeFinale : Arrivee demandée par le client
    // Contrat :
    //      Fonction récursive qui permet de tester tous les parcours réréalisables
    //      à partir des trajets du catalogue, partant du départ demandé
    //      et qui appelle l'affichage lorsque le parcours arrive à destination
};

#endif // Catalogue_H
/*************************************************************************
                           TabTrajet.h  -   Interface de TabTrajet.cpp
                                            Un tableau Dynamique de Trajet *
                           -------------------
    début                : 15/11/2017
    copyright            : (C) $YEAR$ par Greg & Etienne
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface du module <TabTrajet> (fichier TabTrajet.h) -------------------
#if ! defined ( TabTrajet_H )
#define TabTrajet_H

//------------------------------------------------------------------------
// Rôle du module <TabTrajet>
// Stocke un tableau dynamique de Trajet *
//      Se réalloue automatiquement
//      Gère l'ajout de TrajetSimple
//      Dispose de Geters pour sa taille et ses trajets par indice
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées

#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

class TabTrajet {
//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//
public:

    void Add ( const Trajet * t );
    // Contrat :
    //      Ajoute à la fin du tableau le pointeur de trajet passé en paramètre

    const Trajet * Get ( unsigned int i ) const;
    // Contrat :
    //      Renvoi le pointeur de trajet positionné à la i-ème case du tableau

    unsigned int GetUtilise() const;
    // Contrat :
    //      Renvoi le nombre de trajet contenu de le tableau

    TabTrajet();                                            // Constructeur
    virtual ~TabTrajet();

protected:
    unsigned int max;
    unsigned int utilise;
    const Trajet** listTrajet;
    void realloc ();

};
#endif // TabTrajet_H
//--------------Interface de <TestUnit.cpp>
#ifndef _TESTUNIT_H
#define _TESTUNIT_H

/*******************
 * Prototypes here *
 *******************/
void test();


#endif // ifndef _TESTUNIT_H
/*************************************************************************
                           TrajetCompose  -  Interface de TrajetCompose
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface du module <TrajetCompose> (fichier TrajetCompose.h) -------------------
#if ! defined ( TrajetCompose_H )
#define TrajetCompose_H

//------------------------------------------------------------------------
// Rôle du module <TrajetCompose>
// Manipule les trajets composés :
//      Création et destruction de trajets composés
//      Geter de depart et arrivée
//      Affichage du trajet
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "TabTrajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

class TrajetCompose : public Trajet {
    public:
//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
    virtual char * getDepart() const;
    virtual char * getArrivee() const;
    // Contrat :
    //      Renvoie le départ ou l'arrivée du trajet appelant la méthode

    virtual void Afficher() const;
    // Contrat :
    //      Affiche le trajet appelant la méthode

//---------------------------------------------------- Constructor and Destructor

    TrajetCompose(TabTrajet * t);
    virtual ~TrajetCompose ();

    protected:
      TabTrajet *t;


};
#endif // TrajetCompose_H
/*************************************************************************
                           Trajet.h  -  Interface de TrajetSimple et TrajetCompose
                                        Classe purement abstraite
                           -------------------
    début                : 15/11/2017
    copyright            : (C) $YEAR$ par Greg & Etienne
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface du module <Trajet> (fichier Trajet.h) -------------------
#if ! defined ( Trajet_H )
#define Trajet_H

//------------------------------------------------------------------------
// Rôle du module <Trajet>
// Déclare les méthodes implémentées dans les classes enfants
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types


class Trajet {
//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//

public:

    virtual ~Trajet() {};

    virtual char * getDepart() const = 0;
    virtual char * getArrivee() const = 0;
    // Contrat :
    //      Renvoie le départ ou l'arrivée du trajet appelant la méthode

    virtual void Afficher() const = 0;
    // Contrat :
    //      Affiche le trajet appelant la méthode
};
#endif // Trajet_H
/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface du module <TrajetSimple> (fichier TrajetSimple.h) -------------------
#if ! defined ( TrajetSimple_H )
#define TrajetSimple_H

//------------------------------------------------------------------------
// Rôle du module <TrajetSimple>
// Manipule les trajets composés :
//      Création et destruction de trajets simples
//      Geter de depart et arrivée
//      Affichage du trajet
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

class TrajetSimple : public Trajet {
    public:
//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//
//---------------------------------------------------- Constructor and Destructor

    TrajetSimple(char * dep, char * arrivee, char * mt);
    virtual ~TrajetSimple ();

    virtual char * getDepart() const;
    virtual char * getArrivee() const;
    // Contrat :
    //      Renvoie le départ ou l'arrivée du trajet appelant la méthode

    virtual void Afficher() const;
    // Contrat :
    //      Affiche le trajet appelant la méthode

    protected:
      char * depart;
      char * arrivee;
      char * moyen;

};
#endif // TrajetSimple_H
/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


void Catalogue::Afficher() const
{
  unsigned int size = catalog->GetUtilise();
  if (size > 0 )
  {
    cout << endl << "Le catalogue contient " << size << " trajets :" << endl;
    for (unsigned int i = 0; i < size; i++)
    {
      cout << i+1 << " - ";
      if (catalog->Get(i) != nullptr)
      {
        catalog->Get(i)->Afficher();
      }
      else
      {
        cout << "null pointer..." << endl;
      }
    }
    cout << endl;
  }
  else
  {
      cout << "Le catalogue est vide..." << endl;
  }
}

void Catalogue::AjouterTrajet(const Trajet * T)
{
  catalog->Add(T);
}

void Catalogue::RechercherSimple(const char * depart, const char * arrivee) const
{
    cout << endl << "******************************************" << endl;
    cout << "Parcours directs disponibles pour faire " << depart << " --> " << arrivee << " :" << endl;
    for (unsigned int i = 0; i < catalog->GetUtilise(); i++)
    {
        if ( !strcmp(depart, catalog->Get(i)->getDepart()) && !strcmp(arrivee, catalog->Get(i)->getArrivee()))
        {
            catalog->Get(i)->Afficher();
        }
    }
    cout << "******************************************" << endl << endl;
}

void Catalogue::RechercherAvancee(const char * depart, const char * arrivee) const
{
    cout << endl << "******************************************" << endl;
    cout << "Parcours disponibles pour faire " << depart << " --> " << arrivee << " :" << endl << endl;
    int * utilise = new int[catalog->GetUtilise()];
    for (unsigned int i = 0; i < catalog->GetUtilise(); i++)
    {
        for (unsigned int j = 0; j < catalog->GetUtilise(); j++)
            {
                utilise[j] = 0;
            }
        if ( !strcmp(depart, catalog->Get(i)->getDepart()) )
        {
            utilise[i] = 1;
            this->recure(utilise, 2, i, arrivee);
        }
    }
    cout << "******************************************" << endl << endl;
    delete [] utilise;
}



//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
    catalog = new TabTrajet();
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
    delete catalog;
} //----- Fin de ~Catalogue



//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


void Catalogue::recure(int utilise[], int numeroTrajet, int trajetPrecedent , const char * arriveeFinale) const
{
    if ( !strcmp(catalog->Get(trajetPrecedent)->getArrivee(), arriveeFinale) )     // Si on a trouvé un parcours
    {
        this->AfficherParcours(utilise);
        return;
    }
    for (unsigned int i = 0; i < catalog->GetUtilise(); i++)
    {
        if ( !strcmp(catalog->Get(i)->getDepart(), catalog->Get(trajetPrecedent)->getArrivee()) && utilise[i] == 0)
        {
            utilise[i] = numeroTrajet;
            this->recure(utilise, numeroTrajet + 1, i, arriveeFinale);
            utilise[i] = 0;
        }
    }
}

void Catalogue::AfficherParcours(int utilise[]) const
{
    int indiceMax = this->max(utilise);
    cout << "--------------------------" << endl;
    for (int j = 1; j <= indiceMax; j++)
    {
        for (unsigned int i = 0; i < catalog->GetUtilise(); i++)
        {
            if (j == utilise[i])
            {
                catalog->Get(i)->Afficher();
            }
        }
    }
}

int Catalogue::max(int utilise[]) const       // On sait que utilise est de la taille de catalog
{
    int maxi = 0;
    for (unsigned int i = 0; i < catalog->GetUtilise(); i++)
    {
        if (utilise[i] > maxi) maxi = utilise[i];
    }
    return maxi;
}
#include <iostream>
#include <cstring>
using namespace std;

#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Trajet.h"
#include "TabTrajet.h"
#include "Catalogue.h"

//----------TESTS
#include "TestUnit.h"

//----------Constante
#define MAX 100


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

  Catalogue *MonCatalogue = new Catalogue();

  cout << "Bonjour et bienvenu dans votre agence de voyage !" << endl;
  cout << "Que voulez vous faire ?" << endl << endl;
  print_option();

  unsigned int choix = 50;
  int nbTrajets;
  char * depart = new char[MAX];
  char * arrivee = new char[MAX];
  char * moyen = new char[MAX];


  cin >> choix;
  while (choix != 0)
  {
    if (choix == 1)     // Ajout de trajet simple
    {
      cout << "Veulliez indiquer le départ, l'arrivée et le moyen de transport de votre trajet :" << endl;
      cin >> depart;
      cin >> arrivee;
      cin >> moyen;
      const Trajet * trajet = new const TrajetSimple(depart, arrivee, moyen);
      MonCatalogue->AjouterTrajet(trajet);
      cout << "Trajet ajouté !" << endl;
    }

    if (choix == 2)     // Ajout de trajet composé
    {
      cout << "Combien de trajets simples composent votre trajet ?" << endl;
      cin >> nbTrajets;
      if (nbTrajets > 1)
      {
        TabTrajet * tab = new TabTrajet();
        cout << "Veulliez indiquer le départ, l'arrivée et le moyen de transport de chaque étape :" << endl;
        bool valide = true;
        for (int i = 0; i < nbTrajets; i++)
        {
            cin >> depart;
            if (i > 0 && strcmp(depart, arrivee))
            {
                cout << "Votre trajet n'est pas valide..." << endl;
                valide = false;
                i = nbTrajets; //on arrete de lire cin
            }
            cin >> arrivee;
            cin >> moyen;
            const Trajet * sousTrajet = new const TrajetSimple(depart, arrivee, moyen);
            tab->Add(sousTrajet);
        }
        const Trajet * trajet = new const TrajetCompose(tab);
        if (valide)
        {
            MonCatalogue->AjouterTrajet(trajet);
            cout << "Trajet ajouté !" << endl;
        }
        else
        {
            delete trajet;
        }
      }
      else
      {
        cout << "Ce n'est pas très utile..." << endl;
      }
    }

    if (choix == 3)     // Affichage du catalogue
    {
      MonCatalogue->Afficher();
    }

    if (choix == 4)     // Recherche simple
    {
      cout << "Veulliez indiquer le départ et l'arrivée de votre voyage :" << endl;
      cin >> depart;
      cin >> arrivee;
      MonCatalogue->RechercherSimple(depart, arrivee);
    }

    if (choix == 5)     // Recherche avancée
    {
        cout << "Veulliez indiquer le départ et l'arrivée de votre voyage :" << endl;
        cin >> depart;
        cin >> arrivee;
        MonCatalogue->RechercherAvancee(depart, arrivee);
    }

    cout << endl << "Maintenant, que voulez vous faire ?" << endl << endl;
    print_option();

    cin >> choix;
  }   // Fin du while

  cout << "Good bye and have a nice trip ! ;)" << endl;
  delete [] depart;
  delete [] arrivee;
  delete [] moyen;
  delete MonCatalogue;
  return 0;
}
/*************************************************************************
                           TabTrajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TabTrajet> (fichier TabTrajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TabTrajet.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void TabTrajet::Add ( const Trajet * t )
{
  if (this->utilise >= this->max)
  {
      this->realloc();
  }
  for (unsigned int i = 0; i < utilise; i++)
  {
      if (listTrajet[i] == t)
      {
          cout << "Trajet déjà présent dans le catalogue..." << endl;
          return;
      }
  }
  this->listTrajet[this->utilise] = t;
  this->utilise++;
  return;
}


const Trajet * TabTrajet::Get ( unsigned int i ) const
{
    if (i >= this->utilise)
    {
        return nullptr;
    }
    return this->listTrajet[i];
}

unsigned int TabTrajet::GetUtilise() const
{
  return this->utilise;
}


//-------------------------------------------- Constructeurs - destructeurs

TabTrajet::TabTrajet ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <TabTrajet>" << endl;
#endif
    max = 5;
    utilise = 0;
    listTrajet = new const Trajet*[max];
    for (unsigned int i = 0; i < max; i++)
    {
      listTrajet[i] = nullptr;
    }
} //----- Fin de TabTrajet


TabTrajet::~TabTrajet ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <TabTrajet>" << endl;
#endif

    for (unsigned int i = 0; i < max; i++)
    {
        if (listTrajet[i] != nullptr)
        {
            delete listTrajet[i];
        }
    }
    delete [] listTrajet;
} //----- Fin de ~TabTrajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void TabTrajet::realloc()
{
    const Trajet** newList = new const Trajet*[max*2];
    for (unsigned int i = 0; i < utilise; i++)
    {
        newList[i] = listTrajet[i];
    }
    for (unsigned int i = utilise; i < 2*max; i++)
    {
        newList[i] = nullptr;
    }
    const Trajet ** old = listTrajet;
    listTrajet = newList;
    delete [] old;
    max *= 2;
}
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
/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

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
/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

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

  if (depart == NULL || arrivee == NULL || moyen == NULL)
  {
    cerr << "Erreur lors de l'allocation des attributs du TrajetSimple" << endl;
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
