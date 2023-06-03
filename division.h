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



DoubleLinkedList createTapeDiv(char c[])
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
}StateDiv;


void division()
{

    StateDiv* div = (StateDiv*)malloc(sizeof(StateDiv));
    StateDiv* zero = div;
    zero->self = NULL;
    zero->state = 0;

    StateDiv* one = (StateDiv*)malloc(sizeof(StateDiv));
    one->self = NULL;
    one->state = 1;

    StateDiv* two = (StateDiv*)malloc(sizeof(StateDiv));
    two->self = NULL;
    two->state = 2;

    StateDiv* three = (StateDiv*)malloc(sizeof(StateDiv));
    three->self = NULL;
    three->state = 3;

    StateDiv* four = (StateDiv*)malloc(sizeof(StateDiv));
    four->self = NULL;
    four->state = 4;

    StateDiv* five = (StateDiv*)malloc(sizeof(StateDiv));
    five->self = NULL;
    five->state = 5;

    StateDiv* siz = (StateDiv*)malloc(sizeof(StateDiv));
    siz->self = NULL;
    siz->state = 6;

    StateDiv* sev = (StateDiv*)malloc(sizeof(StateDiv));
    sev->self = NULL;
    sev->state = 7;

    StateDiv* ei = (StateDiv*)malloc(sizeof(StateDiv));
    ei->self = NULL;
    ei->state = 8;

    StateDiv* nine = (StateDiv*)malloc(sizeof(StateDiv));
    nine->self = NULL;
    nine->state = 9;

    StateDiv* ten = (StateDiv*)malloc(sizeof(StateDiv));
    nine->self = NULL;
    nine->state = 10;

    StateDiv* halt = (StateDiv*)malloc(sizeof(StateDiv));
    halt->self = NULL;
    halt->state = -1;
    halt->next = NULL;

//connecting them
    zero->self = NULL;
    zero->next = one;
    one->next = two;
    one->self = ten;
    two->self = two;
    two->next = three;
    three->next = four;
    three->self = three;
    four->self = four;
    four->next = five;
    five->next = siz;
    five->self = ei;
    siz->self = siz;
    siz->next = ei;
//   
    ei->self = ei;
    ei->next = nine;
    nine->self = nine;
    nine->next = one;
    ten->self = ten;
    ten->next = halt;
//

    char a[] = "1111/11";
    DoubleLinkedList tape = createTapeDiv(a);
    Node* pointer = tape.head;
    StateDiv* s = div;
    Node* ptr = tape.head;
        printf("\n");

    while (pointer->next->data== '-' )
    {
        pointer = pointer->next;
    }
    printf("%c",pointer->data );


//func

    while (s->state != -1)
    {
    
         // -/-,R   0->1
        if (s->state == 0 && pointer->data == '-')
        {                      
                  waitFor(1);
                  clrscr();
    displayDoubleLinkekdList(tape, pointer);    printf("%i", s->state);
            pointer->data = '-';
                           // waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
            pointer = pointer->next;
        }

        // 1/-,R   1->2
       else if (s->state == 1 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer); printf("%i", s->state);
            pointer->data = '-';
             waitFor(1);
   displayDoubleLinkekdList1(tape, pointer); printf("%i", s->state);
            s = s->next;
            pointer = pointer->next;

        } 


            // 1/1,R   2->2
       else if (s->state == 2 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);printf("%i", s->state);
            pointer->data = '1';
            // waitFor(1);
   //displayDoubleLinkekdList1(tape, pointer);
            s = s->self;
            pointer = pointer->next;

        } 


            // ///,R   2->3
       else if (s->state == 2 && pointer->data == '/')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);printf("%i", s->state);
            pointer->data = '/';
            // waitFor(1);
   //displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
            pointer = pointer->next;

        } 

        
            // 1/1,R   3->3
       else if (s->state == 3 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);printf("%i", s->state);
            pointer->data = '1';
            // waitFor(1);
   //displayDoubleLinkekdList1(tape, pointer);
            s = s->self;
            pointer = pointer->next;

        } 


                    // E/E,R   3->3
       else if (s->state == 3 && pointer->data == 'E')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);printf("%i", s->state);
            pointer->data = 'E';
            // waitFor(1);
   //displayDoubleLinkekdList1(tape, pointer);
            s = s->self;
            pointer = pointer->next;

        } 

         // Z/Z,L   3->4
       else if (s->state == 3 && pointer->data == 'Z')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);printf("%i", s->state);
            pointer->data = 'Z';
            // waitFor(1);
   //displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
            pointer = pointer->previous;

        } 

                 // -/-,L   3->4
       else if (s->state == 3 && pointer->data == '-')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);printf("%i", s->state);
            pointer->data = '-';
            // waitFor(1);
   //displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
            pointer = pointer->previous;

        } 

                 // E/E,L   4->4
       else if (s->state == 4 && pointer->data == 'E')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);printf("%i", s->state);
            pointer->data = 'E';
            // waitFor(1);
   //displayDoubleLinkekdList1(tape, pointer);
            s = s->self;
            pointer = pointer->previous;

        } 

                 // 1/E,L   4->5
       else if (s->state == 4 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);printf("%i", s->state);
            pointer->data = 'E';
             waitFor(1);
   displayDoubleLinkekdList1(tape, pointer);printf("%i", s->state);
            s = s->next;
            pointer = pointer->previous;

        } 


        // ///,R   5->6
       else if (s->state == 4 && pointer->data == '/')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);printf("%i", s->state);
            pointer->data = '/';
            // waitFor(1);
   //displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
            pointer = pointer->next;

        } 

                // 1/1,L   5->8
       else if (s->state == 5 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);printf("%i", s->state);
            pointer->data = '1';
            // waitFor(1);
   //displayDoubleLinkekdList1(tape, pointer);
            s = s->self;
            pointer = pointer->previous;

        } 

            // E/1,R   6->6
       else if (s->state == 6 && pointer->data == 'E')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);printf("%i", s->state);
            pointer->data = '1';
             waitFor(1);
   displayDoubleLinkekdList1(tape, pointer);printf("%i", s->state);
            s = s->self;
            pointer = pointer->next;

        } 

//             // Z/Z,R   6->6
//        else if (s->state == 6 && pointer->data == 'Z')
//         {                            waitFor(1);
//         clrscr();
//     displayDoubleLinkekdList(tape, pointer);printf("%i", s->state);
//             pointer->data = 'Z';
//             // waitFor(1);
//   // displayDoubleLinkekdList1(tape, pointer);printf("%i", s->state);
//             s = s->next;
//             pointer = pointer->next;

//         } 

        // -/Z,L   6->8
       else if (s->state == 6 && pointer->data == '-')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);printf("%i", s->state);
            pointer->data = 'Z';
             waitFor(1);
   displayDoubleLinkekdList1(tape, pointer);printf("%i", s->state);
            s = s->next;
            pointer = pointer->previous;

        }
        // 1/1,L   8->8
       else if (s->state == 8 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);printf("%i", s->state);
            pointer->data = '1';
            // waitFor(1);
   //displayDoubleLinkekdList1(tape, pointer);
            s = s->self;
            pointer = pointer->previous;

        }

                // Z/Z,L   8->8
       else if (s->state == 8 && pointer->data == 'Z')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);printf("%i", s->state);
            pointer->data = 'Z';
            // waitFor(1);
   //displayDoubleLinkekdList1(tape, pointer);
            s = s->self;
            pointer = pointer->previous;

        }

                // ///,L   8->9
       else if (s->state == 8 && pointer->data == '/')
        {                            waitFor(1);
        clrscr();
        s->next  = nine;
    displayDoubleLinkekdList(tape, pointer);printf("%i", s->state);
            pointer->data = '/';
            // waitFor(1);
   //displayDoubleLinkekdList1(tape, pointer);
   printf("\n%i", s->next->state);
            //s = s->next;
            
            s = nine;
            pointer = pointer->previous;

        }

        // 1/1,L   9->9
       else if (s->state == 9 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);printf("%i", s->state);
            pointer->data = '1';
            // waitFor(1);
   //displayDoubleLinkekdList1(tape, pointer);
            s = s->self;
            pointer = pointer->previous;

        }

        // -/-,L   9->1
       else if (s->state == 9 && pointer->data == '-')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);printf("%i", s->state);
            pointer->data = '-';
            // waitFor(1);
   //displayDoubleLinkekdList1(tape, pointer);
            s = one;
            pointer = pointer->next;

        }

                // //-,R   1->10
       else if (s->state == 1 && pointer->data == '/')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);printf("%i", s->state);
            pointer->data = '-';
             waitFor(1);
displayDoubleLinkekdList1(tape, pointer);printf("%i", s->state);
            s = s->self;
            pointer = pointer->next;

        }

                        // Z/1,R   10->10
       else if (s->state == 10 && pointer->data == 'Z')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);printf("%i", s->state);
            pointer->data = '1';
             waitFor(1);
   displayDoubleLinkekdList1(tape, pointer);printf("%i", s->state);
            s = s->self;
            pointer = pointer->next;

        }

            // 1/-,R   10->10
       else if (s->state == 10 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);printf("%i", s->state);
            pointer->data = '-';
             waitFor(1);
   displayDoubleLinkekdList1(tape, pointer);printf("%i", s->state);
            s = s->self;
            pointer = pointer->next;

        }
        
            // -/-,S   10->-1
       else if (s->state == 10 && pointer->data == '-')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);printf("%i", s->state);
            pointer->data = '-';
            // waitFor(1);
   //displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
           // pointer = pointer->next;

        }
    }
    

}