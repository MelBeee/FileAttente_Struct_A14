////////////////////////////////////////////////////////////////////////////////
//								FileAttente.h									               //
//				  Fait par Mélissa Boucher et Xavier Brosseau				         //
//			Créé le 29 octobre 2014,	Derniere modif 16 novembre 2014			   //
//			Déclaration de la classe FileAttente qui stock le 1er et dernier		//
//			clients en attente. Les méthodes utilisés sont fait pour modififer	//
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
       
	//	Intrant : prend un pointeur du noeud et l'identifie
	//	comme le nouveau premier de la liste
	void SetPremier(ClientsEnAttente * p);					             
	//	Extrant : Retourne le pointeur du premier noeud dans la list
	ClientsEnAttente*  GetPremier() const; 
	//	Intrant : prend un pointeur du noeud et l'identifie
	//	comme le nouveau dernier de la list avec le pointeur dernier.	
	void SetDernier(ClientsEnAttente * p);					             
	//	Extrant : Retourne le pointeur du dernier noeud dans la list	 
	ClientsEnAttente*  GetDernier() const;	             
	//	Intrant :Prend un int et le met comme valeur  du NbGroupes
	void SetNbGroupes(int nb);             
	//	Intrant :Prend un int et le met comme valeur  du NbPersonnes 
	void SetNbPersonnes(int nb);			             
	//	Intrant :Prend un int et le met comme valeur  du NbGroupesTotal 	 
	void SetNbGroupesTotal(int nb);					             
	//	Intrant :Prend un int et le met comme valeur  du NbPersonnesTotal
	void SetNbPersonnesTotal(int nb);

public:				             
	// Constructeur par défaut
	FileAttente();					             
	//	Intrant : Ostream
	//	effectue l'affichage des clients de la list.
	void   Afficher(ostream & out) const;             
	//	Extrant : retourne le nombre de groupes que contient laFile
	int    ObtenirNbGroupes() const;				             
	//	Extrant : retourne le nombre de clients que contient laFile
	int    ObtenirNbPersonnes() const;			             
	// Extrant : retourne le nombre de client total qui a été servi.
	int    ObtenirNbPersonnesTotal() const;				             
	//	Extrant : retourne le nombre de groupe qui a été servi
	int    ObtenirNbGroupesTotal() const;						             
	//	Intrant : une chaine String
	//	Extrant : la même chaine mais en majuscule mettre le string passé 
	// en paramètre en majuscule, pour verifier si les noms sont pareils
	string  MettreEnMajuscules(string nom) const;				             
	//	Intrant : -le pointeur du client -le nom -le nombre de personne
	//	Extrant : si le client est pareil que celui de l'instance. Vérifie si 
	// le client passé en parametre met le client de l'instance sont pareil
	bool EstLeMemeNom(ClientsEnAttente * p, string nom, int nbPersonnes) const;						             
	//	Intrant : Le client a mettre en file. 	 
	//	Ajoute un nouveau client dans la file d'attente
	void	Ajouter(ClientsEnAttente::Client clientAMettreEnFile);				             
	// Intrant : -le nombre de place de la réservation.
	//				 -la/les section(s) du client. assigner un groupe a une table.
	ClientsEnAttente::Client Retirer(int nbPlacesDeLaTable, Section sectionDeLaTable);				             
	// Intrant : -le nom du client -le nombre de personne
	//	Extrant : si le client a retirer existe. retirer un groupe de la file.
	bool	Retirer(string nomClient, int nbPersonnes);						             
	//	Intrant : l'indice du client
	//	Extrant : la chaine de caractère du client retourne un client
	string	GetClient(int indice) const;           
	//	Intrant : 	Extrant : 	 
	//	verifie si la file est vide
	bool	EstVide() const;						             
	//	Intrant : 	Extrant : 	 
	//	Méthode qui vérifie si un nom est dans la liste
	bool   VérifierSiPrésent(string nom, int nbPersonnes) const;            
	//	Intrant : 	Extrant : 	 
	//	Pour afficher le choix de section
	string AfficherSection(int i) const;	             
	//	Intrant : 	Extrant : 	 
	//	
	void ReduireBoucle(ClientsEnAttente * & pTemporaire, bool & trouver, ClientsEnAttente * & meilleursChoix, int & i, Section & sectionDeLaTable);
};
#endif
