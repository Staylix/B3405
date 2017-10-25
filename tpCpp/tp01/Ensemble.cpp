/*************************************************************************
                           Ensemble  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Ensemble> (fichier Ensemble.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Ensemble.h"
//#define MAP

//------------------------------------------------------------- Constantes
void tri(int * values, int n);

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Ensemble::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


void Ensemble::Afficher(void)
{
    cout << this->occupe << "\r\n";
    cout << this->cardMax << "\r\n";

    if (this->occupe == 0)
    {
        cout << "{}" << "\r\n";
        return;
    }
    tri(values, occupe);
    cout << "{";
    for (int i=0; i<(occupe-1); i++)
        cout << values[i] << ",";
    cout << values[occupe-1] << "}\r\n";
}

bool Ensemble::EstEgal(const Ensemble & e2) const
{
    if (this->occupe != e2.occupe)
    {
        return false;
    }
    for (int i = 0; i<this->occupe; i++)
    {
        if (this->values[i] != e2.values[i])
        {
            return false;
        }
    }
    return true;
}

crduEstInclus Ensemble::EstInclus(const Ensemble & e2) const
{
    if (this->EstEgal(e2))
    {
        return INCLUSION_LARGE;
    }
    if (this->occupe >= e2.occupe)
    {
        return NON_INCLUSION;
    }
    int j = 0;
    for (int i = 0; i < e2.occupe; i++)
    {
        if (this->values[j] == e2.values[i])
        {
            j++;
        }
        else if (this->values[j] < e2.values[i])
        {
            return NON_INCLUSION;
        }
        else continue;
        if (j >= (this->occupe))
        {
            return INCLUSION_STRICTE;
        }
    }
    return INCLUSION_STRICTE;
}

crduAjouter Ensemble::Ajouter(int aAjouter)
{
    if (this->cardMax == this->occupe)
    {
        for (int i=0; i < this->cardMax; i++)
        {
            if (this->values[i] == aAjouter)
            {
                return DEJA_PRESENT;
            }
        }
        return PLEIN;
    }
    this->values[this->occupe] = aAjouter;
    this->occupe++;
    tri(this->values, this->occupe);
    return AJOUTE;
}

unsigned int Ensemble::Ajuster(int delta)
{
    if (delta > 0)
    {
        int * tmp = new int[this->cardMax + delta];
        for (int i = 0; i < this->occupe; i++)
        {
            tmp[i] = this->values[i];
        }
        this->values = tmp;
        this->cardMax = this->cardMax + delta;
        return this->cardMax;
    }
    else if (delta < 0)
    {
        if (this->cardMax + delta <= this->occupe)
        {
            this->cardMax = this->occupe;
            return this->cardMax;
        }
        else
        {
            this->cardMax += delta;
            return this->cardMax;
        }
    }
    return this->cardMax;
}

bool Ensemble::Retirer(int element)
{
    bool trouve;
    for (int i=0; i < this->occupe; i++)
    {
        if (this->values[i] == element)
        {
            for (int j=i; j < this->occupe-1; j++)
            {
                this->values[j] = this->values[j+1];
            }
            this->occupe--;
            this->cardMax = this->occupe;
            return true;
        }
        else if (this->values[i] > element)
        {
            this->cardMax = this->occupe;
            return false;
        }
    }
    this->cardMax = this->occupe;
    return false;
}

unsigned int Ensemble::Retirer(const Ensemble & unEnsemble)
{
  if (this == &unEnsemble)
  {
    int tmp = this->occupe;
    this->occupe = 0;
    return tmp;
  }
  int s_init = this->cardMax;
  int i;
  int count = 0;
  for (i=0; i<unEnsemble.occupe; i++)
  {
    bool status = this->Retirer(unEnsemble.values[i]);
    if (status == false)
      continue;
    count++;
  }
  this->cardMax = s_init;
  return count;
}

int Ensemble::Reunir(const Ensemble & unEnsemble)
{
  crduEstInclus inclus = this->EstInclus(unEnsemble);
  if (inclus != NON_INCLUSION || this == &unEnsemble)
    return 0;

  bool reajust = false;
  int ajoutes = 0;
  int i;
  int j;

  for(i=0; i<unEnsemble.occupe; i++) {
    bool trouve = false;
    for(j=0; j<this->occupe && trouve == false; j++) {
      if (unEnsemble.values[i] == this->values[j])
        trouve = true;
    }
    if(!trouve)
    {
      ajoutes++;
      if(this->occupe < this->cardMax) {
        this->values[this->occupe] = unEnsemble.values[i];
        this->occupe++;
      }
      else if(this->occupe == this->cardMax) { //----reajustement
        reajust = true;
        this->Ajuster(1);
        this->values[occupe] = unEnsemble.values[i];
        this->occupe++;
      }
    }
  }
  if (ajoutes)
    tri(this->values, this->occupe);
  if (reajust)
    return -1;
  return ajoutes;
}



//------------------------------------------------- Surcharge d'opérateurs
Ensemble & Ensemble::operator = ( const Ensemble & unEnsemble )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
/*Ensemble::Ensemble ( const Ensemble & unEnsemble )
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Ensemble>" << endl;
#endif
} //----- Fin de Ensemble (constructeur de copie)
*/

Ensemble::Ensemble(unsigned int card)
{
#ifdef MAP
    cout << "Appel au constructeur de <Ensemble>" << endl;
#endif

    values = new int[card];
    occupe = 0;
    cardMax = card;
}


Ensemble::Ensemble(int * tab, unsigned int nbElements )
{
#ifdef MAP
    cout << "Appel au constructeur de <Ensemble>" << endl;
#endif
    values = new int[nbElements];
    cardMax = nbElements;
    occupe = 0;

    if (nbElements > 0)
    {
        int *t = new int[nbElements];
        for(int j=0; j<nbElements; j++)
        {
            t[j] = tab[j];
        }

        tri(t, nbElements);

        values[0] = t[0];
        occupe++;
        for(int j=1; j<nbElements; j++)
        {
            if(t[j-1] != t[j])
            {
                values[occupe++] = t[j];
            }
        }
    }
}
 //----- Fin de Ensemble


Ensemble::~Ensemble()
{
#ifdef MAP
    cout << "Appel au destructeur de <Ensemble>" << endl;
#endif

    delete [] values;
} //----- Fin de ~Ensemble


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void tri(int * values, int n)
{
    for (int i =0; i<n; i++)
    {
        for (int j=0; j<n-1; j++)
        {
            if (values[j]>values[j+1])
            {
                int tmp = values[j];
                values[j] = values[j+1];
                values[j+1] = tmp;
            }
        }
    }
}
