/* Report errors in the comments below  */
/* Author - Akash Lodha
   Date - 20/9/2013
   Topic - pOSTFIX TO EXPRESSION TREE
           Evaluation of the expression tree
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void postorder(struct tree *node);
void push(struct tree *node);
struct tree* pop();
int evaluateTree(struct tree *node);

struct tree
       {
       char data;
       tree *left;
       tree *right;    
       }*Tree;
       
struct stack
       {
       struct tree *ptr;
       stack *next;     
       }*top;
       
void push(struct tree *node)       
       {
       struct stack *temp = (struct stack*)malloc(sizeof(struct stack));
       temp->ptr = node;
       temp->next = NULL;
       if(top==NULL)          
          top = temp;
       else
           {
           temp->next = top;
           top = temp;     
           }   
       }
      
struct tree* pop()
       {
       struct stack *temp = top;
       struct tree *temp1 = temp->ptr;         
       temp = temp->next;
       top = temp;                                
       return temp1;   
       }       
       
main()
      {
      char exp[100];
      printf("Enter the Expression\n");
      scanf(" %s",&exp);
      for(int i=0;i<strlen(exp);i++)
            {
            struct tree *node =(struct tree*)malloc(sizeof(struct tree));
            node->data = exp[i];
            node->left = node->right = NULL;                         
            if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' || exp[i]=='^')                        
                  {
                  node->right = pop();
                  node->left=pop();
                  push(node);         
                  }
            else
                push(node);     
            } 
      Tree = pop();
      printf("%d",evaluateTree(Tree));
      getch();            
      } 
      
int evaluateTree(struct tree *node)
    {                   
    if(node!=NULL)
           {
           if(node->data=='+' || node->data=='-'|| node->data=='/'|| node->data=='*'|| node->data=='^')
                  {
                  int x = evaluateTree(node->left);
                  int y = evaluateTree(node->right);
                  if(node->data== '+')
                          return x+y;             
                  else if(node->data== '-')
                          return x-y;
                  else if(node->data== '*')
                          return x*y;                
                  else if(node->data== '/')
                          return x/y;       
                  }   
           return (node->data)-48;              
           }                   
    }                    
