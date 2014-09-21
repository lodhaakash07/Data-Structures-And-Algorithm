/*
Author - Akash Lodha
Date - 9/12/13
Topic - Implementation of stack using Arrays
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int max_size = 4;// Default Maximum Size of The Stack
int top = -1;

int pop(int[]);
void push(int a[]);
void display(int[]);
// Function to remove the toppmost element of the stack
int pop(int stack[])
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
void push(int stack[])
     {
     /*Check if the stack is full
     Overflow occurs when stack is full and we try to push element
     */
              
     if(top==max_size-1)
           printf("Stack Overflow");         
     else
         {
           int value;
           printf("Enter the value:\n");                     
           scanf("%d",&value);
           stack[++top] = value;
         }        
     }
// Function to display the stacks elements 
void display(int stack[])
     {
     for(int i=0;i<=top;i++)
         printf("%d\n",stack[i]);
     }
     
main()
     {
     int n;
     int value;      
     int a[max_size];
     printf("Chose from the options:\n");
     while(1)
           {
           printf("1.Push\n");
           printf("2.Pop\n");
           printf("3.Display\n");
           printf("4.Exit\n");
           scanf("%d",&n);
           switch(n)
                {
                case 1:{
                      push(a);
                      break;}
                case 2:{
                      printf("The popped value is %d\n",pop(a));
                      break;}
                case 3:{
                      display(a);
                      break;}
                case 4:
                       exit(1);
                default:
                       printf("Wrong input, Try Again");                     
                }   
           printf("\n\n");       
           }      
     }     
