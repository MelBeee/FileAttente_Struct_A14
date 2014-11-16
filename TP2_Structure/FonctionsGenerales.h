////////////////////////////////////////////////////////////////////////////////
//							  FonctionsGenerales.h							               //
//				  Fait par M�lissa Boucher et Xavier Brosseau				         //
//							Cr�� le 29 octobre 2014							               //
//						Derniere modif 11 novembre 2014						            //
//																		                        //
//				D�clarations des fonctions utilis� dans le main				         //
////////////////////////////////////////////////////////////////////////////////
#ifndef _FONCTIONSGENERALES_H_
#define _FONCTIONSGENERALES_H_
#include "FileAttente.h"
////////////////////////////////////////////////////////////////////////////////
//								MenuFaireChoix()							                  //
//		Intrant : Aucun		Extrant : Int (Choix fait par l'utilisateur		   //
//	   Fonction qui permet a l'utilisateur de faire un choix dans le menu	   //
////////////////////////////////////////////////////////////////////////////////
int MenuFaireChoix();
////////////////////////////////////////////////////////////////////////////////
//							DemanderInfoClient()							                  //
//			Intrant : string , int , int		Extrant : Aucun				         //
//		Fonction qui denmande les renseignements necessaires � la			      //
//			cr�ation d'une nouvelle instance de client dans la file			      //
////////////////////////////////////////////////////////////////////////////////
void DemanderInfoClient(string& nom, int& nbre, int& sections);
////////////////////////////////////////////////////////////////////////////////
//								Attendre()									                  //
//					Intrant : Aucun		Extrant : Aucun						         //
//		Fonction qui fait en sorte que l'utilisateur doit peser				      //
//			sur une touche pour que le programme se continue				         // 
////////////////////////////////////////////////////////////////////////////////
void Attendre();
////////////////////////////////////////////////////////////////////////////////
//								Sections()									                  //
//		Intrant : int , string(message a afficher)		Extrant : Aucun		   //
//		Demande a l'utilisateur oui ou non pour les differentes sections	      //
////////////////////////////////////////////////////////////////////////////////
char Sections(int & section, string nom);
////////////////////////////////////////////////////////////////////////////////
//								   AssignerTable()									         //
//		            Intrant : laFile		Extrant : Aucun		                  //
//	            Fonction general qui appel les autres fonctions                //
//                permettant l'assignation a une table                        //
////////////////////////////////////////////////////////////////////////////////
void AssignerTable(FileAttente & laFile);
////////////////////////////////////////////////////////////////////////////////
//							QuitterLeProgramme()							                  //
//			Intrant : laFile		Extrant : bool quitter ou non			            //
//		Fonction qui v�rifie s'il reste des gens en file, si oui on			      //
//			demande a l'utilsiateur s'il veux quand meme quitter			         // 
////////////////////////////////////////////////////////////////////////////////
bool QuitterLeProgramme(FileAttente & laFile);
////////////////////////////////////////////////////////////////////////////////
//							AffichageFinale()								                  //
//					Intrant : laFile	Extrant : Aucun						            //
//		Affiche le nombre de r�servation totale, le nombre de client total	   //
//		et le nombre de personne restant dans la file au moment de quitter      //
////////////////////////////////////////////////////////////////////////////////
void AffichageFinale(FileAttente & laFile);
////////////////////////////////////////////////////////////////////////////////
//								RetraitClient()								               //
//					Intrant : laFile	Extrant : Aucun						            //
//		Retire un client qui s'en va de la file parce que c'est trop long	      //
////////////////////////////////////////////////////////////////////////////////
void RetraitClient(FileAttente & laFile);
////////////////////////////////////////////////////////////////////////////////
//								SetClientSection()							               //
//					Intrant : int, client	Extrant : Aucun					         //
//		Fonction qui pushback les Section(enum) dans le vecteur du client	      //
////////////////////////////////////////////////////////////////////////////////
void SetClientSection(int section, Client& c);
////////////////////////////////////////////////////////////////////////////////
//							  DeterminerSection()							               //
//						Intrant : Aucun	Extrant : Int						            //
//		Fonction determine les diff�rentes sections a mettre dans le vector	   //
////////////////////////////////////////////////////////////////////////////////
int DeterminerSection();
////////////////////////////////////////////////////////////////////////////////
//							CreationClient()								                  //
//					Intrant : Client	Extrant : Client					               //
//	   Fonction qui englobe tout les fonctions pour cr�er un nouveau client    //
////////////////////////////////////////////////////////////////////////////////
Client CreationClient(Client n);
////////////////////////////////////////////////////////////////////////////////
//							AfficherUnClient()								               //
//					Intrant : laFile	Extrant : Aucun						            //
//			 Fonction qui affiche un client demander par l'utilisateur	   	   //
////////////////////////////////////////////////////////////////////////////////
void AfficherUnClient(FileAttente & laFile, ostream & out);
////////////////////////////////////////////////////////////////////////////////
//						  AfficherLigneSeparation()							            //
//					Intrant : Aucun		Extrant : Aucun						         //
//		Fonctions de paresseux ! :) Affiche une ligne de = pour s�parer		   //
////////////////////////////////////////////////////////////////////////////////
void AfficherLigneSeparation();
////////////////////////////////////////////////////////////////////////////////
//								GetInt()									                     //
//					Intrant : Chaine de caract�re � v�rifier				            //
//			Extrant : Boolean (true si caract�re valide false contraire)	      //
//			Fonction qui permet de v�rififer si la chaine de caract�re		      //
//			pass� en parametre est un caract�re numeric ou alphabetique		      //
////////////////////////////////////////////////////////////////////////////////
bool GetInt(int & n);
////////////////////////////////////////////////////////////////////////////////
//						  DemanderQuiEstClient()							               //
//			Intrant : string, int , File	Extrant : Aucun					         //
//		Fonction qui demande nom et nombre d'une reservation tant qu'il		   //
//      n'y a pas trouver une �quivalente a celle entr� par l'utilisateur	   //
////////////////////////////////////////////////////////////////////////////////
bool DemanderQuiEstClient(string & nom, int & nbre, FileAttente & laFile);
////////////////////////////////////////////////////////////////////////////////
//						  AfficherLaFileEnEntier()							               //
//					Intrant : ostream, laFile		Extrant : Aucun			         //
//		               Afficher la file d'attente en entier	             	   //
////////////////////////////////////////////////////////////////////////////////
void AfficherLaFileEnEntier(ostream & out, FileAttente & laFile);
////////////////////////////////////////////////////////////////////////////////
//						  AfficherLigneSeparation()							            //
//					Intrant : Aucun		Extrant : Aucun						         //
//		Fonctions de paresseux ! :) Affiche une ligne de = pour s�parer		   //
////////////////////////////////////////////////////////////////////////////////
bool SwitchMenu(bool quitter, FileAttente & laFile, Client nouveau);
////////////////////////////////////////////////////////////////////////////////
//										DemanderRang()								            //
//				Intrant : laFile et le rang		Extrant : bool				         //
//		Fonction qui demande un rang a l'utilisateur et retourne si il existe   //
////////////////////////////////////////////////////////////////////////////////
bool DemanderRang(FileAttente & laFile, int & Rang);
////////////////////////////////////////////////////////////////////////////////
//									 AfficherEntete()								            //
//					Intrant : string		Extrant : Aucun						         //
//					Affiche l'entete des diff�rents choix du menu					   //
////////////////////////////////////////////////////////////////////////////////
void AfficherEntete(string entete);

#endif
