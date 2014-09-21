/*
Author - Akash Lodha
Date - 9/12/13
Topic - Implementation of stack using Arrays
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int max_size = 1000;// Default Maximum Size of The Stack
int stack[1000];
int top = -1;


int pop();
void push(int);
void converionFromDecimalToBinary(int number);

main()
    {
    int number;
    printf("Enter the number\n");
    scanf("%d",&number);
    converionFromDecimalToBinary(number);
    getch();
    }

 void converionFromDecimalToBinary(int n)
    {
    /*Logic- Divide the number by 2
             push the remainder to the stack
             continue step 1 & 2 until the number becomes o
             pop the stack elements
    */                                   
    while(n!=0)
        {
        push(n%2);
        n = n/2;
        }    
    while(top!=-1)
        printf("%d ",pop());        
    }

// Function to remove the toppmost element of the stack
int pop()
    {
    /* First check if the Stack is empty
       Underflow Occurs when we try to pop from an empty stack
       */               
    if(top==-1)
          printf("Stack Underflow");
    else
          //return the topmost element of the stack
          //decrease top by -1
          return stack[top--];              
    }

//Function to push a value  at the top of the stacks
void push(int value)
     {
     /*Check if the stack is full
     Overflow occurs when stack is full and we try to push element
     */
              
     if(top==max_size-1)
           printf("Stack Overflow");         
     else         
           stack[++top] = value;               
     }
