////////////////////////////////////////////////////////////////////////////////
//								ClientsEnAttente.cpp									  //
//				  Fait par M�lissa Boucher et Xavier Brosseau				  //
//							Cr�� le 29 octobre 2014							  //
//						Derniere modif 16 novembre 2014						  //
//																		      //
//				  //
////////////////////////////////////////////////////////////////////////////////
#include "ClientsEnAttente.h"


							//--- CONSTRUCTEURS ---\\

////////////////////////////////////////////////////////////////////////////////
//								  Param�trique								  //
////////////////////////////////////////////////////////////////////////////////
ClientsEnAttente::ClientsEnAttente(string nom, int nbPersonne, vector<Section> sections)
{
	SetPr�c�dent(nullptr);  
	SetSuivant(nullptr);
	clientsTable_.nomReservation = nom;
	clientsTable_.nombreDePersonnes = nbPersonne;
	clientsTable_.sectionChoisis = sections;
}
////////////////////////////////////////////////////////////////////////////////
//								  Par D�faut								  //
////////////////////////////////////////////////////////////////////////////////
ClientsEnAttente::ClientsEnAttente()
{
	vector<Section> vect; 
	SetPr�c�dent(nullptr);
	SetSuivant(nullptr);
	clients_Table_.nomReservation = "";
	clients_Table.nombreDePersonnes = 0;
	clients_Table.sectionChoisis = vect;
}

							//--- MUTATEURS ---\\

////////////////////////////////////////////////////////////////////////////////
//								  SetPr�c�dent								  //
////////////////////////////////////////////////////////////////////////////////
void ClientsEnAttente::SetPr�c�dent(ClientsEnAttente * p)
{
	pPr�c�dent_ = p;
}
////////////////////////////////////////////////////////////////////////////////
//								  SetSuivant								  //
////////////////////////////////////////////////////////////////////////////////
void ClientsEnAttente::SetSuivant(ClientsEnAttente *p)
{
	pSuivant_ = p;
}
////////////////////////////////////////////////////////////////////////////////
//								  SetClient									  //
////////////////////////////////////////////////////////////////////////////////
void ClientsEnAttente::SetClient(Client c)
{
	clientsTable_.nomReservation = c.nomReservation;
	clientsTable_.nombreDePersonnes = c.nombreDePersonnes;
	clientsTable_.sectionChoisis = c.sectionChoisis;
}

							//--- Accesseurs ---\\

////////////////////////////////////////////////////////////////////////////////
//								  GetNom									  //
////////////////////////////////////////////////////////////////////////////////
string ClientsEnAttente::GetNom() const
{
	return clientsTable_.nomReservation;
}
////////////////////////////////////////////////////////////////////////////////
//							GetNombrePersonne								  //
////////////////////////////////////////////////////////////////////////////////
int ClientsEnAttente::GetNombrePersonne() const
{
	return clientsTable_.nombreDePersonnes;
}
////////////////////////////////////////////////////////////////////////////////
//							GetclientSection								  //
////////////////////////////////////////////////////////////////////////////////
vector<Section> ClientsEnAttente::GetClientSection() const
{
	return clientsTable_.sectionChoisis;
}
////////////////////////////////////////////////////////////////////////////////
//								  GetPr�c�dent								  //
////////////////////////////////////////////////////////////////////////////////
ClientsEnAttente * ClientsEnAttente::GetPr�c�dent() const
{
	return pPr�c�dent_;
}
////////////////////////////////////////////////////////////////////////////////
//								  GetSuivant								  //
////////////////////////////////////////////////////////////////////////////////
ClientsEnAttente * ClientsEnAttente::GetSuivant() const
{
	return pSuivant_;
}
////////////////////////////////////////////////////////////////////////////////
//								  GetClient									  //
////////////////////////////////////////////////////////////////////////////////
Client ClientsEnAttente::GetClient() const
{
   return clientsTable_;
}
////////////////////////////////////////////////////////////////////////////////
//							  ChoixSection									  //
////////////////////////////////////////////////////////////////////////////////
bool ClientsEnAttente::ChoixSection(ClientsEnAttente c, Section s)
{
	bool present = false;
	for (unsigned int i = 0; i < c.GetClientSection().size(); i++)
	{
		if (c.GetClientSection().at(i) == s) // Si la section pass� en parametre est dans le vector du client
		{
			present = true; // On met a true
		}
	}
	return present;
}