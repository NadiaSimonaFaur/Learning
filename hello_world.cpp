#include <iostream>
#include "Dreptunghi.h"
#include "Cerc.h"
#include "Controller.h"
#include "Figura.h"

int main() {
std::cout << "Hello World!" << std::endl;
Dreptunghi d(1,2,3,4);
d.print();
Cerc c(4,2,8);
c.print();

Controller controller;
    controller.adaugaDreptunghi(1, 3, 2, 4);
    controller.adaugaCerc(0, 0, 3);
    controller.adaugaDreptunghi(-2, 0, 3, 3);
    controller.adaugaDreptunghi(0, 1, 1, 1);
    controller.adaugaCerc(1, -1, 2);
    controller.adaugaCerc(-2, 3, 1);
    controller.adaugaDreptunghi(2, -2, 2, 1);
    controller.adaugaDreptunghi(-1, 1, 5, 1);
    controller.adaugaDreptunghi(4, -2, 2, 1);
    controller.adaugaCerc(2, -2, 1);

    std::cout << "Figurile de pe scena:\n";
    for (Figura* p : controller.getLista()) {
        p->print();
    }
    std::cout << std::endl;
    //calcul arie totala ->varianta polimorfism
    std::cout << "Aria totala (polimorfism) a figurilor geometrice este: "<< controller.ariaTotala() <<std::endl;
    std::cout << std::endl;
    //calcul arie totala ->varianta test explicit de tip
    std::cout << "Aria totala (test explicit de tip) a figurilor geometrice este: "<< controller.ariaTotala1() <<std::endl;
    std::cout << std::endl;
    //cea mai mare figura ->varianta polimorfism
    Figura* figura = controller.ceaMaiMareFigura();
    std::cout << "Cea mai mare figura(polimorfism) este: " << std::endl;
    figura->print();
    std::cout << std::endl;
    //cea mai mare figura ->varianta test explicit de tip
    Figura* figura2 = controller.ceaMaiMareFigura1();
    std::cout << "Cea mai mare figura(test explicit de tip) este: " << std::endl;
    Cerc* cerc = dynamic_cast<Cerc*>(figura2);
    if (cerc != nullptr) {
        std::cout << "Cerc:(Raza = " << cerc->getRaza() << " ) - (Coordonata x: " << cerc->getX() << ", Coordonata y = " << cerc->getY() << ")-Aria:" << 3.14 * cerc->getRaza() * cerc->getRaza() << std::endl;
    }
    else {
        Dreptunghi* pd = (Dreptunghi*)figura2;
        std::cout << "Dreptunghi:(Lungime = " << pd->getOrizontal() << ", latime = " << pd->getVertical() << " ) - (Coordonata x: " << pd->getX() << ", Coordonata y = " << pd->getY() << ")-Aria:" << pd->getOrizontal() * pd->getVertical() << std::endl;
    }
    std::cout << std::endl;
    //raporteaza crescator dupa arie ->polimorfism:
    std::cout << "Lista cu figuri sortate crescator(polimorfism) in functie de arie: " << std::endl;
    for (Figura* fig : controller.raporteazaCrescator()) {
        fig->print();
    }
    std::cout << std::endl;
    //raporteaza crescator dupa arie ->test explicit de tip
    std::cout << "Lista cu figuri sortate crescator(test explicit de tip) in functie de arie: " << std::endl;
    for (Figura* fig : controller.raporteazaCrescator1()) {
        Cerc* cerc = dynamic_cast<Cerc*>(fig);
        if (cerc != nullptr) {
            std::cout << "Cerc:(Raza = " << cerc->getRaza() << " ) - (Coordonata x: " << cerc->getX() << ", Coordonata y = " << cerc->getY() << ")-Aria:" << 3.14 * cerc->getRaza() * cerc->getRaza() << std::endl;
        }
        else {
            Dreptunghi* pd = (Dreptunghi*)fig;
            std::cout << "Dreptunghi:(Lungime = " << pd->getOrizontal() << ", latime = " << pd->getVertical() << " ) - (Coordonata x: " << pd->getX() << ", Coordonata y = " << pd->getY() << ")-Aria:" << pd->getOrizontal() * pd->getVertical() << std::endl;
        }
    }
    std::cout << std::endl;
    //raporteaza stanga dreapta ->polimorfism
    std::cout << "Lista cu figuri sortate de la stanga la dreapta (polimorfism): " << std::endl;
    for (Figura* fig : controller.raporteazaStangaDreapta()) {
        fig->print();
    }
    std::cout << std::endl;
    //raporteaza stanga dreapta ->test explicit de tip
    std::cout << "Lista cu figuri sortate de la stanga la dreapta (test explicit de tip): " << std::endl;
    for (Figura* fig : controller.raporteazaStangaDreapta1()) {
    
        Cerc* cerc = dynamic_cast<Cerc*>(fig);
        if (cerc != nullptr) {
            std::cout << "Cerc:(Raza = " << cerc->getRaza() << " ) - (Coordonata x: " << cerc->getX() << ", Coordonata y = " << cerc->getY() << ")-Aria:" << 3.14 * cerc->getRaza() * cerc->getRaza() << std::endl;
        }
        else {
            Dreptunghi* pd = (Dreptunghi*)fig;
            std::cout << "Dreptunghi:(Lungime = " << pd->getOrizontal() << ", latime = " << pd->getVertical() << " ) - (Coordonata x: " << pd->getX() << ", Coordonata y = " << pd->getY() << ")-Aria:" << pd->getOrizontal() * pd->getVertical() << std::endl;
        }
    }
    //elimina figura de arie mai mica decat o valoare data->polimorfism
    std::cout << std::endl << "Eliminare figura cu arie mai mica decat valoarea data (polimorfism):" << std::endl;
    for (Figura* f : controller.eliminaFigura()) {
        f->print();
    }


return 0 ;
}
