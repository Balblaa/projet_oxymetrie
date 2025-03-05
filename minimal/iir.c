#include "iir.h"

absorp iirTest(char* filename){
    //printf("Poulpe1\n");
	absorp	res = {.acr = 0.0, .acir = 0, .dcr = 0, .dcir = 0};
    FILE* myfile = initFichier(filename);

    /*Verification de louverture du fichier
    if(myfile == NULL){
        printf("Erreur lors de l'ouverture");
        res.acr = 0;
        res.acir = 0;
        res.dcr = 0;
        res.dcir = 0;
    }*/
    //printf("Poulpe2\n");
    /*Creation des absorp pour les calculs*/
    absorp last_x = {.acr = 0.0, .acir = 0, .dcr = 0, .dcir = 0};
    absorp last_y = {.acr = 0.0, .acir = 0, .dcr = 0, .dcir = 0};
    absorp current_x = {.acr = 0.0, .acir = 0, .dcr = 0, .dcir = 0};

    /*Initialisation des variables*/
    //printf("last_y    => acr : %f, dcr : %f, acir : %f, dcir : %f\n", last_y.acr, last_y.dcr, last_y.acir, last_y.dcir);
    //printf("last_x    => acr : %f, dcr : %f, acir : %f, dcir : %f\n",last_x.acr, last_x.dcr, last_x.acir, last_x.dcir);
    //printf("current_x => acr : %f, dcr : %f, acir : %f, dcir : %f\n",current_x.acr, current_x.dcr, current_x.acir, current_x.dcir);
    //printf("Poulpe3\n\n");

    bool condition = true;

    while(fgetc(myfile) != EOF){

        if(condition){
            condition = false;
            fseek(myfile, SEEK_SET, 0);
        }

        //Lecture ligne par ligne
        current_x = lireFichier(myfile);
        //printf("current_x => acr : %f, dcr : %f, acir : %f, dcir : %f\n",current_x.acr, current_x.dcr, current_x.acir, current_x.dcir);
        //printf("last_x    => acr : %f, dcr : %f, acir : %f, dcir : %f\n",last_x.acr, last_x.dcr, last_x.acir, last_x.dcir);
        //printf("last_y    => acr : %f, dcr : %f, acir : %f, dcir : %f\n\n",last_y.acr, last_y.dcr, last_y.acir, last_y.dcir);

        //On passe dans le filtre
        res = iir(current_x, last_x, last_y);
        //printf("current_y => acr : %f, dcr : %f, acir : %f, dcir : %f\n\n",res.acr, res.dcr, res.acir, res.dcir);

        //On fait un decalage
        last_x = current_x;
        last_y = res;
    }

    /*Fermeture du fichier*/
    //printf("Presque presque fin\n");
    finFichier(myfile);
    //printf("Presque fin\n\n");
    return res;

}

absorp iir(absorp current_x, absorp last_x, absorp last_y){
    absorp current_y;

    current_y.acr =  current_x.acr - last_x.acr + (0.992 * last_y.acr);
    current_y.acir =  current_x.acir - last_x.acir + (0.992 * last_y.acir);

    current_y.dcr = current_x.dcr;
    current_y.dcir = current_x.dcir;



    return current_y;
}