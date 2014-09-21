/* Report errors in the comment below */
/* 
Author = Akash Lodha
Date - 20/9/2013
Program - Displaying singly Linked in reverse manner
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
            int data;
            node *next;      
           }*head,*root;
           
void addNodes(int value);
void displayReverse(struct node*);

void displayReverse(struct node *temp)
     {
     if(temp!=NULL)
          {         
          displayReverse(temp->next);//Back Tracking
          printf("%d ",temp->data);         
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
      while(1)
             {
             printf("\n\nChose From Options\n");
             printf("1.Add Elements\n"); 
             printf("2.Display Reverse\n");
             printf("3.Exit\n");
             int n;
             scanf("%d",&n);
             switch(n)
                      {
                      case 1:{
                              int value;
                              printf("Enter the value:\n");
                              scanf("%d",&value);
                              addNodes(value);
                              break;
                              }     
                      case 2:
                             {
                             displayReverse(head);       
                             break;
                             }    
                      case 3:
                           exit(1);
                      default:
                              printf("Wrong Input\n");                 
                      }   
             }     
      }           
