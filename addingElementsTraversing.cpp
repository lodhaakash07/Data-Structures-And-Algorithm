/*
Author - Akash Lodha
Date - 9/12/13
Topic - Implementation of Singly Linked list
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void add_Element(int);
void display_Traversing();

struct node
    {
    int data;
    struct node *next;
    }*root,*head;

//Function To add elements to the Linked Lists
void add_Element(int value)
    {
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;
    //head == NULL . This condition is satisfied When we add the first node to the Linked List
    if(head==NULL)
        root=head=temp;         
    else
        {
        root->next = temp;
        root= temp;        
        }    
    } 

//Traversing through the Linked List
void display_Traversing()
    {
    struct node *temp=head;
    // First check if there is any node or not
    if(head==NULL)
        printf("Linked List is Empty");
    else
        {
        while(temp!=NULL)
            {
            printf("%d ",temp->data);
            temp = temp->next;
            }    
        }    
    }
    
main()	
	{
	int n;
    printf("Chose from the options:\n");
    while(1)
           {
           printf("\n1.Add elements to the Linked List \n");
           printf("2.Display The elements \n");
           printf("3.exit \n");
           scanf("%d",&n);
           switch(n)
                {
                case 1:{
               		   int value;
               		   printf("Enter the value to add\n"); 
      		           scanf("%d",&value);
                	   add_Element(value);
                	   break;
                	   }
                case 2:{
                	   display_Traversing();
                	   break;
                	   }
                case 3:
                       exit(1);	   
                default:
                		printf("Wrong Input!!!\n");
                }
           printf("\n\n");     	
           }     	
	}    
