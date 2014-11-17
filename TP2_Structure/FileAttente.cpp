////////////////////////////////////////////////////////////////////////////////
//								FileAttente.cpp													//
//				  Fait par Mélissa Boucher et Xavier Brosseau							//
//			Créé le 29 octobre 2014,	Derniere modif 16 novembre 2014			   //
//			Définition de la classe FileAttente qui stock le 1er et dernier		//
//			clients en attente. Les méthodes utilisés sont fait pour modififer	//
//			la file et afficher la file.														//
////////////////////////////////////////////////////////////////////////////////
#include "FileAttente.h"
////////////////////////////////////////////////////////////////////////////////
void FileAttente::SetDernier(ClientsEnAttente * p)
{
	pDernier_ = p;
}
////////////////////////////////////////////////////////////////////////////////
ClientsEnAttente* FileAttente::GetDernier() const
{
	return pDernier_;
}
////////////////////////////////////////////////////////////////////////////////
void FileAttente::SetNbGroupes(int nb)
{
	nbGroupes_ = nb;
}
////////////////////////////////////////////////////////////////////////////////
void FileAttente::SetNbPersonnes(int nb)
{
	nbPersonne_ = nb;
}
////////////////////////////////////////////////////////////////////////////////
void FileAttente::SetNbGroupesTotal(int nb)
{
	nbGroupesTotal_ = nb;
}
////////////////////////////////////////////////////////////////////////////////
void FileAttente::SetNbPersonnesTotal(int nb)
{
	nbPersonnesTotal_ = nb;
}
////////////////////////////////////////////////////////////////////////////////
void FileAttente::SetPremier(ClientsEnAttente * p)
{
	pPremier_ = p;
}
////////////////////////////////////////////////////////////////////////////////
ClientsEnAttente* FileAttente::GetPremier() const
{
	return pPremier_;
}
////////////////////////////////////////////////////////////////////////////////
FileAttente::FileAttente()
{
	SetNbGroupes(0);  // il n'y a pas d'éléments dans la liste
	SetNbPersonnes(0);
	SetNbGroupesTotal(0);
	SetNbPersonnesTotal(0);
	SetPremier(nullptr);     // on pointe sur rien
	SetDernier(nullptr);
}
////////////////////////////////////////////////////////////////////////////////
int FileAttente::ObtenirNbGroupes() const
{
	return nbGroupes_;
}
////////////////////////////////////////////////////////////////////////////////
int FileAttente::ObtenirNbPersonnes() const
{
	return nbPersonne_;
}
////////////////////////////////////////////////////////////////////////////////
int FileAttente::ObtenirNbPersonnesTotal() const
{
	return nbPersonnesTotal_;
}
////////////////////////////////////////////////////////////////////////////////
int FileAttente::ObtenirNbGroupesTotal() const
{
	return nbGroupesTotal_;
}
////////////////////////////////////////////////////////////////////////////////
void FileAttente::Afficher(ostream & out) const
{
	ClientsEnAttente * pTemporaire = GetPremier();
	int indice = 1;

	if (pTemporaire == nullptr)
		throw exception(" La file d'attente est vide ");

	while (pTemporaire != 0) // tant qu'on arrive pas a un pointeur null
	{
		cout << GetClient(indice) << endl;  // on affiche un client
		indice++; 
		pTemporaire = pTemporaire->GetSuivant(); // on affecte au client suivant
	}
}
////////////////////////////////////////////////////////////////////////////////
void FileAttente::Ajouter(ClientsEnAttente::Client clientAMettreEnFile)
{
	ClientsEnAttente * pNouveau = new ClientsEnAttente(clientAMettreEnFile.nomReservation,
		clientAMettreEnFile.nombreDePersonnes,
		clientAMettreEnFile.sectionChoisis);

	if (EstVide()) // si la file est vide, il n'y a pas de client
	{
		SetPremier(pNouveau);
		SetDernier(pNouveau);  // ajouté quand on a un pointe
	}
	else // si la file est rempli, il faut changer le dernier client
	{
		pNouveau->SetPrécédent(GetDernier());
		GetDernier()->SetSuivant(pNouveau);
		SetDernier(pNouveau);
	}
	SetNbGroupes(ObtenirNbGroupes() + 1);
	SetNbPersonnes(ObtenirNbPersonnes() + clientAMettreEnFile.nombreDePersonnes);
}
////////////////////////////////////////////////////////////////////////////////
bool FileAttente::Retirer(string nomClient, int nbPersonnes)
{
	ClientsEnAttente * pTemporaire = GetPremier();
	bool existe = false;

	if (pTemporaire == nullptr)
		throw exception("La liste est vide");

	if (VérifierSiPrésent(nomClient, nbPersonnes))
	{
		while (pTemporaire != nullptr && !existe)
		{
			if (pTemporaire != nullptr && EstLeMemeNom(pTemporaire, nomClient, nbPersonnes))
				existe = true;

			else
				pTemporaire = pTemporaire->GetSuivant();
		}
		if (existe)
		{
			if (pTemporaire->GetPrécédent() != nullptr) //si le pTempo n'est pas le 1er
			{
				if (pTemporaire->GetSuivant() != nullptr) //si le pTempo n'est pas le dernier
				{
					pTemporaire->GetSuivant()->SetPrécédent(pTemporaire->GetPrécédent());
					pTemporaire->GetPrécédent()->SetSuivant(pTemporaire->GetSuivant());
				}
				else //si le pTempo est le dernier
				{
					SetDernier(pTemporaire->GetPrécédent());
					pTemporaire->GetPrécédent()->SetSuivant(0);
				}
			}
			else //si le pTempo est le premier de la file	
			{
				if (pTemporaire->GetSuivant() != nullptr) // premier mais pas dernier
				{
					SetPremier(pTemporaire->GetSuivant());
					pTemporaire->GetSuivant()->SetPrécédent(nullptr);
				}
				else // si le premier et dernier
				{
					SetPremier(nullptr);
					SetDernier(nullptr);
				}
			}
			SetNbPersonnes(ObtenirNbPersonnes() - pTemporaire->GetNombrePersonne());
			SetNbGroupes(ObtenirNbGroupes() - 1);
			delete pTemporaire; // tjrs delete ! :D 
		}
	}
	return existe;
}
////////////////////////////////////////////////////////////////////////////////
string FileAttente::GetClient(int indice) const
{
	ClientsEnAttente * pBalayage = GetPremier();
	int compteur = 1;
	while (compteur != indice) // on va chercher le client a l'indice passé en parametre 
	{
		pBalayage = pBalayage->GetSuivant();
		compteur++;
	}
   // et on affiche ses informations
	string nom = " Nom de la réservation : " + pBalayage->GetNom();
	string nombre = " Nombre de personne : " + to_string(pBalayage->GetNombrePersonne());
	string section = " Sections possibles : |";
	for (unsigned int i = 0; i < pBalayage->GetClientSection().size(); i++)
	{
		section += AfficherSection(pBalayage->GetClientSection()[i]) + "|";
	}
	return (nom + "\n" + nombre + "\n" + section + "\n");
}
////////////////////////////////////////////////////////////////////////////////
string FileAttente::AfficherSection(int i) const
{
	string section;
	switch (i)
	{
	case TerrasseNonFumeur: section = "Terrasse NonFumeur"; break;
	case TerrasseFumeur: section = "Terrasse Fumeur"; break;
	case SalleManger: section = "Salle A Manger"; break;
	}
	return section;
}
////////////////////////////////////////////////////////////////////////////////
bool FileAttente::EstVide() const
{
	return GetPremier() == 0; 
}
////////////////////////////////////////////////////////////////////////////////
bool FileAttente::VérifierSiPrésent(string nom, int nbPersonnes) const
{
	ClientsEnAttente * pBalayage = GetPremier();
   // vérifie tout les clients de la file pour voir si le client demandé existe vraiment.
	while (pBalayage != nullptr && !EstVide() && !EstLeMemeNom(pBalayage, nom, nbPersonnes))
	{
		pBalayage = pBalayage->GetSuivant();
	}
	return pBalayage != nullptr;
}
////////////////////////////////////////////////////////////////////////////////
bool FileAttente::EstLeMemeNom(ClientsEnAttente * p, string nom, int nbPersonnes) const
{
	return (MettreEnMajuscules(p->GetNom()) == MettreEnMajuscules(nom) && p->GetNombrePersonne() == nbPersonnes);
}
////////////////////////////////////////////////////////////////////////////////
string FileAttente::MettreEnMajuscules(string nom) const
{
	for (unsigned int i = 0; i < nom.size(); ++i)
	{
		nom[i] = toupper(nom[i]);
	}
	return nom;
}
////////////////////////////////////////////////////////////////////////////////
ClientsEnAttente::Client FileAttente::Retirer(int nbPlacesDeLaTable, Section sectionDeLaTable)
{
	ClientsEnAttente * pTemporaire = GetPremier();
	ClientsEnAttente * meilleursChoix = nullptr; // meilleur groupe pour la combinaison demandé
	bool trouver = false;
	ClientsEnAttente::Client c;

	for (int i = nbPlacesDeLaTable; i > 0 && !trouver; i--)  // on commence par notre nbdeplace demandé,
	{                                                        //  puis a chaque tour de boucle on va voir les groupes un peu plus petit
		pTemporaire = GetPremier();
		while (pTemporaire != nullptr && !trouver) // on parcours tout les clients de la file
		{
			ReduireBoucle(pTemporaire, trouver, meilleursChoix, i, sectionDeLaTable);
			pTemporaire = pTemporaire->GetSuivant(); // va chercher le suivant
		}
	}

	if (!trouver)
		throw exception("Pas de groupe correspondant aux demandes");
   // affiche et "créer" un client temporaire pour le delete
	cout << " Bonne appetit " << meilleursChoix->GetNom() << endl;
	c.nombreDePersonnes = meilleursChoix->GetNombrePersonne();
	c.nomReservation = meilleursChoix->GetNom();
	c.sectionChoisis = meilleursChoix->GetClientSection();
   // delete le client assigner a une table
	Retirer(meilleursChoix->GetNom(), meilleursChoix->GetNombrePersonne());

	SetNbGroupesTotal(ObtenirNbGroupesTotal() + 1);
	SetNbPersonnesTotal(ObtenirNbPersonnesTotal() + c.nombreDePersonnes);
	return c;
}
////////////////////////////////////////////////////////////////////////////////
void FileAttente::ReduireBoucle(ClientsEnAttente * & pTemporaire, bool & trouver, ClientsEnAttente * & meilleursChoix, int & i, Section & sectionDeLaTable)
{
	if (pTemporaire->GetNombrePersonne() == i) // verifie si le nbre de personne du groupe est egale a notre compteur
	{
		for (unsigned int j = 0; j < pTemporaire->GetClientSection().size() && !trouver; j++) // on parcours le vecteur de nos sections
		{
			trouver = (AfficherSection(pTemporaire->GetClientSection().at(j)) == AfficherSection(sectionDeLaTable)); // pour comparer avec la section demandé
			if (trouver)
				meilleursChoix = pTemporaire; // attribut le meilleur choix jusqu'a maintenant 
		}
	}
}
