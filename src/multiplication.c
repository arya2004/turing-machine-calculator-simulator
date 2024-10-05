#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "../include/doublelinkedlist.h"

#define clrscr() //printf("\e[1;1H\e[2J")

void waitFor(unsigned int secs) {
    unsigned int retTime = time(0); // + secs;
    while (time(0) < retTime);
        clrscr();
}

typedef struct statem {
    int state;
    struct statem* self;
    struct statem* next;
} StateMul;

StateMul* createState(int state, StateMul* self, StateMul* next) {
    StateMul* newState = (StateMul*)malloc(sizeof(StateMul));
    newState->state = state;
    newState->self = self;
    newState->next = next;
    return newState;
}

void displayAndWait(DoubleLinkedList tape, Node* pointer) {
    waitFor(1);
    displayDoubleLinkekdList(tape, pointer);
}

void displayAndWait1(DoubleLinkedList tape, Node* pointer) {
    waitFor(1);
    displayDoubleLinkekdList1(tape, pointer);
}

DoubleLinkedList createTapeMul(char c[]) {
    DoubleLinkedList d = newDoubleLinkedList(d, '-');
    for (int i = 0; i < 20; i++) d = insertEndDoubleLinkedList(d, '-');
    for (int i = 0; c[i] != '\0'; i++) d = insertEndDoubleLinkedList(d, c[i]);
    for (int i = 0; i < 20; i++) d = insertEndDoubleLinkedList(d, '-');
    return d;
}

void multiplication(char a[]) {
    StateMul* zero = createState(0, NULL, NULL);
    StateMul* one = createState(1, NULL, NULL);
    StateMul* two = createState(2, NULL, NULL);
    StateMul* three = createState(3, NULL, NULL);
    StateMul* four = createState(4, NULL, NULL);
    StateMul* five = createState(5, NULL, NULL);
    StateMul* six = createState(6, NULL, NULL);
    StateMul* seven = createState(7, NULL, NULL);
    StateMul* eight = createState(8, NULL, NULL);
    StateMul* nine = createState(9, NULL, NULL);
    StateMul* halt = createState(-1, NULL, NULL);

    //connecting them
    zero->next = one;
    one->next = four; one->self = two;
    two->self = two; two->next = three;
    three->next = halt;
    four->self = four; four->next = five;
    five->next = six; five->self = eight;
    six->self = six; six->next = seven;
    seven->self = seven; seven->next = five;
    eight->self = eight; eight->next = nine;
    nine->self = nine; nine->next = zero;

    DoubleLinkedList tape = createTapeMul(a);
    Node* pointer = tape.head;
    while (pointer->data == '-') pointer = pointer->next;
    StateMul* s = zero;

    while (s->state != -1) {
        displayAndWait(tape, pointer);

        if (s->state == 0 && pointer->data == '1') {
            pointer->data = '-';
            displayAndWait1(tape, pointer);
            s = s->next;
            pointer = pointer->next;
        }
        else if (s->state == 1 && pointer->data == '1') {
            s = s->next;
            pointer = pointer->next;
        }
        else if (s->state == 4 && pointer->data == '1') {
            s = s->self;
            pointer = pointer->next;
        }
        else if (s->state == 4 && pointer->data == '*') {
            s = s->next;
            pointer = pointer->next;
        }
        else if (s->state == 5 && pointer->data == '1') {
            pointer->data = 'E';
            displayAndWait1(tape, pointer);
            s = s->next;
            pointer = pointer->next;
        }
        else if (s->state == 6 && (pointer->data == '1' || pointer->data == 'Z')) {
            s = s->self;
            pointer = pointer->next;
        }
        else if (s->state == 6 && pointer->data == '-') {
            pointer->data = 'Z';
            displayAndWait1(tape, pointer);
            s = s->next;
            pointer = pointer->previous;
        }
        else if (s->state == 7 && (pointer->data == '1' || pointer->data == 'Z')) {
            s = s->self;
            pointer = pointer->previous;
        }
        else if (s->state == 7 && pointer->data == 'E') {
            s = s->next;
            pointer = pointer->next;
        }
        else if (s->state == 5 && pointer->data == 'Z') {
            s = s->self;
            pointer = pointer->previous;
        }
        else if (s->state == 8 && pointer->data == 'E') {
            pointer->data = '1';
            displayAndWait1(tape, pointer);
            s = s->self;
            pointer = pointer->previous;
        }
        else if (s->state == 8 && pointer->data == '*') {
            s = s->next;
            pointer = pointer->previous;
        }
        else if (s->state == 9 && pointer->data == '1') {
            s = s->self;
            pointer = pointer->previous;
        }
        else if (s->state == 9 && pointer->data == '-') {
            s = s->next;
            pointer = pointer->next;
        }
        else if (s->state == 1 && pointer->data == '*') {
            pointer->data = '1';
            displayAndWait1(tape, pointer);
            s = s->self;
            pointer = pointer->next;
        }
        else if (s->state == 2 && pointer->data == '1') {
            s = s->self;
            pointer = pointer->next;
        }
        else if (s->state == 2 && pointer->data == 'Z') {
            pointer->data = '1';
            displayAndWait1(tape, pointer);
            s = s->self;
            pointer = pointer->next;
        }
        else if (s->state == 2 && pointer->data == '-') {
            s = s->next;
            pointer = pointer->previous;
        }
        else if (s->state == 3 && pointer->data == '1') {
            pointer->data = '-';
            displayAndWait1(tape, pointer);
            s = s->next;
        }
    }
    displayDoubleLinkekdList1(tape, pointer);
    oneDoubleLinkekdList(tape);
    
    free(zero); free(one); free(two); free(three); free(four);
    free(five); free(six); free(seven); free(eight); free(nine); free(halt);
    dropLinkedList(tape);
}
