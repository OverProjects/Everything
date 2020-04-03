#include <stdio.h>
#include <stdlib.h>

#include "Puissance_Q/srcPQ.h"



int main(int argc, char** argv)
{
    int temp;
    printf("1. Puissance Quatre\n");
    printf("Your choice : ");
    scanf("%d", &temp);

    switch (temp)
    {
        case 1: PQ_main(); break;
        default : break;
    }



    return 0;
}
