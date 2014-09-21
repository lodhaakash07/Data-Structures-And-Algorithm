/* Report errors in the comment below */
/* 
Author = Akash Lodha
Date - 20/9/2013
Program - Displaying singly Linked in reverse manner
*/

#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
            char data;
            node *next;      
           }*head,*root;
int number=0;           
           
void addNodes(int value);
int displayReverse(struct node*);

int displayReverse(struct node *temp)
     {
     if(temp!=NULL)
          {         
          displayReverse(temp->next);//Back Tracking
          number =  number + ((temp->data)-48)*10;         
          }                      
     }

//Adding new nodes to the Linked List           
void addNodes(char value)
     {
     struct node *temp = (struct node*)malloc(sizeof(struct node));
     temp->data = value;
     temp->next = NULL;
     if(head==NULL)
           head = root=temp;
     else
         {
         root->next = temp;
         root = temp;}       
     }            
           
           
main()
      {
      char n[1000];
      printf("Enter the Number\n");
      scanf("%s",&n);
      for(int i=0;i<strlen(n);i++)
             addNodes(n[i]);
      printf("Revers is \n");       
      printf("%d",displayReverse(head));
      getch();       
      }           
