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
#include <iostream>
#include <string>
using namespace std; 

////////////////////////////////////////////////////////////////////////////////
// A FAIRE / FINIR															  //
// Retirer(client) / retirer(nom, nombre) / GetClient / AfficherUnClient	  //
// AfficherUnSeulClient														  //
// Commenter FileAttente.h .cpp / ClientsEnAttente.h .cpp					  //
// Tester tout																  //
////////////////////////////////////////////////////////////////////////////////
int main()
{
	// Pour faire afficher les caractères spéciaux
	setlocale(LC_ALL, "");
	// Création de l'instance de la classe FileAttente
	FileAttente laFile;
	// Variable servant à savoir si on quitte le programme ou non
	bool quitter = true;
	// Instance de la structure Client pour ajouter des nouveaux clients à la file
	Client nouveau;

	// tant que quitter est a true, on continue 
	while (quitter)
	{
		// switch du choix de l'utilisateur
		switch (MenuFaireChoix())
		{
		case 1:
			laFile.Ajouter(CreationClient(nouveau));
			break;
		case 2:
			AssignerTable();
			break;
		case 3:
			RetraitClient(laFile);
			break;
		case 4:
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
			quitter = QuitterLeProgramme(laFile);
			if (!quitter)
			{
				AffichageFinale(laFile);
			}
			break;
		}
	}
}

