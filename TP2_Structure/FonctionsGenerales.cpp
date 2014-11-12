////////////////////////////////////////////////////////////////////////////////
//								FonctionsGenerales.cpp									                  //
//				  Fait par M�lissa Boucher et Xavier Brosseau				         //
//							Cr�� le 29 octobre 2014							               //
//						Derniere modif 16 novembre 2014						            //
//																		                        //
//				      //
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

   // Affichage du menu
   AfficherLigneSeparation();
   cout << " 1. Ajouter un client dans la file " << endl
      << " 2. Assigner une table " << endl
      << " 3. Retirer un client qui quitte " << endl
      << " 4. Afficher un client de la file " << endl
      << " 5. Afficher la file d'attente en entier " << endl
      << " 6. Quitter le programme " << endl;
   AfficherLigneSeparation();

   // Faire un choix, recommencez tant que le caract�re entr� n'est pas un chiffre
   // entre 1 et 6 et pas un caract�re
   do
   {
      cout << " Faites votre choix : ";
      GetInt(Choix);
      cout << endl;
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

   // Demander le nom de la reservation a l'utilisateur
   cout << " Le nom de la r�servation : ";
   cin >> nom;
   do
   {
      // demander le nombre de personne a l'utilisateur 
      // tant qu'il rentre un nombre invalide
      cout << " Combien de personne � table : ";
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
   string sallemanger = "Salle � Manger ? ";

   section[0] = Sections(sections, nonfumeur);
   section[1] = Sections(sections, fumeur);
   section[2] = Sections(sections, sallemanger);

   // Si l'utilisateur � dit oui a la terrasse nonfumeur, on augmente de 1
   if (section[0] == 'o')
   {
      sections += 1;
   }
   // Si l'utilisateur � dit oui a la terrasse fumeur, on augmente de 10
   if (section[1] == 'o')
   {
      sections += 10;
   }
   // Si l'utilisateur � dit oui a la salle a manger, on augmente de 100
   if (section[2] == 'o')
   {
      sections += 100;
   }
   // Si l'utilisateur a dit non a tout les sections, il est ind�ci donc oui a tout
   if (section[0] == 'n' && section[1] == 'n' && section[2] == 'n')
   {
      cout << " Vous avez dit non � tout nos sections. " << endl
         << " Nous pensons donc que vous �tes ind�cis." << endl
         << " Nous avons d�cid� pour vous que toutes les sections sont � votre go�t. " << endl;
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
   // tant que le caract�re n'est pas o ou n on redemande a l'utilisateur
   do
   {
      cout << nom;
      cin >> selectionne;

      if (selectionne != 'o' && selectionne != 'n')
         cout << " Choix invalide, recommencez (o/n) " << endl;
   } while (selectionne != 'o' && selectionne != 'n');

   return selectionne;
}

////////////////////////////////////////////////////////////////////////////////
//								SetClientSection()							  //
////////////////////////////////////////////////////////////////////////////////
void SetClientSection(int section, Client& c)
{
   // si section > 100, ca veux dire que l'utilisateur a dit oui a SalleAManger
   // on pushback donc SalleAManger dans le vecteur<section> du Client
   if (section >= 100)
   {
      c.sectionChoisis.push_back(SalleManger);
      section -= 100;
   }
   // si section > 10, ca veux dire que l'utilisateur a dit oui a TerrasseFumeur
   // on pushback donc TerrasseFumeur dans le vecteur<section> du Client
   if (section >= 10)
   {
      c.sectionChoisis.push_back(TerrasseFumeur);
      section -= 10;
   }
   // si section > 1, ca veux dire que l'utilisateur a dit oui a TerrasseNonFumeur
   // on pushback donc TerrasseNonFumeur dans le vecteur<section> du Client
   if (section >= 1)
   {
      c.sectionChoisis.push_back(TerrasseNonFumeur);
      section -= 1;
   }
}

////////////////////////////////////////////////////////////////////////////////
//							   AssignerTable()								  //
////////////////////////////////////////////////////////////////////////////////
void AssignerTable(FileAttente & laFile)
{
   system("cls");
   AfficherLigneSeparation();
   cout << " Assignation d'une table " << endl;
   AfficherLigneSeparation();

   if (laFile.EstVide())
   {
      cout << "La file est vide" << endl;
   }
   else
   {
      int nbrePersonne, section;
      Section sectiontable;

      cout << "Combien de personnes peuvent s'asseoir a cette table ? ";
      cin >> nbrePersonne;
      do
      {
         cout << " Dans quelle section se trouve la table ? (Fumeur 1 , NonFumeur 2, SalleManger 3) ";
         cin >> section;
      } while (section < 1 || section > 3);

      if (section = 1)
      {
         sectiontable = Section::TerrasseFumeur;
      }
      else if (section = 2)
      {
         sectiontable = Section::TerrasseNonFumeur;
      }
      else
      {
         sectiontable = Section::SalleManger;
      }

      laFile.Assigner(nbrePersonne, sectiontable);

   }


   //  Client tempo = laFile.Retirer(nbrePersonne, sectiontable);
   //// changer section
   //  cout << " Bonne app�tit " << tempo.nomReservation << endl;

   //laFile.Retirer(tempo.nomReservation, tempo.nombreDePersonnes);

   Attendre();
}

////////////////////////////////////////////////////////////////////////////////
//						   QuitterLeProgramme()								  //
////////////////////////////////////////////////////////////////////////////////
bool QuitterLeProgramme(FileAttente & const laFile)
{
   system("cls");
   AfficherLigneSeparation();
   cout << " Quitter " << endl;
   AfficherLigneSeparation();
   // false pour quitter, true pour ne pas quitter
   bool quitter;
   // choix si on quitte ou non lorsqu'il reste des clients en file
   char choix;

   if (laFile.EstVide())
   {
      cout << "La file est vide" << endl;
   }

   if (!laFile.EstVide())  // si file d'attente non vide
   {
      do // refaire tant que l'utilisateur a pas entrer o ou n
      {
         cout << " Il y a encore des clients en file, �tes-vous sur de vouloir quitter ? (o/n) ";
         cin >> choix;
         if (choix != 'o' && choix != 'n')
            cout << " Choix invalide, recommencez " << endl;
      } while (choix != 'o' && choix != 'n');
      // si le choix est non, on quitte, si oui, on conitnue
      if (choix == 'n')
      {
         quitter = true;
      }
      else
      {
         
         quitter = false;
      }
   }
   else
   {
      quitter = false;
   }


   system("cls");
   return quitter;
}

////////////////////////////////////////////////////////////////////////////////
//								AffichageFinale()							  //
////////////////////////////////////////////////////////////////////////////////
void AffichageFinale(FileAttente & const laFile)
{
   // affiche les infofinales en utilisant les fonctions de la file
   AfficherLigneSeparation();
   cout << " Il y a eu " << laFile.ObtenirNbGroupesTotal() << " r�servations combl�s " << endl;
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

   if (!laFile.EstVide())
   {
      string nom;
      int nbre;

      DemanderQuiEstClient(nom, nbre, laFile);
      // maintenant qu'on a trouver les bonnes donn�es, on le retire avec la fonction retirer
      laFile.Retirer(nom, nbre);

      cout << " Aurevoir " << nom << endl;
   }
   else
   {
      cout << " La file est vide " << endl; 
   }

   Attendre();
}

////////////////////////////////////////////////////////////////////////////////
//								CreationClient()							  //
////////////////////////////////////////////////////////////////////////////////
Client CreationClient(Client n)
{
   // Affichage du titre du choix choisi 
   system("cls");
   AfficherLigneSeparation();
   cout << " Ajout d'un client " << endl;
   AfficherLigneSeparation();

   int sections;

   // Demander les infos du client pour ensuite le cr�er 
   DemanderInfoClient(n.nomReservation, n.nombreDePersonnes, sections);
   SetClientSection(sections, n);

   return n;
}

////////////////////////////////////////////////////////////////////////////////
//								AfficherUnClient()							               //
////////////////////////////////////////////////////////////////////////////////
void AfficherUnClient(FileAttente & const laFile, ostream & out)
{
   system("cls");
   AfficherLigneSeparation();
   cout << " Affichage d'un client en attente " << endl;
   AfficherLigneSeparation();

   int nbre;
   string nom, infoClient;

   // si la file est vide on peut pas afficher de client 
   if (laFile.EstVide())
   {
      cout << " La file est vide ! " << endl; 
   }
   else
   {
      // demande qui est client 
      DemanderQuiEstClient(nom, nbre, laFile);
      // affiche le client
      system("cls");
      AfficherLigneSeparation();
      cout << " Affichage d'un client en attente " << endl;
      AfficherLigneSeparation();
      cout << laFile.GetClient(laFile.DonnerLeRang(nom, nbre));
      AfficherLigneSeparation();
   }

   Attendre();
}

void AfficherLaFileEnEntier(ostream & out, FileAttente & laFile)
{
   system("cls");
   AfficherLigneSeparation();
   cout << " Affichage de la file d'attente " << endl;
   AfficherLigneSeparation();
   cout << endl;

   if (laFile.EstVide())
   {
      cout << "La file est vide " << endl; 
   }
   else
   {
      laFile.Afficher(cout);
   }

   AfficherLigneSeparation();
   out << " Il y a " << laFile.ObtenirNbGroupes() << " groupes dans la liste" << endl
      << " Il y a " << laFile.ObtenirNbPersonnes() << " personnes en file " << endl;
   AfficherLigneSeparation();
   Attendre();
}

////////////////////////////////////////////////////////////////////////////////
//							DemanderQuiEstClient()							               //
////////////////////////////////////////////////////////////////////////////////
void DemanderQuiEstClient(string & nom, int & nbre, FileAttente & const laFile)
{
   if (laFile.EstVide())
   {
      cout << " La file est vide " << endl; 
   }
   // demander tant qu'il n'a pas entrer des donn�es qui existe
   do
   {
      cout << " Quel �tait le nom de votre r�servation ? ";
      cin >> nom;
      cout << " Pour combien de personnes avez vous r�serv� ? ";
      cin >> nbre;
      // utilise la fonction verifier si pr�sent pour analyser donn�es entr�es par le user
      if (!laFile.V�rifierSiPr�sent(nom, nbre))
         cout << " Vous n'avez pas donn� les bonnes informations, recommencez. " << endl;
   } while (!laFile.V�rifierSiPr�sent(nom, nbre));
}

////////////////////////////////////////////////////////////////////////////////
//						AfficherLigneSeparation()							  //
////////////////////////////////////////////////////////////////////////////////
void AfficherLigneSeparation()
{
   // cout de paresseux :)
   cout << " ========================================================================= " << endl;
}