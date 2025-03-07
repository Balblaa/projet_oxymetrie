#ifndef FICHIERS_H
#define FICHIERS_H
#include <stdio.h>
#include <stdlib.h>
#include "define.h"

/// ouvre un fichier en mode lecture et renvoie son poiteur
/// \param nomFichier: nom du fichier a traiter
/// \return pointeur pour lire le fichier
FILE* initFichier(char* nomFichier );

/// renvoie sous forme d'absorp la ligne pointer par pf
/// 1490,2148,886,2100 -> acr, dcr, acir, dcir
/// \param pf: pointeur du fichier étudier
/// \return absorp de la ligne correspondante
absorp lireFichier(FILE* pf);

/// ferme le fichier
/// \param pf: pointeur du fichier étudier
void finFichier(FILE* pf);
#endif

