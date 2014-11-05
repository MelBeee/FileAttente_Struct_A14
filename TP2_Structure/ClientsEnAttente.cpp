// Définition d'un noeud. Essentiellement des
// mutateurs et accesseurs
//
// par Pierre Prud'homme, octobre 2014
//-------------------------------------------------
#include "ClientsEnAttente.h"

ClientsEnAttente::ClientsEnAttente(string nom, int nbPersonne, int section)
{
	SetPrécédent(nullptr);   // 0 indique qu'on ne connait pas l'adresse; équivaut à null
	SetSuivant(nullptr);
	clientsTable.nomReservation = nom;
	clientsTable.nombreDePersonnes = nbPersonne;
	SetClientSection(section);
}

ClientsEnAttente::~ClientsEnAttente()
{
	pPrécédent_ = 0;
	pSuivant_ = 0;
	delete pPrécédent_;
	delete pSuivant_;
	
}

void ClientsEnAttente::SetClientSection(int section)
{
	if (section >= 100)
	{
		clientsTable.sectionChoisis.push_back(SalleManger);
		section -= 100;
	}
	if (section >= 10)
	{
		clientsTable.sectionChoisis.push_back(TerrasseFumeur);
		section -= 10;
	}
	if (section >= 1)
	{
		clientsTable.sectionChoisis.push_back(TerrasseNonFumeur);
		section -= 1;
	}
}

void ClientsEnAttente::SetPrécédent(ClientsEnAttente * p)
{
	pPrécédent_ = p;
}

void ClientsEnAttente::SetSuivant(ClientsEnAttente *p)
{
	pSuivant_ = p;
}

vector<Section> ClientsEnAttente::GetClientSection()
{
	return clientsTable.sectionChoisis;
}

ClientsEnAttente * ClientsEnAttente::GetPrécédent() const
{
	return pPrécédent_;
}

ClientsEnAttente * ClientsEnAttente::GetSuivant() const
{
	return pSuivant_;
}

ClientsEnAttente::Client ClientsEnAttente::GetClient()
{
	return clientsTable;
}

void ClientsEnAttente::SetClient(Client c)
{
	clientsTable.nomReservation = c.nomReservation;
	clientsTable.nombreDePersonnes = c.nombreDePersonnes;
}
