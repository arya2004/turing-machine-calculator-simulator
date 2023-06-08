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


void factorial()
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

    char a[] = "0000";
    DoubleLinkedList tape = createTapeFac(a);
    Node* pointer = tape.head;
    StateFac* s = fac;
    Node* ptr = tape.head;
    printf("\n");

    while (pointer->data== ' ' )
    {
        pointer = pointer->next;
    }
    
    //func

    while (s->state != 24)
    {
        // 0/0,R   0->0
        if (s->state == 0 && pointer->data == '0')
        {                      
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
            s = s->first;
            pointer = pointer->next;
        }

        // -/1,S   0->1
        else if (s->state == 0 && pointer->data == ' ')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            waitFor(1);
            displayDoubleLinkekdList1(tape, pointer);
            s = s->second;

        } 


        // 1/1,L   1->1
        else if (s->state == 1 && pointer->data == '1')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            s = s->first;
            pointer = pointer->previous;

        } 

        // 0/0,L   1->1
        else if (s->state == 1 && pointer->data == '0')
        {                           
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
            s = s->first;
            pointer = pointer->previous;

        } 

        // -/-,R   1->2
        else if (s->state == 1 && pointer->data == ' ')
        {                          
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = ' ';
            s = s->second;
            pointer = pointer->next;

        } 
        // 0/x,R   2->3
        else if (s->state == 2 && pointer->data == '0')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = 'X';
            waitFor(1);
            displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->next;

        } 

        // 1/1,R   3->3
        else if (s->state == 3 && pointer->data == '1')
        {                          
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            s = s->first;
            pointer = pointer->next;

        } 

        // 0/0,R   3->3
        else if (s->state == 3 && pointer->data == '0')
        {                           
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
            s = s->first;
            pointer = pointer->next;

        } 

        // -/0,S   3->4
        else if (s->state == 3 && pointer->data == ' ')
        {                           
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
            waitFor(1);
            displayDoubleLinkekdList1(tape, pointer);
            s = s->second;
        } 

        // 0/0,L   4->4
        else if (s->state == 4 && pointer->data == '0')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
            s = s->first;
            pointer = pointer->previous;

        } 

        // 1/1,L   4->4
        else if (s->state == 4 && pointer->data == '1')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            s = s->first;
            pointer = pointer->previous;

        } 
        // x/x,R   4->2
        else if (s->state == 4 && pointer->data == 'X')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = 'X';
            s = s->second;
            pointer = pointer->next;

        } 

        // 1/1,R   2->5
        else if (s->state == 2 && pointer->data == '1')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            s = s->second;
            pointer = pointer->next;

        } 

        // 0/0,R   5->5
        else if (s->state == 5 && pointer->data == '0')
        {                           
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
            s = s->first;
            pointer = pointer->next;

        } 

        // -/1,L   5->7
        else if (s->state == 5 && pointer->data == ' ')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            waitFor(1);
            displayDoubleLinkekdList1(tape, pointer);
            s = s->second;
            pointer = pointer->previous;

        }

        // 1/1,L   7->7
        else if (s->state == 7 && pointer->data == '1')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            s = s->first;
            pointer = pointer->previous;

        }

        // 0/0,L   7->7
        else if (s->state == 7 && pointer->data == '0')
        {                           
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
            s = s->first;
            pointer = pointer->previous;

        }

        // X/0,L   7->7
        else if (s->state == 7 && pointer->data == 'X')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
            waitFor(1);
            displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->previous;

        }

        // -/-,R   7->8
        else if (s->state == 7 && pointer->data == ' ')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = ' ';
            s = s->second;
            pointer = pointer->next;

        }

        // 0/-,R   8->9
        else if (s->state == 8 && pointer->data == '0')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = ' ';
            waitFor(1);
            displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->next;

        }

        // 0/X,R   9->10
        else if (s->state == 9 && pointer->data == '0')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = 'X';
            waitFor(1);
            displayDoubleLinkekdList1(tape, pointer);
            s = s->second;
            pointer = pointer->next;

        }

        // 0/0,R   10->10
        else if (s->state == 10 && pointer->data == '0')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
            s = s->first;
            pointer = pointer->next;

        }

        // 1/1,R   10->11
        else if (s->state == 10 && pointer->data == '1')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            s = s->second;
            pointer = pointer->next;

        }

        // 0/X,R   11->12
        else if (s->state == 11 && pointer->data == '0')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = 'X';
            waitFor(1);
            displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->next;
        }
        // 0/0,R   12->12
        else if (s->state == 12 && pointer->data == '0')
        {                           
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
            s = s->first;
            pointer = pointer->next;

        }

        // 1/1,R   12->12
        else if (s->state == 12 && pointer->data == '1')
        {                           
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            s = s->first;
            pointer = pointer->next;


        }

        // -/0,S   12->13
        else if (s->state == 12 && pointer->data == ' ')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
            waitFor(1);
            displayDoubleLinkekdList1(tape, pointer);
            s = s->second;
        }

        // 0/0,L   13->13
        else if (s->state == 13 && pointer->data == '0')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
            s = s->first;
            pointer = pointer->previous;

        }
        // 1/1,L   13->13
        else if (s->state == 13 && pointer->data == '1')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            s = s->first;
            pointer = pointer->previous;

        }

        // X/X,R   13->11
        else if (s->state == 13 && pointer->data == 'X')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = 'X';
            s = s->second;
            pointer = pointer->next;

        }

        // 1/1,L   11->14
        else if (s->state == 11 && pointer->data == '1')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            s = s->second;
            pointer = pointer->previous;

        }

        // x/0,L   14->14
        else if (s->state == 14 && pointer->data == 'X')
        {                           
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
            s = s->first;
            pointer = pointer->previous;

        }

        // 1/1,L   14->15
        else if (s->state == 14 && pointer->data == '1')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            s = s->second;
            pointer = pointer->previous;

        }


        // 1/0,L   15->15
        else if (s->state == 15 && pointer->data == '1')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
            waitFor(1);
            displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->previous;
        }

        // 0/0,L   15->15
        else if (s->state == 15 && pointer->data == '0')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
            s = s->first;
            pointer = pointer->previous;

        }


        // x/x,r   15->9
        else if (s->state == 15 && pointer->data == 'X')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = 'X';
            s = s->second;
            pointer = pointer->next;
        }   

        // 1/1,l   9->6
        else if (s->state == 9 && pointer->data == '1')
        {                           
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            s = s->first;
            pointer = pointer->previous;

        }     


        // 1/1,l   6->6
        else if (s->state == 6 && pointer->data == '1')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            s = s->first;
            pointer = pointer->previous;

        }  

        // x/x,l   6->6
        else if (s->state == 6 && pointer->data == 'X')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = 'X';
            s = s->first;
            pointer = pointer->previous;

        }    

        // 0/0,l   6->6
        else if (s->state == 6 && pointer->data == '0')
        {                           
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
            s = s->first;
            pointer = pointer->previous;

        }   

        //-/-,r   6->16
        else if (s->state == 6 && pointer->data == ' ')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = ' ';
            s = s->second;
            pointer = pointer->next;

        } 

        // x/-,r   16->17
        else if (s->state == 16 && pointer->data == 'X')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = ' ';
            waitFor(1);
            displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->next;

        }   

        // x/x,r   17->19
        else if (s->state == 17 && pointer->data == 'X')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = 'X';
            s = s->second;
            pointer = pointer->next; 
        } 

        // x/x,r   19->19
        else if (s->state == 19 && pointer->data == 'X')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = 'X';
            s = s->first;
            pointer = pointer->next; 
        } 

        // 0/0,r   19->19
        else if (s->state == 19 && pointer->data == '0')
        {                           
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
            s = s->first;
            pointer = pointer->next; 
        } 

        // 1/1,r   19->20
        else if (s->state == 19 && pointer->data == '1')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            s = s->second;
            pointer = pointer->next; 
        } 

        // x/x,r   20->20
        else if (s->state == 20 && pointer->data == 'X')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = 'X';
            s = s->first;
            pointer = pointer->next;  
        } 

        // 0/0,r   20->20
        else if (s->state == 20 && pointer->data == '0')
        {                           
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
            s = s->first;
            pointer = pointer->next;  
        } 

        // 1/1,l   20->21
        else if (s->state == 20 && pointer->data == '1')
        {                           
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            s = s->second;
            pointer = pointer->previous;

        } 

        // x/x,l   21->21
        else if (s->state == 21 && pointer->data == 'X')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = 'X';
            s = s->first;
            pointer = pointer->previous;  
        } 

        // 1/x,l   21->6
        else if (s->state == 21 && pointer->data == '1')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = 'X';
            s = s->second;
            pointer = pointer->previous;  

        } 

        // 0/x,l   21->6
        else if (s->state == 21 && pointer->data == '0')
        {                          
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = 'X';
            s = s->second;
            pointer = pointer->previous;  

        } 

        // 1/-,r   17->18
        else if (s->state == 17 && pointer->data == '1')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = ' ';
            waitFor(1);
            displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->next;  
        } 

        // 0/-,r   17->18
        else if (s->state == 17 && pointer->data == '0')
        {                           
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = ' ';
            waitFor(1);
            displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->next;  
       
        } 

        // 0/-,r   18->18
        else if (s->state == 18 && pointer->data == '0')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = ' ';
            waitFor(1);
            displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->next;  
        } 

        // x/x,r   18->22
        else if (s->state == 18 && pointer->data == 'X')
        {                          
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = 'X';
            s = s->second;
            pointer = pointer->next;  
        } 

        // x/x,r   22->22
        else if (s->state == 22 && pointer->data == 'X')
        {                          
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = 'X';
            s = s->first;
            pointer = pointer->next;  

        }

        // 0/0,r   22->22
        else if (s->state == 22 && pointer->data == '0')
        {                           
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
            s = s->first;
            pointer = pointer->next;  
        } 

        // 1/1,r   22->22
        else if (s->state == 22 && pointer->data == '1')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            s = s->first;
            pointer = pointer->next;  
        } 

        // -/1,l   22->23
        else if (s->state == 22 && pointer->data == ' ')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            s = s->second;
            pointer = pointer->previous;  
        } 

        // 1/1,l   23->23
        else if (s->state == 23 && pointer->data == '1')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '1';
            s = s->first;
            pointer = pointer->previous;  

        } 
        // 0/0,l   23->23
        else if (s->state == 23 && pointer->data == '0')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
            s = s->first;
            pointer = pointer->previous;  
        } 

        // x/0,r   23->23
        else if (s->state == 23 && pointer->data == 'X')
        {                           
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
            waitFor(1);
            displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->next;  
        } 

        // -/-,r   23->9
        else if (s->state == 23 && pointer->data == ' ')
        {                         
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = ' ';
            waitFor(1);
            displayDoubleLinkekdList1(tape, pointer);
            s = s->second;
            pointer = pointer->next;  
        } 

        // 1/-,r   16->25
        else if (s->state == 16 && pointer->data == '1')
        {                           
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = ' ';
            waitFor(1);
            displayDoubleLinkekdList1(tape, pointer);
            s = s->second;
            pointer = pointer->next;  

        } 

        // 1/-,r   25->25
        else if (s->state == 25 && pointer->data == '1')
        {                         
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = ' ';
            waitFor(1);
            displayDoubleLinkekdList1(tape, pointer);
            s = s->first;
            pointer = pointer->next;  
        } 

        // 0/0,r   25->25
        else if (s->state == 25 && pointer->data == '0')
        {                           
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = '0';
            s = s->first;
            pointer = pointer->next;  

        } 

        // -/-,s   25->halt
        else if (s->state == 25 && pointer->data == ' ')
        {                           
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = ' ';
            s = s->second;
        } 

        // 1/-,s   18->halt
        else if (s->state == 18 && pointer->data == '1')
        {                            
            waitFor(1);
            displayDoubleLinkekdList(tape, pointer);
            pointer->data = ' ';
            waitFor(1);clrscr();
            displayDoubleLinkekdList1(tape, pointer);
            s = s->third;

        } 

    }
    
    zeroDoubleLinkekdList(tape);
    tape = dropLinkedList(tape);

}


