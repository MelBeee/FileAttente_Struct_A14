#include "FonctionsGenerales.h"


int main()
{
   setlocale(LC_ALL, "");
   FileAttente laFile; 
   bool quitter = true;
   Client nouveau; 

   while (quitter)
   {
      switch (MenuFaireChoix())
      {
      case 1:
		 system("cls");
         cout << " Ajout d'un client " << endl;
		 laFile.Ajouter(CreationClient(nouveau));
         break;
      case 2:
		 system("cls");
         cout << " Assignation d'une table " << endl;
         AssignerTable();
         break;
      case 3:
		 system("cls");
         cout << " Retrait d'un client qui quitte " << endl;
		 RetraitClient(laFile);
         break;
      case 4:
		 system("cls");
         cout << " Affichage d'un client en attente " << endl;
		 AfficherUnClient(laFile); 
         break;
      case 5:
		 system("cls");
         cout << " Affichage de la file d'attente " << endl;
		 laFile.Afficher(cout); 
         break;
      case 6:
         cout << " Quitter " << endl;
         quitter = QuitterLeProgramme(laFile);
         if (!quitter)
         {
            AffichageFinale(laFile);
         }
         break;
      }
   }
}

