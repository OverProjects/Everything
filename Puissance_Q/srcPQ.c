#include <stdio.h>
#include <stdlib.h>

//#include "srcPQ.h"

#define col 6
#define row 7

enum{HAUT, HAUTDROITE, DROITE, BASDROITE, BAS, BASGAUCHE, GAUCHE, HAUTGAUCHE};

int display(int tab[row][col])
{
    printf( "---------------------------\n");
    printf( "   1   2   3   4   5   6\n");
    printf( "---------------------------\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf(" | "); printf("%d", tab[i][j]);
            if (j == col - 1) {printf(" |\n");}
        }
    }

    return 0;
}

int checkInLine(int tab[row][col], int i, int j, int direction)
{
    int nbRepetition = 0;
    int tempWinner = 0;
    int tempI = 0;
    int tempJ = 0;

    if (direction == HAUT)
    {
        tempI = 0;
        while (tempI < row || nbRepetition != 4)
        {
            if (tab[tempI][j] == tab[i][j])
                {nbRepetition++;}
            else {nbRepetition = 0;}

            tempI++;
        }
    }

    else if (direction == HAUTDROITE)
    {
        tempI = i; tempJ = j;
        while ((tempI >= 0 && tempJ < col))
            {tempI--; tempJ++;}
        while ((tempI < row && tempJ >= 0) || nbRepetition != 4)
        {
            if (tab[tempI][tempJ] == tab[i][j])
                {nbRepetition++;}
            else {nbRepetition = 0;}

            tempI--;
            tempJ--;
        }
    }

    else if (direction == DROITE)
    {
        tempJ = 0;
        while (tempJ < col || nbRepetition != 4)
        {
            if (tab[i][tempJ] == tab[i][j])
                {nbRepetition++;}
            else {nbRepetition = 0;}

            tempJ++;
        }
    }

    else if (direction == BASDROITE)
    {
        tempI = 0; tempJ = 0;
        while (tempI < row && tempJ < col)
            {tempI++; tempJ++;}
        while ((tempI >= 0 && tempJ >= 0) || nbRepetition != 4)
        {
            if (tab[tempI][tempJ] == tab[i][j])
                {nbRepetition++;}
            else {nbRepetition = 0;}

            tempI--;
            tempJ--;
        }
    }

    else if (direction == BAS)
    {
        tempI = 0;
        while (tempI < row || nbRepetition != 4)
        {
            if (tab[tempI][j] == tab[i][j])
                {nbRepetition++;}
            else {nbRepetition = 0;}
        }
    }

    else if (direction == BASGAUCHE)
    {
        tempI = i; tempJ = j;
        while ((tempI >= 0 && tempJ < col))
            {tempI--; tempJ++;}
        while ((tempI < row && tempJ >= 0) || nbRepetition != 4)
        {
            if (tab[tempI][tempJ] == tab[i][j])
                {nbRepetition++;}
            else {nbRepetition = 0;}

            tempI--;
            tempJ--;
        }
    }

        else if (direction == GAUCHE)
    {
        tempJ = 0;
        while (tempJ < col || nbRepetition != 4)
        {
            if (tab[i][tempJ] == tab[i][j])
                {nbRepetition++;}
            else {nbRepetition = 0;}

            tempJ++;
        }
    }

    else if (direction == HAUTGAUCHE)
    {
        tempI = 0; tempJ = 0;
        while (tempI < row && tempJ < col)
            {tempI++; tempJ++;}
        while ((tempI >= 0 && tempJ >= 0) || nbRepetition != 4)
        {
            if (tab[tempI][tempJ] == tab[i][j])
                {nbRepetition++;}
            else {nbRepetition = 0;}

            tempI--;
            tempJ--;
        }
    }

    if (nbRepetition == 4) {tempWinner = tab[i][j];}

    //for (y = 0; y < row; y++)
      //  for (x = 0; w < col; )

    return tempWinner;
}

int checkWinner(int tab[row][col])
{
    int temp = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (tab[i][j] != 0)
            {
                if (i > 0) // en haut
                    {if (tab[i - 1][j] == tab[i][j]) {temp = checkInLine(tab, i, j, HAUT);}}
                if (i > 0 && j < col - 1) //en haut à droite
                    {if (tab[i - 1][j + 1] == tab[i][j]) {temp = checkInLine(tab, i, j, HAUTDROITE);}}
                if (j < col - 1)  // à droite
                    {if (tab[i][j + 1] == tab[i][j]) {temp = checkInLine(tab, i, j, DROITE);}}
                if (j < col - 1 && i < row - 1)  //en bas à droite
                    {if (tab[i + 1][j + 1] == tab[i][j]) {temp = checkInLine(tab, i, j, BASDROITE);}}
                if (i < row - 1) // en bas
                    {if (tab[i + 1][j] == tab[i][j]) {temp = checkInLine(tab, i, j, BAS);}}
                if (i < row - 1 && j > 0) // en bas à gauche
                    {if (tab[i + 1][j - 1] == tab[i][j]) {temp = checkInLine(tab, i, j, BASGAUCHE);}}
                if (j > 0) // à gauche
                    {if (tab[i][j - 1] == tab[i][j]) {temp = checkInLine(tab, i, j, GAUCHE);}}
                if (i > 0 && j > 0) // en haut à gauche
                    {if (tab[i - 1][j - 1] == tab[i][j]) {temp = checkInLine(tab, i, j, HAUTGAUCHE);}}
            }
        }
    }
    return temp;
}

int PQmain()
{
    int tab[row][col] = {0};
    int winner = 0;
    int player = 1;
    int temp;
    int quitDescent1 = 0;
    int incre = row - 1;

    printf("Welcome to P4, you'll play one by one\n");
    printf("This is the grind\n");
    display(tab);

    while (!winner)
    {
        while (quitDescent1 == 0) // le joueur place un pion
        {
            temp = 0;
            printf("\nplayer %d, ", player); printf("chose your column : ");
            scanf("%d", &temp);
            temp--;

            if (temp < 0 || temp > col - 1) {printf("Try again\n");}

            else if (tab[incre][temp] == 0)
            {
                tab[incre][temp] = player;
                display(tab);
                quitDescent1 = 1;
            }
            else
            {
                incre--;
                if (incre == -1) {printf( "\nColumn impossible");}
            }

        }

        quitDescent1 = 0;

        if (player == 1) {player = 2;}
        else {player = 2;} // on change de joueur

        temp = checkWinner(tab); // algo de check
        if (temp != 0)
        {
            printf("\nEt le gagnant est le joueur %d !\n", temp);
            winner = 1;
        }
    }

    printf("\nAller salut");

    return 0;
}
