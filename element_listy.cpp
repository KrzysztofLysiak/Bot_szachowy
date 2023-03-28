#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <cassert>
#include <conio.h>

#include "element_listy.hpp"

//Tworca projektu: Krzysztof Lysiak


element_listy::element_listy(int o,int k, int l, int m, int n, int p){   //KONSTRUKTOR
    nast = NULL;
    pop = NULL;
    kolumna_obecna = l;
    wiersz_obecny = k;
    kolumna_docelowa = n;
    wiersz_docelowy = m;
    rodzaj_figury = o;
    kolor =p;
};

class element_listy* element_listy::adres(){return this;};     //Zwraca adres obecnego elementu


