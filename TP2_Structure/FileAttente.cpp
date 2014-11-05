// Implantation d'une liste de noeuds
//
// par Pierre Prud'homme, octobre 2014
//-------------------------------------------------
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

void FileAttente::SetPremier(ClientsEnAttente * p)
{
	pPremier_ = p;
}

ClientsEnAttente* FileAttente::GetPremier() const
{
	return pPremier_;
}

bool FileAttente::EstVide() const
{
	return GetPremier() == 0;
}

FileAttente::FileAttente()
{
	SetNbGroupes(0);  // il n'y a pas d'�l�ments dans la liste
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

void FileAttente::AjouterEnFinDeListe(string nom)
{
	ClientsEnAttente * pNouveau = new ClientsEnAttente(nom);

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
	SetNbElements(ObtenirNbGroupes() + 1);
}

string FileAttente::RetirerDeLaListe()
{
	ClientsEnAttente * pTemporaire = GetPremier();
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
	SetNbGroupes(ObtenirNbGroupes() - 1);

	return nom;
}

// retourne le nombre d'�l�ments de la liste
int FileAttente::ObtenirNbGroupes() const
{
	return nbGroupes_;
}

int FileAttente::ObtenirNbPersonnes() const
{
	return nbPersonne_;
}

void FileAttente::Afficher(ostream & out) const
{
	ClientsEnAttente * pTemporaire = GetPremier();

	while (pTemporaire != 0)
	{
		out << pTemporaire->GetNom() << endl;
		pTemporaire = pTemporaire->GetSuivant();
	}
	out << "Il y a " << ObtenirNbGroupes() << " elements dans la liste"
		<< endl << endl;
}

string FileAttente::MettreEnMajuscules(string nom) const
{
	for (int i = 0; i < nom.size(); ++i)
	{
		nom[i] = toupper(nom[i]);
	}
	return nom;
}

bool FileAttente::EstLeMemeNom(ClientsEnAttente * p, string nom) const
{
	return MettreEnMajuscules(p->GetNom()) == MettreEnMajuscules(nom);
}

//--- M�thode qui v�rifie si un nom est dans la liste
bool   FileAttente::V�rifierSiPr�sent(string nom) const
{
	ClientsEnAttente * pBalayage = GetPremier();

	while (pBalayage != nullptr && !EstLeMemeNom(pBalayage, nom))
	{
		pBalayage = pBalayage->GetSuivant();
	}

	return pBalayage != nullptr;
}

int FileAttente::DonnerLeRang(string nom) const
{
	ClientsEnAttente * pBalayage = GetPremier();
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

void  FileAttente::PasserDevantToutLeMonde()
{
	if (ObtenirNbGroupes() > 1)
	{
		ClientsEnAttente * pTricheur = GetDernier();
		// modifier la file pour 'enlever' le dernier
		SetDernier(GetDernier()->GetPr�c�dent());
		GetDernier()->SetSuivant(nullptr);

		GetPremier()->SetPr�c�dent(pTricheur);
		pTricheur->SetSuivant(GetPremier());
		pTricheur->SetPr�c�dent(nullptr);
		SetPremier(pTricheur);
	}
}


