////////////////////////////////////////////////////////////////////////////////
//								FileAttente.cpp									  //
//				  Fait par Mélissa Boucher et Xavier Brosseau				  //
//							Créé le 29 octobre 2014							  //
//						Derniere modif 16 novembre 2014						  //
//																		      //
//			  //
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
	SetPremier(nullptr);     // on pointe sur rien
	SetDernier(nullptr);
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
	int indice = 0;

	if (pTemporaire == nullptr)
		throw exception("ggguugugu");

	while (pTemporaire != 0)
	{
		cout << GetClient(indice) << endl;
		indice++;
		pTemporaire = pTemporaire->GetSuivant();
	}

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

	if (pTemporaire == nullptr)
	{
		throw exception("La liste est vide");
	}
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

	string nom = " Nom de la réservation : " + pBalayage->GetNom();
	string nombre = " Nombre de personne : " + to_string(pBalayage->GetNombrePersonne());
	string section = " Sections possibles : |";
	for (unsigned int i = 0; i < pBalayage->GetClientSection().size(); i++)
	{
		section += AfficherSection(pBalayage->GetClientSection()[i]) + "|";
	}
	return (nom + "\n" + nombre + "\n" + section + "\n");
}

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


bool FileAttente::EstVide() const
{
	return GetPremier() == 0;
}

bool FileAttente::VérifierSiPrésent(string nom, int nbPersonnes) const
{
	ClientsEnAttente * pBalayage = GetPremier();

   
   while (pBalayage != nullptr && !EstVide() && !EstLeMemeNom(pBalayage, nom, nbPersonnes))
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

	while (!EstVide() && !EstLeMemeNom(pBalayage, nom, nbPersonnes))
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



Client FileAttente::Assigner(int nbPlacesDeLaTable, Section sectionDeLaTable)
{
	ClientsEnAttente * pTemporaire = GetPremier();
	ClientsEnAttente * meilleursChoix = nullptr;
	bool trouver = false;
	Client c;

	for (int i = nbPlacesDeLaTable; i > 0 && !trouver; i--)
	{
		pTemporaire = GetPremier();
		while (pTemporaire != nullptr && !trouver)
		{
			if (pTemporaire->GetNombrePersonne() == i)
			{
				for (unsigned int j = 0; j < pTemporaire->GetClientSection().size() && !trouver; j++)
				{
					trouver = AfficherSection(sectionDeLaTable) == AfficherSection(pTemporaire->GetClientSection().at(j));
					if (trouver)
						meilleursChoix = pTemporaire;
				}
			}
			pTemporaire = pTemporaire->GetSuivant();
		}
	}

	if (!trouver)
		throw exception("Pas de groupe correspondant aux demandes");


		cout << " Bonne appetit " << meilleursChoix->GetNom() << endl;
		c.nombreDePersonnes = meilleursChoix->GetNombrePersonne();
		c.nomReservation = meilleursChoix->GetNom();
		c.sectionChoisis = meilleursChoix->GetClientSection();

		Retirer(meilleursChoix->GetNom(), meilleursChoix->GetNombrePersonne());

	return c;
}
