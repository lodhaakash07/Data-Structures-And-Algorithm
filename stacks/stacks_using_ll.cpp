/*
Author - Akash Lodha
Date - 9/12/13
Topic - Implementation of stack using Arrays
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void push(int);
void pop();
void display();

struct stack
       {
       int value;
       struct stack *next;     
       }*top;

//Function To add a node to the stack
void push(int value)
     {
     /*To add we store the new value in a temporary variable temp
       To the next pointer of temp assing the stack
       move the pointer of stack to temp     
       Linked List memory is dynamically allocated , therfor no need to check for oerflow
     */         
     struct stack *temp;
     temp = (struct stack*)malloc(sizeof(struct stack));
     temp->value = value;
     temp->next = NULL;
     /*
       top==NULL
       It executes when we add the first element to the stack
       */
     if(top==NULL)
          {
          top = temp;
          top ->next = NULL;
          }
     else
         {
         temp ->next = top;
         top = temp; 
         top->next = NULL;              
         }      
     }      


//Function to delete a node from the stack     
void pop()      
    {
    struct stack *temp=top;           
    if(top==NULL)
        //Underflow occurs when we try to remove a node from empty stack
        printf("Stack Underflow");
    else
        {              
        temp = temp->next;
        top = temp;              
        }               
    }

//Function used to treverse through the stack
void display()
    {
    struct stack *temp=top;
    printf("\n\n");
    while(temp!=NULL)
      {
      printf("%d\n",temp->value);
      temp = temp->next;
      }  
    }
main()
     {
     int n;
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
                      int value;
                      printf("Enter the value:\n");                     
                      scanf("%d",&value);                     
                      push(value);
                      break;}
                case 2:{
                      pop();
                      break;}
                case 3:{
                      display();
                      break;}
                case 4:
                       exit(1);
                default:
                       printf("Wrong input, Try Again");                     
                }   
           printf("\n\n");       
           }      
     }     
