// D�finition d'un noeud. Essentiellement des
// mutateurs et accesseurs
//
// par Pierre Prud'homme, octobre 2014
//-------------------------------------------------
#include "ClientsEnAttente.h"

// Constructeur Param�trique
ClientsEnAttente::ClientsEnAttente(string nom, int nbPersonne, int section)
{
	SetPr�c�dent(nullptr);   // 0 indique qu'on ne connait pas l'adresse; �quivaut � null
	SetSuivant(nullptr);
	clientsTable_.nomReservation = nom;
	clientsTable_.nombreDePersonnes = nbPersonne;
	SetClientSection(section);
}

// Destructeur
ClientsEnAttente::~ClientsEnAttente()
{
	pPr�c�dent_ = 0;
	pSuivant_ = 0;
	delete pPr�c�dent_;
	delete pSuivant_;
}

// Mutateurs
void ClientsEnAttente::SetClientSection(int section)
{
	if (section >= 100)
	{
		clientsTable_.sectionChoisis.push_back(SalleManger);
		section -= 100;
	}
	if (section >= 10)
	{
		clientsTable_.sectionChoisis.push_back(TerrasseFumeur);
		section -= 10;
	}
	if (section >= 1)
	{
		clientsTable_.sectionChoisis.push_back(TerrasseNonFumeur);
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

void ClientsEnAttente::SetClient(Client c)
{
	clientsTable_.nomReservation = c.nomReservation;
	clientsTable_.nombreDePersonnes = c.nombreDePersonnes;
}

// Accesseurs

string ClientsEnAttente::GetNom() const
{
	return clientsTable_.nomReservation;
}

int ClientsEnAttente::GetNombrePersonne() const
{
	return clientsTable_.nombreDePersonnes;
}

vector<Section> ClientsEnAttente::GetClientSection() const
{
	return clientsTable_.sectionChoisis;
}

ClientsEnAttente * ClientsEnAttente::GetPr�c�dent() const
{
	return pPr�c�dent_;
}

ClientsEnAttente * ClientsEnAttente::GetSuivant() const
{
	return pSuivant_;
}

ClientsEnAttente::Client ClientsEnAttente::GetClient() const
{
	return clientsTable_;
}