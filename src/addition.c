#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include "../include/doublelinkedlist.h"

#define clrscr() //printf("\e[1;1H\e[2J")

typedef struct stateadd {
    int state;
    struct stateadd* self;
    struct stateadd* next;
} StateAdd;

void waitFor(unsigned int secs) {
    unsigned int retTime = time(0);
    while (time(0) < retTime);
    clrscr();
}

DoubleLinkedList createTapeAdd(char c[]) {   
    int l = 20;
    DoubleLinkedList d = newDoubleLinkedList(d, '-');
    for (int ii = 0; ii < 20; ii++)
        d = insertEndDoubleLinkedList(d, '-');

    for (int i = 0; c[i] != '\0'; i++)
        d = insertEndDoubleLinkedList(d, c[i]);

    for (int ii = 0; ii < 20; ii++)
        d = insertEndDoubleLinkedList(d, '-');

    return d;
}

StateAdd* createState(int state, StateAdd* next, StateAdd* self) {
    StateAdd* newState = (StateAdd*)malloc(sizeof(StateAdd));
    newState->state = state;
    newState->next = next;
    newState->self = self;
    return newState;
}

void freeStates(StateAdd* head) {
    while (head) {
        StateAdd* temp = head;
        head = head->next;
        free(temp);
    }
}

void addition(char a[]) {
    // Creating and linking states
    StateAdd* zero = createState(0, NULL, NULL);
    StateAdd* one = createState(1, NULL, one);
    StateAdd* two = createState(2, NULL, two);
    StateAdd* three = createState(3, NULL, three);
    StateAdd* halt = createState(-1, NULL, NULL);

    zero->next = one;
    one->next = two;
    two->next = three;
    three->next = halt;

    DoubleLinkedList tape = createTapeAdd(a);
    Node* pointer = tape.head;
    StateAdd* s = zero;

    while (pointer->next->data == '-') {
        pointer = pointer->next;
    }

    while (s->state != -1) {
        switch (s->state) {
            case 0:
                if (pointer->data == '-') {
                    displayDoubleLinkekdList(tape, pointer);
                    s = s->next;
                    pointer = pointer->next;
                }
                break;

            case 1:
                if (pointer->data == '1') {
                    displayDoubleLinkekdList(tape, pointer);
                    pointer = pointer->next;
                } else if (pointer->data == '+') {
                    displayDoubleLinkekdList(tape, pointer);
                    pointer->data = '1';
                    displayDoubleLinkekdList1(tape, pointer);
                    s = s->next;
                    pointer = pointer->next;
                }
                break;

            case 2:
                if (pointer->data == '1') {
                    displayDoubleLinkekdList(tape, pointer);
                    pointer = pointer->next;
                } else if (pointer->data == '-') {
                    displayDoubleLinkekdList(tape, pointer);
                    s = s->next;
                    pointer = pointer->previous;
                }
                break;

            case 3:
                if (pointer->data == '1') {
                    displayDoubleLinkekdList(tape, pointer);
                    pointer->data = '-';
                    displayDoubleLinkekdList1(tape, pointer);
                    s = s->next;
                }
                break;
        }
        waitFor(1);
    }

    oneDoubleLinkekdList(tape);
    tape = dropLinkedList(tape);

    freeStates(zero);
}
