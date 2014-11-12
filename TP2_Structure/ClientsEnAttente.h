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
#ifndef _CLIENTSENATTENTE_H_
#define _CLIENTSENATTENTE_H_
#include <string>
#include <vector>
using namespace std;

enum Section
{
	TerrasseNonFumeur = 1, TerrasseFumeur = 10, SalleManger = 100
};

struct Client
{
	string nomReservation;
	int nombreDePersonnes;
	vector<Section> sectionChoisis;
};

class ClientsEnAttente
{
	Client clientsTable_;
	ClientsEnAttente * pPr�c�dent_;  // Chaque noeud retient l'adresse de celui qui le pr�c�de
	ClientsEnAttente * pSuivant_;    // et de celui qui le suit

public:
	//--- Constructeurs


	ClientsEnAttente(string nom, int nbPersonne, vector<Section> sections);
	~ClientsEnAttente();

	void SetPr�c�dent(ClientsEnAttente * p);
	void SetSuivant(ClientsEnAttente *p);
	void SetClient(Client c);

	ClientsEnAttente * GetPr�c�dent() const;
	ClientsEnAttente * GetSuivant() const;
	string GetNom() const;
	int GetNombrePersonne() const;
	vector<Section> GetClientSection() const;
	
	bool ChoixSection(ClientsEnAttente c, Section s);
};

#endif
