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
#include "FonctionsGenerales.h"

void Attendre()
{
	cout << endl << "Appuyer sur une touche pour continuer" << endl;
	cin.ignore(cin.rdbuf()->in_avail() + 1);
	system("cls");
}

bool GetInt(int & n)
{
	string str;
	getline(cin, str);
	bool caractere = true; 

	stringstream buffer(str);
	buffer >> n;

	if (!buffer)
	{
		cout << "Caractère incorrecte" << endl;
		caractere = false; 
	}

	//if (!buffer.eof())
	//{
	//	cout << "Buffer end of file" << endl;
	//	caractere = false;
	//}

	return caractere;
}

int MenuFaireChoix()
{
	int Choix = -1;
	AfficherLigneSeparation();
	cout << " 1. Ajouter un client dans la file " << endl
		<< " 2. Assigner une table " << endl
		<< " 3. Retirer un client qui quitte " << endl
		<< " 4. Afficher un client de la file " << endl
		<< " 5. Afficher la file d'attente en entier " << endl
		<< " 6. Quitter le programme " << endl;
	AfficherLigneSeparation();

	do
	{
		cout << " Faites votre choix : ";
	} while (!GetInt(Choix) && Choix < 1 || Choix > 6);

	system("cls");

	return Choix;
}

void DemanderInfoClient(string& nom, int& nbre, int& sections)
{
	cout << " Bienvenue ! Veuillez entrer les informations suivantes s'il vous plait " << endl;

	cout << " Le nom de la réservation : ";
	cin >> nom;

	do
	{
		cout << " Combien de personne à table : ";
		cin >> nbre;

		if (nbre < 1)
			cout << " Nombre invalide, recommencez " << endl;
	} while (nbre < 1);

	cout << " Est-ce que vous aimeriez manger dans les sections suivantes (o/n) " << endl;
	sections = DeterminerSection();

	Attendre();
}

int DeterminerSection()
{
	const int nbresection = 3;
	char section[nbresection];
	int sections = 0;

	do
	{
		cout << " Terrasse non fumeur : ";
		cin >> section[0];

		if (section[0] != 'o' && section[0] != 'n')
			cout << " Choix invalide, recommencez (o/n) " << endl;
	} while (section[0] != 'o' && section[0] != 'n');

	do
	{
		cout << " Terrasse fumeur : ";
		cin >> section[1];

		if (section[1] != 'o' && section[1] != 'n')
			cout << " Choix invalide, recommencez (o/n) " << endl;
	} while (section[1] != 'o' && section[1] != 'n');

	do
	{
		cout << " Salle à manger : ";
		cin >> section[2];

		if (section[2] != 'o' && section[2] != 'n')
			cout << " Choix invalide, recommencez (o/n) " << endl;
	} while (section[2] != 'o' && section[2] != 'n');

	if (section[0] == 'o') // Terrasse non fumeur 1
	{
		sections += 1;
	}
	if (section[1] == 'o') // Terrasse fumeur  10
	{
		sections += 10;
	}
	if (section[2] == 'o') // Salle a Manger   100
	{
		sections += 100;
	}
	if (section[0] == 'n' && section[1] == 'n' && section[2] == 'n')
	{
		cout << " Vous avez dit non à tout nos sections. " << endl
			<< " Nous pensons donc que vous êtes indécis." << endl
			<< " Nous avons décidé pour vous que toutes les sections sont à votre goût. " << endl;
		sections = 111;
	}

	return sections;
}

void AssignerTable()
{

	Attendre();
}

bool QuitterLeProgramme(FileAttente const laFile)
{
	bool quitter = false;
	char choix;

	if (laFile.ObtenirNbGroupes() != 0)  // si file d,attente non vide
	{
		do
		{
			cout << " Il y a encore des clients en file, êtes-vous sur de vouloir quitter ? (o/n) ";
			cin >> choix;
			if (choix != 'o' && choix != 'n')
				cout << " Choix invalide, recommencez " << endl;
		} while (choix != 'o' && choix != 'n');

		if (choix == 'n')
		{
			quitter = true;
		}
	}

	system("cls");
	return quitter;
}


void AffichageFinale(FileAttente const laFile)
{
	AfficherLigneSeparation();
	cout << " Il y a eu " << laFile.ObtenirNbGroupesTotal() << " réservations comblés " << endl;
	cout << " Il y a eu " << laFile.ObtenirNbPersonnesTotal() << " clients servis dans le restaurant ce soir " << endl;
	cout << " Il restait " << laFile.ObtenirNbPersonnes() << " clients dans la file d'attente lors de la fermeture du restaurant " << endl;
	AfficherLigneSeparation();
	Attendre();
}

void RetraitClient(FileAttente& laFile)
{
	string nom;
	int nbre;

	do
	{
		cout << " Quel était le nom de votre réservation ? ";
		cin >> nom;
		cout << " Pour combien de personnes avez vous réservé ? ";
		cin >> nbre;
		if (!laFile.VérifierSiPrésent(nom, nbre))
			cout << " Vous n'avez pas donné les bonnes informations, recommencez. " << endl;
	} while (!laFile.VérifierSiPrésent(nom, nbre));

	laFile.Retirer(nom, nbre);

	cout << " Aurevoir " << nom << endl;
}


void SetClientSection(int section, Client& c)
{
	if (section >= 100)
	{
		c.sectionChoisis.push_back(SalleManger);
		section -= 100;
	}
	if (section >= 10)
	{
		c.sectionChoisis.push_back(TerrasseFumeur);
		section -= 10;
	}
	if (section >= 1)
	{
		c.sectionChoisis.push_back(TerrasseNonFumeur);
		section -= 1;
	}
}

Client CreationClient(Client n)
{
	string nom;
	int nbre, sections;

	DemanderInfoClient(nom, nbre, sections);
	n.nomReservation = nom;
	n.nombreDePersonnes = nbre;
	SetClientSection(sections, n);

	return n;
}

void AfficherUnClient(FileAttente const laFile)
{
	int pos;


	if (laFile.EstVide())
	{
		cout << " La file est vide ";
	}
	else
	{
		do
		{
			cout << "Quelle est la position du client dans la file ? ";
			cin >> pos;
		} while (pos != 1); // changer pour le faire tant et aussi longtemps qu'on a pas une position valide.
	}



	laFile.GetClient(1);
}

void AfficherLigneSeparation()
{
	cout << " ========================================================================= " << endl;
}