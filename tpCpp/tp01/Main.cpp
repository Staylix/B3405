using namespace std;
#include <iostream>

#include "Ensemble.h"


int main(int argc, char *argv[])
{

//---------------------------------------constructeur avec un int, ou par défaut
/*
  Ensemble * e00 = new Ensemble();
  Ensemble * e01 = new Ensemble(10);
  Ensemble * e02 = new Ensemble(100);
  Ensemble * e04 = new Ensemble(0);


  e00->Afficher();
  e01->Afficher();
  e02->Afficher();
  e04->Afficher();

  delete e00;
  delete e01;
  delete e02;
  delete e04;
*/

//-------------------------------------------constructeur avec un tableau de int
/*
  int tab0[0];
  int tab1[10] = {1};
  int tab2[] = {0,1,2,3,4,5,6,7,8,9,10};
  int tab3[] = {1,2,3,1,2,3,5,6,2,3,9,4,7,58,5,8,58};
  int tab4[] = {-1,-2,-3,1,2,3,5,6,2,3,-9,4,7,-58,5,-8,58};


  Ensemble * e10 = new Ensemble(tab0, 0);
  Ensemble * e11 = new Ensemble(tab1, 10);
  Ensemble * e12 = new Ensemble(tab2, 11);
  Ensemble * e13 = new Ensemble(tab3, 17);
  Ensemble * e14 = new Ensemble(tab4, 17);

  e10->Afficher();
  e11->Afficher();
  e12->Afficher();
  e13->Afficher();
  e14->Afficher();

  delete e10;
  delete e11;
  delete e12;
  delete e13;
  delete e14;
*/

//---------------------------------------------------------------Test de EstEgal
/*
  int tab0[0];
  int tab1[10] = {1};
  int tab2[] = {-1,-2,-3,1,2,3,5,6,2,3,-9,4,7,-58,5,-8,58};


  Ensemble e10(tab0, 0);
  Ensemble e10cop(tab0, 0);
  cout << e10.EstEgal(e10cop)<<endl;

  Ensemble e11(tab1, 10);
  Ensemble e11cop(tab1, 10);
  cout << e11.EstEgal(e11cop)<<endl;


  Ensemble e13(tab2, 17);
  Ensemble e13cop(tab2, 17);
  cout << e13.EstEgal(e13cop)<<endl;

  cout<< e13.EstEgal(e10)<<endl;
  cout<< e10.EstEgal(e11)<<endl;
  cout<< e11.EstEgal(e13)<<endl;

// Attendu : 1, 1, 1, 0, 0, 0
*/

//_____________________________________________________________Test de EstInclus
/*
int tab0[0];
int tab1[10] = {1};
int tab2[] = {0,1,2,3,4,5,6,7,8,9,10};
int tab3[] = {0,1,2,3,1,2,3,5,6,2,3,9,4,7,10,58,5,8,58};
int tab4[] = {-1,-2,-3,1,2,3,5,6,2,3,-9,4,7,5,-8};

Ensemble e10(tab0, 0);
Ensemble e11(tab1, 10);
Ensemble e12(tab2, 11);
Ensemble e13(tab3, 19);
Ensemble e14(tab4, 17);

cout << e12.EstInclus(e12) << endl;
cout << e10.EstInclus(e11) << endl;
cout << e12.EstInclus(e13) << endl;
cout << e13.EstInclus(e12) << endl;
cout << e14.EstInclus(e12) << endl;

// Attendu : large, stricte, stricte, non, non
//      ie : 0, 1, 1, 2, 2
*/

//_______________________________________________________________Test de Ajouter
/*
int tab0[0];
int tab2[] = {0,1,2,3,4,5,6,7,8,9,10};

Ensemble e10(2);
Ensemble e12(tab2, 11);

cout << e10.Ajouter(2) << endl;
cout << e10.Ajouter(-2) << endl;
cout << e10.Ajouter(3) << endl;
cout << e10.Ajouter(2) << endl;

cout << e12.Ajouter(11) << endl;

// Attendu : ajoute, ajoute, plein, deja, plein
//      ie : 2, 2, 1, 0, 1
// DEJA_PRESENT, PLEIN, AJOUTE
*/

//_______________________________________________________________Test de Ajuster
/*
int tab2[] = {0,1,2,3,4,5,6,7,8,9,10};

Ensemble e40(0);
Ensemble e41(10);
Ensemble e42(tab2, 12);

cout << e40.Ajuster(10) << endl;
cout << e41.Ajuster(0) << endl;
cout << e41.Ajuster(-2) << endl;
cout << e41.Ajuster(5) << endl;
cout << e42.Ajuster(0) << endl;
cout << e42.Ajuster(-3) << endl;
cout << e42.Ajuster(5) << endl;


// Expected : 10, 10, 8, 13, 12, 11, 16
*/
//_______________________________________________________________Test de Retirer
/*
int tab2[] = {0,1,2,3,4,5,6,7,8,9,10};

Ensemble e42(tab2, 12);
Ensemble e41(10);

e42.Afficher();
cout << e42.Retirer(3) << endl;
cout << e42.Retirer(13) << endl;
e42.Afficher();

e41.Afficher();
cout << e41.Retirer(10) << endl;
e41.Afficher();
*/

//______________________________________________________Test de Retirer multiple

/*int tab2[] = {0,1,2,3,4,5,6,7,8,9,10};
int tab3[] = {0,1,2,3,1,2,3,5,6,2,3,9,4,7,10,58,5,8,58};


Ensemble e52(tab2, 12);
Ensemble e51(10);
Ensemble e53(tab3, 19);

cout << e53.Retirer(e52) << endl;
e53.Afficher();
cout << e53.Retirer(e51) << endl;
e53.Afficher();
cout << e52.Retirer(e53) << endl;
e52.Afficher();

// Expected : 11, 0, 0
*/

//______________________________________________________Test de Reunir
  /*int tabVide[0];
  int tab0[4] = {3, 4};
  int tab1[10] = {1, 5, 0};
  int tab2[] = {3, 4, 5,6,7,8, 3, 4};
  Ensemble vide(tabVide, 0);
  Ensemble videCop(tabVide, 0);
  Ensemble e0(tab0, 4);
  Ensemble e0cop(tab0, 4);
  Ensemble e1(tab1, 10);
  Ensemble e1cop(tab1, 10);
  Ensemble e2(tab2, 8);
  Ensemble e2cop(tab2, 8);
  Ensemble e13(tab2, 17);*/
  
/*---element identique
  cout << vide.Reunir(vide) << endl;
  vide.Afficher();
  cout << e0.Reunir(e0) << endl;
  e0.Afficher();
  cout << e2.Reunir(e2) << endl;
  e2.Afficher();
//---------OK*/

/*---Ensembles inclus
  cout << e0.Reunir(vide) << endl;
  e0.Afficher();
  cout << e1.Reunir(e0) << endl; //e1 inclus e0
  e1.Afficher();//----OK*/

/*---Ensemble vide
  cout << vide.Reunir(e0) << endl; // expected -1
  vide.Afficher(); //expected {1 5}
  cout << e0.Reunir(videCop) << endl; // expected 0
  e0.Afficher(); //expected {1 5}----OK*/

/*---Ensemble sans intersection
  cout << e0.Reunir(e1) << endl; //expected -1
  e0.Afficher(); //expected 0 1 3 4 5
  cout << e1.Reunir(e0cop) << endl; //expected 2
  e1.Afficher(); //expected 0 1 3 4 5 ---OK*/

/*--Ensemble avec intersection
  e0.Afficher();
  e2.Afficher();
  cout << e0.Reunir(e2) << endl; //expected beaucoup
  cout << e2.Reunir(e1) << endl; //expected 1
  e0.Afficher();
  e2.Afficher();//   */


//______________________________________________________Test de Intersection

  int tabVide[0];
  int tab0[4] = {3, 4};
  int tab1[10] = {1, 5, 0};
  int tab2[] = {3, 4, 5,6,7,8, 3, 4, 99};
  Ensemble vide(tabVide, 0);
  Ensemble videCop(tabVide, 0);
  Ensemble e0(tab0, 4);
  Ensemble e0cop(tab0, 4);
  Ensemble e1(tab1, 10);
  Ensemble e1cop(tab1, 10);
  Ensemble e2(tab2, 10);
  Ensemble e2cop(tab2, 10);
  Ensemble e13(tab2, 17);
  
  cout << "expected 0" << endl;
  cout << vide.Intersection(vide) << endl;
  cout << vide.Intersection(e0) << endl;
  cout << e0.Intersection(e0) << endl;
  //e0.Afficher();
  vide.Afficher();

  cout << "expected not 0" << endl;
  cout << e0.Intersection(vide) << endl;
  cout << e0cop.Intersection(e2) << endl;
  cout << e1.Intersection(e2) << endl;
  cout << e2.Intersection(e1cop) << endl;
  e2.Afficher();




    return 0;
}
