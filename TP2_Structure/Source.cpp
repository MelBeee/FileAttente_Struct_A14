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
         AfficherLigneSeparation();
         cout << " Ajout d'un client " << endl;
         AfficherLigneSeparation();
         laFile.Ajouter(CreationClient(nouveau));
         break;
      case 2:
         system("cls");
         AfficherLigneSeparation();
         cout << " Assignation d'une table " << endl;
         AfficherLigneSeparation();
         AssignerTable();
         break;
      case 3:
         system("cls");
         AfficherLigneSeparation();
         cout << " Retrait d'un client qui quitte " << endl;
         AfficherLigneSeparation();
         RetraitClient(laFile);
         break;
      case 4:
         system("cls");
         AfficherLigneSeparation();
         cout << " Affichage d'un client en attente " << endl;
         AfficherLigneSeparation();
         AfficherUnClient(laFile);
         break;
      case 5:
         system("cls");
         AfficherLigneSeparation();
         cout << " Affichage de la file d'attente " << endl;
         AfficherLigneSeparation();
         laFile.Afficher(cout);
         Attendre(); 
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

