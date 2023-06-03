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
#define clrscr() //printf("\e[1;1H\e[2J")
void waitFor (unsigned int secs) {
    unsigned int retTime = time(0);// + secs;   // Get finishing time.
    while (time(0) < retTime);               // Loop until it arrives.
}


DoubleLinkedList createTapeAdd(char c[])
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

typedef struct stateadd{
    int state;
    struct stateadd* self;
    struct stateadd* next;
}StateAdd;


void addition()
{
    StateAdd*add = (StateAdd*)malloc(sizeof(StateAdd));
    StateAdd* zero = add;
    zero->self = NULL;
    zero->state = 0;

    StateAdd* one = (StateAdd*)malloc(sizeof(StateAdd));
    one->self = NULL;
    one->state = 1;

    StateAdd* two = (StateAdd*)malloc(sizeof(StateAdd));
    two->self = NULL;
    two->state = 2;

    StateAdd* three = (StateAdd*)malloc(sizeof(StateAdd));
    three->self = NULL;
    three->state = 3;

    StateAdd* four = (StateAdd*)malloc(sizeof(StateAdd));
    four->self = NULL;
    four->state = -1;


    //connecting them
    zero->self = NULL;
    zero->next = one;
    one->next = two;
    one->self = one;
    two->self = two;
    two->next = three;
    three->next = four;
    three->self = three;
    four->self = NULL;
    four->next = NULL;


//

    char a[] = "11111+111";
    DoubleLinkedList tape = createTapeAdd(a);
    Node* pointer = tape.head;
    StateAdd* s = add;
    Node* ptr = tape.head;
        printf("\n");

    while (pointer->next->data== '-' )
    {
        pointer = pointer->next;
    }
    printf("%c",pointer->data );

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

        // 1/1,R   1->1
       else if (s->state == 1 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            // waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->self;
            pointer = pointer->next;

        } 

        // +/1,R   1->2
       else if (s->state == 1 && pointer->data == '+')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
             waitFor(1);
   displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
            pointer = pointer->next;

        } 

        // 1/1,R   2->2
       else if (s->state == 2 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            // waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->self;
            pointer = pointer->next;

        } 

        // -/-,L   2->3
       else if (s->state == 2 && pointer->data == '-')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '-';
            // waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
            pointer = pointer->previous;

        } 

        // 1/-,S  3->4
       else if (s->state == 3 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '-';
             waitFor(1);
   displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
            //pointer = pointer->next;

        } 

    }
    
}
