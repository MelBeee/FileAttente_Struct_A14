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
#include "ClientsEnAttente.h"

// Constructeur Param�trique
ClientsEnAttente::ClientsEnAttente(string nom, int nbPersonne, vector<Section> sections)
{
	SetPr�c�dent(nullptr);   // 0 indique qu'on ne connait pas l'adresse; �quivaut � null
	SetSuivant(nullptr);
	clientsTable_.nomReservation = nom;
	clientsTable_.nombreDePersonnes = nbPersonne;
	clientsTable_.sectionChoisis = sections;
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

