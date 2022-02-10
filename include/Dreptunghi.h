#pragma once


#ifndef DREPTUNGHI_H
#define DREPTUNGHI_H


#include "Figura.h"




class Dreptunghi : public Figura
{

public:
	//constructor varianta 1
	Dreptunghi(int a, int b, int c, int d) : x(a), y(b), orizontal(c), vertical(d){}
	//constructor varianta 2
	//Dreptunghi(int, int);
	virtual int getX() { return x; }
	int getY() { return y; }
	int getOrizontal() { return orizontal; }
	int getVertical() {return vertical;}
	virtual void print();
	virtual double calculeazaAria() { return orizontal * vertical; }

private:
	int orizontal, vertical;   //lungimea si latimea dreptunghiului
	int x, y; //coordonate carteziene

};


#endif


