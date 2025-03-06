#include "affichage.h"

void affichage(oxy myOxy){

    if (access(".verrouData", F_OK ) == -1){

        FILE* verrou = fopen(".verrouData", "w");

        if(verrou == NULL){
            return;
        }

        FILE* myfile = fopen("data.txt", "w");
        if(myfile == NULL){
            return;
        }

        fprintf(myfile, "%d\n%d", myOxy.spo2, myOxy.pouls);

        fclose(myfile);
        fclose(verrou);
        remove(".verrouData");
    }

}