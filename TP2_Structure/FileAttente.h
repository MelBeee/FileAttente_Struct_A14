// On va d�velopper une liste de noeuds
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

	bool    EstVide() const;

	bool    EstLeMemeNom(ClientsEnAttente * p, string nom) const;
	string  MettreEnMajuscules(string nom) const;

public:
	//--- Constructeur par d�faut
	FileAttente();

	//--- Destructeur par d�faut
	~FileAttente();

	//--- La liste peut s'afficher elle-m�me
	void   Afficher(ostream &) const;

	//--- et retourner le nombre de groupes qu'elle contient
	int    ObtenirNbGroupes() const;

	//--- et retourner le nombre client qu'elle contient
	int    ObtenirNbPersonnes() const;

	//--- on peut ajouter en fin de liste et retirer au d�but de la liste
	void   Ajouter(string nom, int nbPersonne, int section);
	
	string RetirerDeLaListe();

	//--- M�thode qui v�rifie si un nom est dans la liste
	bool   V�rifierSiPr�sent(string nom) const;

	//--- M�thode qui retourne un entier correspondant au rang dans la liste
	//    0 signifie absent. 
	int    DonnerLeRang(string nom) const;

	//--- De faire passer le dernier en premier dans la liste
	void  PasserDevantToutLeMonde();
};
#endif