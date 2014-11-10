// D�claration du noeud du client
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
	TerrasseNonFumeur  = 1, TerrasseFumeur = 10, SalleManger = 100
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
};

#endif
