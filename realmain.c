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

#define clrscr() //printf("\e[1;1H\e[2J")
void waitFor (unsigned int secs) {
    unsigned int retTime = time(0);// + secs;   // Get finishing time.
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


typedef struct stated{
    int state;
    struct stated* self;
    struct stated* next;
}StateDiv;


void division(char a[])
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
    ten->self = NULL;
    ten->state = 10;

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
    printf("%i",ei->next->state );
    nine->self = nine;
    nine->next = one;
     printf("%i",nine->self->state );
    ten->self = ten;
    ten->next = halt;
//

   // char a[] = "1111/11";
    DoubleLinkedList tape = createTapeDiv(a);
    Node* pointer = tape.head;
    StateDiv* s = div;
    Node* ptr = tape.head;
        printf("\n");

    while (pointer->next->data== '-' )
    {
        pointer = pointer->next;
    }
   // printf("%c",pointer->data );


//func
    ei->next = nine;
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
       else if (s->state == 5 && pointer->data == '/')
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

            // Z/Z,R   6->6
       else if (s->state == 6 && pointer->data == 'Z')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);printf("%i", s->state);
            pointer->data = 'Z';
            // waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);printf("%i", s->state);
            s = s->self;
            pointer = pointer->next;

        } 

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

typedef struct statem{
    int state;
    struct statem* self;
    struct statem* next;
}StateMul;

void multiplication(char a[])
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

    //char a[] = "111*111";
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

DoubleLinkedList createTapeAdd(char c[])
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

typedef struct stateadd{
    int state;
    struct stateadd* self;
    struct stateadd* next;
}StateAdd;


void addition(char a[])
{
    StateAdd*add = (StateAdd*)malloc(sizeof(StateAdd));
    StateAdd* zero = add;
    zero->self = NULL;
    zero->state = 0;

    StateAdd* one = (StateAdd*)malloc(sizeof(StateAdd));
    one->self = NULL;
    one->state = 1;

    StateAdd* two = (StateAdd*)malloc(sizeof(StateAdd));
    two->self = NULL;
    two->state = 2;

    StateAdd* three = (StateAdd*)malloc(sizeof(StateAdd));
    three->self = NULL;
    three->state = 3;

    StateAdd* four = (StateAdd*)malloc(sizeof(StateAdd));
    four->self = NULL;
    four->state = -1;


    //connecting them
    zero->self = NULL;
    zero->next = one;
    one->next = two;
    one->self = one;
    two->self = two;
    two->next = three;
    three->next = four;
    three->self = three;
    four->self = NULL;
    four->next = NULL;


//

    //char a[] = "11111+111";
    DoubleLinkedList tape = createTapeAdd(a);
    Node* pointer = tape.head;
    StateAdd* s = add;
    Node* ptr = tape.head;
        printf("\n");

    while (pointer->next->data== '-' )
    {
        pointer = pointer->next;
    }
    printf("%c",pointer->data );

    while (s->state != -1)
    {
        
    // -/-,R   0->1
        if (s->state == 0 && pointer->data == '-')
        {                      
                  waitFor(1);
                  clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '-';
                           // waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
            pointer = pointer->next;
        }

        // 1/1,R   1->1
       else if (s->state == 1 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            // waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->self;
            pointer = pointer->next;

        } 

        // +/1,R   1->2
       else if (s->state == 1 && pointer->data == '+')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
             waitFor(1);
   displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
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

        // -/-,L   2->3
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

        // 1/-,S  3->4
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
    
}


DoubleLinkedList createTapeSub(char c[])
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

typedef struct statess{
    int state;
    struct statess* self;
    struct statess* next;
}StateSub;

void subtraction(char a[])
{
              // Loop until it arrives.


    StateSub* ss = (StateSub*)malloc(sizeof(StateSub));
    StateSub* createhelper = ss;
    createhelper->self = NULL;
    createhelper->state = 0;

    
    createhelper->next = (StateSub*)malloc(sizeof(StateSub));
    createhelper = createhelper->next;
    createhelper->self = NULL;
    createhelper->state = 1;
    StateSub* oneptr = createhelper;

    createhelper->next = (StateSub*)malloc(sizeof(StateSub));
    createhelper = createhelper->next;
    createhelper->self = createhelper;
    createhelper->state = 2;


    createhelper->next = (StateSub*)malloc(sizeof(StateSub));
    createhelper = createhelper->next;
    createhelper->self = createhelper;
    createhelper->state = 3;


    createhelper->next = (StateSub*)malloc(sizeof(StateSub));
    createhelper = createhelper->next;
    createhelper->self = NULL;
    createhelper->state = 4;


    createhelper->next = (StateSub*)malloc(sizeof(StateSub));
    createhelper = createhelper->next;
    StateSub* fiveptr = createhelper;
   // createhelper->self = createhelper; //points at halt -1
    createhelper->state = 5;
   // printf("%i", createhelper->state);
    createhelper->self = (StateSub*)malloc(sizeof(StateSub));
    createhelper = createhelper->self;
    StateSub* haltptr = createhelper;

    createhelper->self = NULL;
    createhelper->state = -1;
    createhelper->next = NULL;

    createhelper = fiveptr;

    createhelper->next = (StateSub*)malloc(sizeof(StateSub));
    createhelper = createhelper->next;
    createhelper->self = createhelper;
    createhelper->state = 6;
   // printf("%i", createhelper->state);

    createhelper->next = (StateSub*)malloc(sizeof(StateSub));
    createhelper = createhelper->next;
    createhelper->self = haltptr; // points at halt -1
    createhelper->state = 7;

    StateSub* svnptr = createhelper;

    createhelper->next = (StateSub*)malloc(sizeof(StateSub));
    createhelper = createhelper->next;
    createhelper->self = createhelper;
    createhelper->state = 8;

    createhelper->next = oneptr;
    printf("%i", ss->next->state);


   // char a[] = "111111+11";
    DoubleLinkedList tape = createTapeSub(a);
    Node* pointer = tape.head;
    StateSub* s = ss;
    Node* ptr = tape.head;
        printf("\n");
    // for (int i = 0; i < 48; i++)
    // {
    //     printf("%c",ptr->data );
    //     ptr = ptr->next;
    // }
    while (pointer->next->data== '-' )
    {
        pointer = pointer->next;
    }
    printf("%c",pointer->data );

    //func
    while (s->state != -1)
    {   // -/-,R   0->1
        if (s->state == 0 && pointer->data == '-')
        {                      
                  waitFor(1);
                  clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '-';
                          //  waitFor(1);
  //  displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
            pointer = pointer->next;


    
        }
        // 1/-,R   1->2
       else if (s->state == 1 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '-';
                           // waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
            pointer = pointer->next;

        }
        // 1/1,r  2->2
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
        // -/-,r  2->3
     else   if (s->state == 2 && pointer->data == '+')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '+';
                            waitFor(1);
                            clrscr();
    displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
            pointer = pointer->next;

        }
        // 1/1,r   3->3
      else  if (s->state == 3 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
                           waitFor(1);
                           clrscr();
    displayDoubleLinkekdList1(tape, pointer);
            s = s->self;
            pointer = pointer->next;

        }
        // -/-,L  3->4
     else   if (s->state == 3 && pointer->data == '-')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '-';
                            waitFor(1);
                            clrscr();
    displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
            pointer = pointer->previous;

        }

    // 1/-,L  4->5
     else   if (s->state == 4 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '-';
                            waitFor(1);
                            clrscr();
    displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
            pointer = pointer->previous;

        }
    
    // +/-,n  5->halt
     else   if (s->state == 5 && pointer->data == '+')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '-';
                            waitFor(1);
                            clrscr();
    displayDoubleLinkekdList1(tape, pointer);
            s = s->self; //halt
           // pointer = pointer->previous;

        }

    // 1/1,L  5->6
     else   if (s->state == 5 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
                            waitFor(1);
                            clrscr();
    displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
            pointer = pointer->previous;

        }

        // 1/1,L  6->6
     else   if (s->state == 6 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
                            waitFor(1);
                            clrscr();
    displayDoubleLinkekdList1(tape, pointer);
            s = s->self;
            pointer = pointer->previous;

        }
        
     // +/+,L  6-7
     else   if (s->state == 6 && pointer->data == '+')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '+';
                            waitFor(1);
                            clrscr();
    displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
            pointer = pointer->previous;

        }   

    // -/-,S  7->halt
     else   if (s->state == 7 && pointer->data == '-')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '-';
                            waitFor(1);
                            clrscr();
    displayDoubleLinkekdList1(tape, pointer);
            s = s->self; //halt
            //pointer = pointer->previous;

        }

    // 1/1,L  7->8
     else   if (s->state == 7 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
                            waitFor(1);
                            clrscr();
    displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
            pointer = pointer->previous;

        }

    // 1/1,L  8->8
     else   if (s->state == 8 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
                            waitFor(1);
                            clrscr();
    displayDoubleLinkekdList1(tape, pointer);
            s = s->self;
            pointer = pointer->previous;

        }    

    // -/-,r  8->1
     else   if (s->state == 8 && pointer->data == '-')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '-';
                            waitFor(1);
                            clrscr();
    displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
            pointer = pointer->next;

        }
    }
     displayDoubleLinkekdList1(tape, pointer);
}


DoubleLinkedList createTapeFac(char c[])
{   
    int l = 20;
    DoubleLinkedList d = newDoubleLinkedList(d,'-');
    for (int ii = 0; ii < 10; ii++)
{
    d = insertEndDoubleLinkedList(d, '-');
}

for (int i = 0; c[i] != '\0'; i++)
{
    d = insertEndDoubleLinkedList(d, c[i]);
}
    for (int ii = 0; ii < 50; ii++)
{
    d = insertEndDoubleLinkedList(d, '-');
}

    return d;
}

typedef struct state{
    int state;
    struct state* first;//first
    struct state* second;
    struct state* third;
}StateFac;


void factorial(char a[])
{
    StateFac* fac = (StateFac*)malloc(sizeof(StateFac));
    StateFac* zero = fac;
    zero->state = 0;

    StateFac* one = (StateFac*)malloc(sizeof(StateFac));
    one->first = NULL;
    one->state = 1;

        StateFac* two = (StateFac*)malloc(sizeof(StateFac));
    two->first = NULL;
    two->state = 2;

        StateFac* three = (StateFac*)malloc(sizeof(StateFac));
    three->first = NULL;
    three->state = 3;

        StateFac* four = (StateFac*)malloc(sizeof(StateFac));
    four->first = NULL;
    four->state = 4;

        StateFac* five = (StateFac*)malloc(sizeof(StateFac));
    five->first = NULL;
    five->state = 5;

        StateFac* six = (StateFac*)malloc(sizeof(StateFac));
    six->first = NULL;
    six->state = 6;

        StateFac*seven = (StateFac*)malloc(sizeof(StateFac));
    seven->first = NULL;
    seven->state = 7;

        StateFac* eight = (StateFac*)malloc(sizeof(StateFac));
    eight->first = NULL;
    eight->state = 8;

        StateFac* nine = (StateFac*)malloc(sizeof(StateFac));
    nine->first = NULL;
    nine->state = 9;

        StateFac* ten = (StateFac*)malloc(sizeof(StateFac));
    ten->first = NULL;
    ten->state = 10;

        StateFac* eleven = (StateFac*)malloc(sizeof(StateFac));
    eleven->first = NULL;
    eleven->state = 11;

        StateFac* twelve = (StateFac*)malloc(sizeof(StateFac));
    twelve->first = NULL;
    twelve->state = 12;

        StateFac* thirteen = (StateFac*)malloc(sizeof(StateFac));
    thirteen->first = NULL;
    thirteen->state = 13;

        StateFac* forteen = (StateFac*)malloc(sizeof(StateFac));
    forteen->first = NULL;
    forteen->state = 14;

        StateFac* fifteen = (StateFac*)malloc(sizeof(StateFac));
    fifteen->first = NULL;
    fifteen->state = 15;

        StateFac* sixteen = (StateFac*)malloc(sizeof(StateFac));
    sixteen->first = NULL;
    sixteen->state = 16;

        StateFac* seventeen = (StateFac*)malloc(sizeof(StateFac));
    seventeen->first = NULL;
    seventeen->state = 17;

        StateFac* eighteen = (StateFac*)malloc(sizeof(StateFac));
    eighteen->first = NULL;
    eighteen->state = 18;

        StateFac* nineteen = (StateFac*)malloc(sizeof(StateFac));
    nineteen->first = NULL;
    nineteen->state = 19;

        StateFac* twenty = (StateFac*)malloc(sizeof(StateFac));
    twenty->first = NULL;
    twenty->state = 20;

        StateFac* twentyone = (StateFac*)malloc(sizeof(StateFac));
    twentyone->first = NULL;
    twentyone->state = 21;

        StateFac* twentytwo = (StateFac*)malloc(sizeof(StateFac));
    twentytwo->first = NULL;
    twentytwo->state = 22;


        StateFac* twentythree = (StateFac*)malloc(sizeof(StateFac));
    twentythree->first = NULL;
    twentythree->state = 23;

        StateFac* twentfour = (StateFac*)malloc(sizeof(StateFac));
    twentfour->first = NULL;
    twentfour->state = 24;

        StateFac* twentfive = (StateFac*)malloc(sizeof(StateFac));
    twentfive->first = NULL;
    twentfive->state = 25;
//connecting them
    zero->first = zero;
    zero->second = one;
    one->second = two;
    one->first = one;
    two->first = three;
    two->second = five;
    three->second = four;
    three->first = three;
    four->first = four;
    four->second = two;
    five->second = seven;
    five->first = five;
    six->first = six;
    six->second = sixteen;
    seven->first = seven;
    seven->second = eight;
    eight->first = nine;
    //ei->second = nine;
    nine->first = six;
    nine->second = ten;
    ten->first = ten;
    ten->second = eleven;
    eleven->first= twelve;
    eleven->second = forteen;
    twelve->first = twelve;
    twelve->second = thirteen;
    thirteen->first = thirteen;
    thirteen->second = eleven;
    forteen->first = forteen;
    forteen->second = fifteen;
    fifteen->first = fifteen;
    fifteen->second = nine;
    sixteen->first = seventeen;
    sixteen->second = twentfive;
    seventeen->first = eighteen;
    seventeen->second = nineteen;
    eighteen->first = eighteen;
    eighteen->second = twentytwo;
    eighteen->third = twentfour;
    nineteen->first = nineteen;
    nineteen->second = twenty;
    twenty->first = twenty;
    twenty->second = twentyone;
    twentyone->first = twentyone;
    twentyone->second = six;
    twentytwo->first= twentytwo;
    twentytwo->second = twentythree;
    twentythree->first = twentythree;
    twentythree->second = nine;
    twentfour->first = NULL;

    
//

    //char a[] = "0000";
    DoubleLinkedList tape = createTapeFac(a);
    Node* pointer = tape.head;
    StateFac* s = fac;
    Node* ptr = tape.head;
        printf("\n");

    while (pointer->data== '-' )
    {
        pointer = pointer->next;
    }
    printf("%c",pointer->data );
    
    //func

    while (s->state != 24)
    {
        // 0/0,R   0->0
        if (s->state == 0 && pointer->data == '0')
        {                      
                  waitFor(1);
                  clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
                          //  waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->next;
            printf("\n%i", s->state);
        }

        // -/1,S   0->1
       else if (s->state == 0 && pointer->data == '-')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
             waitFor(1);
  displayDoubleLinkekdList1(tape, pointer);
            s = s->second;
            //pointer = pointer->next;
            printf("\n%i", s->state);

        } 

        
        // 1/1,L   1->1
       else if (s->state == 1 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            // waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->previous;
            printf("\n%i", s->state);

        } 

        // 0/0,L   1->1
       else if (s->state == 1 && pointer->data == '0')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
            // waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->previous;
            printf("\n%i", s->state);

        } 

                // -/-,R   1->2
       else if (s->state == 1 && pointer->data == '-')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '-';
            // waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->second;
            pointer = pointer->next;
            printf("\n%i", s->state);
            

        } 
                // 0/x,R   2->3
       else if (s->state == 2 && pointer->data == '0')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = 'X';
             waitFor(1);
   displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->next;
            printf("\n%i", s->state);

        } 

        // 1/1,R   3->3
       else if (s->state == 3 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
           //  waitFor(1);
   //displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->next;
            printf("\n%i", s->state);

        } 

                // 0/0,R   3->3
       else if (s->state == 3 && pointer->data == '0')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
           //  waitFor(1);
   //displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->next;
            printf("\n%i", s->state);

        } 

            // -/0,S   3->4
       else if (s->state == 3 && pointer->data == '-')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
            waitFor(1);
   displayDoubleLinkekdList1(tape, pointer);
            s = s->second;
           // pointer = pointer->next;
printf("\n%i", s->state);
        } 

        // 0/0,L   4->4
       else if (s->state == 4 && pointer->data == '0')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
           //  waitFor(1);
   //displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->previous;
            printf("\n%i", s->state);

        } 

                // 1/1,L   4->4
       else if (s->state == 4 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
           //  waitFor(1);
   //displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->previous;
printf("\n%i", s->state);
        } 
                        // x/x,R   4->2
       else if (s->state == 4 && pointer->data == 'X')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = 'X';
           //  waitFor(1);
   //displayDoubleLinkekdList1(tape, pointer);
            s = s->second;
            pointer = pointer->next;
            printf("\n%i", s->state);

        } 

    // 1/1,R   2->5
       else if (s->state == 2 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
           //  waitFor(1);
   //displayDoubleLinkekdList1(tape, pointer);
            s = s->second;
            pointer = pointer->next;printf("\n%i", s->state);

        } 

    // 0/0,R   5->5
       else if (s->state == 5 && pointer->data == '0')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
           //  waitFor(1);
   //displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->next;
            printf("\n%i", s->state);

        } 

            // -/1,L   5->7
       else if (s->state == 5 && pointer->data == '-')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
             waitFor(1);
   displayDoubleLinkekdList1(tape, pointer);
            s = s->second;
            pointer = pointer->previous;
            printf("\n%i", s->state);

        }

                    // 1/1,L   7->7
       else if (s->state == 7 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
           //  waitFor(1);
   //displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->previous;
            printf("\n%i", s->state);

        }

                            // 0/0,L   7->7
       else if (s->state == 7 && pointer->data == '0')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
           //  waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->previous;
            printf("\n%i", s->state);

        }

         // X/0,L   7->7
       else if (s->state == 7 && pointer->data == 'X')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
             waitFor(1);
   displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->previous;
            printf("\n%i", s->state);

        }

        // -/-,R   7->8
       else if (s->state == 7 && pointer->data == '-')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '-';
             //waitFor(1);
   //displayDoubleLinkekdList1(tape, pointer);
            s = s->second;
            pointer = pointer->next;
            printf("\n%i", s->state);

        }

        // 0/-,R   8->9
       else if (s->state == 8 && pointer->data == '0')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '-';
             waitFor(1);
   displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->next;
printf("\n%i", s->state);
        }

        // 0/X,R   9->10
       else if (s->state == 9 && pointer->data == '0')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = 'X';
             waitFor(1);
   displayDoubleLinkekdList1(tape, pointer);
            s = s->second;
            pointer = pointer->next;
            printf("\n%i", s->state);

        }

                // 0/0,R   10->10
       else if (s->state == 10 && pointer->data == '0')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
             //waitFor(1);
   //displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->next;
            printf("\n%i", s->state);

        }

                        // 1/1,R   10->11
       else if (s->state == 10 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
             //waitFor(1);
   //displayDoubleLinkekdList1(tape, pointer);
            s = s->second;
            pointer = pointer->next;
            printf("\n%i", s->state);

        }

         // 0/X,R   11->12
       else if (s->state == 11 && pointer->data == '0')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = 'X';
             waitFor(1);
   displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->next;
printf("\n%i", s->state);
        }
         // 0/0,R   12->12
       else if (s->state == 12 && pointer->data == '0')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
             //waitFor(1);
   //displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->next;
            printf("\n%i", s->state);

        }

                 // 1/1,R   12->12
       else if (s->state == 12 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
             //waitFor(1);
   //displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->next;
            printf("\n%i", s->state);

        }

                // -/0,S   12->13
       else if (s->state == 12 && pointer->data == '-')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
             waitFor(1);
   displayDoubleLinkekdList1(tape, pointer);
            s = s->second;
            //pointer = pointer->next;
            printf("\n%i", s->state);

        }

                    // 0/0,L   13->13
       else if (s->state == 13 && pointer->data == '0')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
           //  waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->previous;
            printf("\n%i", s->state);

        }
            // 1/1,L   13->13
       else if (s->state == 13 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
           //  waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->previous;
printf("\n%i", s->state);
        }

                // X/X,R   13->11
       else if (s->state == 13 && pointer->data == 'X')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = 'X';
           //  waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->second;
            pointer = pointer->next;
            printf("\n%i", s->state);

        }

        // 1/1,L   11->14
       else if (s->state == 11 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
           //  waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->second;
            pointer = pointer->previous;
            printf("\n%i", s->state);

        }

                // x/0,L   14->14
       else if (s->state == 14 && pointer->data == 'X')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
           //  waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->previous;
            printf("\n%i", s->state);

        }

                        // 1/1,L   14->15
       else if (s->state == 14 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
           //  waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->second;
            pointer = pointer->previous;
            printf("\n%i", s->state);

        }


         // 1/0,L   15->15
       else if (s->state == 15 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
             waitFor(1);
   displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->previous;
printf("\n%i", s->state);
        }

                // 0/0,L   15->15
       else if (s->state == 15 && pointer->data == '0')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
           //  waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->previous;printf("\n%i", s->state);

        }


                // x/x,r   15->9
       else if (s->state == 15 && pointer->data == 'X')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = 'X';
           //  waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->second;
            pointer = pointer->next;
printf("\n%i", s->state);
        }   

                        // 1/1,l   9->6
       else if (s->state == 9 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
           //  waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->previous;
            printf("\n%i", s->state);

        }     

    
                            // 1/1,l   6->6
       else if (s->state == 6 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
           //  waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->previous;
            printf("\n%i", s->state);

        }  

             // x/x,l   6->6
       else if (s->state == 6 && pointer->data == 'X')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = 'X';
           //  waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->previous;
            printf("\n%i", s->state);

        }    

           // 0/0,l   6->6
       else if (s->state == 6 && pointer->data == '0')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
           //  waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->previous;
            printf("\n%i", s->state);

        }   

           //-/-,r   6->16
       else if (s->state == 6 && pointer->data == '-')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '-';
           //  waitFor(1);
   ///displayDoubleLinkekdList1(tape, pointer);
            s = s->second;
            pointer = pointer->next;
        printf("\n%i",s->state);
        } 
        // x/-,r   16->17
       else if (s->state == 16 && pointer->data == 'X')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '-';
             waitFor(1);
   displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->next;
           printf("\n%i",s->state);
            
        }   
        // x/x,r   17->19
       else if (s->state == 17 && pointer->data == 'X')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = 'X';
            // waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->second;
            pointer = pointer->next; 
            printf("\n%i", s->state); 
        } 

        // x/x,r   19->19
       else if (s->state == 19 && pointer->data == 'X')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = 'X';
            // waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->next; 
            printf("\n%i", s->state); 
        } 

        // 0/0,r   19->19
       else if (s->state == 19 && pointer->data == '0')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
            // waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->next; 
            printf("\n%i", s->state); 
        } 

        // 1/1,r   19->20
       else if (s->state == 19 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            // waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->second;
            pointer = pointer->next; 
            printf("\n%i", s->state); 
        } 

        // x/x,r   20->20
       else if (s->state == 20 && pointer->data == 'X')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = 'X';
            // waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->next;  
            printf("\n%i", s->state);
        } 

            // 0/0,r   20->20
       else if (s->state == 20 && pointer->data == '0')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
            // waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->next;  
            printf("\n%i", s->state);
        } 

            // 1/1,l   20->21
       else if (s->state == 20 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            // waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->second;
            pointer = pointer->previous;
            printf("\n%i", s->state);  
        } 

                // x/x,l   21->21
       else if (s->state == 21 && pointer->data == 'X')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = 'X';
            // waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->previous;  
            printf("\n%i", s->state);
        } 

     // 1/x,l   21->6
       else if (s->state == 21 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = 'X';
            // waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->second;
            pointer = pointer->previous;  
            printf("\n%i", s->state);
        } 

     // 0/x,l   21->6
       else if (s->state == 21 && pointer->data == '0')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = 'X';
            // waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->second;
            pointer = pointer->previous;  
            printf("\n%i", s->state);
        } 

         // 1/-,r   17->18
       else if (s->state == 17 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '-';
             waitFor(1);
  displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->next;  
            printf("\n%i", s->state);
        } 
         // 0/-,r   17->18
       else if (s->state == 17 && pointer->data == '0')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '-';
             waitFor(1);
  displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->next;  
            printf("\n%i", s->state);
        } 
         // 0/-,r   18->18
       else if (s->state == 18 && pointer->data == '0')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '-';
             waitFor(1);
  displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->next;  
            printf("\n%i", s->state);
        } 
         // x/x,r   18->22
       else if (s->state == 18 && pointer->data == 'X')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = 'X';
            // waitFor(1);
  //displayDoubleLinkekdList1(tape, pointer);
            s = s->second;
            pointer = pointer->next;  
            printf("\n%i", s->state);
        } 
         // x/x,r   22->22
       else if (s->state == 22 && pointer->data == 'X')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = 'X';
            // waitFor(1);
  //displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->next;  
            printf("\n%i", s->state);
        }

             // 0/0,r   22->22
       else if (s->state == 22 && pointer->data == '0')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
            // waitFor(1);
  //displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->next;  
            printf("\n%i", s->state);
        } 

          // 1/1,r   22->22
       else if (s->state == 22 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            // waitFor(1);
  //displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->next;  
            printf("\n%i", s->state);
        } 

          // -/1,l   22->23
       else if (s->state == 22 && pointer->data == '-')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            // waitFor(1);
  //displayDoubleLinkekdList1(tape, pointer);
            s = s->second;
            pointer = pointer->previous;  
            printf("\n%i", s->state);
        } 

          // 1/1,l   23->23
       else if (s->state == 23 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            // waitFor(1);
  //displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->previous;  
            printf("\n%i", s->state);
        } 
          // 0/0,l   23->23
       else if (s->state == 23 && pointer->data == '0')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
            // waitFor(1);
  //displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->previous;  
            printf("\n%i", s->state);
        } 

          // x/0,r   23->23
       else if (s->state == 23 && pointer->data == 'X')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
             waitFor(1);
  displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->next;  
            printf("\n%i", s->state);
        } 
          // -/-,r   23->9
       else if (s->state == 23 && pointer->data == '-')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
             waitFor(1);
  displayDoubleLinkekdList1(tape, pointer);
            s = s->second;
            pointer = pointer->next;  
            printf("\n%i", s->state);
        } 

          // 1/-,r   16->25
       else if (s->state == 16 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '-';
             waitFor(1);
  displayDoubleLinkekdList1(tape, pointer);
            s = s->second;
            pointer = pointer->next;  
            printf("\n%i", s->state);
        } 

          // 1/-,r   25->25
       else if (s->state == 25 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '-';
             waitFor(1);
  displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->next;  
            printf("\n%i", s->state);
        } 

          // 0/0,r   25->25
       else if (s->state == 25 && pointer->data == '0')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
          //   waitFor(1);
  //displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->next;  
            printf("\n%i", s->state);
        } 
          // -/-,s   25->halt
       else if (s->state == 25 && pointer->data == '-')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '-';
          //   waitFor(1);
  //displayDoubleLinkekdList1(tape, pointer);
            s = s->second;
            //pointer = pointer->next;  
            printf("\n%i", s->state);
        } 

              // 1/-,s   18->halt
       else if (s->state == 18 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '-';
            waitFor(1);
  displayDoubleLinkekdList1(tape, pointer);
            s = s->third;
            //pointer = pointer->next;  
            printf("\n%i", s->state);
        } 

    }
    


}

DoubleLinkedList t(char c[])
{   
    int l = 20;
    DoubleLinkedList d = newDoubleLinkedList(d,'-');
    for (int ii = 0; ii < 30; ii++)
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

typedef struct statebb{
    int state;
    struct statebb* self;
    struct statebb* next;
}State;

int bin(char a[])

{
    
    

    State* ss = (State*)malloc(sizeof(State));
    ss->self = ss;
    ss->state = 0;
     ss->next = (State*)malloc(sizeof(State));
     ss->next->self = ss->next;
     ss->next->state = 1;
     
     ss->next->next = (State*)malloc(sizeof(State));
     ss->next->next->self = ss->next->next;
      ss->next->next->state = 2;
      ss->next->next->next = NULL;

    //int a[10] = {1,1,1,0,1,1,1,1,1,1};
    //char a[] = "1110111111";
    //char a[10] = {'1','0','1','0','1','0','1','0','1','0'};
    DoubleLinkedList tape = t(a);
    Node* pointer = tape.head;
    State* s = ss;
    Node* ptr = tape.head;
    printf("\n");
    for (int i = 0; i < 30; i++)
    {
        printf("%c",ptr->data );
        ptr = ptr->next;
    }
    while (pointer->data== '-' )
    {
        pointer = pointer->next;
    }
    while (s->state != 2)
    {   // 1/1,R   0->0
        if (s->state == 0 && pointer->data == '1')
        {                      
                  waitFor(1);
                  clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
                          //  waitFor(1);
  //  displayDoubleLinkekdList1(tape, pointer);
            s = s->self;
            pointer = pointer->next;


    
        }
        // 0/0,R   0->0
       else if (s->state == 0 && pointer->data == '0')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
                           // waitFor(1);
  // displayDoubleLinkekdList1(tape, pointer);
            s = s->self;
            pointer = pointer->next;

        }
        // b/b,l  0->1
        else if (s->state == 0 && pointer->data == '-')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '-';
                           // waitFor(1);
   // displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
            pointer = pointer->previous;

        }
        // 1/0,L  1->1
     else   if (s->state == 1 && pointer->data == '1')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
                            waitFor(1);
                            clrscr();
    displayDoubleLinkekdList1(tape, pointer);
            s = s->self;
            pointer = pointer->previous;

        }
        // b/1,n   1->2
      else  if (s->state == 1 && pointer->data == '-')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
                           waitFor(1);
                           clrscr();
    displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
           // pointer = pointer->next;

        }
        // 0/1,n  1->2
     else   if (s->state == 1 && pointer->data == '0')
        {                            waitFor(1);
        clrscr();
    displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
                            waitFor(1);
                            clrscr();
    displayDoubleLinkekdList1(tape, pointer);
            s = s->next;
            //pointer = pointer->next;

        }
        
    }
  
    //  Node* ptr2= tape.head;
    //  printf("\n");
    // for (int i = 0; i < 30; i++)
    // {
    //     printf("%c",ptr2->data );
    //     ptr2 = ptr2->next;
    // }
    // waitFor(1);
   // displayDoubleLinkekdList(tape, pointer);

    return 0;
}


char arrd[100];

char arrf[100];
char arrm[100];
char arrb[100];

char arrs[100];
char arra[100];
int main()
{
    
    int n=0;
    int c = 1;
    
    int choice;
    while (c)
    {
        printf("\n\t\t* * * MENU * * *");
        printf("\n1:add");
        printf("\n2.sub");
        printf("\n3.mul ");
        printf("\n4.div");
        printf("\n5.faactorial");
        printf("\n6.bin inc");
        printf("\n0.exit");
        printf("\n\n give your choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            
            scanf("%s", &arra);
                
                addition(arra);
                break;
            case 2:
                        
            scanf("%s", &arrs);
                subtraction(arrs);
                break;
            case 3:
                        
            scanf("%s", &arrm);
                 multiplication(arrm);
                break;
            case 4:
                        
            scanf("%s", &arrd);
                division(arrd);
                break;
            case 5:
                        
            scanf("%s", &arrf);
                factorial(arrf);
                break;
            case 6:
                scanf("%s", &arrb);
                bin(arrb);
                break;

            case 0:
             c = 0;
        }

    }
       


    
}