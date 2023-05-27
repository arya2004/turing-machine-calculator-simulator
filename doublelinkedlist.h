#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* previous;
}Node;

typedef struct {
    Node* head;
    int size;
    Node* tail;
}DoubleLinkedList;

DoubleLinkedList dropLinkedList(DoubleLinkedList);

DoubleLinkedList newDoubleLinkedList(DoubleLinkedList doublelinkedlist, int data){
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

int headDoubleLinkedList(DoubleLinkedList doublelinkedlist){
    return doublelinkedlist.head->data;
}

int tailDoubleLinkedList(DoubleLinkedList doublelinkedlist){
    return doublelinkedlist.tail->data;
}

DoubleLinkedList insertEndDoubleLinkedList(DoubleLinkedList doublelinkedlist, int data){
    doublelinkedlist.tail->next = (Node*) malloc(sizeof(Node));
    doublelinkedlist.tail->next->data = data;
    doublelinkedlist.tail->next->previous = doublelinkedlist.tail;
    doublelinkedlist.tail->next->next = NULL;
    doublelinkedlist.size = doublelinkedlist.size + 1;
    doublelinkedlist.tail = doublelinkedlist.tail->next;
    return doublelinkedlist;
}

DoubleLinkedList insertBeginningDoubleLinkedList(DoubleLinkedList doublelinkedlist, int data){
    doublelinkedlist.head->previous = (Node*)malloc(sizeof(Node));
    doublelinkedlist.size = doublelinkedlist.size + 1;
    doublelinkedlist.head->previous->data = data;
    doublelinkedlist.head->previous->next = doublelinkedlist.head;
    doublelinkedlist.head->previous->previous = NULL;
    doublelinkedlist.head = doublelinkedlist.head->previous;
    return doublelinkedlist;
}

DoubleLinkedList insertAnyDoubleLinkedList(DoubleLinkedList doublelinkedlist, int data, int position){
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

DoubleLinkedList deleteBeginningDoubleLinkedList(DoubleLinkedList doublelinkedlist){
    if (doublelinkedlist.size == 0)
    {
        printf("\nlinked list is empty in deleteBeginningDoubleLinkedList");
        exit(1);
    }
    else if (doublelinkedlist.size == 1)
    {
       doublelinkedlist =  dropLinkedList(doublelinkedlist);
    }
    else
    {
    doublelinkedlist.head = doublelinkedlist.head->next;
    free(doublelinkedlist.head->previous);
    doublelinkedlist.head->previous = NULL;
    doublelinkedlist.size = doublelinkedlist.size - 1;
    
    }
    return doublelinkedlist;
}
DoubleLinkedList deleteEndDoubleLinkedList(DoubleLinkedList doublelinkedlist){
    if (doublelinkedlist.size == 0)
    {
        printf("\nlinked list is empty in deleteEndDoubleLinkedList");
        exit(1);
    }
    else if (doublelinkedlist.size == 1)
    {
       doublelinkedlist =  dropLinkedList(doublelinkedlist);
    }
    else
    {
    doublelinkedlist.tail = doublelinkedlist.tail->previous;
    free(doublelinkedlist.tail->next);
    doublelinkedlist.tail->next = NULL;
    doublelinkedlist.size = doublelinkedlist.size -1;
    
    }
    return doublelinkedlist;
}

DoubleLinkedList deleteAnyDoubleLinkedList(DoubleLinkedList doublelinkedlist,int position){
    if (doublelinkedlist.size == 0)
    {
        printf("\nlinked list is empty in deleteAnyDoubleLinkedList");
        exit(1);
    }
    else if (doublelinkedlist.size == 1)
    {
       doublelinkedlist =  dropLinkedList(doublelinkedlist);
    }
    if (position < 1 || position > doublelinkedlist.size)
    {
        printf("\nposition out of bound in deleteAnyDoubleLinkedList");
        exit(1);
    }
    else if (position == 1)
    {
       doublelinkedlist =  deleteBeginningDoubleLinkedList(doublelinkedlist);
    }
    else if (position == doublelinkedlist.size)
    {
       doublelinkedlist =  deleteEndDoubleLinkedList(doublelinkedlist);
    }
    else
    {
        Node* ptr = doublelinkedlist.head;
        for (int i = 1; i < position - 1; i++)
        {
            ptr = ptr->next;
        }
        ptr->next = ptr->next->next;
        free(ptr->next->previous);
        ptr->next->previous = ptr;
        doublelinkedlist.size = doublelinkedlist.size -1;
        
        
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


void displayDoubleLinkekdList(DoubleLinkedList doublelinkedlist){
    Node* temp = doublelinkedlist.head;
        printf("\nHEAD");
    for (int i = 0; i < doublelinkedlist.size; i++)
    {
        printf("<->%i", temp->data);
        temp = temp->next;
    }
    printf("<->TAIL");
}