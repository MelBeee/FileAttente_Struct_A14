#include "FonctionsGenerales.h"

void Attendre()
{
   cout << endl << "Appuyer sur une touche pour continuer" << endl;
   cin.ignore(cin.rdbuf()->in_avail() + 1);
   system("cls");
}


int MenuFaireChoix()
{
   int Choix;

   cout << " 1. Ajouter un client dans la file " << endl
      << " 2. Assigner une table " << endl
      << " 3. Retirer un client qui quitte " << endl
      << " 4. Afficher un client de la file " << endl
      << " 5. Afficher la file d'attente en entier " << endl
      << " 6. Quitter le programme " << endl;

   do
   {
      cout << " Faites votre choix : ";
      cin >> Choix;

      if (Choix < 1 || Choix > 6)
         cout << " Choix Invalide, recommencez " << endl;
   } while (Choix < 1 || Choix > 6);

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

   cout << " Sections : " << sections;

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
      cout << " Salla à manger : ";
      cin >> section[2];

      if (section[2] != 'o' && section[2] != 'n')
         cout << " Choix invalide, recommencez (o/n) " << endl;
   } while (section[2] != 'o' && section[2] != 'n');

   if (section[0] == 'o') // Terrasse non fumeur  1
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

bool QuitterLeProgramme()
{
   bool quitter = false;
   char choix;

   if (!quitter)  // si file d,attente non vide
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


void AffichageFinale()
{
   cout << " Il y a eu " << " réservations comblés " << endl;
   cout << " Il y a eu " << " clients servis dans le restaurant ce soir " << endl;
   cout << " Il restait " << " clients dans la file d'attente lors de la fermeture du restaurant " << endl;
   Attendre();
}