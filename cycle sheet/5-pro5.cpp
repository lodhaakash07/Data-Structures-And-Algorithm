/*
Author - Akash Lodha
Date - 9/12/13
Topic - Implementation of queue using Singly Linked List
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct queue
	{
	int trainno;
	char name[20];
	int age;
	char source[20];
	char destination[20];
	struct queue *next;
	}*front,*rear;

struct queue* getValue();

 
struct queue* getValue()
       {
       struct queue *temp;
	   temp = (struct queue*)malloc(sizeof(struct queue)); 
       printf("Enter train no\n");
       scanf("%d",&temp->trainno);
       printf("Enter name\n");
       scanf("%s",&temp->name);
       printf("Enter source\n");
       scanf("%s",&temp->source);
       printf("Enter arrival\n");
       scanf("%s",&temp->destination);  
       temp ->next = NULL;    
       } 
//This Function Adds an element to the queue
void enqueue()
	{
    //Store the value in a new temporary node             
	struct queue *temp;
	temp = getValue();
	temp->next = NULL;
	// if condition executes when first value is added
	if(front==NULL)
		front = rear = temp;
	else
		{
		rear->next = temp;
		rear = temp;
		}	
	}

void process()
     {
     struct queue *temp = front;
     while(temp!=NULL)         
          {
          struct queue *Temp = front;
          int count = 0;
          while(Temp!=temp)
              {
              if(Temp->trainno == temp->trainno)                     
                 count++;
              Temp= Temp->next;
              }
          if(count<6)    
           printf("%s ticked booked in train no %d \n",temp->name,temp->trainno);                        
          else
           printf("%s ticked not booked in train no %d \n",temp->name,temp->trainno);
          temp = temp->next;
          }
     }

main()
	{
	
    int n;
        do{  
         enqueue();
         printf("ctr+z to stop input\n1.to continue\n\n"); }
            while(scanf("%d",&n)!=EOF);
    process();     
    getch();
    }
