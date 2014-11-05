// Définition d'un noeud. Essentiellement des
// mutateurs et accesseurs
//
// par Pierre Prud'homme, octobre 2014
//-------------------------------------------------
#include "Noeud.h"

ClientsEnAttente::ClientsEnAttente()
{
   SetPrécédent(0);   // 0 indique qu'on ne connait pas l'adresse; équivaut à null
   SetSuivant(0);
}

ClientsEnAttente::ClientsEnAttente(string nom)
{
   SetPrécédent(nullptr);   // 0 indique qu'on ne connait pas l'adresse; équivaut à null
   SetSuivant(nullptr);
}

void ClientsEnAttente::SetPrécédent(ClientsEnAttente * p)
{
   pPrécédent_ = p;
}

void ClientsEnAttente::SetSuivant(ClientsEnAttente *p)
{
   pSuivant_ = p;
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
