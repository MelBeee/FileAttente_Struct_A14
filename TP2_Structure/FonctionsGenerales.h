////////////////////////////////////////////////////////////////////////////////
//								Source.cpp									  //
//				  Fait par Mélissa Boucher et Xavier Brosseau				  //
//							Créé le 29 octobre 2014							  //
//						Derniere modif 11 novembre 2014						  //
//																		      //
//			Menu utilisateur servant à tester les différentes fonctions		  //
//			de la file d'attente dans le cadre d'une utilisateur d'une		  //	 
//			file de clients et d'attribuation de table dans un restaurant.	  //
////////////////////////////////////////////////////////////////////////////////
#ifndef _FONCTIONSGENERALES_H_
#define _FONCTIONSGENERALES_H_
#include <sstream>
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
Client CreationClient(Client n);
void AfficherUnClient(FileAttente const laFile);
void AfficherLigneSeparation();
bool GetInt(int & n);

#endif
