// On va développer une liste de noeuds
//
// par Pierre Prud'homme, octobre 2014
//-------------------------------------------------
#ifndef _LISTE_H_
#define _LISTE_H_
#include "ClientsEnAttente.h"
#include <iostream>
using namespace std;

class FileAttente
{
	ClientsEnAttente * pPremier_;  // Premier de la file
	ClientsEnAttente * pDernier_;  // Dernier de la file
	int     nbGroupes_;// Nombre de noeuds dans la file
	int		nbPersonne_;//Nombre de client dans la file

	void    SetPremier(ClientsEnAttente * p);
	ClientsEnAttente*  GetPremier() const;

	void    SetDernier(ClientsEnAttente * p);
	ClientsEnAttente*  GetDernier() const;

	void    SetNbGroupes(int nb);
	void	SetNbPersonnes(int nb);

public:
	//--- Constructeur par défaut
	FileAttente();

	//--- Destructeur par défaut
	~FileAttente();

	//--- La liste peut s'afficher elle-même
	void   Afficher(ostream & out) const;

	//--- et retourner le nombre de groupes qu'elle contient
	int    ObtenirNbGroupes() const;

	//--- et retourner le nombre client qu'elle contient
	int    ObtenirNbPersonnes() const;

	string  MettreEnMajuscules(string nom) const;
	bool    EstLeMemeNom(ClientsEnAttente * p, string nom, int nbPersonnes) const;
	void Ajouter(Client clientAMettreEnFile);
	Client Retirer(int nbPlacesDeLaTable, Section sectionDeLaTable);
	bool Retirer(string nomClient, int nbPersonnes);
	string GetClient(int indice) const; 
	bool EstVide() const;

	//--- Méthode qui vérifie si un nom est dans la liste
	bool   VérifierSiPrésent(string nom, int nbPersonnes) const;

	//--- Méthode qui retourne un entier correspondant au rang dans la liste
	//    0 signifie absent. 
	int    DonnerLeRang(string nom, int nbPersonnes) const;

	//--- De faire passer le dernier en premier dans la liste
	void  PasserDevantToutLeMonde();
};
#endif