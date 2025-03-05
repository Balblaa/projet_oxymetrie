#include "fir.h"
#include "iir.h"

int main(){

    printf("Bonjour Mr Octopus\n");
    absorp bobby = iirTest("log/log1_fir.dat");
    printf("last y    => acr : %d, dcr : %d, acir : %d, dcir : %d\n",bobby.acr, bobby.dcr, bobby.acir, bobby.dcir);
    printf("resultat  => acr : 732, dcr : 2048, acir : 1525, dcir : 2000\n",bobby.acr, bobby.dcr, bobby.acir, bobby.dcir);
    printf("\nAu revoir Mr Octopus\n");

    return 0;
}