#ifndef CERC_H
#define CERC_H


#include "Figura.h"



class Cerc : public Figura
{

public:
	//constructor varianta 1
	//Cerc(int a, int b, int c) : x(a), y(b), raza(c){}
	//constructor varianta 2
	Cerc(int, int, int);
	virtual int getX() { return x-raza; }
	int getY() { return y; }
	int getRaza() { return raza; }
	
	virtual void print();
	virtual double calculeazaAria() { return pi * raza * raza; }

private:
	int raza;   //lungimea si latimea dreptunghiului
	int x, y;                  //coordonate carteziene

	const double pi = 3.14;
};


#endif

