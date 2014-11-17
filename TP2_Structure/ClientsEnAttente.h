////////////////////////////////////////////////////////////////////////////////
//								      ClientsEnAttente.h								      //
//				      Fait par M�lissa Boucher et Xavier Brosseau				      //
//			Cr�� le 29 octobre 2014,	Derniere modif 16 novembre 2014			   //
//			D�claration de la classe ClientsEnAttente qui permet de cr�er        //
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
	// Permet de cr�er un ClientsEnAttente avec des valeurs demand�es
	ClientsEnAttente(string nom, int nbPersonne, vector<Section> sections);
	//	Intrants: un pointeur sur un Client Extrants: Aucun
	//	Permet d'initialis� le Client pr�c�dant a notre instance de client
	void SetPr�c�dent(ClientsEnAttente * p);
	//	Intrants: un pointeur sur un Client Extrants: Aucun
	//	Permet d'initialis� le Client suivant a notre instance de client
	void SetSuivant(ClientsEnAttente *p);
	// Intrants: un Client Extrants: Aucun
	//	Permet de "setter" les valeurs d'un client
	void SetClient(Client c);
	//	Intrants: Aucun Extrants: un pointeur sur un Client
	//	Permet d'obtenir le pointeur sur le client pr�c�dent celui demand�
	ClientsEnAttente * GetPr�c�dent() const;
	//	Intrants: Aucun Extrants: un pointeur sur un Client
	//	Permet d'obtenir le pointeur sur le client suivant celui demand�
	ClientsEnAttente * GetSuivant() const;
	//	Intrants: Aucun Extrants: string du nom du client
	//	Permet d'obtenir le nom du client
	string GetNom() const;
	// Intrants: Aucun Extrants: int du nombre de personne
	//	Permet d'obtenir le nombre de personne	
	int GetNombrePersonne() const;
	//	Intrants: Aucun Extrants: vector des sections demand�es
	//	Permet d'obtenir les sections que le client a demand�es
	vector<Section> GetClientSection() const;
	//	Intrants: Aucun Extrants: Client
	//	Permet d'obtenir un client
	Client GetClient() const;
	//	Intrants: Client, et une section Extrant : bool Pr�sent
	//	Permet de parcourir le vector de section du client pour compar� avec la section demand�. Si la section y est pr�sente, retourne vrai sinon, faux
	bool ChoixSection(ClientsEnAttente c, Section s);

private:
	Client clientsTable_;				// Instance de struct Client
	ClientsEnAttente * pPr�c�dent_;  // Chaque noeud retient l'adresse de celui qui le pr�c�de
	ClientsEnAttente * pSuivant_;    // et de celui qui le suit
};

#endif
