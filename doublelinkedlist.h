/*

https://github.com/arya2004/dataStructures/blob/master/doublelinkedlist.h
PLEASE REFER TO ABOVE LINK FOR VERSATILE DOUBLY LINKEDLIST CODE
THIS ONE WILL BE TAILORED MADE FOR THE PROJECT, SO AVOID DIRECTLY COPYING THIS ONE

*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>

typedef struct node {
    char data;
    struct node* next;
    struct node* previous;
}Node;

typedef struct {
    Node* head;
    int size;
    Node* tail;
}DoubleLinkedList;

DoubleLinkedList dropLinkedList(DoubleLinkedList);

DoubleLinkedList newDoubleLinkedList(DoubleLinkedList doublelinkedlist, char data){
    doublelinkedlist.size = 1;
    doublelinkedlist.head = (Node*) malloc( sizeof(Node));
    doublelinkedlist.head->data = data;
    doublelinkedlist.head->previous = NULL;;
    doublelinkedlist.head->next = NULL;
    doublelinkedlist.tail = doublelinkedlist.head;
    return doublelinkedlist;
    
}

int sizeDoubleLinkedList(DoubleLinkedList doublelinkedlist){
    return doublelinkedlist.size;
}

char headDoubleLinkedList(DoubleLinkedList doublelinkedlist){
    return doublelinkedlist.head->data;
}

char tailDoubleLinkedList(DoubleLinkedList doublelinkedlist){
    return doublelinkedlist.tail->data;
}

DoubleLinkedList insertEndDoubleLinkedList(DoubleLinkedList doublelinkedlist, char data){
    doublelinkedlist.tail->next = (Node*) malloc(sizeof(Node));
    doublelinkedlist.tail->next->data = data;
    doublelinkedlist.tail->next->previous = doublelinkedlist.tail;
    doublelinkedlist.tail->next->next = NULL;
    doublelinkedlist.size = doublelinkedlist.size + 1;
    doublelinkedlist.tail = doublelinkedlist.tail->next;
    return doublelinkedlist;
}

DoubleLinkedList insertBeginningDoubleLinkedList(DoubleLinkedList doublelinkedlist, char data){
    doublelinkedlist.head->previous = (Node*)malloc(sizeof(Node));
    doublelinkedlist.size = doublelinkedlist.size + 1;
    doublelinkedlist.head->previous->data = data;
    doublelinkedlist.head->previous->next = doublelinkedlist.head;
    doublelinkedlist.head->previous->previous = NULL;
    doublelinkedlist.head = doublelinkedlist.head->previous;
    return doublelinkedlist;
}

DoubleLinkedList insertAnyDoubleLinkedList(DoubleLinkedList doublelinkedlist, char data, int position){
    if (position < 1 || position > doublelinkedlist.size + 1)
    {
        printf("\nposition out of bound in insertAnyDoubleLinkedList");
        exit(1);
    }
    else if (position == 1)
    {
       doublelinkedlist =  insertBeginningDoubleLinkedList(doublelinkedlist, data);
    }
    else if (position == doublelinkedlist.size + 1)
    {
       doublelinkedlist =  insertEndDoubleLinkedList(doublelinkedlist, data);
    }
    else{
        Node * temp = (Node*)malloc(sizeof(Node));
        Node* ptr = doublelinkedlist.head;
        for (int i = 1; i < position - 1; i++)
        {
            ptr = ptr->next;
        }
        
        temp->data = data;
        temp->next = ptr->next;
        ptr->next = temp;
        temp->previous = ptr;
        temp->next->previous = temp;
        doublelinkedlist.size = doublelinkedlist.size + 1;
        
        
    }
    return doublelinkedlist;
}


DoubleLinkedList dropLinkedList(DoubleLinkedList doublelinkedlist){
    Node* temp = doublelinkedlist.head;
    while (temp != NULL)
    {
        temp = temp->next;
        free(doublelinkedlist.head);
        doublelinkedlist.head = temp;
    }
    doublelinkedlist.head = NULL;
    doublelinkedlist.tail = NULL;
    doublelinkedlist.size = 0;
    return doublelinkedlist;
}


void displayDoubleLinkekdList(DoubleLinkedList doublelinkedlist, Node* pp){
    Node* temp = doublelinkedlist.head;
        printf("\n");
    for (int i = 0; i < doublelinkedlist.size; i++)
    {
        if (temp == pp)
        {
            printf("\033[0;31m%c\033[0m", temp->data);
            i++; //Set the text to the color red
            temp = temp->next;
        }
        
        printf("%c", temp->data);
        temp = temp->next;
    }
   
}
void displayDoubleLinkekdList1(DoubleLinkedList doublelinkedlist, Node* pp){
    Node* temp = doublelinkedlist.head;
        printf("\n");
    for (int i = 0; i < doublelinkedlist.size; i++)
    {
        if (temp == pp)
        {
            printf("\033[0;32m%c\033[0m", temp->data);
            i++; //Set the text to the color red
            temp = temp->next;
        }
        
        printf("%c", temp->data);
        temp = temp->next;
    }
   
}