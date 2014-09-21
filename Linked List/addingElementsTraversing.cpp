/*   *** If any error Found in the code ..Please Comment below...*****   */

/*
Author - Akash Lodha
Date - 9/14/13
Topic - Inserting new nodes to Linked List
                  Inserting At Start
                  Inserting At End
                  Inserting At Any Position
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void insertNodeAtStart(int);
void insertNodeAtEnd(int);
void add_Element(int);
void insertNodeAnyPosition(int,int);
void display_Traversing();
int countNodes();
int getvalue();

struct node
    {
    int data;
    struct node *next;
    }*root,*head;
//head always points to the first node
// root points to the current node    
    
/* Function to add element at the start of the linked list
            If list empty (head==NULL)
                    head = new node;
            else
                temp = new node
                temp next = head
                head = temp;
*/
void insertNodeAtStart(int value)   
     {
     struct node *temp;
     temp = (struct node*)malloc(sizeof(struct node));
     temp -> data = value;
     temp ->next = NULL;
     if(head == NULL)
             /*
             head = temp is also correct in this case
             we always use root to point to current node
             */
             head = root = temp;
     else
         {
         temp->next = head;
         head = temp;    
         }                              
     }
     
void insertNodeAtEnd(int value)
     {
     struct node *temp,*curr=head;
     temp = (struct node*)malloc(sizeof(struct node));
     temp -> data = value;
     temp ->next = NULL;
     //If First Node
     if(head == NULL)
             {
             /*
             head = temp is also correct in this case
             we always use root to point to current node
             */        
             head = root = temp;
             head->next = NULL;
             }
     else
           {
           /* Traverse till the end of the list
              we use curr->next!=null
                     because we want to go to 1 pointer less
           */                     
           while(curr->next!=NULL)
                  curr = curr->next;       
           curr->next = temp; 
           /* Alternatively This can be also done as
                       we know root always points to current node
                          root->next = temp;
                          root = temp;
                            if we want to use the root always initilize while insering the first node as head = root = temp;
           */                        
           }                            
     }         
     
//Insert Node At any Position 
void insertNodeAnyPosition(int value,int position)
     {
     //First check if the position exsists
     //countNodes() returns the total number of nodes
     // we use countNodes()+1 to insert element at last position                        
     if(position>countNodes()+1)
         printf("Enter valid Position");       
     
     else
         {
             //If Insertion at beginning
             if(position==1)     
                     insertNodeAtStart(value);
             //Insertion at the end        
             else if(position==countNodes())
                     insertNodeAtEnd(value);
             //Insertion At any other position
             else
                 {
                 struct node *temp,*prev=head,*curr=prev;
                 temp = (struct node*)malloc(sizeof(struct node));
                 temp -> data = value;
                 temp ->next = NULL;         
                 /*traverse to the position and add the node
                            prev contains all the elements before the insert position
                            curr conatins all the position after the insert position
                 */
                 for(int i=1;i<position-1;i++)
                       {
                       prev = prev->next;
                       curr = prev;
                       }     
                 curr = curr->next;                         
                 temp->next = curr;
                 prev->next = temp;
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
           printf("2.Insert Node At Beginning \n");
           printf("3.Insert Node At End \n");
           printf("4.Insert Node At Any position \n");
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
                	   insertNodeAtStart(getvalue());
                	   break;
                	   }
                case 3:{               		   
                	   insertNodeAtEnd(getvalue());
                	   break;
                	   }   
                case 4:{              
                       int pos;	   
                       printf("Enter the position to inser:\n");          
                       scanf("%d",&pos);          
                	   insertNodeAnyPosition(getvalue(),pos);
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
