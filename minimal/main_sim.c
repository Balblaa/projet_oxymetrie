#include "fir.h"
#include "iir.h"
#include "mesure.h"

int main(){

    oxy res = { .spo2 = 0, .pouls = 0};
    res = mesureTest("log/log1_iir.dat");
    printf("Result => SPO2 : %d, Pouls : %d.\n", res.spo2, res.pouls);
    return 0;
}