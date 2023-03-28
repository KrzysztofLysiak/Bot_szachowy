#ifndef SZACHOWNICA
#define SZACHOWNICA

//Tworca projektu: Krzysztof Lysiak

#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <cassert>
#include <conio.h>

#include "Pionki.hpp"
#include "listaa.hpp"
#include "element_listy.hpp"


class szachownica{

friend class lista;
friend int ocena(szachownica* s, int glebokosc);
friend class ruch;

public:

    szachownica * kopia();             //Tworzy niezalezn¹ kopie szachownicy
    szachownica();                     // Konstruktor bezparametrowy
    szachownica(const szachownica&h);  // Konstruktor od szachownicy
    void wypisz();                     // Wypisuje w konsoli obecn¹ pozycje
    void wykonajruch(class element_listy* r); // Ta metoda wykonuje ruch który jest zapisany za pomoca obiektu typu "element_listy"
    void wykonajruch(int wiersz,int kolumna,int n_wiersz,int n_kolumna);  // Ta metoda wykonuje ruch, trzeba najpierw podaæ obecne po³o¿enie (za pomoc¹ liczb), nastêpnie pozycjê docelow¹
    class lista* mozliwe_ruchy();      // Ta metoda zwraca wskaŸnik do listy ruchów które mog¹ wykonac figury danego koloru
    int czy_pole_pod_biciem(int wiersz, int kolumna,kolor_na_posunieciu kol);  // Ta metoda zwraca wiadomoœæ czy dane pole jest atakowane przez figury danego koloru
    int zlicz();         // zlicza iloœæ punktów (czarne maj¹ pkt ujemne bia³e dodatnie)
    int czy_krol_pod_biciem(kolor_na_posunieciu kolor);   // Sprawdzenie czy król jest pod biciem
    kolor_na_posunieciu czyj_ruch;

    class Figure *glowa[8][8];
    private:
    int czy_szach;
    int czy_mat;
};

int ocena(class szachownica* s, int glebokosc);


#endif
