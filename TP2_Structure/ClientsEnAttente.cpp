////////////////////////////////////////////////////////////////////////////////
//									ClientsEnAttente.cpp											//
//					 Fait par Mélissa Boucher et Xavier Brosseau							//
//			Créé le 29 octobre 2014,	Derniere modif 16 novembre 2014			   //
//			Définition des fonctions/méthodes de la classe ClientsEnAttente		//
//				Qui nous permettent de construire une instance de class ou			//
//			d'acceder aux informations/changer les informations d'un Client		//
////////////////////////////////////////////////////////////////////////////////
#include "ClientsEnAttente.h"
////////////////////////////////////////////////////////////////////////////////
ClientsEnAttente::ClientsEnAttente(string nom, int nbPersonne, vector<Section> sections)
{
	SetPrécédent(nullptr);  
	SetSuivant(nullptr);
	clientsTable_.nomReservation = nom;
	clientsTable_.nombreDePersonnes = nbPersonne;
	clientsTable_.sectionChoisis = sections;
}
////////////////////////////////////////////////////////////////////////////////
void ClientsEnAttente::SetPrécédent(ClientsEnAttente * p)
{
	pPrécédent_ = p;
}
////////////////////////////////////////////////////////////////////////////////
void ClientsEnAttente::SetSuivant(ClientsEnAttente *p)
{
	pSuivant_ = p;
}
////////////////////////////////////////////////////////////////////////////////
void ClientsEnAttente::SetClient(Client c)
{
	clientsTable_.nomReservation = c.nomReservation;
	clientsTable_.nombreDePersonnes = c.nombreDePersonnes;
	clientsTable_.sectionChoisis = c.sectionChoisis;
}
////////////////////////////////////////////////////////////////////////////////
string ClientsEnAttente::GetNom() const
{
	return clientsTable_.nomReservation;
}
////////////////////////////////////////////////////////////////////////////////
int ClientsEnAttente::GetNombrePersonne() const
{
	return clientsTable_.nombreDePersonnes;
}
////////////////////////////////////////////////////////////////////////////////
vector<Section> ClientsEnAttente::GetClientSection() const
{
	return clientsTable_.sectionChoisis;
}
////////////////////////////////////////////////////////////////////////////////
ClientsEnAttente * ClientsEnAttente::GetPrécédent() const
{
	return pPrécédent_;
}
////////////////////////////////////////////////////////////////////////////////
ClientsEnAttente * ClientsEnAttente::GetSuivant() const
{
	return pSuivant_;
}
////////////////////////////////////////////////////////////////////////////////
ClientsEnAttente::Client ClientsEnAttente::GetClient() const
{
	return clientsTable_;
}
////////////////////////////////////////////////////////////////////////////////
bool ClientsEnAttente::ChoixSection(ClientsEnAttente c, Section s)
{
	bool present = false;
	for (unsigned int i = 0; i < c.GetClientSection().size(); i++)
	{
		if (c.GetClientSection().at(i) == s) // Si la section passé en parametre est dans le vector du client
		{
			present = true; // On met a true
		}
	}
	return present;
}