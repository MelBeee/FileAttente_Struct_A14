// Déclaration du noeud du client
//
// par Pierre Prud'homme, octobre 2014
//-------------------------------------------------
#ifndef _CLIENTSENATTENTE_H_
#define _CLIENTSENATTENTE_H_
#include <string>
#include <vector>
using namespace std;


enum Section
{
	TerrasseNonFumeur = 1, TerrasseFumeur = 10, SalleManger = 100
};

class ClientsEnAttente
{
	struct Client
	{
		string nomReservation;
		int nombreDePersonnes;
		vector<Section> sectionChoisis;
	};

	Client clientsTable;
	ClientsEnAttente * pPrécédent_;  // Chaque noeud retient l'adresse de celui qui le précède
	ClientsEnAttente * pSuivant_;    // et de celui qui le suit

public:
	//--- Constructeurs

	ClientsEnAttente(string nom, int nbPersonne, int section);
	~ClientsEnAttente();

	void SetPrécédent(ClientsEnAttente * p);
	void SetSuivant(ClientsEnAttente *p);
	void SetClient(Client c);
	void SetClientSection(int section);

	vector<Section> GetClientSection();
	ClientsEnAttente * GetPrécédent() const;
	ClientsEnAttente * GetSuivant() const;
	Client GetClient();
};

#endif
