// D�finition d'un noeud. Essentiellement des
// mutateurs et accesseurs
//
// par Pierre Prud'homme, octobre 2014
//-------------------------------------------------
#include "Noeud.h"

ClientsEnAttente::ClientsEnAttente()
{
   SetPr�c�dent(0);   // 0 indique qu'on ne connait pas l'adresse; �quivaut � null
   SetSuivant(0);
}

ClientsEnAttente::ClientsEnAttente(string nom)
{
   SetPr�c�dent(nullptr);   // 0 indique qu'on ne connait pas l'adresse; �quivaut � null
   SetSuivant(nullptr);
}

void ClientsEnAttente::SetPr�c�dent(ClientsEnAttente * p)
{
   pPr�c�dent_ = p;
}

void ClientsEnAttente::SetSuivant(ClientsEnAttente *p)
{
   pSuivant_ = p;
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
