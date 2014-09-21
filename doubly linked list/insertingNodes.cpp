/*   *** If any error Found in the code ..Please Comment below...*****   */

/*
Author - Akash Lodha
Date - 9/17/13
Topic - Inserting Nodes to a Doubly Linked List
                  Inserting nodes at beginning
                  Inserting Nodes At End
                  Inserting Nodes at position                  
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void insertNodes(int,int);
void display();
void displayReverse();
int count();
int getValue();

struct node
       {
       int data;
       node *next;//points to the next node
       node *prev;//points to the previous node          
       }*head,*root;


//Display The Linked List     
void insertNodes(int pos,int value)
     {
     struct node *temp;
     temp = (struct node*)malloc(sizeof(struct node));
     temp->data = value;
     temp->prev = temp->next = NULL;
     if(head==NULL)
           head= root = temp; //Adding  the first node
     else
         {
         if(pos==1)    //Inserting node at the first position
               {
               temp->next = head;
               head->prev = temp;
               head = temp;        
               }        
         else if(pos==count()+1)
              {
              root->next = temp;
              temp->prev = root;
              root = temp;                  
              }      
         else if(pos<count()+1) //Any other position
              {
              struct node *ptr=head;                  
              for(int i=1;i<pos;i++)
                   ptr = ptr->next;                 
              temp->next = ptr;
              temp->prev = ptr->prev;
              ptr->prev = temp; 
              temp->prev->next = temp;  
              }        
         }                      
     } 
    
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

//gets the value of the new node to insert    
int getValue()
      {    
      printf("Enter the Value:\n");
      int value;
      scanf("%d",&value);      
      return value;    
      }       
    
main()
      {
      int n;
      printf("Enter from the following option\n");
      while(1)
              {
              printf("1.Add Elements \n");
              printf("2.Insert At Begining\n");
              printf("3.Insert At end\n");
              printf("4.Insert At Position\n");
              printf("5.Display Element \n");   
              printf("6.Display Reverse\n");
              printf("7.Exit\n");   
              scanf("%d",&n);
              switch(n)
                  {
                  case 1:{
                          insertNodes(count()+1,getValue());//Add elements
                          break;
                          }
                  case 2:{
                          insertNodes(1,getValue());//1 is to signify 1st position 
                          break;
                          }        
                  case 3:{
                          
                         insertNodes(count()+1,getValue());//count returns the number of node
                                                    //count()+1 will add in the last position 
                          break;
                          }        
                  case 4: {
                          int pos;
                          printf("Enter the Position\n");
                          scanf("%d",&pos);
                          if(pos<=count()+1)
                              insertNodes(pos,getValue());
                          else
                              printf("Wrong Position\n");    
                          break;
                          }         
                  case 5:{
                         display();
                         break; 
                          }  
                  case 6:{
                         displayReverse();
                         break; 
                          }          
                  case 7:
                         exit(1);         
                  default:
                          printf("Wrong Input\n");            
                            
                  }
              printf("\n\n");    
              }                    
      }        
       
