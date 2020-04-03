#include <stdio.h>
#include <stdlib.h>

//#include "srcPQ.h"

#define col 6
#define row 7

int display(int tab[col][row])
{
    printf( "   1   2   3   4   5   6   7\n");
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            printf(" | "); printf("%d", tab[i][j]);
            if (j == col) {printf(" |\n");}
        }
    }

    return 0;
}

int PQmain()
{
    int tab[col][row] = {0};
    int winner = 0;
    int player = 1;
    int temp;
    bool quitDescent1 = false;
    bool quitDescent2 = false;

    printf("Welcome to P4, you'll play one by one\n");
    printf("This is the grind\n");
    display(tab);

    while (!winner)
    {

        printf("player %d, ", player); printf("chose your column : ");
        scanf("%d", temp);

        int i = row
        //jsuis bouré
        while (!quitDescent1)
        {
            if (tab[temp][i] == 0) {tab[temp][i] = player; quitDescent1 = true}
            else {i--;}

            if (i = -1) {printf( "column impossible");}
        }

        for (int i = row; i != 0; i--)
        {
            if (tab[temp][row] == 0) {tab[temp][row] = player;}
        }

        //jusque la
        player += 1;
        if (player > 2) {player = 1;}
    }

    return 0;
}
