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


DoubleLinkedList createTapeMul(char c[])
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
}StateMul;

void multiplication()
{

    StateMul* mul = (StateMul*)malloc(sizeof(StateMul));
    StateMul* zero = mul;
    zero->self = NULL;
    zero->state = 0;

    StateMul* one = (StateMul*)malloc(sizeof(StateMul));
    one->self = NULL;
    one->state = 1;

    StateMul* two = (StateMul*)malloc(sizeof(StateMul));
    two->self = NULL;
    two->state = 2;

    StateMul* three = (StateMul*)malloc(sizeof(StateMul));
    three->self = NULL;
    three->state = 3;

    StateMul* four = (StateMul*)malloc(sizeof(StateMul));
    four->self = NULL;
    four->state = 4;

    StateMul* five = (StateMul*)malloc(sizeof(StateMul));
    five->self = NULL;
    five->state = 5;

    StateMul* siz = (StateMul*)malloc(sizeof(StateMul));
    siz->self = NULL;
    siz->state = 6;

    StateMul* sev = (StateMul*)malloc(sizeof(StateMul));
    sev->self = NULL;
    sev->state = 7;

    StateMul* ei = (StateMul*)malloc(sizeof(StateMul));
    ei->self = NULL;
    ei->state = 8;

    StateMul* nine = (StateMul*)malloc(sizeof(StateMul));
    nine->self = NULL;
    nine->state = 9;

    StateMul* halt = (StateMul*)malloc(sizeof(StateMul));
    halt->self = NULL;
    halt->state = -1;
    halt->next = NULL;

//connecting them
    zero->self = NULL;
    zero->next = one;
    one->next = four;
    one->self = two;
    two->self = two;
    two->next = three;
    three->next = halt;
    three->self = NULL;
    four->self = four;
    four->next = five;
    five->next = siz;
    five->self = ei;
    siz->self = siz;
    siz->next = sev;
    sev->self = sev;
    sev->next = five;
    ei->self = ei;
    ei->next = nine;
    nine->self = nine;
    nine->next = zero;

    
//

    char a[] = "111*111";
    DoubleLinkedList tape = createTapeMul(a);
    Node* pointer = tape.head;
    StateMul* s = mul;
    Node* ptr = tape.head;
        printf("\n");

    while (pointer->data== '-' )
    {
        pointer = pointer->next;
    }
    printf("%c",pointer->data );

    //func

    while (s->state != -1)
    {   // 1/-,R   0->1
        if (s->state == 0 && pointer->data == '1')
        {                      
                  waitFor(1);
                  clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '-';
                            waitFor(1);
   displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
            pointer = pointer->next;
        }

        // 1/1,R   1->4
       else if (s->state == 1 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            // waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
            pointer = pointer->next;

        } 

                // 1/1,R   4->4
       else if (s->state == 4 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            // waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->self;
            pointer = pointer->next;

        }  

                // */*,R   4->5
       else if (s->state == 4 && pointer->data == '*')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '*';
            // waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
            pointer = pointer->next;

        }   

                // 1/E,R   5->6
       else if (s->state == 5 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = 'E';
             waitFor(1);
   displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
            pointer = pointer->next;

        }   

                // 1/1,R   6->6
       else if (s->state == 6 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            // waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->self;
            pointer = pointer->next;

        }   

                // Z/Z,R   6->6
       else if (s->state == 6 && pointer->data == 'Z')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = 'Z';
            // waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->self;
            pointer = pointer->next;

        }   

                // -/Z,L   6->7
       else if (s->state == 6 && pointer->data == '-')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = 'Z';
             waitFor(1);
  displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
            pointer = pointer->previous;

        }   

                // 1/1,L   7->7
       else if (s->state == 7 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            // waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->self;
            pointer = pointer->previous;

        }   


                // Z/Z,L   7->7
       else if (s->state == 7 && pointer->data == 'Z')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = 'Z';
            // waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->self;
            pointer = pointer->previous;

        }   

                // E/E,R   7->5
       else if (s->state == 7 && pointer->data == 'E')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = 'E';
            // waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
            pointer = pointer->next;

        }   

                // Z/Z,L   5->8
       else if (s->state == 5 && pointer->data == 'Z')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = 'Z';
            // waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->self;
            pointer = pointer->previous;

        }   

                // E/1,L   8->8
       else if (s->state == 8 && pointer->data == 'E')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
             waitFor(1);
   displayDoubleLinkekdList1(tape, pointer);
            s = s->self;
            pointer = pointer->previous;

        }   

                // */*,L   8->9
       else if (s->state == 8 && pointer->data == '*')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '*';
            // waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
            pointer = pointer->previous;

        }   

                // 1/1,L   9->9
       else if (s->state == 9 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            // waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->self;
            pointer = pointer->previous;

        }   

                // -/-,R   9->0
       else if (s->state == 9 && pointer->data == '-')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '-';
            // waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
            pointer = pointer->next;

        }   

                // */1,R   1->2
       else if (s->state == 1 && pointer->data == '*')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
             waitFor(1);
   displayDoubleLinkekdList1(tape, pointer);
            s = s->self;
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

                // Z/1,R   2->2
       else if (s->state == 2 && pointer->data == 'Z')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
             waitFor(1);
  displayDoubleLinkekdList1(tape, pointer);
            s = s->self;
            pointer = pointer->next;

        }   

                // -/-,L  2->3
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

                // 1/#,S   3->-1
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
displayDoubleLinkekdList1(tape, pointer);

    
    
}