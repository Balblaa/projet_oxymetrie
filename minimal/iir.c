#include "iir.h"

absorp iirTest(char* filename){
	absorp	res = {.acr = 0.0, .acir = 0, .dcr = 0, .dcir = 0};
    FILE* myfile = initFichier(filename);

    /*Creation des absorp pour les calculs*/
    absorp last_x = {.acr = 0.0, .acir = 0, .dcr = 0, .dcir = 0};
    absorp last_y = {.acr = 0.0, .acir = 0, .dcr = 0, .dcir = 0};
    absorp current_x = {.acr = 0.0, .acir = 0, .dcr = 0, .dcir = 0};

    bool condition = true;

    while(fgetc(myfile) != EOF){

        if(condition){
            condition = false;
            fseek(myfile, SEEK_SET, 0);
        }

        //Lecture ligne par ligne
        current_x = lireFichier(myfile);

        //On passe dans le filtre
        res = iir(current_x, last_x, last_y);

        //On fait un decalage
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
/*
absorp lireMyFile(FILE* pf, int line){

}*/