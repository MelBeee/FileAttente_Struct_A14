////////////////////////////////////////////////////////////////////////////////
//							  FonctionsGenerales.h							  //
//				  Fait par Mélissa Boucher et Xavier Brosseau				  //
//							Créé le 29 octobre 2014							  //
//						Derniere modif 11 novembre 2014						  //
//																		      //
//				Déclarations des fonctions utilisé dans le main				  //
////////////////////////////////////////////////////////////////////////////////
#ifndef _FONCTIONSGENERALES_H_
#define _FONCTIONSGENERALES_H_
#include <sstream>
#include <iostream>
#include <string>
#include "FileAttente.h"
using namespace std;

////////////////////////////////////////////////////////////////////////////////
//								MenuFaireChoix()							  //
//		Intrant : Aucun		Extrant : Int (Choix fait par l'utilisateur		  //
//	   Fonction qui permet a l'utilisateur de faire un choix dans le menu	  //
////////////////////////////////////////////////////////////////////////////////
int MenuFaireChoix();
////////////////////////////////////////////////////////////////////////////////
//							DemanderInfoClient()							  //
//			Intrant : string , int , int		Extrant : Aucun				  //
//		Fonction qui denmande les renseignements necessaires à la			  //
//			création d'une nouvelle instance de client dans la file			  //
////////////////////////////////////////////////////////////////////////////////
void DemanderInfoClient(string& nom, int& nbre, int& sections);
////////////////////////////////////////////////////////////////////////////////
//								Attendre()									  //
//					Intrant : Aucun		Extrant : Aucun						  //
//		Fonction qui fait en sorte que l'utilisateur doit peser				  //
//			sur une touche pour que le programme se continue				  // 
////////////////////////////////////////////////////////////////////////////////
void Attendre();
////////////////////////////////////////////////////////////////////////////////
//								Sections()									  //
//		Intrant : int , string(message a afficher)		Extrant : Aucun		  //
//		Demande a l'utilisateur oui ou non pour les differentes sections	  //
////////////////////////////////////////////////////////////////////////////////
char Sections(int & section, string nom);
void AssignerTable();
bool QuitterLeProgramme(FileAttente const laFile);
void AffichageFinale(FileAttente const laFile);
int DeterminerSection();
void RetraitClient(FileAttente& laFile);
void SetClientSection(int section, Client& c);
Client CreationClient(Client n);
void AfficherUnClient(FileAttente const laFile);
void AfficherLigneSeparation();
////////////////////////////////////////////////////////////////////////////////
//								GetInt()									  //
//					Intrant : Chaine de caractère à vérifier				  //
//			Extrant : Boolean (true si caractère valide false contraire)	  //
//			Fonction qui permet de vérififer si la chaine de caractère		  //
//			passé en parametre est un caractère numeric ou alphabetique		  //
////////////////////////////////////////////////////////////////////////////////
bool GetInt(int & n);

#endif
