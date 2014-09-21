/*   *** If any error Found in the code ..Please Comment below...*****   */

/*
Author - Akash Lodha
Date - 9/14/13
Topic -   Create two Stacks S1 and S2 
          Identify the bigger stack based on the no of element
*/


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
       {
       int data;
       struct node *next;    
       }*top[2];
//top[0] contains stack s1
//top[1] contains stack s2    

void push(int,int);
void pop(int);
int count(int);
void display(int);

void push(int value,int stack)
     {
     struct node *temp;
     temp = (struct node*)malloc(sizeof(struct node)); 
     temp -> data = value;
     temp -> next = NULL;
     //Adding the first node
     if(top[stack]==NULL)
         top[stack] = temp;
     else
         {
         temp->next = top[stack];
         top[stack] = temp;           
         }                       
     }
     
void pop(int stack)
     {
     struct node *temp = top[stack];   
     //Underflow occurs when there is Empty stack     
     if(top[stack]=NULL)
          printf("Stack UnderFlow");
     else
         {
         temp = temp->next;
         top[stack] = temp;            
         }
     }  
     
void display(int stack)
     {
     struct node *temp=top[stack];
     printf("\n");
     while(temp!=NULL)
      {
      printf("%d\n",temp->data);
      temp = temp->next;
      }            
     } 

//returns the number of nodes contained in the stack     
int count(int stack)
     {
     struct node *temp=top[stack];
     int count=0;
     while(temp!=NULL)
      {
      count++;
      temp = temp->next;
      } 
     return count;            
     }            


void stackOperations(int stack)
        {
        int n;
        printf("Chose from the options:\n");
        while(1)
           {
           printf("1.Push\n");
           printf("2.Pop\n");
           printf("3.Display\n");
           printf("4.Continue\n");
           scanf("%d",&n);
           int flag =0;
           switch(n)
                {
                case 1:{
                      int value;
                      printf("Enter the value:\n");                     
                      scanf("%d",&value);                     
                      push(value,stack);
                      break;}
                case 2:{
                      pop(stack);
                      break;}
                case 3:{
                      display(stack);
                      break ;}
                case 4:{
                       flag =1; 
                       break;}
                default:
                       printf("Wrong input, Try Again");                     
                } 
           if(flag == 1)
                   break;       
           printf("\n\n");       
           }              
      }              

main()
     {
     printf("Access Stack 1:\n");
     stackOperations(0);     
     printf("Access Stack 2:\n"); 
     stackOperations(1);
     //stack1>stack2
     if(count(0)>count(1))
         {
          printf("Bigger stack is s1\n");
          display(0);
         } 
     //stack1<stack2    
     else if(count(0)<count(1))
         { 
          printf("Bigger stack is s2\n");
          display(1);    
         } 
     //stack1 = stack2    
     else 
          printf("Size of both stacks are same\n");   
     getch();     
     }
