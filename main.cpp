#include <stdio.h>
#include <stdlib.h>

bool display(int tab[7][6])
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            printf(" | "); printf("%d", tab[i][j]);
            if (j == 5) {printf(" |\n");}
        }
    }
    return true;
}

int main(int argc, char** argv)
{
    int tab[7][6] = {0};
    if (!display(tab)) {printf("Impossible de récupérer le tableau");}
    return 0;
}
