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
bool QuitterLeProgramme(FileAttente const laFile);
void AffichageFinale(FileAttente const laFile);
int DeterminerSection();
void RetraitClient(FileAttente& laFile);
void SetClientSection(int section, Client& c);
string AfficherSection(int i);
Client CreationClient(Client n);
void AfficherUnClient(FileAttente const laFile);
void AfficherLigneSeparation();

#endif
