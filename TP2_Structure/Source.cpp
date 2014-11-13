////////////////////////////////////////////////////////////////////////////////
//				   			      Source.cpp									            //
//				   Fait par Mélissa Boucher et Xavier Brosseau				         //
//						      Créé le 29 octobre 2014							            //
//						   Derniere modif 16 novembre 2014						         //
//																		                        //
//			Menu utilisateur servant à tester les différentes fonctions		      //
//			de la file d'attente dans le cadre d'une utilisateur d'une		      //	 
//			file de clients et d'attribuation de table dans un restaurant.	      //
////////////////////////////////////////////////////////////////////////////////
#include "FonctionsGenerales.h"
#include <iostream>
#include <string>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
// A FAIRE / FINIR															               //	
// Commenter FileAttente.h .cpp / ClientsEnAttente.h .cpp                     //
// Tester tout																                  //
////////////////////////////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL, ""); // Pour faire afficher les caractères spéciaux
	bool quitter = true; // Variable servant à savoir si on quitte le programme ou non
   Client nouveau; // Instance de la structure Client pour ajouter des nouveaux clients à la file
   FileAttente laFile;	// Création de l'instance de la classe FileAttente
	
	while (quitter) // tant que quitter est a true, on continue 
	{
		try
		{
			quitter = SwitchMenu(quitter, laFile, nouveau); // switch du choix de l'utilisateur
		}
		catch (exception e)
		{
			cout << e.what();
         Attendre();
		}
	}
}

