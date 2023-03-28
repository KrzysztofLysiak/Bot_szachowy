#ifndef LISTAA
#define LISTAA

//Tworca projektu: Krzysztof Lysiak

#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <cassert>
#include <conio.h>

#include "Pionki.hpp"
#include "element_listy.hpp"
#include "Szachownica.hpp"


class lista{

public:

    lista(int element);   // konstruktor, tworzy pierwszy element listy o podanej warto�ci
    int rozmiar();        // Zwraca rozmiar listy
    class element_listy* zwroc(int k);      // Zwraca wska�nik do i-tego elementu listy (iteracja od 1)
    void dowiaz(Figura fig, int k, int l, int m, int n, int p);  // Tworzy nowy "element_listy" i dowi�zuje go do obecnej listy
    void zdejmij();   // Zdejmuje ostatni element na li�cie

private:
    class element_listy* glowa;     //  adres 1 elementu listy
    class element_listy* ogon;      // adres ostatniego elementu
    int counter;                    // ilo�� elemetn�w listy (iteracja od 1)
};
#endif
