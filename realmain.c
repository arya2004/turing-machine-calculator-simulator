#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include <time.h>
#include "doublelinkedlist.h"
#include"subtraction.h"
#include "multiplication.h"
#include "factorial.h"
#include "division.h"
#include "addition.h"
// int main()
// {
//     //division();
//    // multiplication();
//    //factorial();
//    addition();
//     return 0;
// }

int main()
{
    
    int n=0;
    int c = 1;
    
    int choice;
    while (c)
    {
        printf("\n\t\t* * * MENU * * *");
        printf("\n1:add");
        printf("\n2.sub");
        printf("\n3.mul ");
        printf("\n4.div");
        printf("\n5.faactorial");
        printf("\n6.bin inc");
        printf("\n0.exit");
        printf("\n\n give your choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                addition();
                break;
            case 2:
                subtraction();
                break;
            case 3:
                 multiplication();
                break;
            case 4:
                division();
                break;
            case 5:
                factorial();
                break;
            case 6:
                
                break;

            case 0:
             c = 0;
        }

    }
       


    
}