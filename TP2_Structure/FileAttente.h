////////////////////////////////////////////////////////////////////////////////
//								Source.cpp									  //
//				  Fait par M�lissa Boucher et Xavier Brosseau				  //
//							Cr�� le 29 octobre 2014							  //
//						Derniere modif 11 novembre 2014						  //
//																		      //
//			Menu utilisateur servant � tester les diff�rentes fonctions		  //
//			de la file d'attente dans le cadre d'une utilisateur d'une		  //	 
//			file de clients et d'attribuation de table dans un restaurant.	  //
////////////////////////////////////////////////////////////////////////////////
#ifndef _FILEATTENTE_H_
#define _FILEATTENTE_H_
#include "ClientsEnAttente.h"
#include <iostream>
using namespace std;

class FileAttente
{
	ClientsEnAttente * pPremier_;  // Premier de la file
	ClientsEnAttente * pDernier_;  // Dernier de la file
	int nbGroupes_ = 0;// Nombre de noeuds dans la file
	int nbPersonne_ = 0;//Nombre de client dans la file
	int nbPersonnesTotal_ = 0;//Nombre de client dans la file au total
	int nbGroupesTotal_ = 0;//Nombre de Groupe dans la file au total

	void    SetPremier(ClientsEnAttente * p);
	ClientsEnAttente*  GetPremier() const;

	void    SetDernier(ClientsEnAttente * p);
	ClientsEnAttente*  GetDernier() const;

	void    SetNbGroupes(int nb);
	void	SetNbPersonnes(int nb);
	void	SetNbGroupesTotal(int nb);
	void	SetNbPersonnesTotal(int nb);

public:
	//--- Constructeur par d�faut
	FileAttente();

	//--- Destructeur par d�faut
	~FileAttente();

	//--- La liste peut s'afficher elle-m�me
	void   Afficher(ostream & out) const;

	//--- et retourner le nombre de groupes qu'elle contient
	int    ObtenirNbGroupes() const;

	//--- et retourner le nombre client qu'elle contient
	int    ObtenirNbPersonnes() const;

	//--- et retourner le nombre client qu'elle contient
	int    ObtenirNbPersonnesTotal() const;

	//--- et retourner le nombre client qu'elle contient
	int    ObtenirNbGroupesTotal() const;

   //--- mettre le string pass� en caract�re en majuscule, pour verifier si les noms sont pareils
	string  MettreEnMajuscules(string nom) const;

   //--- v�rifie si le client pass� en parametre et le client de l'instance sont pareil
	bool    EstLeMemeNom(ClientsEnAttente * p, string nom, int nbPersonnes) const;

   //--- ajoute un nouveau client dans la file d'attente
	void	Ajouter(Client clientAMettreEnFile);

   //--- assigner un groupe a une table
   Client 	Assigner(int nbPlacesDeLaTable, Section sectionDeLaTable);

   //--- retirer un groupe de la file
	bool	Retirer(string nomClient, int nbPersonnes);

   //--- retourner un client 
	string	GetClient(int indice) const;

   //--- verifie si la file est vide
	bool	EstVide() const;

	//--- M�thode qui v�rifie si un nom est dans la liste
	bool   V�rifierSiPr�sent(string nom, int nbPersonnes) const;

	//--- M�thode qui retourne un entier correspondant au rang dans la liste
	//    0 signifie absent. 
	int    DonnerLeRang(string nom, int nbPersonnes) const;

	//--- De faire passer le dernier en premier dans la liste
	void  PasserDevantToutLeMonde();

	//--- Pour afficher le choix de section
	string AfficherSection(int i) const;
};
#endif
