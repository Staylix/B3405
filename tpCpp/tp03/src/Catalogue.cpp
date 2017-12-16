/*************************************************************************
                            Catalogue.cpp
                             -------------------
    début                : 15/11/2017
    auteurs              : B3405 - Etienne et Grégoir
*************************************************************************/

//----------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp)

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

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

void Catalogue::RechercherSimple(const string & depart, const string & arrivee) const
{
    cout << endl << "******************************************" << endl;
    cout << "Parcours directs disponibles pour faire " << depart << " --> " << arrivee << " :" << endl;
    for (unsigned int i = 0; i < catalog->GetUtilise(); i++)
    {
        if ( depart == catalog->Get(i)->getDepart() && arrivee == catalog->Get(i)->getArrivee() )
        {
            catalog->Get(i)->Afficher();
        }
    }
    cout << "******************************************" << endl << endl;
}

void Catalogue::RechercherAvancee(const string & depart, const string & arrivee) const
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
        if ( depart == catalog->Get(i)->getDepart() )
        {
            utilise[i] = 1;
            this->recure(utilise, 2, i, arrivee);
        }
    }
    cout << "******************************************" << endl << endl;
    delete [] utilise;
}

void Catalogue::Save(string fichier) const
{
    ofstream os(fichier, ios::out | ios::app);
    for (unsigned int i = 0; i < this->catalog->GetUtilise(); i++)
    {
        this->catalog->Get(i)->Ecrire(os);
    }
    os.close();
}
void Catalogue::Save(string fichier, string type) const
{
    ofstream os(fichier, ios::out | ios::app);
    for (unsigned int i = 0; i < this->catalog->GetUtilise(); i++)
    {
        this->catalog->Get(i)->Ecrire(os, type);
    }
    os.close();
}
void Catalogue::Save(string fichier, string ville, unsigned int DouA) const
{
    ofstream os(fichier, ios::out | ios::app);
    for (unsigned int i = 0; i < this->catalog->GetUtilise(); i++)
    {
        if (DouA == 0 && ville == this->catalog->Get(i)->getDepart())
        {
            this->catalog->Get(i)->Ecrire(os);
        }
        else if (DouA == 1 && ville == this->catalog->Get(i)->getArrivee())
        {
            this->catalog->Get(i)->Ecrire(os);
        }
    }
    os.close();
}
void Catalogue::Save(string fichier, string depart, string arrivee) const
{
    ofstream os(fichier, ios::out | ios::app);
    for (unsigned int i = 0; i < this->catalog->GetUtilise(); i++)
    {
        if (depart == this->catalog->Get(i)->getDepart() && arrivee == this->catalog->Get(i)->getArrivee())
        {
            this->catalog->Get(i)->Ecrire(os);
        }
    }
    os.close();
}
void Catalogue::Save(string fichier, unsigned int first, unsigned int last) const
{
    ofstream os(fichier, ios::out | ios::app);
    for (unsigned int i = 0; i < this->catalog->GetUtilise(); i++)
    {
        if ( (i+1) >= first && (i+1) <= last )
        {
            this->catalog->Get(i)->Ecrire(os);
        }
    }
    os.close();
}

void Catalogue::Lire(string fichier)
{
    string depart;
    string arrivee;
    string moyen;
    ifstream is(fichier, ios::in);
    unsigned int nb;
    string nbS;
    getline(is, moyen);
    while (!is.eof())
    {
        if (moyen == "TC")
        {
            TabTrajet * tab = new TabTrajet();
            getline(is, nbS);
            nb = stoi(nbS);
            getline(is, depart);
            getline(is, arrivee);
            for (unsigned int i = 0; i < nb; i++)
            {
                getline(is, depart);
                getline(is, arrivee);
                getline(is, moyen);
                const Trajet * sousTrajet = new const TrajetSimple(depart, arrivee, moyen);
                tab->Add(sousTrajet);
            }
            const Trajet * trajet = new const TrajetCompose(tab);
            this->AjouterTrajet(trajet);
        }
        else
        {
            getline(is, depart);
            getline(is, arrivee);
            getline(is, moyen);
            const Trajet * trajet = new const TrajetSimple(depart, arrivee, moyen);
            this->AjouterTrajet(trajet);
        }
        getline(is, moyen);
    }
}
void Catalogue::Lire(string fichier, string type)
{
    string depart;
    string arrivee;
    string moyen;
    ifstream is(fichier, ios::in);
    unsigned int nb;
    string nbS;
    getline(is, moyen);
    while (!is.eof())
    {
        if (moyen == "TC")
        {
            TabTrajet * tab = new TabTrajet();
            getline(is, nbS);
            nb = stoi(nbS);
            getline(is, depart);
            getline(is, arrivee);
            for (unsigned int i = 0; i < nb; i++)
            {
                getline(is, depart);
                getline(is, arrivee);
                getline(is, moyen);
                const Trajet * sousTrajet = new const TrajetSimple(depart, arrivee, moyen);
                tab->Add(sousTrajet);
            }
            const Trajet * trajet = new const TrajetCompose(tab);
            if (type == "TC")
            {
                this->AjouterTrajet(trajet);
            }
            else delete trajet;
        }
        else
        {
            getline(is, depart);
            getline(is, arrivee);
            getline(is, moyen);
            const Trajet * trajet = new const TrajetSimple(depart, arrivee, moyen);
            if (type == "TS")
            {
                this->AjouterTrajet(trajet);
            }
            else delete trajet;
        }
        getline(is, moyen);
    }
}
void Catalogue::Lire(string fichier, string ville, unsigned int DouA)
{
    string depart;
    string arrivee;
    string moyen;
    ifstream is(fichier, ios::in);
    unsigned int nb;
    string nbS;
    getline(is, moyen);
    while (!is.eof())
        {
        if (moyen == "TC")
        {
            getline(is, nbS);
            nb = stoi(nbS);
            getline(is, depart);
            getline(is, arrivee);
            if ((DouA == 0 && depart == ville) || (DouA == 1 && arrivee == ville))
            {
                TabTrajet * tab = new TabTrajet();
                for (unsigned int i = 0; i < nb; i++)
                {
                    getline(is, depart);
                    getline(is, arrivee);
                    getline(is, moyen);
                    const Trajet * sousTrajet = new const TrajetSimple(depart, arrivee, moyen);
                    tab->Add(sousTrajet);
                }
                const Trajet * trajet = new const TrajetCompose(tab);
                this->AjouterTrajet(trajet);
            }
            else
            {
                for (unsigned int i = 0; i < nb; i++)
                {
                    getline(is, depart);
                    getline(is, arrivee);
                    getline(is, moyen);
                }
            }
        }
        else
        {
            getline(is, depart);
            getline(is, arrivee);
            getline(is, moyen);
            if ((DouA == 0 && depart == ville) || (DouA == 1 && arrivee == ville))
            {
                const Trajet * trajet = new const TrajetSimple(depart, arrivee, moyen);
                this->AjouterTrajet(trajet);
            }
        }
        getline(is, moyen);
    }
}
void Catalogue::Lire(string fichier, string dep, string arr)
{
    string depart;
    string arrivee;
    string moyen;
    ifstream is(fichier, ios::in);
    unsigned int nb;
    string nbS;
    getline(is, moyen);
    while (!is.eof())
        {
        if (moyen == "TC")
        {
            getline(is, nbS);
            nb = stoi(nbS);
            getline(is, depart);
            getline(is, arrivee);
            if (depart == dep && arrivee == arr)
            {
                TabTrajet * tab = new TabTrajet();
                for (unsigned int i = 0; i < nb; i++)
                {
                    getline(is, depart);
                    getline(is, arrivee);
                    getline(is, moyen);
                    const Trajet * sousTrajet = new const TrajetSimple(depart, arrivee, moyen);
                    tab->Add(sousTrajet);
                }
                const Trajet * trajet = new const TrajetCompose(tab);
                this->AjouterTrajet(trajet);
            }
            else
            {
                for (unsigned int i = 0; i < nb; i++)
                {
                    getline(is, depart);
                    getline(is, arrivee);
                    getline(is, moyen);
                }
            }
        }
        else
        {
            getline(is, depart);
            getline(is, arrivee);
            getline(is, moyen);
            if (depart == dep && arrivee == arr)
            {
                const Trajet * trajet = new const TrajetSimple(depart, arrivee, moyen);
                this->AjouterTrajet(trajet);
            }
        }
        getline(is, moyen);
    }
}
void Catalogue::Lire(string fichier, unsigned int first, unsigned int last)
{
    unsigned int count = 0;
    string depart;
    string arrivee;
    string moyen;
    ifstream is(fichier, ios::in);
    unsigned int nb;
    string nbS;
    getline(is, moyen);
    while (!is.eof())
    {
        count++;
        if (moyen == "TC")
        {
            TabTrajet * tab = new TabTrajet();
            getline(is, nbS);
            nb = stoi(nbS);
            getline(is, depart);
            getline(is, arrivee);
            for (unsigned int i = 0; i < nb; i++)
            {
                getline(is, depart);
                getline(is, arrivee);
                getline(is, moyen);
                const Trajet * sousTrajet = new const TrajetSimple(depart, arrivee, moyen);
                tab->Add(sousTrajet);
            }
            const Trajet * trajet = new const TrajetCompose(tab);
            if (count >= first && count <= last)
            {
                this->AjouterTrajet(trajet);
            }
            else
            {
                delete trajet;
            }
        }
        else
        {
            getline(is, depart);
            getline(is, arrivee);
            getline(is, moyen);
            const Trajet * trajet = new const TrajetSimple(depart, arrivee, moyen);
            if (count >= first && count <= last)
            {
                this->AjouterTrajet(trajet);
            }
            else
            {
                delete trajet;
            }
        }
        getline(is, moyen);
    }
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

void Catalogue::recure(int utilise[], int numeroTrajet, int trajetPrecedent , const string & arriveeFinale) const
{
    if (catalog->Get(trajetPrecedent)->getArrivee() == arriveeFinale)
    {
        this->AfficherParcours(utilise);
        return;
    }
    for (unsigned int i = 0; i < catalog->GetUtilise(); i++)
    {
        if ( catalog->Get(i)->getDepart() == catalog->Get(trajetPrecedent)->getArrivee() && utilise[i] == 0 )
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

int Catalogue::max(int utilise[]) const // On sait que utilise est de la taille de catalog
{
    int maxi = 0;
    for (unsigned int i = 0; i < catalog->GetUtilise(); i++)
    {
        if (utilise[i] > maxi) maxi = utilise[i];
    }
    return maxi;
}
