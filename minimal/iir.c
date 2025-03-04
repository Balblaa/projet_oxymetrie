#include "iir.h"


absorp iirTest(char* filename){
	absorp	res;
    FILE* myfile = initFichier(filename);

    /*Verification de louverture du fichier
    if(myfile == NULL){
        printf("Erreur lors de l'ouverture");
        res.acr = 0;
        res.acir = 0;
        res.dcr = 0;
        res.dcir = 0;
    }*/

    /*Creation des absorp pour les calculs*/
    absorp last_x;
    absorp last_y;
    absorp current_x;

    /*Initialisation des variables*/
    last_y.acr = 0;
    last_y.acir = 0;
    last_y.dcr = 0;
    last_y.dcir = 0;

    last_x.acr = 0;
    last_x.acir = 0;
    last_x.dcr = 0;
    last_x.dcir = 0;

    while(fgetc(myfile) != EOF){
        /*Lecture ligne par ligne*/
        current_x = lireFichier(myfile);

        /*On passe dans le filtre*/
        res = iir(current_x, last_x, last_y);

        /*On fait un decalage*/
        last_x = current_x;
        last_y = res;
    }

    /*Fermeture du fichier*/
    finFichier(myfile);
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