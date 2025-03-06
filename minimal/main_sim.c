#include "fir.h"
#include "iir.h"
#include "mesure.h"
#include "affichage.h"
#include "autotests.h"

int main(){

    // Initialisation
    FILE* myfile = initFichier("log1.dat");
    absorp myAborsp = {.acr = 0, .acir = 0, .dcir = 0, .dcr = 0};
    buffer mybuffer = {.size = 0, .front = 0};
    absorp last_x = {.acr = 0, .acir = 0, .dcir = 0, .dcr = 0};
    absorp last_y = {.acr = 0, .acir = 0, .dcir = 0, .dcr = 0};
    absorp tempo = {.acr = 0, .acir = 0, .dcir = 0, .dcr = 0};
    onde myOnde = {.max_ACR = 0, .min_ACR = 0, .max_ACIR = 0, .min_ACIR = 0, .counter_period = 0, .period = 0};
    oxy myOxy = {.pouls = 0, .spo2 = 0};

    int init = 1;
    while(getc(myfile) != EOF) {

        if (init) {
            fseek(myfile, SEEK_SET, 0);
            init = 0;
        }
        myAborsp = lireFichier(myfile);

        // Filtre FIR
        fir(&mybuffer, myAborsp);

        // Filtre IIR
        tempo = iir(myAborsp, last_x, last_y);
        last_x = myAborsp;
        last_y = tempo;
        myAborsp = tempo;

        // Mesure de oxy
        mesure(myAborsp, &myOnde, &myOxy);

        // Affichage
        if(myOnde.period != 0){
            affichage(myOxy);
            printf("%d, %d\n", myOxy.pouls, myOxy.spo2);
        }
    }

    fclose(myfile);

    return 0;
}