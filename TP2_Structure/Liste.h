// On va d�velopper une liste de noeuds
//
// par Pierre Prud'homme, octobre 2014
//-------------------------------------------------
#ifndef _LISTE_H_
#define _LISTE_H_
#include "ClientsEnAttente.h"
#include <iostream>
using namespace std;

class Liste
{
   ClientsEnAttente * pPremier_;  // Premier de la liste
   ClientsEnAttente * pDernier_;  // Dernier de la liste
   int     nbElements_;// Nombre de noeuds dans la liste

   void    SetPremier(ClientsEnAttente * p);
   ClientsEnAttente*  GetPremier() const;

   void    SetDernier(ClientsEnAttente * p);
   ClientsEnAttente*  GetDernier() const;

   void    SetNbElements(int nb);
   bool    EstVide() const;

   bool    EstLeMemeNom(ClientsEnAttente * p, string nom) const;
   string  MettreEnMajuscules(string nom) const;

public:
   //--- Constructeur par d�faut
   Liste();

   //--- La liste peut s'afficher elle-m�me
   void   Afficher(ostream &) const;

   //--- et retourner le nombre d'�l�ments qu'elle contient
   int    GetNbElements() const;

   //--- on peut ajouter en fin de liste et retirer au d�but de la liste
   void   AjouterEnFinDeListe(string nom);
   string RetirerDeLaListe();

   //--- M�thode qui v�rifie si un nom est dans la liste
   bool   V�rifierSiPr�sent(string nom) const;

   //--- M�thode qui retourne un entier correspondant au rang dans la liste
   //    0 signifie absent. 
   int    DonnerLeRang(string nom) const;

   //--- De faire passer le dernier en premier dans la liste
   void  PasserDevantToutLeMonde();
};
#endif