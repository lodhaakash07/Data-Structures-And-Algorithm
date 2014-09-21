/*    Report Errors in comments */
/* Author = Akash Lodha
   Date - 18/9/2013
   Topic - Inserting in Linked List
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct node{
            int data;
            node *next;
            }*head,*root;
            
void display();    
int getValue();
int count();    
void insertNodes(int,int);     
// Head always points to the first position
// root always points to the current position

void insertNodes(int pos,int value)
     {
     struct node *temp;
     temp = (struct node*)malloc(sizeof(struct node));
     temp->data = value;
     temp->next = NULL;                
     if(head==NULL)
        head = root = temp;
     else
         {
         if(pos==1)  //  Inserting Node at first Position
               {
               temp ->next = head;
               head = temp;      
               }    
         else if(pos==count()+1) //Inserting Node at last Position
              {
              root->next = temp;
              root = temp;                  
              }      
         else//Inserting Anywhere else
             {
             struct node *ptr=head;
             for(int i=1;i<pos-1;i++)
                     ptr = ptr->next;
             temp->next = ptr->next;
             ptr->next = temp;                
             }     
         }  
     }
 
// Function return the total number of nodes     
int count()
    {
    struct node *temp = head;
    int count = 0;
    if(temp==NULL)
          return count;
    else
        {
        while(temp!=NULL)
             {
             count++;            
             temp = temp->next;            
             }         
        }            
    return count;     
    }   
    
   
int getValue()
      {    
      printf("Enter the Value:\n");
      int value;
      scanf("%d",&value);      
      return value;    
      } 
 
//Function To display the nodes      
void display()
     {
     printf("\n");         
     struct node *temp = head;
     if(head==NULL)
            printf("Nothing to display\n");         
     else
         for(;temp!=NULL;temp = temp->next)
               printf("%d ",temp->data);       
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
              printf("6.Exit\n");   
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
                      case 6:
                             exit(1);         
                      default:
                              printf("Wrong Input\n");            
                                
                      }
                  printf("\n\n");    
                  }                     
      }   
