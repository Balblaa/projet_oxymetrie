#include "affichage.h"

void affichage(oxy myOxy){

    if (access(".verrouData", F_OK ) != 0){
        FILE* verrou = fopen(".verrouData", "w");
        fclose(verrou);

        FILE* myfile = fopen("data.txt", "w");
        fprintf(myfile, "%d\n%d", myOxy.spo2, myOxy.pouls);
        fclose(myfile);

        remove(".verrouData");
    }

}