////////////////////////////////////////////////////////////////////////////////
//				   			      Source.cpp									            //
//				   Fait par Mélissa Boucher et Xavier Brosseau				         //
//			Créé le 29 octobre 2014,	Derniere modif 16 novembre 2014			   //
//			Menu utilisateur servant à tester les différentes fonctions		      //
//			de la file d'attente dans le cadre d'une utilisateur d'une		      //	 
//			file de clients et d'attribuation de table dans un restaurant.	      //
////////////////////////////////////////////////////////////////////////////////
#include "FonctionsGenerales.h"
#include <iostream>
#include <string>
using namespace std;

void CreationClienstPourTest(FileAttente & laFile);

int main()
{
	setlocale(LC_ALL, ""); // Pour faire afficher les caractères spéciaux
	bool quitter = true; // Variable servant à savoir si on quitte le programme ou non
	ClientsEnAttente::Client nouveau; // Instance de la structure Client pour ajouter des nouveaux clients à la file
   FileAttente laFile;	// Création de l'instance de la classe FileAttente
	
	CreationClienstPourTest(laFile);

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

// Fonction de paresseuuux :) 
void CreationClienstPourTest(FileAttente & laFile)
{
	ClientsEnAttente::Client a, b, c, d, e, f, g;
	vector<Section> h, i, j, k, l, m;

	h.push_back(Section::SalleManger);

	i.push_back(Section::TerrasseFumeur);

	j.push_back(Section::SalleManger);
	j.push_back(Section::TerrasseFumeur);

	k.push_back(Section::TerrasseFumeur);
	k.push_back(Section::TerrasseNonFumeur);

	l.push_back(Section::TerrasseNonFumeur);

	m.push_back(Section::TerrasseFumeur);
	m.push_back(Section::TerrasseNonFumeur);
	m.push_back(Section::SalleManger);

	a.nomReservation = "Arthur";
	a.nombreDePersonnes = 4;
	a.sectionChoisis = h;

	b.nomReservation = "Benoit";
	b.nombreDePersonnes = 6;
	b.sectionChoisis = i;

	c.nomReservation = "Charles";
	c.nombreDePersonnes = 2;
	c.sectionChoisis = j;

	d.nomReservation = "Diane";
	d.nombreDePersonnes = 3;
	d.sectionChoisis = i;

	e.nomReservation = "Elise";
	e.nombreDePersonnes = 4;
	e.sectionChoisis = k;

	f.nomReservation = "Francis";
	f.nombreDePersonnes = 2;
	f.sectionChoisis = l;

	g.nomReservation = "Gaston";
	g.nombreDePersonnes = 8;
	g.sectionChoisis = m; 

	laFile.Ajouter(a);
	laFile.Ajouter(b);
	laFile.Ajouter(c);
	laFile.Ajouter(d);
	laFile.Ajouter(e);
	laFile.Ajouter(f);
	laFile.Ajouter(g);
}