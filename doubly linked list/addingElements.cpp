/*   *** If any error Found in the code ..Please Comment below...*****   */

/*
Author - Akash Lodha
Date - 9/17/13
Topic - Adding Nodes to a Doubly Linked List
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void addNodes(int);
void display();
void displayReverse();

struct node
       {
       int data;
       node *next;//points to the next node
       node *prev;//points to the previous node          
       }*head,*root;
//  head points to the startting node
//  root points to the current node

//Add Notes to the Linked List
void addNodes(int value) 
     {
     struct node *temp;
     temp = (struct node*)malloc(sizeof(struct node));
     temp->data = value;
     temp->prev = temp->next = NULL;             
     if(head==NULL)
          head = root = temp;
     else
         {
         temp->prev = root;      
         root->next =  temp;
         root = temp;    
         }          
     }
     
//Display The Linked List     
void display()
     {
     struct node *temp=head;
     /*
     head always points to the 1st position
     so traverse the list and print it
     */
     if(temp==NULL)
            printf("Nothing to Dispaly \n");
     else
         while(temp!=NULL)
                 {
                 printf("%d ",temp->data);
                 temp = temp->next;         
                 }  
     printf("\n");                          
     }    
    
    
//Display the Linked list in reverse order     
void displayReverse()
     {
     struct node *temp=root;
     /*
     root points to the current location
     traverse the list using temp->prev
     print the nodes*/
     if(temp==NULL)
            printf("Nothing to Dispaly \n");
     else
         while(temp!=NULL)
                 {
                 printf("%d ",temp->data);
                 temp = temp->prev;         
                 }  
     printf("\n");                          
     }      
    
main()
      {
      int n;
      printf("Enter from the following option\n");
      while(1)
              {
              printf("1.Add Elements to the Linked List \n");
              printf("2.Display Element \n");   
              printf("3.Display Reverse\n");
              printf("4.Exit\n");   
              scanf("%d",&n);
              switch(n)
                  {
                  case 1:{
                          printf("Enter the Value:\n");
                          int value;
                          scanf("%d",&value);
                          addNodes(value);
                          break;
                          }
                  case 2:{
                         display();
                         break; 
                          }  
                  case 3:{
                         displayReverse();
                         break; 
                          }          
                  case 4:
                         exit(1);         
                  default:
                          printf("Wrong Input\n");            
                            
                  }
              printf("\n\n");    
              }                    
      }        
       
