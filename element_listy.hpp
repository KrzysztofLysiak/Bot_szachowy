#ifndef ELEMENT_LISTY
#define ELEMENT_LISTY

//Tworca projektu: Krzysztof Lysiak

#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <cassert>
#include <conio.h>

// Element listy jest u¿ywany przez klasê lista, klasa lista dodaj¹c kolejny element(tzn. nowy ruch) zapisuje go za pomoc¹ tej klasy.


class element_listy{


public:
    element_listy(int o,int k, int l, int m, int n, int p);
    element_listy* adres();

    element_listy* nast;
    element_listy* pop;
    int rodzaj_figury;
    int kolumna_obecna;
    int wiersz_obecny;
    int kolumna_docelowa;
    int wiersz_docelowy;
    int kolor;
};

#endif // ELEMENT_LISTY
