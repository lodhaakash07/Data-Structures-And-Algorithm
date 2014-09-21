/* Report errors in the comment below */
/* 
Author = Akash Lodha
Date - 20/9/2013
Program - Display Odd Nodes
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
void onlyOddNodes();

      
void onlyOddNodes()
     {
   
         struct node *temp=head; 
         while(temp->next!=NULL)
                {
                if(temp->next->next!=NULL){
                         temp->next = temp->next->next;
                         temp = temp->next;                          
                         } 
                else
                    temp->next = NULL;         
                }
                               
     } 

//Function to display the list
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
         root = temp;
         root->next = NULL;}       
     }            
          
           
main()
      {
      printf("ctr+z and enter to stop adding nodes\n");
      int n;
      while((scanf("%d",&n))!=EOF)
            addNodes(n);
      onlyOddNodes();      
      display();
      getch();          
      }           
