#include "define.h"
#include "fichiers.h"

/// mesureTest relève les mesures de SPO2 et du pbm pour chaque absorp du fichier filename
/// \param filename: nom du fichier à traiter
/// \return renvoie le SPO2 et le bpm sous forme oxy du dernier absorp du fichier
oxy mesureTest(char* filename);

/// mesure modifie l'oxy passer en paramètre pour lui attribué de nouvelle valeur en fonction de myAbsorp
/// \param myAbsorp: l'absorp dont on souhait mesure les informations
/// \param myOnde: onde étudier
/// \param myOxy: oxe à motifier
void mesure(absorp myAbsorp, onde* myOnde, oxy* myOxy);

/// calculMax_ACR renvoie la plus grande valeur entre la valeur max_ACR de myOnde et la valeur ACR de myAbsorp
/// \param myOnde: onde étudier
/// \param myAbsorp: absorp a comparer
/// \return renvoie un flotant de la valeur la plus grande
float calculMax_ACR(onde myOnde, absorp myAbsorp);

/// calculMax_ACIR renvoie la plus grande valeur entre la valeur max_ACIR de myOnde et la valeur ACIR de myAbsorp
/// \param myOnde: onde étudier
/// \param myAbsorp: absorp a comparer
/// \return renvoie un flotant de la valeur la plus grande
float calculMax_ACIR(onde myOnde, absorp myAbsorp);

/// calculMin_ACR renvoie la plus petite valeur entre la valeur min_ACR de myOnde et la valeur ACR de myAbsorp
/// \param myOnde: onde étudier
/// \param myAbsorp: absorp a comparer
/// \return renvoie un flotant de la valeur la plus petite
float calculMin_ACR(onde myOnde, absorp myAbsorp);

/// calculMin_ACIR renvoie la plus petite valeur entre la valeur min_ACIR de myOnde et la valeur ACIR de myAbsorp
/// \param myOnde: onde étudier
/// \param myAbsorp: absorp a comparer
/// \return renvoie un flotant de la valeur la plus petite
float calculMin_ACIR(onde myOnde, absorp myAbsorp);

/// calculVPP_ACR renvoie la différence entre Max_ACR et Min_ACR de myOnde
/// \param myOnde: onde étudier
/// \return renvoie VPP_ACR
float calculVPP_ACR(onde myOnde);

/// calculVPP_ACIR renvoie la différence entre Max_ACIR et Min_ACIR de myOnde
/// \param myOnde: onde étudier
/// \return renvoie VPP_ACIR
float calculVPP_ACIR(onde myOnde);

/// calculRatio calcul le ration pour le SPO2
/// \param vppacr
/// \param vppacir
/// \param dcr
/// \param dcir
float calculRatio(float vppacr, float vppacir, float dcr, float dcir);

/// 
/// \param ratio
/// \return
float calculSPO2(float ratio);

float calculPeriode();

float calculBPM(float periode);