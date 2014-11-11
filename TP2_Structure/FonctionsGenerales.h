////////////////////////////////////////////////////////////////////////////////
//							  FonctionsGenerales.h							  //
//				  Fait par M�lissa Boucher et Xavier Brosseau				  //
//							Cr�� le 29 octobre 2014							  //
//						Derniere modif 11 novembre 2014						  //
//																		      //
//				D�clarations des fonctions utilis� dans le main				  //
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
//		Fonction qui denmande les renseignements necessaires � la			  //
//			cr�ation d'une nouvelle instance de client dans la file			  //
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
//					Intrant : Chaine de caract�re � v�rifier				  //
//			Extrant : Boolean (true si caract�re valide false contraire)	  //
//			Fonction qui permet de v�rififer si la chaine de caract�re		  //
//			pass� en parametre est un caract�re numeric ou alphabetique		  //
////////////////////////////////////////////////////////////////////////////////
bool GetInt(int & n);

#endif
