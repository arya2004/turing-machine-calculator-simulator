#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

#include "doublelinkedlist.h"
#include <time.h>

#define clrscr()// printf("\e[1;1H\e[2J")
void waitFor (unsigned int secs) {
    unsigned int retTime = time(0) ;//+ secs;   // Get finishing time.
    while (time(0) < retTime);               // Loop until it arrives.
}


DoubleLinkedList createTapeFac(char c[])
{   
    int l = 20;
    DoubleLinkedList d = newDoubleLinkedList(d,'-');
    for (int ii = 0; ii < 20; ii++)
{
    d = insertEndDoubleLinkedList(d, '-');
}

for (int i = 0; c[i] != '\0'; i++)
{
    d = insertEndDoubleLinkedList(d, c[i]);
}
    for (int ii = 0; ii < 20; ii++)
{
    d = insertEndDoubleLinkedList(d, '-');
}

    return d;
}

typedef struct state{
    int state;
    struct state* first;//first
    struct state* second;
    struct state* third;
}StateFac;


void factorial()
{
    StateFac* fac = (StateFac*)malloc(sizeof(StateFac));
    StateFac* zero = fac;
    zero->state = 0;

    StateFac* one = (StateFac*)malloc(sizeof(StateFac));
    one->first = NULL;
    one->state = 1;

        StateFac* two = (StateFac*)malloc(sizeof(StateFac));
    two->first = NULL;
    two->state = 2;

        StateFac* three = (StateFac*)malloc(sizeof(StateFac));
    three->first = NULL;
    three->state = 3;

        StateFac* four = (StateFac*)malloc(sizeof(StateFac));
    four->first = NULL;
    four->state = 4;

        StateFac* five = (StateFac*)malloc(sizeof(StateFac));
    five->first = NULL;
    five->state = 5;

        StateFac* six = (StateFac*)malloc(sizeof(StateFac));
    six->first = NULL;
    six->state = 6;

        StateFac*seven = (StateFac*)malloc(sizeof(StateFac));
    seven->first = NULL;
    seven->state = 7;

        StateFac* eight = (StateFac*)malloc(sizeof(StateFac));
    eight->first = NULL;
    eight->state = 8;

        StateFac* nine = (StateFac*)malloc(sizeof(StateFac));
    nine->first = NULL;
    nine->state = 9;

        StateFac* ten = (StateFac*)malloc(sizeof(StateFac));
    ten->first = NULL;
    ten->state = 10;

        StateFac* eleven = (StateFac*)malloc(sizeof(StateFac));
    eleven->first = NULL;
    eleven->state = 11;

        StateFac* twelve = (StateFac*)malloc(sizeof(StateFac));
    twelve->first = NULL;
    twelve->state = 12;

        StateFac* thirteen = (StateFac*)malloc(sizeof(StateFac));
    thirteen->first = NULL;
    thirteen->state = 13;

        StateFac* forteen = (StateFac*)malloc(sizeof(StateFac));
    forteen->first = NULL;
    forteen->state = 14;

        StateFac* fifteen = (StateFac*)malloc(sizeof(StateFac));
    fifteen->first = NULL;
    fifteen->state = 15;

        StateFac* sixteen = (StateFac*)malloc(sizeof(StateFac));
    sixteen->first = NULL;
    sixteen->state = 16;

        StateFac* seventeen = (StateFac*)malloc(sizeof(StateFac));
    seventeen->first = NULL;
    seventeen->state = 17;

        StateFac* eighteen = (StateFac*)malloc(sizeof(StateFac));
    eighteen->first = NULL;
    eighteen->state = 18;

        StateFac* nineteen = (StateFac*)malloc(sizeof(StateFac));
    nineteen->first = NULL;
    nineteen->state = 19;

        StateFac* twenty = (StateFac*)malloc(sizeof(StateFac));
    twenty->first = NULL;
    twenty->state = 20;

        StateFac* twentyone = (StateFac*)malloc(sizeof(StateFac));
    twentyone->first = NULL;
    twentyone->state = 21;

        StateFac* twentytwo = (StateFac*)malloc(sizeof(StateFac));
    twentytwo->first = NULL;
    twentytwo->state = 22;


        StateFac* twentythree = (StateFac*)malloc(sizeof(StateFac));
    twentythree->first = NULL;
    twentythree->state = 23;

        StateFac* twentfour = (StateFac*)malloc(sizeof(StateFac));
    twentfour->first = NULL;
    twentfour->state = 24;

        StateFac* twentfive = (StateFac*)malloc(sizeof(StateFac));
    twentfive->first = NULL;
    twentfive->state = 25;
//connecting them
    zero->first = zero;
    zero->second = one;
    one->second = two;
    one->first = one;
    two->first = three;
    two->second = five;
    three->second = four;
    three->first = three;
    four->first = four;
    four->second = two;
    five->second = seven;
    five->first = five;
    six->first = six;
    six->second = sixteen;
    seven->first = seven;
    seven->second = eight;
    eight->first = nine;
    //ei->second = nine;
    nine->first = six;
    nine->second = ten;
    ten->first = ten;
    ten->second = eleven;
    eleven->first= twelve;
    eleven->second = forteen;
    twelve->first = twelve;
    twelve->second = thirteen;
    thirteen->first = thirteen;
    thirteen->second = eleven;
    forteen->first = forteen;
    forteen->second = fifteen;
    fifteen->first = fifteen;
    fifteen->second = nine;
    sixteen->first = seventeen;
    sixteen->second = twentfive;
    seventeen->first = eighteen;
    seventeen->second = nineteen;
    eighteen->first = eighteen;
    eighteen->second = twentytwo;
    eighteen->third = twentfour;
    nineteen->first = nineteen;
    nineteen->second = twenty;
    twenty->first = twenty;
    twenty->second = twentyone;
    twentyone->first = twentyone;
    twentyone->second = five;
    twentytwo->first= twentytwo;
    twentytwo->second = twentythree;
    twentythree->first = twentythree;
    twentythree->second = nine;
    twentfour->first = NULL;


    


}