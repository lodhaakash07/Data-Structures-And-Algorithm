/*Author - Akash Lodha
  Date - 22/9/2013
  Topic -Consider a library application which maintains the list of books. The
application contains the following information about the books: Title of
the book, Author name, ISBNand Year of publication. Create a Linked List
to maintain the list of books also to perform the following operations:
Insert a book at any desired position and to delete or search for a book
given the ISBN.
  */
#include<stdio.h> 
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct details
       {
       char title[20];
       char author[20]; 
       char isbn[20];
       int year;             
       details *next;
       } *head,*root;

struct details* getDetails();     
void display();
void deleteRecord(char isbn[20]);
void insert(int);
int count();
  
//Get details from the user       
struct details* getDetails()
       {
       struct details *temp= (struct details*)malloc(sizeof(struct details));         
       printf("\nEnter the title:\n");
       scanf("%s",&temp->title);
       printf("Enter author name\n");
       scanf("%s",&temp->author);
       printf("Enter Isbn\n");
       scanf("%s",&temp->isbn);
       printf("Enter year:\n");
       scanf("%d",&temp->year);
       temp->next = NULL;
       }       
  
void insert(int pos)
     {
     struct details *temp;
     temp = getDetails();              
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
             struct details *ptr=head;
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
    struct details *temp = head;
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
     
void deleteRecord(char isbn[20])
     {
     struct details *temp = head;
     if(head==NULL)
           printf("No records to delete");
     else
         {
         if(strcmp(head->isbn,isbn)==0)// Delete the first node
                    head = head->next;
         else
             {
             while(temp->next!=NULL){
                  if(strcmp(temp->next->isbn,isbn)!=0)
                           temp=temp->next;
                  else     
                           break; }
             temp->next = temp->next->next;                              
             }                               
         }                
     }     
     
void display()
     {
     struct details *temp = head;
     if(head==NULL)
            printf("Nothing to display\n");
     else
         {
         while(temp!=NULL)
                  {
                  printf("\nTitle:%s\n",temp->title);
                  printf("Author:%s\n",temp->author);
                  printf("Isbn:%s\n",temp->isbn);
                  printf("Year:%d\n",temp->year);
                  temp = temp->next;        
                  }                    
         }                
     }    
     
     
main()
      {
      while(1)
           {
           printf("\nChoose from the options\n");
           printf("1.Add\n2.Insert\n3.Delete\n4.Display\n5.Exit\n");
           int n;
           scanf("%d",&n);
           switch(n)
                 {
                 case 1:
                        {
                        insert(0);
                        break;                                     
                        }
                 case 2:
                       {
                       int pos;
                      printf("Enter the Position\n");
                      scanf("%d",&pos);
                      if(pos<=count()+1)
                          insert(pos);
                      else
                          printf("Wrong Position\n");    
                      break;                                            
                       }           
                 case 3:
                        char isbn[20];
                        printf("Enter the isbn to delete\n");
                        scanf("%s",&isbn);
                        deleteRecord(isbn);
                        break;       
                 case 4:
                        display();
                        break;      
                 case 5: exit(1);
                 default:
                        printf("Wrong Input\n");           
                 }           
           }                  
      }
