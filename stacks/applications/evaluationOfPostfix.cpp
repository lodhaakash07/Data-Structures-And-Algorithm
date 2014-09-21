/*   *** If any error Found in the code ..Please Comment below...*****   */

/*
Author - Akash Lodha
Date - 9/14/13
Topic -   Evaluation of postfix expression using stacks
          stacks implemented using Linked List
*/


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void push(int);
int pop();
void evaluatePostfix();

struct stack
       {
       int value;
       struct stack *next;     
       }*top;
       
void evaluatePostfix()
     {
     char expr[1000];
     printf("Enter the expression:-\n");
     scanf("%s",&expr);                
     /*If there are any variables in the expression
         first get the value of the variable from the user 
         and replace the variable with value in the expression*/
     //loop through the whole string
     for(int i=0;i<strlen(expr);i++)
             {
             if(expr[i]=='+' || expr[i]=='-' || expr[i]=='*' || expr[i]=='/' || expr[i]=='^')
                   continue;                     
             else if(expr[i]<'0' || expr[i]>'9') 
                  {
                  char n;
                  printf("Enter the value of %c:\n",expr[i]);
                  scanf(" %c",&n);     
                  //Replace the variable with corrosponding value in the whole string
                  for(int j=i+1;j<strlen(expr);j++)
                          if(expr[i] == expr[j])
                                  expr[j] = n;   
                  expr[i] = n;                
                  }                       
             } 
     /*Program Logic
               If operand push it to stack
               if operator pop twice 
               do the operation
               push the answer
     */
     int answer = 0;
     for(int i=0;i<strlen(expr);i++)
         {
         if(expr[i]=='+' || expr[i]=='-' || expr[i]=='*' || expr[i]=='/' || expr[i]=='^')
                {
                 int n1 = pop();
                 int n2 = pop();        
                 if(expr[i] == '+')                        
                         answer =  n2+n1;
                 else if(expr[i] == '-') 
                         answer = n2-n1;
                 else if(expr[i] == '*')
                         answer = n2*n1;
                 else if(expr[i] == '/')
                         answer = n2/n1;
                 else if(expr[i] == '^')
                         answer = (int)pow(n2,n1);
                 push(answer);        
                 }        
         else if(expr[i]>='0' && expr[i]<='9')
                {
                 int k = (expr[i]-48);       // Conver char digit to int digit      
                 push(k);
                }               
         }   
     printf("The Answer is :%d\n",answer);                   
     getch();               
     }       

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
         }      
     }      


//Function to delete a node from the stack     
int pop()      
    {
    int n;           
    struct stack *temp=top;           
    if(top==NULL)
        //Underflow occurs when we try to remove a node from empty stack
        {
        // If underflow occurs the expression is wrong
        // Therfore exit the program            
        printf("Stack Underflow");
        printf("Wrong Expression");
        getch();
        exit(1);
        }
    else
        {
        n = temp->value;                             
        temp = temp->next;
        top = temp;              
        } 
    return n;                 
    }
    
main()
     {
     evaluatePostfix();      
     }    
