#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "../include/doublelinkedlist.h"

#define clrscr() //printf("\e[1;1H\e[2J")

typedef struct stateadd {
    int state;
    struct stateadd* next;
} StateAdd;

void waitFor(unsigned int secs) {
    unsigned int retTime = time(0);
    while (time(0) < retTime);
    clrscr();
}

DoubleLinkedList createTapeAdd(char c[]) {   
    DoubleLinkedList d = newDoubleLinkedList('-', 20);
    for (int i = 0; c[i] != '\0'; i++)
        d = insertEndDoubleLinkedList(d, c[i]);
    return d;
}

StateAdd* createState(int state, StateAdd* next) {
    StateAdd* newState = (StateAdd*)malloc(sizeof(StateAdd));
    newState->state = state;
    newState->next = next;
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
    StateAdd* zero = createState(0, NULL);
    StateAdd* one = createState(1, NULL);
    StateAdd* two = createState(2, NULL);
    StateAdd* three = createState(3, NULL);
    StateAdd* halt = createState(-1, NULL);

    zero->next = one;
    one->next = two;
    two->next = three;
    three->next = halt;

    DoubleLinkedList tape = createTapeAdd(a);
    Node* pointer = tape.head;

    while (pointer->next->data == '-') {
        pointer = pointer->next;
    }

    StateAdd* s = zero;
    while (s->state != -1) {
        switch (s->state) {
            case 0:
                if (pointer->data == '-') {
                    displayDoubleLinkedList(tape, pointer);
                    s = s->next;
                    pointer = pointer->next;
                }
                break;

            case 1:
                if (pointer->data == '1') {
                    displayDoubleLinkedList(tape, pointer);
                    pointer = pointer->next;
                } else if (pointer->data == '+') {
                    displayDoubleLinkedList(tape, pointer);
                    pointer->data = '1';
                    displayDoubleLinkedList(tape, pointer);
                    s = s->next;
                    pointer = pointer->next;
                }
                break;

            case 2:
                if (pointer->data == '1') {
                    displayDoubleLinkedList(tape, pointer);
                    pointer = pointer->next;
                } else if (pointer->data == '-') {
                    displayDoubleLinkedList(tape, pointer);
                    s = s->next;
                    pointer = pointer->previous;
                }
                break;

            case 3:
                if (pointer->data == '1') {
                    displayDoubleLinkedList(tape, pointer);
                    pointer->data = '-';
                    displayDoubleLinkedList(tape, pointer);
                    s = s->next;
                }
                break;
        }
        waitFor(1);
    }

    oneDoubleLinkedList(tape);
    tape = dropLinkedList(tape);

    freeStates(zero);
}
