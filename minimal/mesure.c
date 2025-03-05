#include "mesure.h"
#include "fichiers.h"

oxy mesureTest(char* filename){
	oxy myOxy;
    onde myOnde = {.max_ACR = 0, .min_ACR = 0, .max_ACIR = 0, .min_ACIR = 0};
    FILE* myfile = fopen(filename, "r");
    absorp myAbsorp = {.acr = 0, .acir = 0, .dcr = 0, .dcir = 0};

    int init = 1;
    int counter_period = 0;
    float period = 0;

    while(getc(myfile) != EOF)
    {
        if(init){
            fseek(myfile, SEEK_SET, 0);
            init = 0;
        }
        myAbsorp = lireFichier(myfile);

        myOnde.max_ACIR = calculMax_ACIR(myOnde, myAbsorp);
        myOnde.min_ACIR = calculMin_ACIR(myOnde, myAbsorp);
        myOnde.max_ACR = calculMax_ACR(myOnde, myAbsorp);
        myOnde.min_ACR = calculMin_ACR(myOnde, myAbsorp);

        if((myAbsorp.acr <= 0) && (myOnde.last_absorp.acr > 0)){
            myOnde.max_ACIR = myAbsorp.acir;
            myOnde.min_ACIR = myAbsorp.acir;
            myOnde.max_ACR = myAbsorp.acr;
            myOnde.min_ACR = myAbsorp.acr;

            period = counter_period * 0.002;
            counter_period = 0;
        }

        counter_period++;
        myOnde.last_absorp = myAbsorp;
        printf("%f\n", period);

        myOxy = mesure(calculBPM(period),
                       calculSPO2(calculRatio(calculVPP_ACR(myOnde),
                                              calculVPP_ACIR(myOnde),
                                              myAbsorp.dcr,
                                              myAbsorp.dcir)));
    }

	return myOxy;

}

oxy mesure(int BPM, int SPO2){
    oxy mySuperOxy = { .spo2 = SPO2, .pouls = BPM};
    return mySuperOxy;
}

float calculMax_ACR(onde myOnde, absorp myAbsorp){

    if(myOnde.max_ACR < myAbsorp.acr){
        myOnde.max_ACR = myAbsorp.acr;
    }
    return myOnde.max_ACR;
}

float calculMax_ACIR(onde myOnde, absorp myAbsorp){

    if(myOnde.max_ACIR < myAbsorp.acir){
        myOnde.max_ACIR = myAbsorp.acir;
    }
    return myOnde.max_ACIR;
}

float calculMin_ACR(onde myOnde, absorp myAbsorp){

    if(myOnde.min_ACR > myAbsorp.acr){
        myOnde.min_ACR = myAbsorp.acr;
    }
    return myOnde.min_ACR;
}

float calculMin_ACIR(onde myOnde, absorp myAbsorp){

    if(myOnde.min_ACIR > myAbsorp.acir){
        myOnde.min_ACIR = myAbsorp.acir;
    }
    return myOnde.min_ACIR;

}

float calculVPP_ACR(onde myOnde){
    return myOnde.max_ACR - myOnde.min_ACR;
}

float calculVPP_ACIR(onde myOnde){
    return myOnde.max_ACIR - myOnde.min_ACIR;
}

float calculRatio(float vppacr, float vppacir, float dcr, float dcir){
    return (vppacr/dcr)/(vppacir/dcir);
}

float calculSPO2(float ratio){
    float res = 0;
    if(ratio == 1){
        res = 85;
    }
    else{
        if(ratio < 0.4){
            printf("Heu vous êtes vivant ? Faudrait aller chez le docteur...");
        }
        else{
            if(ratio < 1){
                res = (ratio * (-25))+ 110;
            }
            else{
                if(ratio > 3.4){
                    printf("Heu vous êtes vivant ? Faudrait aller chez le docteur...");
                }
                else{
                    res = (ratio * (-35.42)) + 120.42;
                }
            }
        }
    }
    return res;
}

float calculBPM(float periode){
    return 60/periode;
}