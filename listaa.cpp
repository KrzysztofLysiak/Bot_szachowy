#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <cassert>
#include <conio.h>

//Tworca projektu: Krzysztof Lysiak

#include "listaa.hpp"

lista::lista(int element){                //KONSTRUKTOR
        element_listy *pierwszy = new element_listy( element, element, element, element, element, element); //tworzy 1 element listy
        glowa = pierwszy->adres(); //przypisuje glowie adres 1 elementu
        ogon = glowa;//przypisuje ogonowi adres 1 elementu
        counter=1;
}

int lista::rozmiar(){return counter;}    //rozmiar listy

class element_listy* lista::zwroc(int l){                 //zwraca k-ty element listy
    int k =0;
    if(l==0)
        k=1;
    else
        k=l;

    element_listy *wskaznik_docelowy = glowa;
        if (k<0 || k> counter){
                std :: cout<< "blad";
                return 0;
        }

        for(;k >0;k--)
        {
            wskaznik_docelowy = wskaznik_docelowy->nast;
        }
    return (wskaznik_docelowy->adres());
}

void lista::dowiaz(Figura fig,int k, int l, int m, int n, int p){

        element_listy *wsk = new element_listy(fig,k,l,m,n,p); //tworzymy element listy i przypisuje go wskaŸnikowi wsk.
        (wsk->pop) = ogon; //przypisuje elementowi listy poprzednik
        ogon -> nast = wsk; //Przypisuje wartoœæ ostatniemu elementowi listy adres nowego elementu
        ogon = wsk; //przypisuje ogonowi listy koñcowy adres
        counter++;
}

void lista::zdejmij(){
    if (counter == 1)
    ;
    else
    {element_listy* wsk1 = ogon->pop; //przypisuje elementowi listy poprzednik
    wsk1->nast = wsk1->adres(); //Przypisuje wartoœæ ostatniemu elementowi listy adres nowego elementu
    counter--;}
}
