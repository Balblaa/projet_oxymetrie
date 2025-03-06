#include "define.h"
#include "fichiers.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/// iirTest retourne le dernier absorp du fichier filename
/// après un filtre fir
/// \param filename: nom du fichier à traiter
/// \return renvoie le dernier absorp calculer
absorp iirTest(char* filename);

/// iir effectue un filtre iir sur current_x
/// \param current_x: absorp voulant être traiter
/// \param last_x: absorp précédent sans passage dans le filtre
/// \param last_y: absorp précédent avec passage dans le filtre
/// \return l'absorp de current_x après un passage de filtre iir
absorp iir(absorp current_x, absorp last_x, absorp last_y);