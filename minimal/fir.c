#include "fir.h"

absorp firTest(char* filename){
	absorp myAbsorp;

    FILE* myfile = initFichier(filename);
    int* character;

    buffer mybuffer;
    mybuffer.front = 0;
    mybuffer.size = 0;

    while(character != EOF)
    {
        myAbsorp = lireFichier(myfile, character);
        mybuffer.array[mybuffer.front] = myAbsorp;
        if(MAXSIZE > mybuffer.size){
            mybuffer.size++;
        }
        if(MAXSIZE > mybuffer.front){
            mybuffer.front++;
        } else {
            mybuffer.front = 0;
        }

        myAbsorp = fir(mybuffer);
        

    }

    finFichier(myfile);
	return myAbsorp;

}

absorp fir(buffer mybuffer){

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

    float sortie_acr = 0;
    float sortie_acir = 0;

    for(int k = 0; k < mybuffer.size; k++){
        sortie_acr += FIR_TAPS[k] * mybuffer.array[mybuffer.front - k].acr;
        sortie_acir += FIR_TAPS[k] * mybuffer.array[mybuffer.front - k].acr;
    }

    absorp new_absorp;
    new_absorp.acr = sortie_acr;
    new_absorp.acir = sortie_acir;
    new_absorp.dcr = mybuffer.array[mybuffer.front].dcr;
    new_absorp.dcir = mybuffer.array[mybuffer.front].dcir;

    return new_absorp;
}