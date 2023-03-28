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

    szachownica * kopia();             //Tworzy niezalezn� kopie szachownicy
    szachownica();                     // Konstruktor bezparametrowy
    szachownica(const szachownica&h);  // Konstruktor od szachownicy
    void wypisz();                     // Wypisuje w konsoli obecn� pozycje
    void wykonajruch(class element_listy* r); // Ta metoda wykonuje ruch kt�ry jest zapisany za pomoca obiektu typu "element_listy"
    void wykonajruch(int wiersz,int kolumna,int n_wiersz,int n_kolumna);  // Ta metoda wykonuje ruch, trzeba najpierw poda� obecne po�o�enie (za pomoc� liczb), nast�pnie pozycj� docelow�
    class lista* mozliwe_ruchy();      // Ta metoda zwraca wska�nik do listy ruch�w kt�re mog� wykonac figury danego koloru
    int czy_pole_pod_biciem(int wiersz, int kolumna,kolor_na_posunieciu kol);  // Ta metoda zwraca wiadomo�� czy dane pole jest atakowane przez figury danego koloru
    int zlicz();         // zlicza ilo�� punkt�w (czarne maj� pkt ujemne bia�e dodatnie)
    int czy_krol_pod_biciem(kolor_na_posunieciu kolor);   // Sprawdzenie czy kr�l jest pod biciem
    kolor_na_posunieciu czyj_ruch;

    class Figure *glowa[8][8];
    private:
    int czy_szach;
    int czy_mat;
};

int ocena(class szachownica* s, int glebokosc);


#endif
