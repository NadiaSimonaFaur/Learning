#include<iostream>
#include "Controller.h"
#include "Figura.h"
#include "Dreptunghi.h"
#include "Cerc.h"




Controller::~Controller() {
	while (lista.size() > 0) {
		Figura* p = lista.back();
		delete p;
		lista.pop_back();
	}
}

//Functii comparator:
bool Controller::comparator(Figura* f1, Figura* f2) {
	return f1->calculeazaAria() < f2->calculeazaAria();
}
bool Controller::comparatorPozitie(Figura* f3, Figura* f4) {
	return f3->getX() < f4->getX();
}
bool Controller::comparatorFiguraMaxima(Figura* f1, Figura* f2) {

	double arie1 = 0;
	double arie2 = 0;
	Cerc* cerc = dynamic_cast<Cerc*>(f1);
       if (cerc != nullptr) {
			arie1 = 3.14 * cerc->getRaza() * cerc->getRaza();
		}
		else {
			Dreptunghi* pd = (Dreptunghi*)f1;
			arie1 = pd->getOrizontal() * pd->getVertical();
		}
	cerc = dynamic_cast<Cerc*>(f2);
	   if (cerc != nullptr) {
		   arie2 = 3.14 * cerc->getRaza() * cerc->getRaza();
	   }
	   else {
		   Dreptunghi* pd = (Dreptunghi*)f2;
		   arie2 = pd->getOrizontal() * pd->getVertical();
	   }
	   return arie1 < arie2;
}
bool Controller::comparatorPozitie2(Figura* f3, Figura* f4) {

	int x = 0;
	int x1 = 0;
	Cerc* cerc = dynamic_cast<Cerc*>(f3);
	if (cerc != nullptr) {
		x = cerc->getX();
	}
	else {
		Dreptunghi* pd = (Dreptunghi*)f3;
		x = pd->getX();
	}
	cerc = dynamic_cast<Cerc*>(f4);
	if (cerc != nullptr) {
		x1 = cerc->getX();
	}
	else {
		Dreptunghi* pd = (Dreptunghi*)f4;
		x1 = pd->getX();
	}
	return x < x1;
}

//IMplementarea metodelor folosind polimorfism si test explicit de tip
void Controller::adaugaDreptunghi(int a, int b, int c, int d) {
	Dreptunghi* p = new Dreptunghi(a, b, c, d);
	lista.push_back(p);
}
void Controller::adaugaCerc(int a, int b, int c) {
	Cerc* cerc = new Cerc(a, b, c);
	lista.push_back(cerc);
}
//Varianta1:aria totala->polimorfism
double Controller::ariaTotala() {

	double rezultat = 0;
	for (Figura* fig : lista) {
		rezultat += fig->calculeazaAria();
	}
	return rezultat;
}
//Varianta2:ariatotala -> test explicit de tip
double Controller::ariaTotala1() {
	double rez = 0;
	for (Figura* f : lista) {
		Cerc* cerc = dynamic_cast<Cerc*>(f);
		if (cerc != nullptr) {
			rez += (3.14 * cerc->getRaza() * cerc->getRaza());
		}
		else {
			Dreptunghi* pd = (Dreptunghi*)f;
			rez += (pd->getOrizontal() * pd->getVertical());
		}
	}
	return rez;
}
//varianta 1:cea mai mare Figura-> polimorfism
Figura* Controller::ceaMaiMareFigura() {
	Figura* fig = lista.front();
	for (Figura* f : lista) {
		if (fig->calculeazaAria() < f->calculeazaAria()) {
			fig = f;
		}
	}
	return fig;
}
//varianta 2:cea mai mare figura-> test explicit de tip
Figura* Controller::ceaMaiMareFigura1() {
	std::list<Figura*> rez = lista;
	rez.sort(comparatorFiguraMaxima);
	return rez.back();
	
}
//varianta 1:raporteaza crescator->polimorfism
std::list<Figura*> Controller::raporteazaCrescator() {

	std::list<Figura*> listaSortata = lista;
	listaSortata.sort(comparator);
	return listaSortata;
}
//varianta 2:raporteaza crescator ->test explicit de tip
std::list<Figura*> Controller::raporteazaCrescator1() {

	std::list<Figura*> listaSortata = lista;
	listaSortata.sort(comparatorFiguraMaxima);
	return listaSortata;
}
//varianta 1:raporteaza stanga dreapta->polimorfism
std::list<Figura*> Controller::raporteazaStangaDreapta() {
	std::list<Figura*> rez = lista;
	rez.sort(comparatorPozitie);
	return rez;
}
//varianta 2:raporteaza stanga dreapta->test explicit de tip
std::list<Figura*> Controller::raporteazaStangaDreapta1() {
	std::list<Figura*> rez = lista;
	rez.sort(comparatorPozitie2);
	return rez;
}
std::list<Figura*> Controller::eliminaFigura() {
	double val;
	std::cout << "Introduceti valoarea: " << std::endl;
	std::cin >> val;
	//pentru a elimina un obiect din lista am 2 posibilitati:
	//1.fie imi fac o copie a listei originale->parcurg copia si sterg din original
	//2.fie imi fac o lista in care pun ce-mi ramane 

	//prima varianta:
	/*std::list<Figura*> rez = lista;
	for (Figura* f : rez) {

		if (f->calculeazaAria() < val) {
			lista.remove(f);
		}
		
	}
	return  rez;*/


	//a 2 a varianta
	std::list<Figura*> lst;
	for (Figura* f : lista) {
		if (f->calculeazaAria() > val) {
			lst.push_back(f);
		}
	}
	return lst;
}
