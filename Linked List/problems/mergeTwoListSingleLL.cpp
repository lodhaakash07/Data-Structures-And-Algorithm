/* Report errors in the comment below */
/* 
Author = Akash Lodha
Date - 20/9/2013
Program - Add nodes to a list
        Reverse it
        Merge the two lists
        Using only a single liked list
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
            int data;
            node *next;      
           }*head,*root;
           
void addNodes(int value);
void buildReverse(struct node*);
void display();

void display()
      {
      struct node *temp = head;
      if(head==NULL)
         printf("Nothing to display");        
      else
          {
          while(temp!=NULL)
             {
             printf("%d ",temp->data);
             temp = temp->next;
             }               
          }
      }

void buildReverse(struct node *temp)
     {
     if(temp!=NULL)
          {         
          buildReverse(temp->next);//Back Tracking
          struct node *temp1 = (struct node*)malloc(sizeof(struct node));
          temp1->data = temp->data;
          temp1->next = NULL;
          root->next = temp1;
          root = temp1;                
          }                      
     }

//Adding new nodes to the Linked List           
void addNodes(int value)
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
      printf("ctr+z and enter to stop adding nodes\n");
      int n;
      while((scanf("%d",&n))!=EOF)
            addNodes(n);
      buildReverse(head);
      display();
      getch();          
      }           
