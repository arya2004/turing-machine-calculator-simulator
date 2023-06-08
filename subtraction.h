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
  
    unsigned int retTime = time(0);// + secs; 
    while (time(0) < retTime);   
     clrscr() ; 
}     
DoubleLinkedList createTapeSub(char c[])
{  
    int l = 20;
    DoubleLinkedList d = newDoubleLinkedList(d,' ');
    for (int ii = 0; ii < 20; ii++)
{
    d = insertEndDoubleLinkedList(d, ' ');
}

for (int i = 0; c[i] != '\0'; i++)
{
    d = insertEndDoubleLinkedList(d, c[i]);
}
    for (int ii = 0; ii < 20; ii++)
{
    d = insertEndDoubleLinkedList(d, ' ');
}

    return d;
}

typedef struct statess{
    int state;
    struct statess* self;
    struct statess* next;
}StateSub;

void subtraction()
{

    StateSub* ss = (StateSub*)malloc(sizeof(StateSub));
    StateSub* createhelper = ss;
    createhelper->self = NULL;
    createhelper->state = 0;

    
    createhelper->next = (StateSub*)malloc(sizeof(StateSub));
    createhelper = createhelper->next;
    createhelper->self = NULL;
    createhelper->state = 1;
    StateSub* oneptr = createhelper;

    createhelper->next = (StateSub*)malloc(sizeof(StateSub));
    createhelper = createhelper->next;
    createhelper->self = createhelper;
    createhelper->state = 2;


    createhelper->next = (StateSub*)malloc(sizeof(StateSub));
    createhelper = createhelper->next;
    createhelper->self = createhelper;
    createhelper->state = 3;


    createhelper->next = (StateSub*)malloc(sizeof(StateSub));
    createhelper = createhelper->next;
    createhelper->self = NULL;
    createhelper->state = 4;


    createhelper->next = (StateSub*)malloc(sizeof(StateSub));
    createhelper = createhelper->next;
    StateSub* fiveptr = createhelper;
    createhelper->state = 5;
    createhelper->self = (StateSub*)malloc(sizeof(StateSub));
    createhelper = createhelper->self;
    StateSub* haltptr = createhelper;

    createhelper->self = NULL;
    createhelper->state = -1;
    createhelper->next = NULL;

    createhelper = fiveptr;

    createhelper->next = (StateSub*)malloc(sizeof(StateSub));
    createhelper = createhelper->next;
    createhelper->self = createhelper;
    createhelper->state = 6;

    createhelper->next = (StateSub*)malloc(sizeof(StateSub));
    createhelper = createhelper->next;
    createhelper->self = haltptr; // points at halt -1
    createhelper->state = 7;

    StateSub* svnptr = createhelper;

    createhelper->next = (StateSub*)malloc(sizeof(StateSub));
    createhelper = createhelper->next;
    createhelper->self = createhelper;
    createhelper->state = 8;

    createhelper->next = oneptr;


    char a[] = "111111-11";
    DoubleLinkedList tape = createTapeSub(a);
    Node* pointer = tape.head;
    StateSub* s = ss;
    Node* ptr = tape.head;
    printf("\n");
    while (pointer->next->data== ' ' )
    {
        pointer = pointer->next;
    }
    printf("%c",pointer->data );

    //func
    while (s->state != -1)
    {   // -/-,R   0->1
        if (s->state == 0 && pointer->data == ' ')
        {                      
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = ' ';
            s = s->next;
            pointer = pointer->next;
        }

        // 1/-,R   1->2
        else if (s->state == 1 && pointer->data == '1')
        {                           
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = ' ';
            waitFor(1);
            displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
            pointer = pointer->next;

        }
        // 1/1,r  2->2
        else if (s->state == 2 && pointer->data == '1')
        {                           
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            s = s->self;
            pointer = pointer->next;

        }

        // -/-,r  2->3
        else   if (s->state == 2 && pointer->data == '-')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '-';
            s = s->next;
            pointer = pointer->next;

        }

        // 1/1,r   3->3
        else  if (s->state == 3 && pointer->data == '1')
        {                            
            waitFor(1);
             displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            s = s->self;
            pointer = pointer->next;

        }

        // -/-,L  3->4
        else   if (s->state == 3 && pointer->data == ' ')
        {                          
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = ' ';
            s = s->next;
            pointer = pointer->previous;

        }

        // 1/-,L  4->5
        else   if (s->state == 4 && pointer->data == '1')
        {                           
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = ' ';
            waitFor(1);
            displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
            pointer = pointer->previous;

        }
    
        // +/-,n  5->halt
        else   if (s->state == 5 && pointer->data == '-')
        {                           
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = ' ';
            waitFor(1);
            displayDoubleLinkekdList1(tape, pointer);
            s = s->self; //halt
        }

        // 1/1,L  5->6
        else   if (s->state == 5 && pointer->data == '1')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            s = s->next;
            pointer = pointer->previous;

        }

        // 1/1,L  6->6
        else   if (s->state == 6 && pointer->data == '1')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            s = s->self;
            pointer = pointer->previous;

        }

        // +/+,L  6-7
        else   if (s->state == 6 && pointer->data == '-')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '-';
            s = s->next;
            pointer = pointer->previous;

        }   

        // -/-,S  7->halt
        else   if (s->state == 7 && pointer->data == ' ')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = ' ';
            s = s->self; //halt

        }

        // 1/1,L  7->8
        else   if (s->state == 7 && pointer->data == '1')
        {                           
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            s = s->next;
            pointer = pointer->previous;

        }

        // 1/1,L  8->8
        else   if (s->state == 8 && pointer->data == '1')
        {                           
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            s = s->self;
            pointer = pointer->previous;

        }    

        // -/-,r  8->1
        else   if (s->state == 8 && pointer->data == ' ')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = ' ';
            s = s->next;
            pointer = pointer->next;

        }
    }
    displayDoubleLinkekdList1(tape, pointer);
    tape = dropLinkedList(tape);
}
