////////////////////////////////////////////////////////////////////////////////
//								Source.cpp									  //
//				  Fait par Mélissa Boucher et Xavier Brosseau				  //
//							Créé le 29 octobre 2014							  //
//						Derniere modif 11 novembre 2014						  //
//																		      //
//			Menu utilisateur servant à tester les différentes fonctions		  //
//			de la file d'attente dans le cadre d'une utilisateur d'une		  //	 
//			file de clients et d'attribuation de table dans un restaurant.	  //
////////////////////////////////////////////////////////////////////////////////
#include "ClientsEnAttente.h"

// Constructeur Paramétrique
ClientsEnAttente::ClientsEnAttente(string nom, int nbPersonne, vector<Section> sections)
{
	SetPrécédent(nullptr);   // 0 indique qu'on ne connait pas l'adresse; équivaut à null
	SetSuivant(nullptr);
	clientsTable_.nomReservation = nom;
	clientsTable_.nombreDePersonnes = nbPersonne;
	clientsTable_.sectionChoisis = sections;
}

// Destructeur
ClientsEnAttente::~ClientsEnAttente()
{
	pPrécédent_ = 0;
	pSuivant_ = 0;
	delete pPrécédent_;
	delete pSuivant_;
}

// Mutateurs


void ClientsEnAttente::SetPrécédent(ClientsEnAttente * p)
{
	pPrécédent_ = p;
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

ClientsEnAttente * ClientsEnAttente::GetPrécédent() const
{
	return pPrécédent_;
}

ClientsEnAttente * ClientsEnAttente::GetSuivant() const
{
	return pSuivant_;
}

