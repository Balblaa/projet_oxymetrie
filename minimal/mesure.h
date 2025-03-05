#include "define.h"

oxy mesureTest(char* filename);
buffer createMyBuffer(char* filename);
float calculMax_ACR(buffer myBuffer);
float calculMax_ACIR(buffer myBuffer);
float calculMin_ACR(buffer myBuffer);
float calculMin_ACIR(buffer myBuffer);
float calculVPP_ACR(buffer myBuffer);
float calculVPP_ACIR(buffer myBuffer);
float calculRatio(float vppacr, float vppacir, float dcr, float dcir);
float calculSPO2(float ratio);
float calculPeriode();
float calculBPM(float periode);
oxy mesure(int BPM, int SPO2);