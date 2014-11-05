// Implantation d'une liste de noeuds
//
// par Pierre Prud'homme, octobre 2014
//-------------------------------------------------
#include "liste.h"

void Liste::SetDernier(Noeud * p)
{
   pDernier_ = p;
}

Noeud* Liste::GetDernier() const
{
   return pDernier_;
}

void Liste::SetNbElements(int nb)
{
   nbElements_ = nb;
}

void Liste::SetPremier(Noeud * p)
{
   pPremier_ = p;
}

Noeud* Liste::GetPremier() const
{
   return pPremier_;
}

bool Liste::EstVide() const
{
   return GetPremier() == 0;
}

Liste::Liste()
{
   SetNbElements(0);  // il n'y a pas d'�l�ments dans la liste
   SetPremier(0);     // on pointe sur rien
   SetDernier(0);
}

void Liste::AjouterEnFinDeListe(string nom)
{
   Noeud * pNouveau = new Noeud(nom);

   if (EstVide())
   {
      SetPremier(pNouveau);
      SetDernier(pNouveau);  // ajout� quand on a un pointe
   }
   else
   {
      // Trouver l'adresse du dernier noeud de la liste
      //Noeud * pTemporaire = GetPremier();
      //while (pTemporaire->GetSuivant() != 0)
      //{
      //   pTemporaire = pTemporaire->GetSuivant();
      //}

      //// tout va bien, on a l'adresse du dernier de la liste
      //// dans pTemporaire
      //pNouveau->SetPr�c�dent(pTemporaire);
      //pTemporaire->SetSuivant(pNouveau);

      pNouveau->SetPr�c�dent(GetDernier());
      GetDernier()->SetSuivant(pNouveau);
      SetDernier(pNouveau);
   }
   SetNbElements(GetNbElements() + 1);
}

string Liste::RetirerDeLaListe()
{
   Noeud * pTemporaire = GetPremier();
   string nom;

   if (pTemporaire == 0)   // if (!pTemporaire)
      throw exception("...La liste est vide...");

   nom = pTemporaire->GetNom();
   SetPremier(GetPremier()->GetSuivant());
   if (GetPremier() != 0)
   {
      GetPremier()->SetPr�c�dent(0);
   }
   else
   {
      SetDernier(0);
   }
   //--- le delete est CRUCIAL comme nous l'avons vu en fin de cours
   delete pTemporaire;  // retourne au syst�me l'espace r�serv�
   SetNbElements(GetNbElements() - 1);

   return nom;
}

// retourne le nombre d'�l�ments de la liste
int Liste::GetNbElements() const
{
   return nbElements_;
}

void Liste::Afficher(ostream & out) const
{
   Noeud * pTemporaire = GetPremier();

   while (pTemporaire != 0)
   {
      out << pTemporaire->GetNom() << endl;
      pTemporaire = pTemporaire->GetSuivant();
   }
   out << "Il y a " << GetNbElements() << " elements dans la liste"
      << endl << endl;
}

string Liste::MettreEnMajuscules(string nom) const
{
   for (int i = 0; i < nom.size(); ++i)
   {
      nom[i] = toupper(nom[i]);
   }
   return nom;
}

bool Liste::EstLeMemeNom(Noeud * p, string nom) const
{
   return MettreEnMajuscules(p->GetNom()) == MettreEnMajuscules(nom);
}

//--- M�thode qui v�rifie si un nom est dans la liste
bool   Liste::V�rifierSiPr�sent(string nom) const
{
   Noeud * pBalayage = GetPremier();

   while (pBalayage != nullptr && !EstLeMemeNom(pBalayage, nom))
   {
      pBalayage = pBalayage->GetSuivant();
   }

   return pBalayage != nullptr;
}

int Liste::DonnerLeRang(string nom) const
{
   Noeud * pBalayage = GetPremier();
   int rang = 1;

   while (pBalayage != nullptr && !EstLeMemeNom(pBalayage, nom))
   {
      pBalayage = pBalayage->GetSuivant();
      rang++;
   }

   if (pBalayage == nullptr)
   {
      rang = 0;
   }

   return rang;
}

void  Liste::PasserDevantToutLeMonde()
{
   if (GetNbElements() > 1)
   {
      Noeud * pTricheur = GetDernier();
      // modifier la file pour 'enlever' le dernier
      SetDernier(GetDernier()->GetPr�c�dent());
      GetDernier()->SetSuivant(nullptr);

      GetPremier()->SetPr�c�dent(pTricheur);
      pTricheur->SetSuivant(GetPremier());
      pTricheur->SetPr�c�dent(nullptr);
      SetPremier(pTricheur);
   }
}


