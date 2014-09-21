/*   *** If any error Found in the code ..Please Comment below...*****   */

/*
Author - Akash Lodha
Date - 18/9/13
Topic - dELETING Nodes from a  Linked List
                 deleting from start
                 deleting from end
                 deleting at any position
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void addNodes(int);
void display();
void deleteNode(int); 
int findPosition(int);
int count();

struct node
       {
       int data;
       node *next;//points to the next node       
       }*head,*root;
//  head points to the startting node
//  root points to the current node

//Add Notes to the Linked List
void addNodes(int value) 
     {
     struct node *temp;
     temp = (struct node*)malloc(sizeof(struct node));
     temp->data = value;      
     temp->next = NULL;       
     if(head==NULL)
          head = root = temp;
     else
         {
         root->next = temp;
         root = temp;
         }          
     }
     
void deleteNode(int value) 
     {
     struct node *temp = head;               
     if(head==NULL)
          printf("No Node to delete");
     else
         {
         struct node *temp;            
         if(findPosition(value)==0)
             printf("Node doesnot Exsists\n");
         else if(findPosition(value)==1 ) //Delete the first node
              {
              if(count()==1) //If there is only 1 element
                    head= NULL;
              else
                    head = head->next;                        
              } 
         else if(findPosition(value)==count()) //Delete the last node        
              {                  
              struct node *ptr=head;                                             
              for(int i=1;i<findPosition(value)-1;i++)                                                      
                      ptr = ptr->next;
              ptr->next = NULL;        
              }
         else   //Rest of the position
             {
             struct node *ptr=head;          
             for(int i=1;i<findPosition(value)-1;i++)          
                     ptr = ptr->next;
             ptr->next= ptr->next->next;     
             }     
         }                    
     }    
     

//return the number of nodes
int count()
     {
     struct node *temp = head;
     int count = 0;
     if(temp==NULL)
         return count;
     else
         while(temp!=NULL)
            {
            temp = temp->next;
            count++;
            }
     return count;       
     }      

//Find the position of a particular node     
int findPosition(int value)
    {
    struct node *temp=head;
    int pos=0;
    if(head==NULL)
         return 0;
    else
        while(temp!=NULL)
             {
             pos++;             
             if(temp->data==value)
                 return pos;                       
             temp = temp->next;            
             }                      
    return 0;         
    }     
    
//Display The Linked List     
void display()
     {
     printf("\n");         
     struct node *temp=head;
     if(head==NULL)
            printf("Nothing to Dispaly \n");
     else
         while(temp!=NULL)
                 {
                 printf("%d ",temp->data);
                 temp = temp->next;         
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
              printf("2.Delete Node\n");
              printf("3.Display Element \n");
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
                         printf("Enter the node to delete\n");
                         int value;
                         scanf("%d",&value);
                         deleteNode(value);
                         break;
                         }        
                  case 3:{
                         display();
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
       
