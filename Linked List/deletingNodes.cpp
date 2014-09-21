/*   *** If any error Found in the code ..Please Comment below...*****   */

/*
Author - Akash Lodha
Date - 9/14/13
Topic -   Deleting At Start
          Deleting At End
          Deleting At Any Position
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void add_Element(int);
void display_Traversing();
int countNodes();
int getvalue();
void deleteFirstNode();
void deleteAtPosition(int pos);

struct node
    {
    int data;
    struct node *next;
    }*root,*head;

//Function To Delete the First Node    
void deleteFirstNode()
     {
     //Check if there are any nodes
     if(head==NULL)
           printf("EMpty List");
     else
         head = head->next;                      
     }   
     
//Function To delete the last Node
void deleteLastNode() 
     {
     //Check if there are any nodes
     if(head==NULL)
           printf("EMpty List");
     else
         {
         struct node *temp=head,*prev=NULL;
         //WHEN THERE IS JUST ONE NODE
         if(temp->next == NULL)
             head = NULL;
         else  
               {  
               //traverse one less than the last node     
               while(temp->next!=NULL)
                    {
                    prev = temp;                  
                    temp = temp->next;
                    }
               prev->next=NULL;  
               }                     
         }                       
     }   
     
//fUNCTION TO DELETE AT SPECIFIC PISTION
void deleteAtPosition(int position)
     {
     //First check if the position exsists
     //countNodes() returns the total number of nodes                      
     if(position>countNodes())
         printf("Enter valid Position");           
     else                     
         {
         //delete the first node                     
         if(position==1)
                deleteFirstNode();
         //delete last node       
         else if(position==countNodes())
                deleteLastNode();
         else
             {
             struct node *temp,*curr=head,*prev=curr;   
             /*traverse to the position and delete the node
                        prev contains all the elements before the delete position
                        curr conatins all the position after the delete position
             */
             for(int i=1;i<position;i++)
                   {
                   prev = curr;                       
                   curr = curr->next;                   
                   }       
             prev->next = NULL;
             prev->next = curr->next;                    
             }                          
         }
     }      
    
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
        // move the pointer of temp till it become null               
        while(temp!=NULL)
            {
            printf("%d ",temp->data);
            temp = temp->next;
            }    
        }    
    }
    
//Count the number of Nodes
int countNodes()
     {
     int count = 0;
     struct node *temp=head;
     while(temp!=NULL)
         {
         temp = temp->next;             
         count++;             
         }
     return count;           
     }   
     
         
//Function To get the new Node    
int getvalue()
     {
     int value;
     printf("Enter the value to add\n"); 
     scanf("%d",&value);
     return value;          
     }    
    
main()	
	{
	int n;
    printf("Chose from the options:\n");
    while(1)
           {
           printf("\n1.Add elements to the Linked List \n");
           printf("2.Delete Node At Beginning \n");
           printf("3.Delete Node At End \n");
           printf("4.Delete Node At Any position \n");
           printf("5.Display \n");
           printf("6.exit \n");
           scanf("%d",&n);
           switch(n)
                {
                case 1:{               		   
                	   add_Element(getvalue());
                	   break;
                	   }
                case 2:{               		   
                	   deleteFirstNode();
                	   break;
                	   }
                case 3:{               		   
                	   deleteLastNode();
                	   break;
                	   }   
                case 4:{              
                       int pos;	   
                       printf("Enter the position to delete:\n");          
                       scanf("%d",&pos);          
                	   deleteAtPosition(pos);
                	   break;
                	   }           	   
                case 5:{
                	   display_Traversing();
                	   break;
                	   }
                case 6:
                       exit(1);	   
                default:
                		printf("Wrong Input!!!\n");
                }
           printf("\n\n");     	
           }     	
	}    
    
