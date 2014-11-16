////////////////////////////////////////////////////////////////////////////////
//								FileAttente.h									               //
//				  Fait par M�lissa Boucher et Xavier Brosseau				         //
//							Cr�� le 29 octobre 2014							               //
//						Derniere modif 16 novembre 2014						            //
//																		                        //
//			D�claration de la classe FileAttente qui stock le 1er et dernier		//
//			clients en attente. Les m�thodes utilis�s sont fait pour modififer	//
//			la file et afficher la file.														//
////////////////////////////////////////////////////////////////////////////////
#ifndef _FILEATTENTE_H_
#define _FILEATTENTE_H_
#include "ClientsEnAttente.h"

class FileAttente
{
	ClientsEnAttente * pPremier_;  // Premier de la file
	ClientsEnAttente * pDernier_;  // Dernier de la file
	int nbGroupes_ = 0;// Nombre de noeuds dans la file
	int nbPersonne_ = 0;//Nombre de client dans la file
	int nbPersonnesTotal_ = 0;//Nombre de client dans la file au total
	int nbGroupesTotal_ = 0;//Nombre de Groupe dans la file au total

	////////////////////////////////////////////////////////////////////////////////

	//												SetPremier()							             
	//							Intrant : prend un pointeur du noeud et l'identifie
	//								comme le nouveau premier de la list avec le
	//								pointeur premier.
	//	

	//												SetPremier()										           
	//						Intrant : prend un pointeur du noeud et l'identifie			
	//							comme le nouveau premier de la list. 					

	////////////////////////////////////////////////////////////////////////////////
	void SetPremier(ClientsEnAttente * p);
	////////////////////////////////////////////////////////////////////////////////
	//												GetPremier()							             
	//										Extrant : Retourne le pointeur du
	//										premier noeud dans la list
	//	
	////////////////////////////////////////////////////////////////////////////////
	ClientsEnAttente*  GetPremier() const;
	////////////////////////////////////////////////////////////////////////////////
	//												SetDernier()							             
	//							Intrant : prend un pointeur du noeud et l'identifie
	//									comme le nouveau dernier de la list avec le
	//									pointeur dernier.	 
	//	
	////////////////////////////////////////////////////////////////////////////////
	void SetDernier(ClientsEnAttente * p);
	////////////////////////////////////////////////////////////////////////////////
	//												GetDernier()							             
	//										Extrant : Retourne le pointeur du
	//										dernier noeud dans la list	 
	//	
	////////////////////////////////////////////////////////////////////////////////
	ClientsEnAttente*  GetDernier() const;
	////////////////////////////////////////////////////////////////////////////////
	//												SetNbGroupes()							             
	//										Intrant :Prend un int et le met
	//											comme valeur  du NbGroupes
	////////////////////////////////////////////////////////////////////////////////
	void SetNbGroupes(int nb);
	////////////////////////////////////////////////////////////////////////////////
	//												SetNbPersonnes()							             
	//										Intrant :Prend un int et le met
	//											comme valeur  du NbPersonnes 
	//	
	////////////////////////////////////////////////////////////////////////////////
	void SetNbPersonnes(int nb);
	////////////////////////////////////////////////////////////////////////////////
	//												SetNbGroupesTotal()							             
	//										Intrant :Prend un int et le met
	//											comme valeur  du NbGroupesTotal 	 
	//	
	////////////////////////////////////////////////////////////////////////////////
	void SetNbGroupesTotal(int nb);
	////////////////////////////////////////////////////////////////////////////////
	//												SetNbPersonnesTotal()							             
	//										Intrant :Prend un int et le met
	//											comme valeur  du NbPersonnesTotal 	 
	//	
	////////////////////////////////////////////////////////////////////////////////
	void SetNbPersonnesTotal(int nb);


public:
	////////////////////////////////////////////////////////////////////////////////
	//												FileAttente()							             
	//											Constructeur par d�faut
	//
	////////////////////////////////////////////////////////////////////////////////
	FileAttente();
	////////////////////////////////////////////////////////////////////////////////
	//											Afficher()							             
	//									Intrant : Ostream
	//									effectue l'affichage des clients de la list.
	// 
	////////////////////////////////////////////////////////////////////////////////
	void   Afficher(ostream & out) const;
	////////////////////////////////////////////////////////////////////////////////
	//									ObtenirNbGroupes()							             
	//					Extrant : retourne le nombre de groupes que contient laFile
	//
	////////////////////////////////////////////////////////////////////////////////

	int    ObtenirNbGroupes() const;
	////////////////////////////////////////////////////////////////////////////////
	//									ObtenirNbPersonnes()							             
	//					Extrant : retourne le nombre de clients que contient laFile
	//
	////////////////////////////////////////////////////////////////////////////////
	int    ObtenirNbPersonnes() const;
	////////////////////////////////////////////////////////////////////////////////
	//									ObtenirNbPersonnesTotal()							             
	//					Extrant : retourne le nombre de client total qui a �t� servi.
	//
	////////////////////////////////////////////////////////////////////////////////
	int    ObtenirNbPersonnesTotal() const;
	////////////////////////////////////////////////////////////////////////////////
	//										ObtenirNbGroupesTotal()							             
	//							Extrant : retourne le nombre de groupe qui a �t� servi
	//
	////////////////////////////////////////////////////////////////////////////////
	int    ObtenirNbGroupesTotal() const;
	////////////////////////////////////////////////////////////////////////////////
	//										MettreEnMajuscules()							             
	//								Intrant : une chaine String
	//								Extrant : la m�me chaine mais en majuscule
	//								mettre le string pass� en caract�re en majuscule,
	//								pour verifier si les noms sont pareils
	//
	////////////////////////////////////////////////////////////////////////////////
	string  MettreEnMajuscules(string nom) const;
	////////////////////////////////////////////////////////////////////////////////
	//										EstLeMemeNom()							             
	//								Intrant : -le pointeur du client
	//										  -le nom
	//										  -le nombre de personne
	//								Extrant : si le client est pareil que celui de l'instance. 
	//								v�rifie si le client pass� en parametre
	//								et le client de l'instance sont pareil
	//
	////////////////////////////////////////////////////////////////////////////////
	bool EstLeMemeNom(ClientsEnAttente * p, string nom, int nbPersonnes) const;
	////////////////////////////////////////////////////////////////////////////////
	//										Ajouter()							             
	//								Intrant : Le client a mettre en file. 	 
	//								Ajoute un nouveau client dans la file d'attente
	//
	////////////////////////////////////////////////////////////////////////////////
	void	Ajouter(ClientsEnAttente::Client clientAMettreEnFile);
	////////////////////////////////////////////////////////////////////////////////
	//										Retirer()							             
	//								Intrant : -le nombre de place de la	r�servation.
	//										  -la/les section(s) du client.
	//								assigner un groupe a une table.
	//
	////////////////////////////////////////////////////////////////////////////////
	ClientsEnAttente::Client Retirer(int nbPlacesDeLaTable, Section sectionDeLaTable);
	////////////////////////////////////////////////////////////////////////////////
	//										Retirer()							             
	//								Intrant : -le nom du client
	//										  -le nombre de personne
	//								Extrant : si le client a retirer existe. 
	//								retirer un groupe de la file.
	//
	////////////////////////////////////////////////////////////////////////////////
	bool	Retirer(string nomClient, int nbPersonnes);
	////////////////////////////////////////////////////////////////////////////////
	//										GetClient()							             
	//								Intrant : l'indice du client
	//								Extrant : la chaine de caract�re du client	 
	//								retourne un client
	//
	////////////////////////////////////////////////////////////////////////////////
	string	GetClient(int indice) const;
	////////////////////////////////////////////////////////////////////////////////
	//										EstVide()							             
	//								Extrant : si la chaine est vide
	//								verifie si la file est vide
	//
	////////////////////////////////////////////////////////////////////////////////
	bool	EstVide() const;
	////////////////////////////////////////////////////////////////////////////////
	//										V�rifierSiPr�sent()							             
	//								Intrant : -le nom du client
	//										  -le nombre de personne
	//								Extrant : si le client est pr�sente	dans la liste 
	//								M�thode qui v�rifie si un nom est dans la liste
	//
	////////////////////////////////////////////////////////////////////////////////
	bool   V�rifierSiPr�sent(string nom, int nbPersonnes) const;
	////////////////////////////////////////////////////////////////////////////////
	//										AfficherSection()							             
	//								Intrant : le ID de la section
	//								Extrant : le string de la section a 
	//								afficher Pour afficher le choix de section
	//
	////////////////////////////////////////////////////////////////////////////////
	string AfficherSection(int i) const;
	////////////////////////////////////////////////////////////////////////////////
	//										ReduireBoucle()							             
	//						Intrant : -la reference du noeud
	//								  -la reference de si il est trouver
	//								  -la reference du meilleurs choix de noeud
	//								  -la reference de l'indice du nombre de place
	//								  -la reference du vecteur de section choisi
	//						determine si le noeud contient les section demand�es
	//
	////////////////////////////////////////////////////////////////////////////////
	void ReduireBoucle(ClientsEnAttente * & pTemporaire, bool & trouver, ClientsEnAttente * & meilleursChoix, int & i, Section & sectionDeLaTable);
};
#endif
