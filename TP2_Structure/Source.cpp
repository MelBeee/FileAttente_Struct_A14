////////////////////////////////////////////////////////////////////////////////
//				   			      Source.cpp									            //
//				   Fait par M�lissa Boucher et Xavier Brosseau				         //
//						      Cr�� le 29 octobre 2014							            //
//						   Derniere modif 16 novembre 2014						         //
//																		                        //
//			Menu utilisateur servant � tester les diff�rentes fonctions		      //
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
	setlocale(LC_ALL, ""); // Pour faire afficher les caract�res sp�ciaux
	bool quitter = true; // Variable servant � savoir si on quitte le programme ou non
   Client nouveau; // Instance de la structure Client pour ajouter des nouveaux clients � la file
   FileAttente laFile;	// Cr�ation de l'instance de la classe FileAttente
	
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

