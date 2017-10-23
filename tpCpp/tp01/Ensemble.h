/*************************************************************************
                           Ensemble  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Ensemble> (fichier Ensemble.h) ----------------
#if ! defined ( Ensemble_H )
#define Ensemble_H
#define CARD_MAX 5

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

enum crduEstInclus { INCLUSION_LARGE, INCLUSION_STRICTE, NON_INCLUSION };
enum crduAjouter { DEJA_PRESENT, PLEIN, AJOUTE };

//------------------------------------------------------------------------
// Rôle de la classe <Ensemble>
//
//
//------------------------------------------------------------------------

class Ensemble
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void Afficher(void);

    bool EstEgal(const Ensemble & unEns) const;
    crduEstInclus EstInclus(const Ensemble & unEns) const;
    crduAjouter Ajouter(int aAjouter);
    unsigned int Ajuster (int);
    bool Retirer(int element);
    unsigned int Retirer(const Ensemble & unEnsemble);

//------------------------------------------------- Surcharge d'opérateurs
    Ensemble & operator = ( const Ensemble & unEnsemble );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    //Ensemble (const Ensemble & unEnsemble);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Ensemble (unsigned int card = CARD_MAX);
    // Mode d'emploi :
    //
    // Contrat :
    //

    Ensemble (int *tab, unsigned int nbEl);
    // Mode d'emploi :
    //
    // Contrat :

    virtual ~Ensemble ( );
    // Mode d'emploi :
    //
    // Contrat :
    //



//------------------------------------------------------------------ PRIVE
protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	int * values;
	unsigned int cardMax;
	unsigned int occupe;

};

//-------------------------------- Autres définitions dépendantes de <Ensemble>

#endif // Ensemble_H
