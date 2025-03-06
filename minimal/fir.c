#include "fir.h"

absorp firTest(char* filename){

	absorp myAbsorp;

    FILE* myfile = initFichier(filename);
    buffer mybuffer = {.front = 0, .size = 0};

    while(getc(myfile) != EOF)
    {
        if(mybuffer.size == 0){
            fseek(myfile, SEEK_SET, 0);
        }
        myAbsorp = lireFichier(myfile);
        myAbsorp = fir(&mybuffer, myAbsorp);
    }

    finFichier(myfile);
	return myAbsorp;

}

absorp fir(buffer* mybuffer, absorp myAbsorp){

    // Initialisation
    float sortie_acr = 0;
    float sortie_acir = 0;

    //region FIR_TAPS
    float FIR_TAPS[51] = {
            1.4774946e-019,
            1.6465231e-004,
            3.8503956e-004,
            7.0848037e-004,
            1.1840522e-003,
            1.8598621e-003,
            2.7802151e-003,
            3.9828263e-003,
            5.4962252e-003,
            7.3374938e-003,
            9.5104679e-003,
            1.2004510e-002,
            1.4793934e-002,
            1.7838135e-002,
            2.1082435e-002,
            2.4459630e-002,
            2.7892178e-002,
            3.1294938e-002,
            3.4578348e-002,
            3.7651889e-002,
            4.0427695e-002,
            4.2824111e-002,
            4.4769071e-002,
            4.6203098e-002,
            4.7081811e-002,
            4.7377805e-002,
            4.7081811e-002,
            4.6203098e-002,
            4.4769071e-002,
            4.2824111e-002,
            4.0427695e-002,
            3.7651889e-002,
            3.4578348e-002,
            3.1294938e-002,
            2.7892178e-002,
            2.4459630e-002,
            2.1082435e-002,
            1.7838135e-002,
            1.4793934e-002,
            1.2004510e-002,
            9.5104679e-003,
            7.3374938e-003,
            5.4962252e-003,
            3.9828263e-003,
            2.7802151e-003,
            1.8598621e-003,
            1.1840522e-003,
            7.0848037e-004,
            3.8503956e-004,
            1.6465231e-004,
            1.4774946e-019
    };
    //endregion

    // Ajout de myAbsorp dans le buffer
    mybuffer->array[mybuffer->front] = myAbsorp;
    if(MAXSIZE > mybuffer->size){
        mybuffer->size++;
    }
    if(MAXSIZE-1 > mybuffer->front){
        mybuffer->front++;
    } else {
        mybuffer->front = 0;
    }

    // Calcul de l'absorp selon la formule
    for(int k = 0; k < mybuffer->size; k++){
        if(mybuffer->front - k < 0){
            sortie_acr += FIR_TAPS[k] * mybuffer->array[mybuffer->front - k + 50].acr;
            sortie_acir += FIR_TAPS[k] * mybuffer->array[mybuffer->front - k + 50].acir;
        } else {
            sortie_acr += FIR_TAPS[k] * mybuffer->array[mybuffer->front - k].acr;
            sortie_acir += FIR_TAPS[k] * mybuffer->array[mybuffer->front - k].acir;
        }
    }

    absorp new_absorp = {.acr = sortie_acr,
                         .acir = sortie_acir,
                         .dcr = mybuffer->array[mybuffer->front].dcr,
                         .dcir = mybuffer->array[mybuffer->front].dcir};

    return new_absorp;
}