#ifndef _FONCTIONSGENERALES_H_
#define _FONCTIONSGENERALES_H_

#include <iostream>
#include <string>
#include "FileAttente.h"
using namespace std;

int MenuFaireChoix();
// Doit passer client en parametre
void DemanderInfoClient(string& nom, int& nbre, int& sections);
void Attendre();
void AssignerTable();
bool QuitterLeProgramme();
void AffichageFinale();
int DeterminerSection();


#endif
