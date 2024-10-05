#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include "../include/doublelinkedlist.h"

#define clrscr() //printf("\e[1;1H\e[2J")

void waitFor(unsigned int secs) {
    unsigned int retTime = time(0); // + secs;
    while (time(0) < retTime);
    clrscr();
}

DoubleLinkedList createTapeDiv(char c[]) {
    DoubleLinkedList d = newDoubleLinkedList(d, '-');
    for (int ii = 0; ii < 20; ii++) {
        d = insertEndDoubleLinkedList(d, '-');
    }
    for (int i = 0; c[i] != '\0'; i++) {
        d = insertEndDoubleLinkedList(d, c[i]);
    }
    for (int ii = 0; ii < 20; ii++) {
        d = insertEndDoubleLinkedList(d, '-');
    }
    return d;
}

typedef struct stated {
    int state;
    struct stated* self;
    struct stated* next;
} StateDiv;

StateDiv* createState(int stateVal) {
    StateDiv* state = (StateDiv*)malloc(sizeof(StateDiv));
    state->state = stateVal;
    state->self = NULL;
    state->next = NULL;
    return state;
}

void displayAndWait(DoubleLinkedList tape, Node* pointer) {
    waitFor(1);
    displayDoubleLinkekdList(tape, pointer);
}

void displayAndWait1(DoubleLinkedList tape, Node* pointer) {
    waitFor(1);
    displayDoubleLinkekdList1(tape, pointer);
}

void division(char a[]) {
    StateDiv* zero = createState(0);
    StateDiv* one = createState(1);
    StateDiv* two = createState(2);
    StateDiv* three = createState(3);
    StateDiv* four = createState(4);
    StateDiv* five = createState(5);
    StateDiv* six = createState(6);
    StateDiv* ei = createState(8);
    StateDiv* nine = createState(9);
    StateDiv* ten = createState(10);
    StateDiv* halt = createState(-1);
    StateDiv* s = zero;

    // Connecting states
    zero->next = one;
    one->next = two;
    one->self = ten;
    two->next = three;
    two->self = two;
    three->next = four;
    three->self = three;
    four->next = five;
    four->self = four;
    five->next = six;
    five->self = ei;
    six->next = ei;
    six->self = six;
    ei->next = nine;
    ei->self = ei;
    nine->next = one;
    nine->self = nine;
    ten->next = halt;
    ten->self = ten;

    DoubleLinkedList tape = createTapeDiv(a);
    Node* pointer = tape.head;

    while (pointer->next->data == '-') {
        pointer = pointer->next;
    }

    while (s->state != -1) {
        displayAndWait(tape, pointer);
        if (s->state == 0 && pointer->data == '-') {
            s = s->next;
            pointer = pointer->next;
        }
        else if (s->state == 1 && pointer->data == '1') {
            pointer->data = '-';
            displayAndWait1(tape, pointer);
            s = s->next;
            pointer = pointer->next;
        }
        else if (s->state == 1 && pointer->data == '/') {
            pointer->data = '-';
            displayAndWait1(tape, pointer);
            s = s->self;
            pointer = pointer->next;
        }
        else if (s->state == 2 && pointer->data == '1') {
            s = s->self;
            pointer = pointer->next;
        }
        else if (s->state == 2 && pointer->data == '/') {
            s = s->next;
            pointer = pointer->next;
        }
        else if (s->state == 3 && pointer->data == '1') {
            s = s->self;
            pointer = pointer->next;
        }
        else if (s->state == 3 && pointer->data == 'E') {
            s = s->self;
            pointer = pointer->next;
        }
        else if (s->state == 3 && (pointer->data == 'Z' || pointer->data == '-')) {
            s = s->next;
            pointer = pointer->previous;
        }
        else if (s->state == 4 && pointer->data == 'E') {
            s = s->self;
            pointer = pointer->previous;
        }
        else if (s->state == 4 && pointer->data == '1') {
            pointer->data = 'E';
            displayAndWait1(tape, pointer);
            s = s->next;
            pointer = pointer->previous;
        }
        else if (s->state == 5 && pointer->data == '/') {
            s = s->next;
            pointer = pointer->next;
        }
        else if (s->state == 5 && pointer->data == '1') {
            s = s->self;
            pointer = pointer->previous;
        }
        else if (s->state == 6 && pointer->data == 'E') {
            pointer->data = '1';
            displayAndWait1(tape, pointer);
            s = s->self;
            pointer = pointer->next;
        }
        else if (s->state == 6 && pointer->data == 'Z') {
            s = s->self;
            pointer = pointer->next;
        }
        else if (s->state == 6 && pointer->data == '-') {
            pointer->data = 'Z';
            displayAndWait1(tape, pointer);
            s = s->next;
            pointer = pointer->previous;
        }
        else if (s->state == 8 && (pointer->data == '1' || pointer->data == 'Z')) {
            s = s->self;
            pointer = pointer->previous;
        }
        else if (s->state == 8 && pointer->data == '/') {
            s->next = nine;
            s = nine;
            pointer = pointer->previous;
        }
        else if (s->state == 9 && pointer->data == '1') {
            s = s->self;
            pointer = pointer->previous;
        }
        else if (s->state == 9 && pointer->data == '-') {
            s = one;
            pointer = pointer->next;
        }
        else if (s->state == 10 && pointer->data == 'Z') {
            pointer->data = '1';
            displayAndWait1(tape, pointer);
            s = s->self;
            pointer = pointer->next;
        }
        else if (s->state == 10 && pointer->data == '1') {
            pointer->data = '-';
            displayAndWait1(tape, pointer);
            s = s->self;
            pointer = pointer->next;
        }
        else if (s->state == 10 && pointer->data == '-') {
            s = s->next;
        }
    }

    oneDoubleLinkekdList(tape);
    tape = dropLinkedList(tape);

    free(zero); free(one); free(two); free(three); free(four);
    free(five); free(six); free(ei); free(nine); free(halt);
}
