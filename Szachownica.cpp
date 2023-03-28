#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <cassert>
#include <conio.h>

//Tworca projektu: Krzysztof Lysiak

#include "Szachownica.hpp"

szachownica::szachownica (){
    for(int j=0;j<8;j++)
       {
       glowa[1][j] = new pion(Biale,1,j,P,1);
       glowa[2][j] = new pusto(Brak,2,j,_,0);
       glowa[3][j] = new pusto(Brak,3,j,_,0);
       glowa[4][j] = new pusto(Brak,4,j,_,0);
       glowa[5][j] = new pusto(Brak,5,j,_,0);
       glowa[6][j] = new pion(Czarne,6,j,P,1);
       }

    glowa[0][0]= new wieza(Biale,0,0,W,10);
    glowa[0][1]= new skoczek(Biale,0,1,S,3);
    glowa[0][2]= new goniec(Biale,0,2,G,3);
    glowa[0][3]= new krol(Biale,0,3,K,1000);
    glowa[0][4]= new dama(Biale,0,4,D,10);
    glowa[0][5]= new goniec(Biale,0,5,G,3);
    glowa[0][6]= new skoczek(Biale,0,6,S,3);
    glowa[0][7]= new wieza(Biale,0,7,W,10);

    glowa[7][0]= new wieza(Czarne,7,0,W,10);
    glowa[7][1]= new skoczek(Czarne,7,1,S,3);
    glowa[7][2]= new goniec(Czarne,7,2,G,3);
    glowa[7][3]= new dama(Czarne,7,3,D,10);
    glowa[7][4]= new krol(Czarne,7,4,K,1000);
    glowa[7][5]= new goniec(Czarne,7,5,G,3);
    glowa[7][6]= new skoczek(Czarne,7,6,S,3);
    glowa[7][7]= new wieza(Czarne,7,7,W,10);

    czy_szach = 0;
    czy_mat = 0;
    czyj_ruch = Biale;
    };


szachownica::szachownica(const szachownica& h):czy_szach(h.czy_szach),czy_mat(h.czy_mat),czyj_ruch(h.czyj_ruch),glowa(){
for(int i=0;i<8;i++)
    for(int j=0;j<8;j++)
        {
        if(h.glowa[i][j]->fi==0)
           glowa[i][j]= new krol(h.glowa[i][j]->kolor,i,j,K,1000);
        if(h.glowa[i][j]->fi==1)
           glowa[i][j]= new dama(h.glowa[i][j]->kolor,i,j,D,10);
        if(h.glowa[i][j]->fi==2)
           glowa[i][j]= new wieza(h.glowa[i][j]->kolor,i,j,W,10);
        if(h.glowa[i][j]->fi==3)
           glowa[i][j]= new skoczek(h.glowa[i][j]->kolor,i,j,S,3);
        if(h.glowa[i][j]->fi==4)
           glowa[i][j]= new goniec(h.glowa[i][j]->kolor,i,j,G,3);
        if(h.glowa[i][j]->fi==5)
           glowa[i][j]= new pion(h.glowa[i][j]->kolor,i,j,P,1);
        if(h.glowa[i][j]->fi==6)
           glowa[i][j]= new pusto(Brak,i,j,_,0);
        }
};


szachownica * szachownica::kopia(){
return new szachownica(*this);
}



int szachownica::zlicz(){
int punkty=0;
for(int i=0;i<8;i++)
    for(int j=0;j<8;j++){
        punkty += (glowa[i][j]->punkty);
        }
return punkty;
};

void szachownica::wykonajruch(element_listy* r){
if (glowa[r->wiersz_obecny][r->kolumna_obecna]->fi != 6){
glowa[r->wiersz_docelowy][r->kolumna_docelowa]=glowa[r->wiersz_obecny][r->kolumna_obecna];
glowa[r->wiersz_obecny][r->kolumna_obecna]=new pusto(Brak,r->wiersz_obecny,r->kolumna_obecna,_,0);
glowa[r->wiersz_obecny][r->kolumna_obecna]->punkty=0;
if(czyj_ruch == Biale)
    czyj_ruch= Czarne;
else
    czyj_ruch = Biale;

glowa[r->wiersz_docelowy][r->kolumna_docelowa]->wiersz = r->wiersz_docelowy;
glowa[r->wiersz_docelowy][r->kolumna_docelowa]->kolumna = r->kolumna_docelowa;}
};

int szachownica::czy_krol_pod_biciem(kolor_na_posunieciu kolor){
for(int i=0;i<8;i++)
    for(int j=0;j<8;j++)
        if ((glowa[i][j]->fi == 0)&&(glowa[i][j]->kolor==kolor)){
            return czy_pole_pod_biciem(i,j,kolor);
            }

return 0;
};

int szachownica::czy_pole_pod_biciem(int wiersz, int kolumna, kolor_na_posunieciu kol){
    //// Bicie po przekatnych i diagonaliach

for(int i=0;wiersz+i<8;i++){
    if(glowa[wiersz+i][kolumna]->kolor==kol)
        break;
    if(glowa[wiersz+i][kolumna]->fi==_)
        continue;
    if((glowa[wiersz+i][kolumna]->kolor != kol) && ((glowa[wiersz+i][kolumna]-> fi== D)|| (glowa[wiersz+i][kolumna]-> fi== W))){
        return 0;}
        }

for(int i=0;wiersz-i>0;i++){
    if(glowa[wiersz-i][kolumna]->kolor==kol)
        break;
    if(glowa[wiersz-i][kolumna]->fi==_)
        continue;
    if((glowa[wiersz-i][kolumna]->kolor != kol) && ((glowa[wiersz-i][kolumna]-> fi== D)|| (glowa[wiersz-i][kolumna]-> fi== W))){
        return 0;}
        }

for(int i=0;kolumna-i>0;i++){
    if(glowa[wiersz][kolumna-i]->kolor==kol)
        break;
    if(glowa[wiersz][kolumna-i]->fi==_)
        continue;
    if((glowa[wiersz][kolumna-i]->kolor != kol) && ((glowa[wiersz][kolumna-i]-> fi== D)|| (glowa[wiersz][kolumna-i]-> fi== W))){
        return 0;}
        }

for(int i=0;kolumna+i<8;i++){
    if(glowa[wiersz][kolumna+i]->kolor==kol)
        break;
    if(glowa[wiersz][kolumna+i]->fi==_)
        continue;
    if((glowa[wiersz][kolumna+i]->kolor != kol) && ((glowa[wiersz][kolumna+i]-> fi== D)|| (glowa[wiersz][kolumna+i]-> fi== W))){
        return 0;}
        }

for(int i=0;(kolumna+i<8)&&(wiersz+i<8);i++){
    if(glowa[wiersz+i][kolumna+i]->kolor==kol)
        break;
    if(glowa[wiersz+i][kolumna+i]->fi==_)
        continue;
    if((glowa[wiersz+i][kolumna+i]->kolor != kol) && ((glowa[wiersz+i][kolumna+i]-> fi== D)|| (glowa[wiersz+i][kolumna+i]-> fi== G))){
        return 0;}
        }

for(int i=0;(kolumna+i<8)&&(wiersz-i>0);i++){
    if(glowa[wiersz-i][kolumna+i]->kolor==kol)
        break;
    if(glowa[wiersz-i][kolumna+i]->fi==_)
        continue;
    if((glowa[wiersz-i][kolumna+i]->kolor != kol) && ((glowa[wiersz-i][kolumna+i]-> fi== D)|| (glowa[wiersz-i][kolumna+i]-> fi== G))){
        return 0;}
        }

for(int i=0;(kolumna-i>0)&&(wiersz+i<8);i++){
    if(glowa[wiersz+i][kolumna-i]->kolor==kol)
        break;
    if(glowa[wiersz+i][kolumna-i]->fi==_)
        continue;
    if((glowa[wiersz+i][kolumna-i]->kolor != kol) && ((glowa[wiersz+i][kolumna-i]-> fi== D)|| (glowa[wiersz+i][kolumna-i]-> fi== G))){
        return 0;}
        }

for(int i=0;(kolumna-i>0)&&(wiersz-i>0);i++){
    if(glowa[wiersz-i][kolumna-i]->kolor==kol)
        break;
    if(glowa[wiersz-i][kolumna-i]->fi==_)
        continue;
    if((glowa[wiersz-i][kolumna-i]->kolor != kol) && ((glowa[wiersz-i][kolumna-i]-> fi== D)|| (glowa[wiersz-i][kolumna-i]-> fi== G))){
        return 0;}
        }

// Bicie pionem

if(czyj_ruch == Czarne )
    {
    if((wiersz+1<8)&&(kolumna+1<8)){
        if (((glowa[wiersz+1][kolumna+1]-> fi == P) && (glowa[wiersz+1][kolumna+1]-> kolor == Czarne)))
            return 0;
            }
    if((wiersz+1<8)&&(kolumna+1<8)){
        if ((glowa[wiersz+1][kolumna-1]-> kolor== Czarne)&&(glowa[wiersz+1][kolumna-1]->fi==P))
            return 0;
            }
    }
else
    {
    if((wiersz-1>0)&&(kolumna+1<8)){
        if (((glowa[wiersz-1][kolumna+1]-> fi == P) && (glowa[wiersz-1][kolumna+1]-> kolor == Biale)))
            return 0;
            }
    if((wiersz-1>0)&&(kolumna-1>0)){
        if ((glowa[wiersz-1][kolumna-1]-> kolor== Biale)&&(glowa[wiersz-1][kolumna-1]->fi==P))
            return 0;
            }
    }


//// Bicie królem
if(glowa[wiersz][kolumna]->kolor == Biale ){
        for(int i = -1; i<2;i++)
            for(int j = -1; j<2;j++)
            {
                if(((wiersz+i)>7)||(wiersz+i<0)||(kolumna+j<0)||(kolumna+j)>7)
                    continue;

                if ((glowa[wiersz+i][kolumna+j]-> fi == K ) && (glowa[wiersz+i][kolumna+j]-> kolor == Czarne))
                 return 0;}
}

if(glowa[wiersz][kolumna]->kolor == Czarne ){
        for(int i = -1; i<2;i++)
            for(int j = -1; j<2;j++)
                {
                 if(((wiersz+i)>7)||(wiersz+i<0)||(kolumna+j<0)||(kolumna+j)>7){

                    continue;}
                 if ((glowa[wiersz+i][kolumna+j]-> fi == 0 ) && (glowa[wiersz+i][kolumna+j]-> kolor == Biale)){

                        return 0;}
                }
}

////Bicie skoczkiem

if(glowa[wiersz][kolumna]->kolor != czyj_ruch ){
        if(wiersz+1<8&&kolumna+2<8){
        if((glowa[wiersz+1][kolumna+2]-> fi == S ) && (glowa[wiersz+1][kolumna+2]-> kolor == Biale))
        return 0;}
}
if(glowa[wiersz][kolumna]->kolor != czyj_ruch ){
        if(wiersz+1<8&&kolumna-2>0){
        if ((glowa[wiersz+1][kolumna-2]-> fi == S ) && (glowa[wiersz+1][kolumna+2]-> kolor == Biale))
        return 0;}
}
if(glowa[wiersz][kolumna]->kolor != czyj_ruch ){
        if(wiersz-1>0&&kolumna+2<8){
        if ((glowa[wiersz-1][kolumna+2]-> fi == S ) && (glowa[wiersz+1][kolumna+2]-> kolor == Biale))
        return 0;}
}
if(glowa[wiersz][kolumna]->kolor != czyj_ruch) {
        if(wiersz-1>0&&kolumna-2>0){
        if ((glowa[wiersz-1][kolumna-2]-> fi == S ) && (glowa[wiersz+1][kolumna+2]-> kolor == Biale))
        return 0;}
}
if(glowa[wiersz][kolumna]->kolor != czyj_ruch ){
        if(wiersz+1<8&&kolumna+2<8){
        if ((glowa[wiersz+1][kolumna+2]-> fi == S ) && (glowa[wiersz+1][kolumna+2]-> kolor == Czarne))
        return 0;}
}
if(glowa[wiersz][kolumna]->kolor != czyj_ruch ){
        if(wiersz+1<8&&kolumna-2>0){
        if ((glowa[wiersz+1][kolumna-2]-> fi == S ) && (glowa[wiersz+1][kolumna+2]-> kolor == Czarne))
        return 0;}
}
if(glowa[wiersz][kolumna]->kolor != czyj_ruch ){
        if(wiersz-1>0&&kolumna+2<8){
        if ((glowa[wiersz-1][kolumna+2]-> fi == S ) && (glowa[wiersz+1][kolumna+2]-> kolor == Czarne))
        return 0;}
}
if(glowa[wiersz][kolumna]->kolor != czyj_ruch ){
    if(wiersz-1>0&&kolumna-2>0){
        if ((glowa[wiersz-1][kolumna-2]-> fi == S ) && (glowa[wiersz+1][kolumna+2]-> kolor == Czarne))
    return 0;}
}
return 1;
};

lista *szachownica::mozliwe_ruchy(){
lista* l = new lista(1);
for(int i=0;i<8;i++)
    for(int j=0;j<8;j++){
        if(((glowa[i][j])->kolor!=czyj_ruch)||((glowa[i][j])->fi==_)){
            continue;}
        glowa[i][j]->mozliwe_ruchy(this,l);        // Wywołuje metody konkretnych figur
        }
  return l;
};

void szachownica::wypisz(){


for(int i=0;i<8;i++)
    {
    for(int j=0; j<8;j++)
        {
        if(glowa[i][j]->fi==0){
            std::cout<<"|";
            std::cout<<"K";
            }
        if(glowa[i][j]->fi==1){
            std::cout<<"|";
            std::cout<<"D";
        }
        if(glowa[i][j]->fi==2){
            std::cout<<"|";
            std::cout<<"W";
        }
        if(glowa[i][j]->fi==3){
            std::cout<<"|";
            std::cout<<"S";
        }
        if(glowa[i][j]->fi==4){
            std::cout<<"|";
            std::cout<<"G";
        }
        if(glowa[i][j]->fi==5){
            std::cout<<"|";
            std::cout<<"P";
        }
        if(glowa[i][j]->fi==6){
            std::cout<<"|";
            std::cout<<"_";
        }
        }
        std::cout<<"\n";
    }
};

void szachownica::wykonajruch(int wiersz,int kolumna,int n_wiersz,int n_kolumna){
if(glowa[wiersz][kolumna]->fi!=6){
delete glowa[n_wiersz][n_kolumna];
glowa[n_wiersz][n_kolumna] = glowa[wiersz][kolumna];
glowa[wiersz][kolumna] = new pusto(Brak,wiersz,kolumna,_,0);
glowa[wiersz][kolumna]->punkty = 0;

if(czyj_ruch == Biale)
    czyj_ruch= Czarne;
else
    czyj_ruch = Biale;

glowa[n_wiersz][n_kolumna]->wiersz=n_wiersz;
glowa[n_wiersz][n_kolumna]->kolumna=n_kolumna;}

};


int ocena(szachownica* s,int glebokosc){ // Funkcja oceny pozycji, algorytm oparty jest na schemacie MinMax, wywołujemy rekurencyjnie funkcję oceny, która zwraca ocenę pozycji za pomoca liczby.
                                        //zakładamy że przeciwnik wykonuje najlepsze ruchy i uwzględniając ten warunek funkcja zwraca informację ile najwięcej punktów możemy uzyskać idą tą drogą.

if(glebokosc == 0){ // Gdy wywołamy rekurencyjnie odpowiednią ilość razy naszą funkcje zostaje zliczona pozycja na szachownicy
    return s->zlicz();
}

int i=0;
lista* wti = s->mozliwe_ruchy();  // Tworzy wskaźnik do listy ruchów i nadaje mu adres zwróconej przez metode"mozliwe ruchy" listy

for(int j=1; j<(wti->rozmiar());j++){   // Przpatrujemy wszystkie możliwe ruchy i wybieramy ten zgodny z regułą algorytmu MinMax
    szachownica* z= s->kopia();         // W forze posługujemy się kopiami danej szachownicy i na nich wykonujemy ruchy
    z->wykonajruch(wti->zwroc(j));
    if(z->czyj_ruch==Biale){
        if(j==1)
            i=ocena(z,(glebokosc-1));
        if (ocena(z,(glebokosc-1)) < i){
            i = ocena(z,(glebokosc-1));
        }
    }
    if(z->czyj_ruch==Czarne)
    {
        if(j==1)
            i=ocena(z,(glebokosc-1));
        if (ocena(z,(glebokosc-1)) > i){
            i = ocena(z,(glebokosc-1));
        }
    }
    delete z;
}
delete wti;

return i;

};

