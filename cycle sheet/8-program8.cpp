/*Author - Akash Lodha
  Date - 22/9/2013
  Topic -Write a program for course registration. Collect the details from the
students such as Name, Registration Number, Course, Course Code,
Course Title, No. of credits using unordered List. Ensure that the
registration number is unique. Perform insertion(), deletion() and
display() operations
  */
#include<stdio.h> 
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct details
       {
       char name[10];
       char regno[8]; 
       char courseid[20];
       char coursetitle[20];
       int  credits;             
       details *next;
       } *head,*root;

struct details* getDetails();     
void display();
void insert(int pos);
int count();
void deleteRecord(char name[20]);
  
//Get details from the user       
struct details* getDetails()
       {
       struct details *temp= (struct details*)malloc(sizeof(struct details));         
       printf("\nEnter ur name:\n");
       scanf("%s",&temp->name);
       printf("Enter Regno\n");
       scanf("%s",&temp->regno);
       printf("Enter CourseId\n");
       scanf("%s",&temp->courseid);
       printf("Enter course title:\n");         
       scanf("%s",&temp->coursetitle);
       printf("Enter credits:\n");
       scanf("%d",&temp->credits);       
       temp->next = NULL;
       }       
  
void insert(int pos)
     {
     struct details *temp;
     temp = getDetails();   
     struct details *temp1=head;
     while(temp1!=NULL)
            {
            if(strcmp(temp->name,temp1->name)==0) 
                   {
                   printf("Student Already exsists \n");
                   return;     
                   }         
            }           
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
    while(temp!=NULL)
         {
         count++;            
         temp = temp->next;            
         }                    
    return count;     
    }  
     
void deleteRecord(char name[20])
     {
     struct details *temp = head;
     if(head==NULL)
           printf("No records to delete");
     else
         {
         if(strcmp(head->name,name)==0)// Delete the first node
                    head = head->next;
         else
             {
             while(temp->next!=NULL){
                  if(strcmp(temp->next->name,name)!=0)
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
                  printf("\nName:%s\n",temp->name);
                  printf("Reg no:%s\n",temp->regno);
                  printf("Course Id:%s\n",temp->courseid);
                  printf("Credits:%d\n",temp->credits);
                  printf("Course title:%s\n",temp->coursetitle);
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
                        char name[20];
                        printf("Enter the name to delete\n");
                        scanf("%s",&name);
                        deleteRecord(name);
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
