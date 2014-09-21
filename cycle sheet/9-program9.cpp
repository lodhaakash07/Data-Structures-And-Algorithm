/*Author - Akash Lodha
  Date - 22/9/2013
  Topic -Create an unordered linked list to enroll the students who wish to
participate for a gaming event by taking details like Name, Register No.,
Age, Phone number. Ensure that nomore than five members are there in
the list with same age. Perform insertion(), deletion() and display()
operations
  */
#include<stdio.h> 
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct details
       {
       char name[10];
       char regno[8]; 
       int age;
       int phoneno;
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
       printf("Enter Age\n");
       scanf("%d",&temp->age);
       printf("Enter Phoneno:\n");
       scanf("%d",&temp->phoneno);       
       temp->next = NULL;
       }       
  
void insert(int pos)
     {
     struct details *temp;
     temp = getDetails();   
     struct details *temp1=head;
     int agecount=0;
     while(temp1!=NULL){  // Checking if age slot is empty
           if(temp->age==temp1->age)
                   agecount++;    
            temp1 = temp1->next;}   
     if(agecount>=5)
            {
            printf("Age group full\n");
            return;        
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
                  printf("Course Id:%d\n",temp->age);
                  printf("mobile no:%d\n",temp->phoneno);
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
