// D�finition d'un noeud. Essentiellement des
// mutateurs et accesseurs
//
// par Pierre Prud'homme, octobre 2014
//-------------------------------------------------
#include "ClientsEnAttente.h"

ClientsEnAttente::ClientsEnAttente(string nom, int nbPersonne, int section)
{
	SetPr�c�dent(nullptr);   // 0 indique qu'on ne connait pas l'adresse; �quivaut � null
	SetSuivant(nullptr);
	clientsTable.nomReservation = nom;
	clientsTable.nombreDePersonnes = nbPersonne;
	SetClientSection(section);
}

ClientsEnAttente::~ClientsEnAttente()
{
	pPr�c�dent_ = 0;
	pSuivant_ = 0;
	delete pPr�c�dent_;
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

void ClientsEnAttente::SetPr�c�dent(ClientsEnAttente * p)
{
	pPr�c�dent_ = p;
}

void ClientsEnAttente::SetSuivant(ClientsEnAttente *p)
{
	pSuivant_ = p;
}

vector<Section> ClientsEnAttente::GetClientSection()
{
	return clientsTable.sectionChoisis;
}

ClientsEnAttente * ClientsEnAttente::GetPr�c�dent() const
{
	return pPr�c�dent_;
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
