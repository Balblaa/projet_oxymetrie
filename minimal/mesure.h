#include "define.h"
#include "fichiers.h"

oxy mesureTest(char* filename);
buffer createMyBuffer(char* filename);
float calculMax_ACR(onde myOnde, absorp myAbsorp);
float calculMax_ACIR(onde myOnde, absorp myAbsorp);
float calculMin_ACR(onde myOnde, absorp myAbsorp);
float calculMin_ACIR(onde myOnde, absorp myAbsorp);
float calculVPP_ACR(onde myOnde);
float calculVPP_ACIR(onde myOnde);
float calculRatio(float vppacr, float vppacir, float dcr, float dcir);
float calculSPO2(float ratio);
float calculPeriode();
float calculBPM(float periode);
void mesure(absorp myAbsorp, onde* myOnde, oxy* myOxy);