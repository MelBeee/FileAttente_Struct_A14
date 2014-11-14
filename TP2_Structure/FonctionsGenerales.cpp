////////////////////////////////////////////////////////////////////////////////
//								FonctionsGenerales.cpp									      //
//				  Fait par Mélissa Boucher et Xavier Brosseau				         //
//							Créé le 29 octobre 2014							               //
//						Derniere modif 16 novembre 2014						            //
//																		                        //
//				     Définitions des fonctions utilisé dans le main	            //
////////////////////////////////////////////////////////////////////////////////
#include "FonctionsGenerales.h"

////////////////////////////////////////////////////////////////////////////////
//								Attendre()									                  //
////////////////////////////////////////////////////////////////////////////////
void Attendre()
{
   cout << endl << "Appuyer sur une touche pour continuer" << endl;
   cin.ignore(cin.rdbuf()->in_avail() + 1);
   system("cls");
}
////////////////////////////////////////////////////////////////////////////////
//								GetInt()									                     //
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
//								MenuFaireChoix()							                  //
////////////////////////////////////////////////////////////////////////////////
int MenuFaireChoix()
{
   // Initialisation a -1 pour rentrer dans la boucle
   int Choix = -1;

   AfficherLigneSeparation(); // Affichage du menu
   cout << " 1. Ajouter un client dans la file " << endl
      << " 2. Assigner une table " << endl
      << " 3. Retirer un client qui quitte 7" << endl
      << " 4. Afficher un client de la file " << endl
      << " 5. Afficher la file d'attente en entier " << endl
      << " 6. Quitter le programme " << endl;
   AfficherLigneSeparation();

   // Faire un choix, recommencez tant que le caractère entré n'est pas un chiffre
   // entre 1 et 6 et pas un caractère
   do
   {
      cout << " Faites votre choix : ";
      GetInt(Choix);
   } while (Choix < 1 || Choix > 6);

   system("cls");

   return Choix;
}
////////////////////////////////////////////////////////////////////////////////
//							   DemanderInfoClient()							               //
////////////////////////////////////////////////////////////////////////////////
void DemanderInfoClient(string& nom, int& nbre, int& sections)
{
   cout << " Bienvenue ! Veuillez entrer les informations suivantes s'il vous plait " << endl;

   cout << " Le nom de la réservation : "; // Demander le nom de la reservation a l'utilisateur
   cin >> nom;
   do
   {
      // demander le nombre de personne a l'utilisateur 
      // tant qu'il rentre un nombre invalide
      cout << " Combien de personne à table : ";
      cin >> nbre;

      if (nbre < 1)
         cout << " Nombre invalide, recommencez " << endl;
   } while (nbre < 1);

   // demander les sections a l'utilisateur
   cout << " Est-ce que vous aimeriez manger dans les sections suivantes (o/n) " << endl;
   sections = DeterminerSection();

   Attendre();
}
////////////////////////////////////////////////////////////////////////////////
//							   DemanderInfoClient()							               //
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

   if (section[0] == 'o') // Si l'utilisateur à dit oui a la terrasse nonfumeur, on augmente de 1
   {
      sections += 1;
   }
   if (section[1] == 'o') // Si l'utilisateur à dit oui a la terrasse fumeur, on augmente de 10
   {
      sections += 10;
   }
   if (section[2] == 'o')// Si l'utilisateur à dit oui a la salle a manger, on augmente de 100
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
//								    Sections()								                  //
////////////////////////////////////////////////////////////////////////////////
char Sections(int & section, string nom)
{
   char selectionne;

   do // tant que le caractère n'est pas o ou n on redemande a l'utilisateur
   {
      cout << nom;
      cin >> selectionne;

      if (selectionne != 'o' && selectionne != 'n')
         cout << " Choix invalide, recommencez (o/n) " << endl;
   } while (selectionne != 'o' && selectionne != 'n');

   return selectionne;
}
////////////////////////////////////////////////////////////////////////////////
//								SetClientSection()							               //
////////////////////////////////////////////////////////////////////////////////
void SetClientSection(int section, Client& c)
{
   if (section >= 100) // si section > 100, ca veux dire que l'utilisateur a dit oui a SalleAManger
   {   // on pushback donc SalleAManger dans le vecteur<section> du Client
      c.sectionChoisis.push_back(SalleManger);
      section -= 100;
   }
   if (section >= 10) // si section > 10, ca veux dire que l'utilisateur a dit oui a TerrasseFumeur
   {   // on pushback donc TerrasseFumeur dans le vecteur<section> du Client
      c.sectionChoisis.push_back(TerrasseFumeur);
      section -= 10;
   }
   if (section >= 1) // si section > 1, ca veux dire que l'utilisateur a dit oui a TerrasseNonFumeur
   {   // on pushback donc TerrasseNonFumeur dans le vecteur<section> du Client
      c.sectionChoisis.push_back(TerrasseNonFumeur);
      section -= 1;
   }
}
////////////////////////////////////////////////////////////////////////////////
//							   AssignerTable()								               //
////////////////////////////////////////////////////////////////////////////////
void AssignerTable(FileAttente & laFile)
{
   system("cls");
   AfficherLigneSeparation();
   cout << " Assignation d'une table " << endl;
   AfficherLigneSeparation();

   if (laFile.EstVide())
      throw exception("\n La file est vide \n");

   int nbrePersonne, section;
   Section sectiontable;

   do
   {
      cout << "Combien de personnes peuvent s'asseoir a cette table ? ";
      cin >> nbrePersonne;
   } while (nbrePersonne < 1);

   do
   {
      cout << " Dans quelle section se trouve la table ? (Fumeur 1 , NonFumeur 2, SalleManger 3) ";
      cin >> section;
   } while (section < 1 || section > 3);

   switch (section)
   {
   case 1: sectiontable = Section::TerrasseFumeur; break;
   case 2: sectiontable = Section::TerrasseNonFumeur; break;
   case 3: sectiontable = Section::SalleManger; break;
   }

   laFile.Assigner(nbrePersonne, sectiontable);

   Attendre();
}
////////////////////////////////////////////////////////////////////////////////
//						   QuitterLeProgramme()								               //
////////////////////////////////////////////////////////////////////////////////
bool QuitterLeProgramme(FileAttente & laFile)
{
   system("cls");
   AfficherLigneSeparation();
   cout << " Quitter " << endl;
   AfficherLigneSeparation();

   bool quitter = false; // false pour quitter, true pour ne pas quitter
   char choix; // choix si on quitte ou non lorsqu'il reste des clients en file

   if (!laFile.EstVide())
   {
      do // refaire tant que l'utilisateur a pas entrer o ou n
      {
         cout << " Il y a encore des clients en file, êtes-vous sur de vouloir quitter ? (o/n) ";
         cin >> choix;
         if (choix != 'o' && choix != 'n')
            cout << " Choix invalide, recommencez " << endl;
      } while (choix != 'o' && choix != 'n');

      if (choix == 'n') // si le choix est non, on quitte, si oui, on conitnue
         quitter = true;
   }
   system("cls");
   return quitter;
}
////////////////////////////////////////////////////////////////////////////////
//								AffichageFinale()							                  //
////////////////////////////////////////////////////////////////////////////////
void AffichageFinale(FileAttente & laFile)
{
   AfficherLigneSeparation(); // affiche les info finales en utilisant les fonctions de la file
   cout << " Il y a eu " << laFile.ObtenirNbGroupesTotal() << " réservations comblés " << endl;
   cout << " Il y a eu " << laFile.ObtenirNbPersonnesTotal() << " clients servis dans le restaurant ce soir " << endl;
   cout << " Il restait " << laFile.ObtenirNbPersonnes() << " clients dans la file d'attente lors de la fermeture du restaurant " << endl;
   AfficherLigneSeparation();
   Attendre();
}
////////////////////////////////////////////////////////////////////////////////
//								RetraitClient()								               //
////////////////////////////////////////////////////////////////////////////////
void RetraitClient(FileAttente & laFile)
{
   system("cls");
   AfficherLigneSeparation();
   cout << " Retrait d'un client qui quitte " << endl;
   AfficherLigneSeparation();

   if (laFile.EstVide())
      throw exception("\n La file est vide \n");

   string nom;
   int nbre;

	if (!DemanderQuiEstClient(nom, nbre, laFile)) // maintenant qu'on a trouver les bonnes données
	{
		laFile.Retirer(nom, nbre); //on le retire avec la fonction retirer
		cout << " Aurevoir " << nom << endl;
	}
   Attendre();
}
////////////////////////////////////////////////////////////////////////////////
//								CreationClient()							                  //
////////////////////////////////////////////////////////////////////////////////
Client CreationClient(Client n)
{
   system("cls");
   AfficherLigneSeparation();
   cout << " Ajout d'un client " << endl;   // Affichage du titre du choix choisi 
   AfficherLigneSeparation();

   int sections;

   DemanderInfoClient(n.nomReservation, n.nombreDePersonnes, sections);   // Demander les infos du client pour ensuite le créer 
   SetClientSection(sections, n);

   return n;
}
////////////////////////////////////////////////////////////////////////////////
//								AfficherUnClient()							               //
////////////////////////////////////////////////////////////////////////////////
void AfficherUnClient(FileAttente & laFile, ostream & out)
{
   system("cls");
   AfficherLigneSeparation();
   cout << " Affichage d'un client en attente " << endl;
   AfficherLigneSeparation();

   int nbre;
   string nom, infoClient;

   if (laFile.EstVide()) // si la file est vide on peut pas afficher de client 
      throw exception("\n La file est vide \n");

	if (!DemanderQuiEstClient(nom, nbre, laFile))  // demande qui est client 
	{
		system("cls");
		AfficherLigneSeparation();
		cout << " Affichage d'un client en attente " << endl;
		AfficherLigneSeparation();
		cout << laFile.GetClient(laFile.DonnerLeRang(nom, nbre));   // affiche le client
		AfficherLigneSeparation();
	}
   Attendre();
}
////////////////////////////////////////////////////////////////////////////////
//							AfficherLaFileEnEntier()							            //
////////////////////////////////////////////////////////////////////////////////
void AfficherLaFileEnEntier(ostream & out, FileAttente & laFile)
{
   system("cls");
   AfficherLigneSeparation();
   cout << " Affichage de la file d'attente " << endl;
   AfficherLigneSeparation();
   cout << endl;

   if (laFile.EstVide())
      throw exception("La file est vide \n");

   laFile.Afficher(cout);

   AfficherLigneSeparation();
   out << " Il y a " << laFile.ObtenirNbGroupes() << " groupes dans la liste" << endl
      << " Il y a " << laFile.ObtenirNbPersonnes() << " personnes en file " << endl;
   AfficherLigneSeparation();
   Attendre();
}
////////////////////////////////////////////////////////////////////////////////
//							DemanderQuiEstClient()							               //
////////////////////////////////////////////////////////////////////////////////
bool DemanderQuiEstClient(string & nom, int & nbre, FileAttente & laFile)
{
   if (laFile.EstVide())
      throw exception("\n La file est vide \n");
	bool recommencer = false; 
	char choix; 
   do // demander tant qu'il n'a pas entrer des données qui existe
   {
      cout << " Quel était le nom de votre réservation ? ";
      cin >> nom;
      cout << " Pour combien de personnes avez vous réservé ? ";
      cin >> nbre;
		if (!laFile.VérifierSiPrésent(nom, nbre)) // utilise la fonction verifier si présent pour analyser données entrées par le user
		{
			cout << " Vous n'avez pas donné les bonnes informations, recommencez ? (o/n) " ;
			do
			{
				cin >> choix;
			} while (choix != 'o' && choix != 'n');
			if (choix == 'n')
			{
				recommencer = true; 
			}
		}
   } while (!laFile.VérifierSiPrésent(nom, nbre) && !recommencer);
	return recommencer; 
}
////////////////////////////////////////////////////////////////////////////////
//						AfficherLigneSeparation()							               //
////////////////////////////////////////////////////////////////////////////////
void AfficherLigneSeparation()
{
   for (int i = 0; i < 50; i++) // cout de paresseux :)
   {
      cout << "=";
   }
   cout << endl;
}
////////////////////////////////////////////////////////////////////////////////
//										SwitchMenu()							               //
////////////////////////////////////////////////////////////////////////////////
bool SwitchMenu(bool quitter, FileAttente & laFile, Client nouveau)
{
   switch (MenuFaireChoix())
   {
   case 1:
      laFile.Ajouter(CreationClient(nouveau));
      break;
   case 2:
      AssignerTable(laFile);
      break;
   case 3:
      RetraitClient(laFile); // pouvoir quitter la boucle ? 
      break;
   case 4:
      AfficherUnClient(laFile, cout); // pouvoir quitter la boucle ? 
      break;
   case 5:
      AfficherLaFileEnEntier(cout, laFile);
      break;
   case 6:
      quitter = QuitterLeProgramme(laFile);
      if (!quitter)
      {
         AffichageFinale(laFile);
      }
      break;
   }
   return quitter;
}