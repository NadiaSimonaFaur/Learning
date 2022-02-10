#include <iostream>
#include "Cerc.h"
using namespace std;



Cerc::Cerc(int x, int y, int raza)
{
	this->x = x;
	this->y = y;
	this->raza = raza;
}

void Cerc::print() {
	cout << "Cerc:(Raza = " << raza << " ) - (Coordonata x: " << x-raza << ", Coordonata y = " << y << ")-Aria:"<<calculeazaAria()<<endl;
}

