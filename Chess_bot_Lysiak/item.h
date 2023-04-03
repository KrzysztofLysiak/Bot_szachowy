#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

//Author: Krzysztof Lysiak

#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <cassert>
#include <conio.h>

// This class is used by the class lista. Program uses this class to keep one move in one object of this

class item{


public:
    item(int o,int k, int l, int m, int n, int p);
    item* adres();

    item* nast;
    item* pop;
    int type_of_figure;
    int current_column;
    int current_line;
    int target_column;
    int target_line;
    int kolor;
};

#endif // ITEM_H_INCLUDED
