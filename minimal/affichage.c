#include "affichage.h"

void affichage(oxy myOxy){

    // vérifie si le fichier .verrouData n'existe pas
    if (access(".verrouData", F_OK ) == -1){

        // création d'un verrou
        FILE* verrou = fopen(".verrouData", "w");
        if(verrou == NULL){
            return;
        }

        // ouverture du fichier data.txt
        FILE* myfile = fopen("data.txt", "w");
        if(myfile == NULL){
            return;
        }

        // écriture des valeur (elle écrase les anciennes)
        fprintf(myfile, "%d\n%d", myOxy.spo2, myOxy.pouls);

        // fermeture est suppression des différents fichiers
        fclose(myfile);
        fclose(verrou);
        remove(".verrouData");
    }

}