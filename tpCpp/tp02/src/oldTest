#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Trajet.h"
#include "TabTrajet.h"
#include "Catalogue.h"


int main()
{
    //Catalogue *MonCatalogue = new Catalogue();
    Catalogue MonCatalogue();

    const TrajetSimple TS1 ((char *)"Saint Egreve", (char *)"Grenoble", (char *)"Hypogriffe");
    TS1.Afficher();

    const TrajetSimple TS2 ((char *)"Grenoble", (char *)"Lyon", (char *)"Hypogriffe");
    TS2.Afficher();

    /*const TrajetSimple TC1 (
        (char *)"Saint Egreve", (char *)"Grenoble", (char *)"Hypogriffe");
    t1.Afficher();*/




    //MonCatalogue.AjouterTrajet()




//_______________________________________________ L'ancien fichier TestValgrind

    /*const TrajetSimple t1 ((char *)"Saint Egreve", (char *)"Grenoble", (char *)"Hypogriffe");
    t1.Afficher();

    const Trajet* t2 = new const TrajetSimple ((char *)"A", (char *)"B", (char *)"C");
    t2->Afficher();

    //    const Trajet* tt = new const TabTrajet ();

    if (true) {
        TabTrajet tt;
        tt.Add((const Trajet *)&t1);
        tt.Add(t2);

        TrajetCompose tc (tt);
    }

    delete t2;
    */

    return 0;
}
