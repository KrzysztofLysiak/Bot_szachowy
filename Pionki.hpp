
#ifndef PIONKI
#define PIONKI

//Tworca projektu: Krzysztof Lysiak


enum Figura{K,D,W,S,G,P,_};
enum kolor_na_posunieciu{Biale,Czarne,Brak};


#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <cassert>
#include <conio.h>


#include "Szachownica.hpp"
#include "listaa.hpp"
#include "element_listy.hpp"

// Klasy Figure i ruch s¹ klasami podstawowymi, natomiast konkretne pionki dziedzicz¹ po obu tych klasach


class Figure{

public:
Figure();
Figure(kolor_na_posunieciu color,int wier,int kol,Figura Fig,int punkty);
virtual void mozliwe_ruchy(class szachownica*s,class lista*l);  // Ta metoda wirtualna jest potrzebna po to aby w linii 284 "Szachownica.cpp"mo¿na by³o wywo³aæ konkretne metody klas pochodnych
Figura fi;                      // Informacja jaka to figura
kolor_na_posunieciu kolor;      // Informacja jaki kolor ma figura

int wiersz;    // Te wartoœci reprezentuj¹ pozycje i iloœæ punktów danej figury
int kolumna;
int punkty;
};


class ruch{
protected:
int GG(class szachownica* szachownica, lista* lista,int wier_poz,int kol_poz, int wiersz,int kolumna,kolor_na_posunieciu kolor); // Ta metoda sprawdza czy mo¿na dany ruch wykonaæ(tzn.czy dany ruch nie powoduje szacha na w³asnym królu) oraz czy nie natknêliœmy siê na figurê, jezeli tak zwraca 0)
int sprawdzenie(szachownica* szachownica, lista* lista, int i, int j,kolor_na_posunieciu kolor);  // Ta metoda przydatna jest w przypadku pionka, aby zobaczyæ czy nie natkn¹³ siê on na inn¹ figurê
};



// Klasy pochodne po Figure i ruch, reprezentuj¹ poszczególne figury oraz maj¹ mo¿liwoœæ zwrócenia jakie mog¹ wykonaæ ruchy za pomoc¹ metody "mozliwe_ruchy"

class skoczek :public ruch ,public Figure{
public:
skoczek(kolor_na_posunieciu,int,int,Figura,int punkt);
void mozliwe_ruchy(szachownica*, lista*);
};

class krol :public ruch ,public Figure{
public:
krol(kolor_na_posunieciu,int,int,Figura,int punkt);
void mozliwe_ruchy(szachownica*, lista*);
};

class dama :public ruch ,public Figure{
public:
dama(kolor_na_posunieciu,int,int,Figura,int punkt);
void mozliwe_ruchy(szachownica*, lista*);
};

class goniec :public ruch ,public Figure{
public:
goniec(kolor_na_posunieciu,int,int,Figura,int punkt);
void mozliwe_ruchy(szachownica*, lista*);
};

class wieza :public ruch ,public Figure{
public:
wieza(kolor_na_posunieciu,int,int,Figura,int punkt);
void mozliwe_ruchy(szachownica*, lista*);
};

class pion : public ruch , public Figure{
public:
pion(const pion& p);
pion(kolor_na_posunieciu,int,int,Figura,int punkt);
void mozliwe_ruchy(szachownica*, lista*);
};

class pusto :public ruch ,public Figure{ // ta klasa reprezentuje puste pole
public:
pusto(kolor_na_posunieciu,int,int,Figura,int punkt);
void mozliwe_ruchy(szachownica*, lista*);
};


#endif
