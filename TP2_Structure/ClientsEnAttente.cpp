////////////////////////////////////////////////////////////////////////////////
//								ClientsEnAttente.cpp									  //
//				  Fait par M�lissa Boucher et Xavier Brosseau				  //
//							Cr�� le 29 octobre 2014							  //
//						Derniere modif 16 novembre 2014						  //
//																		      //
//				  //
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
   cout << " Mon client est d�truit " << endl; 
	//pPr�c�dent_ = 0;
	//pSuivant_ = 0;
	//delete pPr�c�dent_;
	//delete pSuivant_;
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

Client ClientsEnAttente::GetClient() const
{
   return clientsTable_;
}

bool ClientsEnAttente::ChoixSection(ClientsEnAttente c, Section s)
{
	bool present = false;
	for (unsigned int i = 0; i < c.GetClientSection().size(); i++)
	{
		if (c.GetClientSection().at(i) == s)
		{
			present = true;
		}
	}
	return present;
}