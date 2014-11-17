////////////////////////////////////////////////////////////////////////////////
//								      ClientsEnAttente.h								      //
//				      Fait par Mélissa Boucher et Xavier Brosseau				      //
//			Créé le 29 octobre 2014,	Derniere modif 16 novembre 2014			   //
//			Déclaration de la classe ClientsEnAttente qui permet de créer        //
//       des clients a ajouter dans la file d'attente. Structure Client       //
////////////////////////////////////////////////////////////////////////////////
#ifndef _CLIENTSENATTENTE_H_
#define _CLIENTSENATTENTE_H_
#pragma warning (disable:4227)
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

enum Section // enumeration pour les choix de sections que l'utilisateur a
{
	TerrasseNonFumeur = 1, TerrasseFumeur = 10, SalleManger = 100
};
////////////////////////////////////////////////////////////////////////////////
//								Class ClientsEnAttente							        	   //
////////////////////////////////////////////////////////////////////////////////
class ClientsEnAttente
{
public:
	struct Client
	{
		string nomReservation;
		int nombreDePersonnes;
		vector<Section> sectionChoisis;
	};
	//	Intrants: Nom du client, nombre de personne a table et les sections voulus
	// Permet de créer un ClientsEnAttente avec des valeurs demandées
	ClientsEnAttente(string nom, int nbPersonne, vector<Section> sections);
	//	Intrants: un pointeur sur un Client Extrants: Aucun
	//	Permet d'initialisé le Client précédant a notre instance de client
	void SetPrécédent(ClientsEnAttente * p);
	//	Intrants: un pointeur sur un Client Extrants: Aucun
	//	Permet d'initialisé le Client suivant a notre instance de client
	void SetSuivant(ClientsEnAttente *p);
	// Intrants: un Client Extrants: Aucun
	//	Permet de "setter" les valeurs d'un client
	void SetClient(Client c);
	//	Intrants: Aucun Extrants: un pointeur sur un Client
	//	Permet d'obtenir le pointeur sur le client précédent celui demandé
	ClientsEnAttente * GetPrécédent() const;
	//	Intrants: Aucun Extrants: un pointeur sur un Client
	//	Permet d'obtenir le pointeur sur le client suivant celui demandé
	ClientsEnAttente * GetSuivant() const;
	//	Intrants: Aucun Extrants: string du nom du client
	//	Permet d'obtenir le nom du client
	string GetNom() const;
	// Intrants: Aucun Extrants: int du nombre de personne
	//	Permet d'obtenir le nombre de personne	
	int GetNombrePersonne() const;
	//	Intrants: Aucun Extrants: vector des sections demandées
	//	Permet d'obtenir les sections que le client a demandées
	vector<Section> GetClientSection() const;
	//	Intrants: Aucun Extrants: Client
	//	Permet d'obtenir un client
	Client GetClient() const;
	//	Intrants: Client, et une section Extrant : bool Présent
	//	Permet de parcourir le vector de section du client pour comparé avec la section demandé. Si la section y est présente, retourne vrai sinon, faux
	bool ChoixSection(ClientsEnAttente c, Section s);

private:
	Client clientsTable_;				// Instance de struct Client
	ClientsEnAttente * pPrécédent_;  // Chaque noeud retient l'adresse de celui qui le précède
	ClientsEnAttente * pSuivant_;    // et de celui qui le suit
};

#endif
