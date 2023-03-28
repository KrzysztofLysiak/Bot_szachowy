#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <cassert>
#include <conio.h>

#include "Pionki.hpp"

//Tworca projektu: Krzysztof Lysiak

void Figure::mozliwe_ruchy( szachownica*s, lista*l){};

Figure::Figure(){};

Figure:: Figure(kolor_na_posunieciu color,int wier,int kol,Figura Fig,int punkt){
wiersz = wier;
kolumna = kol;
kolor = color;
fi = Fig;

if (color == Czarne)
    punkty = (-punkt);
else
    punkty =punkt;

};


int ruch:: GG(szachownica* szachownica, lista* lista,int wier_poz,int kol_poz, int wier,int kol,kolor_na_posunieciu kolor){

class szachownica* wti= szachownica->kopia();

if(wier <0 || wier>7 ||kol > 7||kol<0){
     return 0;}

if (wti->glowa[wier][kol]->kolor != kolor){
    wti->wykonajruch(wier_poz,kol_poz,wier,kol);
    }
else
{
    return 0;
}

if(wti->czy_krol_pod_biciem(kolor)==0){
   return 0;}
lista->dowiaz(wti->glowa[wier][kol]->fi,wier_poz ,kol_poz ,wier, kol,kolor);
return 1;
};

int ruch:: sprawdzenie(szachownica* szachownica, lista* lista, int wiersz, int kolumna,kolor_na_posunieciu kolor){
if((kolumna+1)>7)
    return 0;
if((szachownica->glowa[wiersz][kolumna+1]->fi)==6)
        return 1;
if ((szachownica->glowa[wiersz][kolumna+1]->kolor == kolor) || (wiersz <0) || (wiersz >7) || (kolumna <0) || (kolumna+1 >7)){
    lista->zdejmij();
}

return 1;
};

pion:: pion(kolor_na_posunieciu color,int wier,int kol,Figura Fig,int punkt):Figure(color,wier,kol,Fig,punkt){};

void pion:: mozliwe_ruchy(szachownica* s, lista* l){

if(kolor == Biale){
        GG(s, l,wiersz,kolumna,(wiersz+1),kolumna,kolor);
        sprawdzenie(s,l,(wiersz+1),kolumna,kolor);
    }
else
    {
        GG(s, l,wiersz,kolumna,wiersz-1,kolumna,kolor);
        sprawdzenie(s,l,wiersz-1 ,kolumna,kolor);
    }
};

wieza::wieza(kolor_na_posunieciu color,int wier,int kol,Figura Fig,int punkt):Figure(color,wier,kol,Fig,punkt){};

void wieza::mozliwe_ruchy(szachownica* s, lista* l){

for(int i = wiersz; i<8; i++){
    if(GG(s,l,wiersz,kolumna,i+1,kolumna,kolor)==0){
        break;}
    }
for(int i = kolumna; i<8; i++){
    if (GG( s, l,wiersz,kolumna,wiersz,i+1,kolor)==0){
        break;}
    }
for(int i = wiersz; i<8; i--){
    if(GG( s, l,wiersz,kolumna,i-1,kolumna,kolor)==0){
        break;}
    }
for(int i = kolumna; i<8; i--){
    if(GG(s, l,wiersz,kolumna,wiersz,i-1,kolor)==0){
        break;}
    }

};

skoczek::skoczek(kolor_na_posunieciu color,int wier,int kol,Figura Fig,int punkt):Figure(color,wier,kol,Fig,punkt){};

void skoczek::mozliwe_ruchy(szachownica* s, lista* l){

    GG(s,l,wiersz,kolumna,wiersz+2,kolumna+1,kolor);
    GG(s,l,wiersz,kolumna,wiersz+1,kolumna+2,kolor);
    GG(s,l,wiersz,kolumna,wiersz+2,kolumna-1,kolor);
    GG(s,l,wiersz,kolumna,wiersz+1,kolumna-2,kolor);
    GG(s,l,wiersz,kolumna,wiersz-2,kolumna+1,kolor);
    GG(s,l,wiersz,kolumna,wiersz-1,kolumna-2,kolor);
    GG(s,l,wiersz,kolumna,wiersz-2,kolumna-1,kolor);
    GG(s,l,wiersz,kolumna,wiersz-1,kolumna+2,kolor);
};

goniec::goniec(kolor_na_posunieciu color,int wier,int kol,Figura Fig,int punkt):Figure(color,wier,kol,Fig,punkt){};

void goniec::mozliwe_ruchy(szachownica* s, lista* l){

for(int j = 1; ;j++)
    if (GG(s, l,wiersz,kolumna,wiersz+j,kolumna+j,kolor)==0){
          goto next1;}
next1:

for(int j = 1; ;j++)
    if (GG(s, l,wiersz,kolumna,wiersz+j,kolumna-j,kolor)==0){
          goto next2;}
next2:

for(int j = 1; ;j++)
    if (GG(s, l,wiersz,kolumna,wiersz-j,kolumna+j,kolor)==0){
          goto next3;}
next3:

for(int j = 1; ;j++)
    if (GG(s, l,wiersz,kolumna,wiersz-j,kolumna-j,kolor)==0){
          goto next4;}
next4:
;
};

dama::dama(kolor_na_posunieciu color,int wier,int kol,Figura Fig,int punkt):Figure(color,wier,kol,Fig,punkt){};

void dama::mozliwe_ruchy(szachownica* s, lista* l){

for(int j = 1; ;j++)
    if (GG(s, l,wiersz,kolumna,wiersz+j,kolumna+j,kolor)==0){
          goto next1;}
next1:

for(int j = 1; ;j++)
    if (GG(s, l,wiersz,kolumna,wiersz+j,kolumna-j,kolor)==0){
          goto next2;}
next2:

for(int j = 1; ;j++)
    if (GG(s, l,wiersz,kolumna,wiersz-j,kolumna+j,kolor)==0){
          goto next3;}
next3:

for(int j = 1; ;j++)
    if (GG(s, l,wiersz,kolumna,wiersz-j,kolumna-j,kolor)==0){
          goto next4;}
next4:


for(int i = wiersz; i<8; i++){
    if(GG(s,l,wiersz,kolumna,i+1,kolumna,kolor)==0){
        break;}
    }
for(int i = kolumna; i<8; i++){
    if (GG( s, l,wiersz,kolumna,wiersz,i+1,kolor)==0){
        break;}
    }
for(int i = wiersz; i<8; i--){
    if(GG( s, l,wiersz,kolumna,i-1,kolumna,kolor)==0){
        break;}
    }
for(int i = kolumna; i<8; i--){
    if(GG(s, l,wiersz,kolumna,wiersz,i-1,kolor)==0){
        break;}
    }
};

krol::krol(kolor_na_posunieciu color,int wier,int kol,Figura Fig, int punkt):Figure(color,wier,kol,Fig,punkt){};

void krol::mozliwe_ruchy(szachownica* s, lista* l){
    for(int i= -1; i< 2;i++)
        for(int j=-1; j<2;j++){
         if(i==0 && j==0)
            break;
         GG(s,l,wiersz,kolumna,wiersz+i,kolumna+j,kolor);
        }
};

pusto::pusto(kolor_na_posunieciu color,int wier,int kol,Figura Fig, int punkt):Figure(color,wier,kol,Fig,punkt){};

void pusto::mozliwe_ruchy(szachownica* s, lista* l){};


