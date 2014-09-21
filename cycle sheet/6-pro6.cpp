/*Author - Akash Lodha
  Date - 22/9/2013
  Topic -Write a program to collect the details from the students such as
Name,Date of Birth, Address, MobileNumber, Email id and store themin
an ordered list.Ordering should be based on the number of characters of
user-id in email address. Take inputfor each user and insertthe detailsinits appropriate position. Perform insertion(), deletion() and display()
operations.
  */
#include<stdio.h> 
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct details
       {
       char name[10];
       char dob[8]; 
       char address[20];
       int mobno;
       char emailid[30];             
       details *next;
       } *head,*rear;

struct details* getDetails();     
void display();

  
//Get details from the user       
struct details* getDetails()
       {
       struct details *temp= (struct details*)malloc(sizeof(struct details));         
       printf("\nEnter ur name:\n");
       scanf("%s",&temp->name);
       printf("Enter date of birth\n");
       scanf("%s",&temp->dob);
       printf("Enter Address\n");
       scanf("%s",&temp->address);
       printf("Enter mobile no:\n");
       scanf("%d",&temp->mobno);
       printf("Enter email id:\n");         
       scanf("%s",&temp->emailid);
       temp->next = NULL;
       }       
  
void insert()
     {
     struct details *temp= getDetails();
     temp->next = NULL;
     if(head==NULL)//Inserting first node
           head = temp;  
     else
         {
         struct details *Temp = head;  
         if(strlen(Temp->emailid)>strlen(temp->emailid)) //Inserting at first
              {temp->next = Temp;            
               head = temp;
               Temp = head; 
               }              
         else
             {      
              while((strlen(Temp->emailid)<strlen(temp->emailid)) && Temp->next!=NULL)
                     Temp = Temp->next;
              if(Temp->next ==NULL) //iNSERTING TO THE LAST
                    Temp->next = temp;
              else//Inserting to any other position
                  {                   
                  temp->next = Temp->next;
                  Temp->next = temp;
                  }
              }                                
         }            
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
                  printf("\nname:%s\n",temp->name);
                  printf("date of birth:%s\n",temp->dob);
                  printf("Address:%s\n",temp->address);
                  printf("mobile no:%d\n",temp->mobno);
                  printf("email id:%s\n",temp->emailid);
                  temp = temp->next;        
                  }                    
         }                
     }    
     
     
main()
      {
      while(1)
           {
           printf("\nChoose from the options\n");
           printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
           int n;
           scanf("%d",&n);
           switch(n)
                 {
                 case 1:
                        {
                        insert();
                        break;                                     
                        }     
                 case 2:
                        char name1[20];
                        printf("Enter the name to delete\n");
                        scanf("%s",&name1);
                        deleteRecord(name1);
                        break;       
                 case 3:
                        display();
                        break;      
                 case 4: exit(1);
                 default:
                        printf("Wrong Input\n");           
                 }           
           }                  
      }
