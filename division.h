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



DoubleLinkedList createTapeDiv(char c[])
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
    struct state* self;
    struct state* next;
}StateDiv;


void division()
{

    StateDiv* div = (StateDiv*)malloc(sizeof(StateDiv));
    StateDiv* zero = div;
    zero->self = NULL;
    zero->state = 0;

    StateDiv* one = (StateDiv*)malloc(sizeof(StateDiv));
    one->self = NULL;
    one->state = 1;

    StateDiv* two = (StateDiv*)malloc(sizeof(StateDiv));
    two->self = NULL;
    two->state = 2;

    StateDiv* three = (StateDiv*)malloc(sizeof(StateDiv));
    three->self = NULL;
    three->state = 3;

    StateDiv* four = (StateDiv*)malloc(sizeof(StateDiv));
    four->self = NULL;
    four->state = 4;

    StateDiv* five = (StateDiv*)malloc(sizeof(StateDiv));
    five->self = NULL;
    five->state = 5;

    StateDiv* siz = (StateDiv*)malloc(sizeof(StateDiv));
    siz->self = NULL;
    siz->state = 6;

    StateDiv* sev = (StateDiv*)malloc(sizeof(StateDiv));
    sev->self = NULL;
    sev->state = 7;

    StateDiv* ei = (StateDiv*)malloc(sizeof(StateDiv));
    ei->self = NULL;
    ei->state = 8;

    StateDiv* nine = (StateDiv*)malloc(sizeof(StateDiv));
    nine->self = NULL;
    nine->state = 9;

    StateDiv* ten = (StateDiv*)malloc(sizeof(StateDiv));
    nine->self = NULL;
    nine->state = 10;

    StateDiv* halt = (StateDiv*)malloc(sizeof(StateDiv));
    halt->self = NULL;
    halt->state = -1;
    halt->next = NULL;

//connecting them
    zero->self = NULL;
    zero->next = one;
    one->next = two;
    one->self = ten;
    two->self = two;
    two->next = three;
    three->next = four;
    three->self = three;
    four->self = four;
    four->next = five;
    five->next = siz;
    five->self = ei;
    siz->self = siz;
    siz->next = ei;
    //sev->self = sev;
  //  sev->next = five;
    ei->self = ei;
    ei->next = nine;
    nine->self = nine;
    nine->next = one;
    ten->self = ten;
    ten->next = halt;
//

    char a[] = "1111/11";
    DoubleLinkedList tape = createTapeDiv(a);
    Node* pointer = tape.head;
    StateDiv* s = div;
    Node* ptr = tape.head;
        printf("\n");

    while (pointer->next->data== '-' )
    {
        pointer = pointer->next;
    }
    printf("%c",pointer->data );


//func

    while (s->state != -1)
    {
    
         // -/-,R   0->1
        if (s->state == 0 && pointer->data == '-')
        {                      
                  waitFor(1);
                  clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '-';
                           // waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
            pointer = pointer->next;
        }

        // 1/-,R   1->2
       else if (s->state == 1 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '-';
             waitFor(1);
   displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
            pointer = pointer->next;

        } 


            // 1/-,R   1->2
       else if (s->state == 1 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '-';
             waitFor(1);
   displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
            pointer = pointer->next;

        } 


    }
    

}