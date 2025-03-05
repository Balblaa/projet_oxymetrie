#include "mesure.h"
#include "fichiers.h"

oxy mesureTest(char* filename){
	oxy myOxy;
    buffer superBuffer = createMyBuffer(filename);
    int dcr = superBuffer.array[superBuffer.front].dcr;
    int dcir = superBuffer.array[superBuffer.front].dcir;
    myOxy = mesure(calculBPM(0.0125),
                   calculSPO2(calculRatio(calculVPP_ACR(superBuffer), calculVPP_ACIR(superBuffer), dcr, dcir)));
	return myOxy;

}

buffer createMyBuffer(char* filename){
    FILE* myfile = initFichier(filename);
    buffer mybuffer = {.front = 0, .size = 0};

    while(getc(myfile) != EOF)
    {
        if(mybuffer.size == 0){
            fseek(myfile, SEEK_SET, 0);
        }
        absorp myAbsorp = lireFichier(myfile);
        mybuffer.array[mybuffer.front] = myAbsorp;
        if(MAXSIZE > mybuffer.size){
            mybuffer.size++;
        }
        if(MAXSIZE-1 > mybuffer.front){
            mybuffer.front++;
        } else {
            mybuffer.front = 0;
        }
    }

    finFichier(myfile);
    return mybuffer;
}

oxy mesure(int BPM, int SPO2){
    oxy mySuperOxy = { .spo2 = SPO2, .pouls = BPM};
    return mySuperOxy;
}

float calculMax_ACR(buffer myBuffer){
    float max_acr = 0;
    for (int i = 0; i < myBuffer.size; ++i) {
        if(max_acr < myBuffer.array[(myBuffer.front+i)%51].acr){
            max_acr = myBuffer.array[(myBuffer.front+i)%51].acr;
        }
    }
    return max_acr;
}

float calculMax_ACIR(buffer myBuffer){
    float max_acir = 0;
    for (int i = 0; i < myBuffer.size; ++i) {
        if(max_acir < myBuffer.array[(myBuffer.front+i)%51].acir){
            max_acir = myBuffer.array[(myBuffer.front+i)%51].acir;
        }
    }
    return max_acir;
}

float calculMin_ACR(buffer myBuffer){
    float min_acr = 0;
    for (int i = 0; i < myBuffer.size; ++i) {
        if(min_acr > myBuffer.array[(myBuffer.front+i)%51].acr){
            min_acr = myBuffer.array[(myBuffer.front+i)%51].acr;
        }
    }
    return min_acr;
}

float calculMin_ACIR(buffer myBuffer){
    float min_acir = 0;
    for (int i = 0; i < myBuffer.size; ++i) {
        if(min_acir > myBuffer.array[(myBuffer.front+i)%51].acir){
            min_acir = myBuffer.array[(myBuffer.front+i)%51].acir;
        }
    }
    return min_acir;
}

float calculVPP_ACR(buffer myBuffer){
    return calculMax_ACR(myBuffer)-calculMin_ACR(myBuffer);
}

float calculVPP_ACIR(buffer myBuffer){
    return calculMax_ACIR(myBuffer)-calculMin_ACIR(myBuffer);
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

float calculPeriode(){

}

float calculBPM(float periode){
    return 1/periode;
}