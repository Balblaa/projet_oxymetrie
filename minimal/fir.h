#include "define.h"
#include "fichiers.h"

/// firTest retourne le dernier absorp du fichier filename en effectuant
/// un filtre FIR sur l'ensemble des donner de filename
/// \param filename: chaine de caractère
/// \returns renvoie le dernier absorp calculer
absorp firTest(char* filename);

/// effectue un filtre FIR sur myAbsorp
/// \param mybuffer: un buffer contenant les précédents absorp de taille MAXSIZE
/// \param myAbsorp: l'asborp traiter
/// \returns renvoie l'absorp après un passage de filtre FIR
absorp fir(buffer* mybuffer, absorp myAbsorp);