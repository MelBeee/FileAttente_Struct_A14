#include <iostream>
#include <string>
using namespace std;

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
         cout << " Choix Invalide, recommencer " << endl;
   } while (Choix < 1 || Choix > 6);

   system("cls");

   return Choix;
}

int main()
{
   bool quitter = true;

   while (quitter)
   {
      switch (MenuFaireChoix())
      {
      case 1:
         cout << " Ajout d'un client " << endl;
         break;
      case 2:
         cout << " Assignation d'une table " << endl;
         break;
      case 3:
         cout << " Retrait d'un client qui quitte " << endl;
         break;
      case 4:
         cout << " Affichage d'un client en attente " << endl;
         break;
      case 5:
         cout << " Affichage de la file d'attente " << endl;
         break;
      case 6:
         cout << " Quitter " << endl;
         quitter = false;
         break;
      }
   }
}
