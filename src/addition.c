#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include "doublelinkedlist.h"

typedef struct stateadd {
    int state;
    struct stateadd* next;
} StateAdd;

void waitFor(unsigned int secs) {
    unsigned int retTime = time(0) + secs; 
    while (time(0) < retTime);  
}

void updateAndMovePointer(DoubleLinkedList tape, Node* pointer, char newData, StateAdd** state, StateAdd* newState, bool moveRight) {
    waitFor(1);
    displayDoubleLinkekdList(tape, pointer);
    pointer->data = newData;
    *state = newState;
    if (moveRight) {
        pointer = pointer->next;
    } else {
        pointer = pointer->previous;
    }
}

DoubleLinkedList createTapeAdd(char c[]) {
    DoubleLinkedList d = newDoubleLinkedList(d, '-');
    for (int i = 0; i < 20; i++) d = insertEndDoubleLinkedList(d, '-');
    for (int i = 0; c[i] != '\0'; i++) d = insertEndDoubleLinkedList(d, c[i]);
    for (int i = 0; i < 20; i++) d = insertEndDoubleLinkedList(d, '-');
    return d;
}

void freeStateAdd(StateAdd* state) {
    while (state != NULL) {
        StateAdd* temp = state;
        state = state->next;
        free(temp);
    }
}

void addition(char a[]) {
    StateAdd* add = (StateAdd*)malloc(sizeof(StateAdd));
    StateAdd* zero = add;
    zero->state = 0;

    StateAdd* one = (StateAdd*)malloc(sizeof(StateAdd));
    one->state = 1;

    StateAdd* two = (StateAdd*)malloc(sizeof(StateAdd));
    two->state = 2;

    StateAdd* three = (StateAdd*)malloc(sizeof(StateAdd));
    three->state = 3;

    StateAdd* four = (StateAdd*)malloc(sizeof(StateAdd));
    four->state = -1;

    // Connecting the states
    zero->next = one;
    one->next = two;
    two->next = three;
    three->next = four;

    DoubleLinkedList tape = createTapeAdd(a);
    Node* pointer = tape.head;
    StateAdd* s = add;

    while (pointer->next->data == '-') pointer = pointer->next;

    while (s->state != -1) {
        if (s->state == 0 && pointer->data == '-') {
            updateAndMovePointer(tape, pointer, '-', &s, s->next, true);
        } else if (s->state == 1 && pointer->data == '1') {
            updateAndMovePointer(tape, pointer, '1', &s, s->next, true); // Use s->next, not s->self
        } else if (s->state == 1 && pointer->data == '+') {
            updateAndMovePointer(tape, pointer, '1', &s, s->next, true);
        } else if (s->state == 2 && pointer->data == '1') {
            updateAndMovePointer(tape, pointer, '1', &s, s->next, true); // Use s->next, not s->self
        } else if (s->state == 2 && pointer->data == '-') {
            updateAndMovePointer(tape, pointer, '-', &s, s->next, false);
        } else if (s->state == 3 && pointer->data == '1') {
            updateAndMovePointer(tape, pointer, '-', &s, s->next, false);
        }
    }

    freeStateAdd(add);
    tape = dropLinkedList(tape);
}
 
