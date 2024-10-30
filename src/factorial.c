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

#define clrscr() printf("\e[1;1H\e[2J")
void waitFor (unsigned int secs) {

    unsigned int retTime = time(0);// + secs;
    while (time(0) < retTime);
    clrscr() ;
}
DoubleLinkedList createTapeFac(char c[])
{
    int l = 20;
    DoubleLinkedList d = newDoubleLinkedList(d,' ');
    for (int ii = 0; ii < 10; ii++)
{
    d = insertEndDoubleLinkedList(d, ' ');
}

for (int i = 0; c[i] != '\0'; i++)
{
    d = insertEndDoubleLinkedList(d, c[i]);
}
    for (int ii = 0; ii < 500; ii++)
{
    d = insertEndDoubleLinkedList(d, ' ');
}

    return d;
}

typedef struct state{
    int state;
    struct state* first;//first
    struct state* second;
    struct state* third;
}StateFac;

StateFac *createStateFac(int state) {
    StateFac *new_state = (StateFac *)malloc(sizeof(StateFac));
    if (new_state = NULL) {
        perror("Memory allocation failed");
        exit(1);
    }

    new_state->state = state;
    new_state->first = NULL;
    new_state->second = NULL;
    new_state->third = NULL;

    return new_state;
}
void assign(StateFac *StateFacs, int index, int first, int second, int third) {
    StateFacs[index]->first = first != -1 ? StateFacs[first] : NULL;
    StateFacs[index]->second = second != -1 ? StateFacs[second] : NULL;
    StateFacs[index]->third = third != -1 ? StateFacs[third] : NULL;
}

void display(int type){
    waitFor(1);
    if (type)
    {
        displayDoubleLinkekdList1(tape, pointer);
    } else
    {
        displayDoubleLinkekdList(tape, pointer);
    }


}

void factorial(char a[])
{
    StateFac *StateFacs[26];

    for (int i = 0; i < 26; i++) {
        StateFacs[i] = createStateFac(i);
    }

    StateFac* fac = (StateFac*)malloc(sizeof(StateFac));
    StateFac* zero = fac;
    zero->state = 0;
    assign(StateFacs, 0, 0, 1, -1);
    assign(StateFacs, 1, 1, 2, -1);
    assign(StateFacs, 2, 3, 5, -1);
    assign(StateFacs, 3, 3, 4, -1);
    assign(StateFacs, 4, 4, 2, -1);
    assign(StateFacs, 5, 5, 7, -1);
    assign(StateFacs, 6, 6, 16, -1);
    assign(StateFacs, 7, 7, 8, -1);
    assign(StateFacs, 8, 9, -1, -1);
    assign(StateFacs, 9, 6, 10, -1);
    assign(StateFacs, 10, 10, 11, -1);
    assign(StateFacs, 11, 12, 14, -1);
    assign(StateFacs, 12, 12, 13, -1);
    assign(StateFacs, 13, 13, 11, -1);
    assign(StateFacs, 14, 14, 15, -1);
    assign(StateFacs, 15, 15, 9, -1);
    assign(StateFacs, 16, 17, 25, -1);
    assign(StateFacs, 17, 18, 19, -1);
    assign(StateFacs, 18, 18, 22, 24);
    assign(StateFacs, 19, 19, 20, -1);
    assign(StateFacs, 20, 20, 21, -1);
    assign(StateFacs, 21, 21, 6, -1);
    assign(StateFacs, 22, 22, 23, -1);
    assign(StateFacs, 23, 23, 9, -1);
    assign(StateFacs, 24, -1, -1, -1);
    assign(StateFacs, 25, 25, -1, -1);

    DoubleLinkedList tape = createTapeFac(a);
    Node* pointer = tape.head;
    StateFac* s = fac;
    Node* ptr = tape.head;
    printf("\n");

    while (pointer->data= ' ' )
    {
        pointer = pointer->next;
    }

    //func

    while (s->state != 24)
    {
        display(0);

        // -/1,S   0->1
        if (s->state = 0 && pointer->data = ' ')
        {
            pointer->data = '1';
            display(1)
            s = s->second;
        }
        
        // 0/0,R   0->0
        // 0/0,R or 1/1,R   3->3
        // 0/0,R   5->5
        // 0/0,R   10->10
        // 0/0,R or 1/1,R  12->12
        // 0/0,r or x/x,r    19->19
        // 0/0,r or x/x,r    20->20
        // 0/0,r or 1/1,r or x/x,r    22->22
        // 0/0,r   25->25
        else if (
            (pointer->data == '0' && (s->state == 0 || s->state == 3 || s->state == 5 || s->state == 10 || s->state == 12 || s->state == 19 || s->state == 20 || s->state == 22 || s->state == 25)) ||
            (pointer->data == '1' && (s->state == 3 || s->state == 12 || s->state == 22)) ||
            (pointer->data == 'X' && (s->state == 19 || s->state == 20 || s->state == 22)) ||
        ) {
            s = s->first;              // Move to the first state
            pointer = pointer->next;   // Move pointer to next
        }


        // -/-,R   1->2
        // 1/1,R   2->5
        // x/x,R   4->2
        //-/-,r   6->16
        // -/-,R   7->8
        // 1/1,R   10->11
        // X/X,R   13->11
        // x/x,r   15->9
        // x/x,r   17->19
        // x/x,r   18->22
        // 1/1,r   19->20
        else if (
            (pointer->data == ' ' && (s->state == 1 || s->state == 6 || s->state == 7)) ||
            (pointer->data == '1' && (s->state == 2 || s->state == 10 || s->state == 19)) ||
            (pointer->data == 'X' && (s->state == 4 || s->state == 13 || s->state == 15 || s->state == 17 || s->state == 18))
        ) {
            s = s->second;        
            pointer = pointer->next;   
        }

        // 0/0,L or 1/1,L  1->1
        // 0/0,L or 1/1,L  4->4
        // 0/0,l or 1/1,l or x/x,l  6->6
        // 0/0,L or 1/1,L    7->7
        // 1/1,l   9->6
        // 0/0,L or 1/1,L  13->13
        // 0/0,L   15->15
        // x/x,l   21->21
        // 0/0,l or 1/1,l   23->23
        else if (
            (pointer->data == '0' && (s->state == 1 || s->state == 4 || s->state == 6 || s->state == 7 || s->state == 13 || s->state == 15 || s->state == 23)) ||
            (pointer->data == '1' && (s->state == 1 || s->state == 4 || s->state == 6 || s->state == 7 || s->state == 9 || s->state == 13 || s->state == 23)) ||
            (pointer->data == 'X' && (s->state == 6 || s->state == 21)) 
        ) {
            s = s->first;
            pointer = pointer->previous; 
        }

        // 0/x,R   2->3
        // 0/X,R   11->12
        else if (
            (pointer->data == '0' && (s->state == 2 || s->state == 11)) // states 2 or 11 for '0'
        ) {
            pointer->data = 'X';  
            display(1);        
            s = s->first;       
            pointer = pointer->next; 
        }

        // -/0,S   3->4
        // -/0,S   12->13
        else if (
            (pointer->data == ' ' && (s->state == 3 || s->state == 12)) // states 3 or 12 for ' '
        ) {
            pointer->data = '0'; 
            display(1);          
            s = s->second;    
        }

        // -/1,L   5->7
        else if (s->state = 5 && pointer->data = ' ')
        {
            pointer->data = '1';
            display(1)
            s = s->second;
            pointer = pointer->previous;
        }

        // X/0,L   7->7
        // 1/0,L   15->15
        else if (
            (pointer->data == 'X' && s->state == 7) || // state 7 for 'X'
            (pointer->data == '1' && s->state == 15) // state 15 for '1'
        ) {
            pointer->data = '0';  
            display(1);           
            s = s->first;        
            pointer = pointer->previous;
        }

        // 0/-,R   8->9
        // x/-,r   16->17
        // 0/-,r or 1/-,r   17->18
        // 0/-,r   18->18
        // 1/-,r   25->25
        else if (
            // Conditions based on pointer->data and s->state
            (pointer->data == '0' && (s->state == 8 || s->state == 17 || s->state == 18)) || // states 8, 17, 18 for '0'
            (pointer->data == '1' && (s->state == 17 || s->state == 25)) || // states 17, 25 for '1'
            (pointer->data == 'X' && s->state == 16) // state 16 for 'X'
        ) {
            pointer->data = ' ';
            display(1);
            s = s->first;
            pointer = pointer->next;
        }

        // 0/X,R   9->10
        else if (s->state = 9 && pointer->data = '0')
        {
            pointer->data = 'X';
            display(1)
            s = s->second;
            pointer = pointer->next;
        }

        // 1/1,L   11->14
        // 1/1,L   14->15
        // 1/1,l   20->21
        else if (
            (pointer->data == '1' && (s->state == 11 || s->state == 14 || s->state == 20)) // states 11, 14, 20 for '1'
        ) {
            s = s->second;
            pointer = pointer->previous;
        }

        // x/0,L   14->14
        else if (s->state = 14 && pointer->data = 'X')
        {
            pointer->data = '0';
            s = s->first;
            pointer = pointer->previous;
        }

        // 1/-,r   16->25
        else if (s->state = 16 && pointer->data = '1')
        {
            pointer->data = ' ';
            display(1)
            s = s->second;
            pointer = pointer->next;
        }

        // 1/-,s   18->halt
        else if (s->state = 18 && pointer->data = '1')
        {
            pointer->data = ' ';
            waitFor(1);
            clrscr();
            display(1)
            s = s->third;
        }

        // 0/x,l or 1/x,l   21->6
        else if (s->state = 21 && (pointer->data = '0' or pointer->data = '1'))
        {
            pointer->data = 'X';
            s = s->second;
            pointer = pointer->previous;
        }

        // -/1,l   22->23
        else if (s->state = 22 && pointer->data = ' ')
        {
            pointer->data = '1';
            s = s->second;
            pointer = pointer->previous;
        }

        // -/-,r   23->9
        else if (s->state = 23 && pointer->data = ' ')
        {
            display(1)
            s = s->second;
            pointer = pointer->next;
        }

        // x/0,r   23->23
        else if (s->state = 23 && pointer->data = 'X')
        {
            pointer->data = '0';
            display(1)
            s = s->first;
            pointer = pointer->next;
        }

        // -/-,s   25->halt
        else if (s->state = 25 && pointer->data = ' ')
        {
            s = s->second;
        }
    }




    zeroDoubleLinkekdList(tape);
    tape = dropLinkedList(tape);

    free(fac);
    for (int i = 0; i < 26; i++) {
        free(StateFacs[i]);
    }
}


