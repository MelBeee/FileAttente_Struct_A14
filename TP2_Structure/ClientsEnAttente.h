////////////////////////////////////////////////////////////////////////////////
//								      ClientsEnAttente.h								      //
//				      Fait par Mélissa Boucher et Xavier Brosseau				      //
//							      Créé le 29 octobre 2014							         //
//						      Derniere modif 16 novembre 2014						      //
//																		                        //
//			Déclaration de la classe ClientsEnAttente qui permet de créer        //
//       des clients a ajouter dans la file d'attente. Structure Client       //
////////////////////////////////////////////////////////////////////////////////
#ifndef _CLIENTSENATTENTE_H_
#define _CLIENTSENATTENTE_H_
#pragma warning (disable:4227)
#include <string>
#include <iostream>
#include <vector>
using namespace std;
////////////////////////////////////////////////////////////////////////////////
//								      enum Section					                     //
//		      enumeration pour les choix de sections que l'utilisateur a        //
////////////////////////////////////////////////////////////////////////////////
enum Section
{
	TerrasseNonFumeur = 1, TerrasseFumeur = 10, SalleManger = 100
};

////////////////////////////////////////////////////////////////////////////////
//								      enum Section					                     //
//		      enumeration pour les choix de sections que l'utilisateur a        //
////////////////////////////////////////////////////////////////////////////////
struct Client
{
	string nomReservation;
	int nombreDePersonnes;
	vector<Section> sectionChoisis;
};

////////////////////////////////////////////////////////////////////////////////
//								MenuFaireChoix()							                  //
//		Intrant : Aucun		Extrant : Int (Choix fait par l'utilisateur		   //
//	   Fonction qui permet a l'utilisateur de faire un choix dans le menu	   //
////////////////////////////////////////////////////////////////////////////////
class ClientsEnAttente
{
	Client clientsTable_;
	ClientsEnAttente * pPrécédent_;  // Chaque noeud retient l'adresse de celui qui le précède
	ClientsEnAttente * pSuivant_;    // et de celui qui le suit

public:
	//--- Constructeur
	ClientsEnAttente(string nom, int nbPersonne, vector<Section> sections);

	void SetPrécédent(ClientsEnAttente * p);
	void SetSuivant(ClientsEnAttente *p);
	void SetClient(Client c);

	ClientsEnAttente * GetPrécédent() const;
	ClientsEnAttente * GetSuivant() const;
	string GetNom() const;
	int GetNombrePersonne() const;
	vector<Section> GetClientSection() const;
   Client GetClient() const;
	
	bool ChoixSection(ClientsEnAttente c, Section s);
};

#endif
