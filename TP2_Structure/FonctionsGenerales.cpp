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


////////////////////////////////////////////////////////////////////////////////
//								Attendre()									  //
////////////////////////////////////////////////////////////////////////////////
void Attendre()
{
	cout << endl << "Appuyer sur une touche pour continuer" << endl;
	cin.ignore(cin.rdbuf()->in_avail() + 1);
	system("cls");
}

////////////////////////////////////////////////////////////////////////////////
//								GetInt()									  //
////////////////////////////////////////////////////////////////////////////////
bool GetInt(int & n)
{
	string str;
	getline(cin, str);
	bool caractere = true;

	stringstream buffer(str);
	buffer >> n;

	if (!buffer)
	{
		caractere = false;
	}

	return caractere;
}

////////////////////////////////////////////////////////////////////////////////
//								MenuFaireChoix()							  //
////////////////////////////////////////////////////////////////////////////////
int MenuFaireChoix()
{
	// Initialisation a -1 pour rentrer dans la boucle
	int Choix = -1;

	// Affichage du menu
	AfficherLigneSeparation();
	cout << " 1. Ajouter un client dans la file " << endl
		<< " 2. Assigner une table " << endl
		<< " 3. Retirer un client qui quitte " << endl
		<< " 4. Afficher un client de la file " << endl
		<< " 5. Afficher la file d'attente en entier " << endl
		<< " 6. Quitter le programme " << endl;
	AfficherLigneSeparation();

	// Faire un choix, recommencez tant que le caractère entré n'est pas un chiffre
	// entre 1 et 6 et pas un caractère
	do
	{
		cout << " Faites votre choix : ";
		if (!GetInt(Choix) && Choix < 1 || Choix > 6)
			cout << " Nombre invalide, recommencez " << endl;
	} while (Choix < 1 || Choix > 6);

	system("cls");

	return Choix;
}

////////////////////////////////////////////////////////////////////////////////
//							   DemanderInfoClient()							  //
////////////////////////////////////////////////////////////////////////////////
void DemanderInfoClient(string& nom, int& nbre, int& sections)
{
	cout << " Bienvenue ! Veuillez entrer les informations suivantes s'il vous plait " << endl;

	// Demander le nom de la reservation a l'utilisateur
	cout << " Le nom de la réservation : ";
	cin >> nom;
	do
	{
		// demander le nombre de personne a l'utilisateur 
		// tant qu'il rentre un nombre invalide
		cout << " Combien de personne à table : ";
		cin >> nbre; 

		if ( nbre < 1)
			cout << " Nombre invalide, recommencez " << endl;
	} while ( nbre < 1);

	// demander les sections a l'utilisateur
	cout << " Est-ce que vous aimeriez manger dans les sections suivantes (o/n) " << endl;
	sections = DeterminerSection();

	Attendre();
}

////////////////////////////////////////////////////////////////////////////////
//							   DemanderInfoClient()							  //
////////////////////////////////////////////////////////////////////////////////
int DeterminerSection()
{
	// tableau de char pour stocker les sections que le client veux
	char section[3];
	int sections = 0;
	// string d'affichage
	string nonfumeur = "Terrasse NonFumeur ? ";
	string fumeur = "Terrasse Fumeur ? ";
	string sallemanger = "Salle à Manger ? ";

	section[0] = Sections(sections, nonfumeur);
	section[1] = Sections(sections, fumeur);
	section[2] = Sections(sections, sallemanger);

	// Si l'utilisateur à dit oui a la terrasse nonfumeur, on augmente de 1
	if (section[0] == 'o') 
	{
		sections += 1;
	}
	// Si l'utilisateur à dit oui a la terrasse fumeur, on augmente de 10
	if (section[1] == 'o') 
	{
		sections += 10;
	}
	// Si l'utilisateur à dit oui a la salle a manger, on augmente de 100
	if (section[2] == 'o') 
	{
		sections += 100;
	}
	// Si l'utilisateur a dit non a tout les sections, il est indéci donc oui a tout
	if (section[0] == 'n' && section[1] == 'n' && section[2] == 'n')
	{
		cout << " Vous avez dit non à tout nos sections. " << endl
			<< " Nous pensons donc que vous êtes indécis." << endl
			<< " Nous avons décidé pour vous que toutes les sections sont à votre goût. " << endl;
		sections = 111;
	}

	return sections;
}

////////////////////////////////////////////////////////////////////////////////
//								    Sections()								  //
////////////////////////////////////////////////////////////////////////////////
char Sections(int & section, string nom)
{
	char selectionne;
	// tant que le caractère n'est pas o ou n on redemande a l'utilisateur
	do
	{
		cout << nom ;
		cin >> selectionne;

		if (selectionne != 'o' && selectionne != 'n')
			cout << " Choix invalide, recommencez (o/n) " << endl;
	} while (selectionne != 'o' && selectionne  != 'n');

	return selectionne;
}

////////////////////////////////////////////////////////////////////////////////
//							   AssignerTable()								  //
////////////////////////////////////////////////////////////////////////////////
void AssignerTable()
{

	Attendre();
}

////////////////////////////////////////////////////////////////////////////////
//						   QuitterLeProgramme()								  //
////////////////////////////////////////////////////////////////////////////////
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
	int sections;

	DemanderInfoClient(n.nomReservation, n.nombreDePersonnes, sections);
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