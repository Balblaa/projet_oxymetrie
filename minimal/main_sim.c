#include "fir.h"
#include "iir.h"
#include "affichage.h"
#include "autotests.h"

int main(){

    testBlocAffichage();
    testBlocFIR();
    testBlocIIR();
    testBlocMesure();

    return 0;
}