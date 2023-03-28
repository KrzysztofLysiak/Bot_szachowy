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

// Aby podaæ ruch musimy pos³ugiwaæ siê cyframi, najpierw podajemy wiersz i kolumne figury któr¹ chcemy siê ruszyæ a nastêpnie podajemy wiersz i kolumnê docelow¹



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

// Funkcja koñczy dzia³anie gdy jeden z królów zostanie zbity:
    while((c.zlicz()<300) && (c.zlicz()>-300)){  // sprawdza czy nie by³o mata
        lista* wpi = c.mozliwe_ruchy(); // Funkcja tworzy mo¿liwe do wykonania ruchy

        for(i=1; i < wpi->rozmiar();i++){ // Funkcja wykonuje mo¿liwe ruchy i od ka¿dego ruchu wywo³uje funkcjê oceny. Ten ruch po którym ocena zwróci³a najwiêksz¹ wartoœæ jest najlepszy i zostanie on potem wykonany
            szachownica* a= c.kopia();
            a->wykonajruch(wpi->zwroc(i));
            j = ocena(a,3);
            if(j > punkty){
                ww=i;
                }
            }
            // Wykonanie ruchu który zosta³ wybrany w petli for:
            c.wykonajruch(wpi->zwroc(ww));
            // Program wypisuje jaki wykona³ ruch:
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
