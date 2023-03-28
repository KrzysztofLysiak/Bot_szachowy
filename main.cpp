#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <cassert>
#include <conio.h>

//Tworca projektu: Krzysztof Lysiak

#include "element_listy.hpp"
#include "listaa.hpp"
#include "Szachownica.hpp"
#include "Pionki.hpp"

// Aby poda� ruch musimy pos�ugiwa� si� cyframi, najpierw podajemy wiersz i kolumne figury kt�r� chcemy si� ruszy� a nast�pnie podajemy wiersz i kolumn� docelow�



int main()
{     // Zmienne pomocnicze
int k=0;
int l=0;
int m=0;
int n=0;
int i =1;
int j = 0;
int ww=0;
int punkty=0;
szachownica c;

// Funkcja ko�czy dzia�anie gdy jeden z kr�l�w zostanie zbity:
    while((c.zlicz()<300) && (c.zlicz()>-300)){  // sprawdza czy nie by�o mata
        lista* wpi = c.mozliwe_ruchy(); // Funkcja tworzy mo�liwe do wykonania ruchy

        for(i=1; i < wpi->rozmiar();i++){ // Funkcja wykonuje mo�liwe ruchy i od ka�dego ruchu wywo�uje funkcj� oceny. Ten ruch po kt�rym ocena zwr�ci�a najwi�ksz� warto�� jest najlepszy i zostanie on potem wykonany
            szachownica* a= c.kopia();
            a->wykonajruch(wpi->zwroc(i));
            j = ocena(a,3);
            if(j > punkty){
                ww=i;
                }
            }
            // Wykonanie ruchu kt�ry zosta� wybrany w petli for:
            c.wykonajruch(wpi->zwroc(ww));
            // Program wypisuje jaki wykona� ruch:
            std::cout<<"\n";
            std::cout<<"Moj ruch:";
            std::cout<<"\n";
            std::cout<<wpi->zwroc(ww)->wiersz_obecny;
            std::cout<<wpi->zwroc(ww)->kolumna_obecna;
            std::cout<<"::";
            std::cout<<wpi->zwroc(ww)->wiersz_docelowy;
            std::cout<<wpi->zwroc(ww)->kolumna_docelowa;
            std::cout<<"\n";

            // Ten fragment kodu odpowiada za pobranie ruchu od gracza i wykonanie go:
            c.wypisz();
            std::cout<<"Twoj ruch:";
            std::cout<<"\n";
            std::cin>>k;
            std::cin>>l;
            std::cin>>m;
            std::cin>>n;
            std::cout<<"Wykonalem Twoj ruch";
            std::cout<<"\n";
            c.wykonajruch(k,l,m,n);
    }

    return 0;
}
