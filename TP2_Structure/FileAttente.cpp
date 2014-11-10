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

		out << "Réservation : " << pTemporaire->GetNom() << endl
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

Client Retirer(int nbPlacesDeLaTable, Section sectionDeLaTable)
{
	Client c;
	// clairement temporaire 
	return c;
}

bool FileAttente::Retirer(string nomClient, int nbPersonnes)
{
	ClientsEnAttente * pTemporaire = GetPremier();
	bool existe = false;
	//string nom;
	//int nbPers;

	if (VérifierSiPrésent(nomClient, nbPersonnes))
	{
		while (pTemporaire != GetDernier() && !existe) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		{
			//nom = pTemporaire->GetNom();
			//nbPers = pTemporaire->GetNombrePersonne();
			
			if (/*nom == nomClient && nbPers == nbPersonnes*/ EstLeMemeNom(pTemporaire,nomClient,nbPersonnes))
			{
				cout << "XXXXXXXX Good\n";
				existe = true;
			}
			else
			{
				cout << "XXXXXXXX pas good\n";
			}
			
			pTemporaire = pTemporaire->GetSuivant();
		}
	}

	return existe;

	/*
	ClientsEnAttente * pTemporaire = GetPremier();
	string nom;

	if (pTemporaire == 0)   // if (!pTemporaire)
		throw exception("...La liste est vide...");

	nom = pTemporaire->GetNom();
	SetPremier(GetPremier()->GetSuivant());
	if (GetPremier() != 0)
	{
		GetPremier()->SetPrécédent(0);
	}
	else
	{
		SetDernier(0);
	}
	SetNbPersonnes(ObtenirNbPersonnes() - pTemporaire->GetNombrePersonne());
	//--- le delete est CRUCIAL comme nous l'avons vu en fin de cours
	delete pTemporaire;  // retourne au système l'espace réservé
	SetNbGroupes(ObtenirNbGroupes() - 1);

	return nom;
	*/
}

string FileAttente::GetClient(int indice) const
{
	// clairement temporaire
	return "";
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