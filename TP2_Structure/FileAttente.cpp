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
#include "FileAttente.h"

void FileAttente::SetDernier(ClientsEnAttente * p)
{
   pDernier_ = p;
}

ClientsEnAttente* FileAttente::GetDernier() const
{
   return pDernier_;
}

void FileAttente::SetNbGroupes(int nb)
{
   nbGroupes_ = nb;
}

void FileAttente::SetNbPersonnes(int nb)
{
   nbPersonne_ = nb;
}

void FileAttente::SetNbGroupesTotal(int nb)
{
   nbGroupesTotal_ = nb;
}

void FileAttente::SetNbPersonnesTotal(int nb)
{
   nbPersonnesTotal_ = nb;
}

void FileAttente::SetPremier(ClientsEnAttente * p)
{
   pPremier_ = p;
}

ClientsEnAttente* FileAttente::GetPremier() const
{
   return pPremier_;
}

FileAttente::FileAttente()
{
   SetNbGroupes(0);  // il n'y a pas d'éléments dans la liste
   SetNbPersonnes(0);
   SetPremier(0);     // on pointe sur rien
   SetDernier(0);
}

FileAttente::~FileAttente()
{
   pPremier_ = 0;
   pDernier_ = 0;
   delete pPremier_;
   delete pDernier_;
}
// retourne le nombre d'éléments de la liste
int FileAttente::ObtenirNbGroupes() const
{
   return nbGroupes_;
}

int FileAttente::ObtenirNbPersonnes() const
{
   return nbPersonne_;
}

int FileAttente::ObtenirNbPersonnesTotal() const
{
   return nbPersonnesTotal_;
}

int FileAttente::ObtenirNbGroupesTotal() const
{
   return nbGroupesTotal_;
}

void FileAttente::Afficher(ostream & out) const
{
   ClientsEnAttente * pTemporaire = GetPremier();

   while (pTemporaire != 0)
   {
      vector<Section> tempo = pTemporaire->GetClientSection();

      out << "Nom de la Réservation : " << pTemporaire->GetNom() << endl
         << "Nb de personnes : " << pTemporaire->GetNombrePersonne() << endl
         << "Sections désirées : ";
      for (unsigned int i = 0; i < tempo.size(); i++)
      {
         cout << AfficherSection(tempo[i]) << ", ";
      }
      cout << endl << endl;
      pTemporaire = pTemporaire->GetSuivant();
   }
   out << "Il y a " << ObtenirNbGroupes() << " groupes dans la liste" << endl
      << "Il y a " << ObtenirNbPersonnes() << " personnes en file " << endl;
}
void FileAttente::Ajouter(Client clientAMettreEnFile)
{

   ClientsEnAttente * pNouveau = new ClientsEnAttente(clientAMettreEnFile.nomReservation,
      clientAMettreEnFile.nombreDePersonnes,
      clientAMettreEnFile.sectionChoisis);

   if (EstVide())
   {
      SetPremier(pNouveau);
      SetDernier(pNouveau);  // ajouté quand on a un pointe
   }
   else
   {
      pNouveau->SetPrécédent(GetDernier());
      GetDernier()->SetSuivant(pNouveau);
      SetDernier(pNouveau);
   }
   SetNbGroupes(ObtenirNbGroupes() + 1);
   SetNbGroupesTotal(ObtenirNbGroupes());

   SetNbPersonnes(ObtenirNbPersonnes() + clientAMettreEnFile.nombreDePersonnes);
   SetNbPersonnesTotal(ObtenirNbPersonnes());
}

bool FileAttente::Retirer(string nomClient, int nbPersonnes)
{
   ClientsEnAttente * pTemporaire = GetPremier();
   bool existe = false;

   if (VérifierSiPrésent(nomClient, nbPersonnes))
   {
      while (pTemporaire != 0 && !existe)
      {
         if (pTemporaire != 0 && EstLeMemeNom(pTemporaire, nomClient, nbPersonnes))
            existe = true;

         else
            pTemporaire = pTemporaire->GetSuivant();
      }
      if (existe)
      {
         if (pTemporaire->GetPrécédent() != 0) //si le pTempo n'est pas le 1er
         {
            if (pTemporaire->GetSuivant() != 0) //si le pTempo n'est pas le dernier
            {
               pTemporaire->GetSuivant()->SetPrécédent(pTemporaire->GetPrécédent());
               pTemporaire->GetPrécédent()->SetSuivant(pTemporaire->GetSuivant());
            }
            else
            {
               SetDernier(pTemporaire->GetPrécédent()); //si le pTempo est le dernier
               pTemporaire->GetPrécédent()->SetSuivant(0);
            }
         }
         else //si le pTempo est le premier de la file	
         {
            if (pTemporaire->GetSuivant() != 0)
            {
               SetPremier(pTemporaire->GetSuivant());
               pTemporaire->GetSuivant()->SetPrécédent(0);
            }
            else
            {
               SetPremier(0);
               SetDernier(0);
            }
         }


         SetNbPersonnes(ObtenirNbPersonnes() - pTemporaire->GetNombrePersonne());
         SetNbGroupes(ObtenirNbGroupes() - 1);
         delete pTemporaire;
      }
   }
   return existe;
}

string FileAttente::GetClient(int indice) const
{
   ClientsEnAttente * pBalayage = GetPremier();
   int compteur = 0;
   while (compteur != indice)
   {
      pBalayage = pBalayage->GetSuivant(); 
      compteur++; 
   }

   string nom = "Nom de la réservation : " + pBalayage->GetNom() ; 
   string nombre = "\n Nombre de personne : " + pBalayage->GetNombrePersonne();
   string section = "\n Sections possibles : | ";
   for (unsigned int i = 0; i < pBalayage->GetClientSection().size(); i++)
   {
	   section += pBalayage->GetClientSection()[i] + " | ";
   }

   nom = nom + nombre + section + "\n \n"; 

   return nom;
}

bool FileAttente::EstVide() const
{
   return GetPremier() == 0;
}

bool FileAttente::VérifierSiPrésent(string nom, int nbPersonnes) const
{
   ClientsEnAttente * pBalayage = GetPremier();

   while (pBalayage != nullptr && !EstLeMemeNom(pBalayage, nom, nbPersonnes))
   {
      pBalayage = pBalayage->GetSuivant();
   }

   return pBalayage != nullptr;
}

bool FileAttente::EstLeMemeNom(ClientsEnAttente * p, string nom, int nbPersonnes) const
{
   return (MettreEnMajuscules(p->GetNom()) == MettreEnMajuscules(nom) && p->GetNombrePersonne() == nbPersonnes);
}

string FileAttente::MettreEnMajuscules(string nom) const
{
   for (unsigned int i = 0; i < nom.size(); ++i)
   {
      nom[i] = toupper(nom[i]);
   }
   return nom;
}

int FileAttente::DonnerLeRang(string nom, int nbPersonnes) const
{
   ClientsEnAttente * pBalayage = GetPremier();
   //int rang = 1; 
   int rang = 0;

   while (pBalayage != nullptr && !EstLeMemeNom(pBalayage, nom, nbPersonnes))
   {
      pBalayage = pBalayage->GetSuivant();
      rang++;
   }

   //if (pBalayage == nullptr)
   //{
   //	rang = 0;
   //}

   return rang;
}

void FileAttente::PasserDevantToutLeMonde()
{
   if (ObtenirNbGroupes() > 1)
   {
      ClientsEnAttente * pTricheur = GetDernier();
      // modifier la file pour 'enlever' le dernier
      SetDernier(GetDernier()->GetPrécédent());
      GetDernier()->SetSuivant(nullptr);

      GetPremier()->SetPrécédent(pTricheur);
      pTricheur->SetSuivant(GetPremier());
      pTricheur->SetPrécédent(nullptr);
      SetPremier(pTricheur);
   }
}

string FileAttente::AfficherSection(int i) const
{
   if (i == TerrasseNonFumeur)
   {
      return "TerrasseNonFumeur";
   }
   else if (i == TerrasseFumeur)
   {
      return "TerrasseFumeur";
   }
   else
   {
      return "SalleManger";
   }
}

void FileAttente::Retirer(int nbPlacesDeLaTable, Section sectionDeLaTable)
{
   ClientsEnAttente * pBalayage = GetPremier();
   bool trouver = false;          

   if (pBalayage == nullptr)
   {
      throw exception("La liste est vide");
   }
   else
   {
      for (int i = nbPlacesDeLaTable; i > 0 && !trouver; i--)
      {
         while (pBalayage != nullptr && pBalayage->GetNombrePersonne() != i && !pBalayage->ChoixSection(*pBalayage, sectionDeLaTable)) // && pBalayage->GetSection() !=sectiondelatable   ([1] != || [2] != || [3] !=  )
         {
            pBalayage = pBalayage->GetSuivant(); 
         }

         if (pBalayage->GetNombrePersonne() == i && pBalayage->ChoixSection(*pBalayage, sectionDeLaTable))
         {
            trouver = true;
         }
            // if(pBalayage->GetClientSection != section)
      }

      if (!trouver)
      {
         throw exception("Pas de groupe correspondant aux demandes");
      }
      else
      {      
         cout << " Bonne appetit " << pBalayage->GetNom() << endl; 
         Retirer(pBalayage->GetNom(), pBalayage->GetNombrePersonne());
      }
   }
  /* return pBalayage->GetClient();*/
}

