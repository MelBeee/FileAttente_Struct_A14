// Déclaration du noeud du client
//
// par Pierre Prud'homme, octobre 2014
//-------------------------------------------------
#ifndef _CLIENTSENATTENTE_H_
#define _CLIENTSENATTENTE_H_
#include <string>
#include <vector>
using namespace std;

struct Client
{
	string nomReservation;
	int nombreDePersonnes;
	vector<Section> sectionChoisis;
};

enum Section
{
	TerrasseNonFumeur = 1, TerrasseFumeur = 10, SalleManger = 100
};

class ClientsEnAttente
{
	Client clientsTable_;
	ClientsEnAttente * pPrécédent_;  // Chaque noeud retient l'adresse de celui qui le précède
	ClientsEnAttente * pSuivant_;    // et de celui qui le suit

public:
	//--- Constructeurs


	ClientsEnAttente(string nom, int nbPersonne, vector<Section> sections);
	~ClientsEnAttente();

	void SetPrécédent(ClientsEnAttente * p);
	void SetSuivant(ClientsEnAttente *p);
	void SetClient(Client c);
	void SetClientSection(int section);


	ClientsEnAttente * GetPrécédent() const;
	ClientsEnAttente * GetSuivant() const;
	Client GetClient() const;
	string GetNom() const; 
	int GetNombrePersonne() const;	
	vector<Section> GetClientSection() const;
};

#endif
