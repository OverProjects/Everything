#include <stdio.h>
#include <stdlib.h>

#include "srcPQ.h"

int display(int tab[7][6])
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            printf(" | "); printf("%d", tab[i][j]);
            if (j == 5) {printf(" |\n");}
        }
    }

    return 0;
}

int PQ_main()
{
    int tab[7][6] = {0};
    display(tab);
    return 0;
}
