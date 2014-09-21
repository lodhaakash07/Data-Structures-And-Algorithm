/*   *** If any error Found in the code ..Please Comment below...*****   */

/*
Author - Akash Lodha
Date - 9/15/13
Topic -   Paranthesis Checking Using Stacks
          Stacks Implemented Using Linked Lists
*/


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

char pop();
void push(char value);

struct node
       {
       char data;
       struct node *next;    
       }*top;
/* Program Logic
           If ( ,{ or [
            push it to stack
           if ),},]
              pop stack
              if(pop stack != corrosponding opening bracket)
                 Paranthesis not matching
              else
                  continue
           check if anything left in stack,
           if not left ,paranthesis are matching
*/                        
                     
       
main()
     {
     char expr[1000];
     printf("Enter the Expression:\n");
     scanf(" %s",&expr);
     int size = strlen(expr);     
     for(int i=0;i<size;i++)
             {
             int flag = 0;
             if(expr[i]=='{' || expr[i]=='(' || expr[i]=='[')
                     push(expr[i]);
             else if(expr[i]=='}')
                     {
                     char k = pop();
                     if(k!='{')
                          flag = 1;           
                     } 
             else if(expr[i]==']')
                     {
                     char k = pop();
                     if(k!='[')
                          flag=1;           
                     } 
             else if(expr[i]==')')
                     {
                     char k = pop();
                     if(k!='(')
                         flag=1;          
                     }  
               if(flag==1)
                    {
                    printf("Paranthesis Not Matching\n");
                    getch();
                    exit(1);  
                    }             
              }                          
     if(top!=NULL)
              printf("Paranthesis Not Matching\n");
     else
              printf("Paranthesis Matching\n");
     getch();
     }      
       
//Function To add a node to the stack
void push(char value)
     {
     /*To add we store the new value in a temporary variable temp
       To the next pointer of temp assing the stack
       move the pointer of stack to temp     
       Linked List memory is dynamically allocated , therfor no need to check for oerflow
     */         
     struct node *temp;
     temp = (struct node*)malloc(sizeof(struct node));
     temp->data = value;
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
         }      
     }      


//Function to delete a node from the stack     
char pop()      
    {
    char n;            
    struct node *temp=top;           
    if(top==NULL)
        {
        //Underflow occurs when we try to remove a node from empty stack
        printf("Paranthesis Not matching");
        getch();
        exit(1);
        free(top);
        }
    else
        {      
        n =  temp->data;              
        temp = temp->next;
        top = temp;              
        }     
    return n;              
    }       
