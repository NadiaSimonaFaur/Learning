#ifndef CONTROLLER_H
#define CONTROLLER_H
#include<list>
#include "Figura.h"

//adauga dreptunghi
//adauga cerc
//raporteazaCeaMaiMareFigura
//calculeaza aria totala
//raporteazaCrescator
//raporteaza stangaDreapta
//elimina figura de arie mai mica decat o valoare data
//raporteaza dr.intersectate de un punct dat


class Controller {

public:
	~Controller();
	void adaugaDreptunghi(int x, int y, int z, int v);
	void adaugaCerc(int x, int y, int z);
	double ariaTotala();// folosind polimorfism
	double ariaTotala1();//folosind test explicit de tip
	Figura* ceaMaiMareFigura(); //folosind polimorfism
	Figura* ceaMaiMareFigura1(); //folosind test explicit de tip
	std::list<Figura*> raporteazaCrescator();//polimorfism
	std::list<Figura*> raporteazaCrescator1();//test explicit de tip
	std::list<Figura*> raporteazaStangaDreapta();//polimorfism
	std::list<Figura*> raporteazaStangaDreapta1();//test explicit de tip
	std::list<Figura*>& getLista() { return lista; }
	std::list<Figura*> eliminaFigura();//polimorfism


private:
	std::list<Figura*>lista;
	static bool comparator(Figura* f1, Figura* f2);
	static bool comparatorPozitie(Figura* f3, Figura* f4);
	static bool comparatorFiguraMaxima(Figura* f3, Figura* f4);
	static bool comparatorPozitie2(Figura* f1, Figura* f4);
};
#endif

