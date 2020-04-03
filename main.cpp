#include <stdio.h>
#include <stdlib.h>

#include "Puissance_Q/srcPQ.c"



int main(int argc, char** argv)
{
    int temp;
    printf("1. Puissance Quatre\n");
    printf("2. Allumettes\n");
    printf("3. Pendu\n");
    printf("4. Master Mind\n");
    printf("5. Bataille navale\n");
    printf("Your choice : ");
    scanf("%d", &temp);

    switch (temp)
    {
        case 1 : PQmain(); break;
        case 2 : break;
        case 3 : break;
        case 4 : break;
        case 5 : break;
        default : break;
    }



    return 0;
}
