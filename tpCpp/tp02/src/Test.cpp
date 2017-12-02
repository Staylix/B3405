#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Trajet.h"
#include "TabTrajet.h"
#include "Catalogue.h"


int main()
{
    //Catalogue *MonCatalogue = new Catalogue();
    Catalogue MonCatalogue();

    const TrajetSimple* ts1 = new const TrajetSimple((char *)"Saint Egreve", (char *)"Grenoble", (char *)"Hypogriffe");
    ts1->Afficher();

    const TrajetSimple* ts2 = new const TrajetSimple((char *)"Grenoble", (char *)"Lyon", (char *)"Hypogriffe");
    ts2->Afficher();


    const TrajetSimple* tc1T1 = new const TrajetSimple((char *)"Grenoble", (char *)"Charavines", (char *)"Speed-Riding");
    const TrajetSimple* tc1T2 = new const TrajetSimple((char *)"Charavines", (char *)"Lyon", (char *)"BlaBlaCar");
    TabTrajet* tc1Tab = new TabTrajet();
    tc1Tab->Add(tc1T1);
    tc1Tab->Add(tc1T2);

    const TrajetCompose * tc1 = new TrajetCompose(*tc1Tab);
    tc1->Afficher();


    const TrajetSimple* tc2T1 = new const TrajetSimple((char *)"Saint Egreve", (char *)"Valfrejus", (char *)"BlaBlaCar");
    const TrajetSimple* tc2T2 = new const TrajetSimple((char *)"Valfrejus", (char *)"Lyon", (char *)"Hypogriffe");
    TabTrajet* tc2Tab = new TabTrajet();
    tc1Tab->Add(tc2T1);
    tc1Tab->Add(tc2T2);

    const TrajetCompose * tc2 = new TrajetCompose(*tc2Tab);
    tc2->Afficher();



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
