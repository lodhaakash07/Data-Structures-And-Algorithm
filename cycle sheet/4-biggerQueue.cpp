/*
Author - Akash Lodha
Date - 9/15/13
Topic - Creating two queues q1 and q2
        finding bigger queue based on the number of nodes
        Implementation of queue using Singly Linked List
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void dequeue(int);
void enqueue(int,int);
void display(int);
void queueOperations(int);

struct queue
	{
	int value;
	struct queue *next;
	}*front[2],*rear[2];

//This function removes the element at the front of the queue
void dequeue(int queue)
	{
	// Underflow Occurs if- There is no element in the queue
	if(front[queue]==NULL)
		printf("Queue UnderFlow");
	else
		front[queue] = front[queue]->next;			
	}

//This Function Adds an element to the queue
void enqueue(int value,int queue)
	{
    //Store the value in a new temporary node             
	struct queue *temp;
	temp = (struct queue*)malloc(sizeof(struct queue));
	temp ->value = value;
	temp ->next = NULL;
	// if condition executes when first value is added
	if(front[queue]==NULL)
		front[queue] = rear[queue] = temp;
	else
		{
		rear[queue]->next = temp;
		rear[queue] = temp;
		}	
	}

//Function To Display Nodes Of the queue
void display(int queue)
	{
    struct queue *temp=front[queue];          
	while(temp!=NULL)
		{
		printf("%d ",temp->value);
		temp = temp->next;
		}
	}
 
//Count the number of elements of the queue    
int count(int queue)
	{
    int count = 0;           
    struct queue *temp=front[queue];          
	while(temp!=NULL)
		{
		count++;
		temp = temp->next;
		}
	return count;	
	}    	

void queueOperations(int queue)
	{
	int n;
    printf("Chose from the options:\n");
    while(1)
           {
           int flag = 0;       
           printf("1.Enqueue\n");
           printf("2.Dequeue\n");
           printf("3.Display\n");
           printf("4.Continue\n");
           scanf("%d",&n);
           switch(n)
                {
                case 1:{
                      int value;
                      printf("Enter the value:\n");                     
                      scanf("%d",&value);                     
                      enqueue(value,queue);
                      break;}
                case 2:{
                      dequeue(queue);
                      break;}
                case 3:{
                      display(queue);
                      break;}
                case 4:{
                       flag =1;
                       break;}
                default:
                       printf("Wrong input, Try Again");                     
                }   
           if(flag==1)
               break;     
           printf("\n\n");       
           }      
	}
	
main()
     {
     printf("Access queue 1:\n");
     queueOperations(0);     
     printf("Access queue 2:\n"); 
     queueOperations(1);
     //q1>q2
     if(count(0)>count(1))
         {
          printf("Bigger queue is q1\n");
          display(0);
         } 
     //q1<q    
     else if(count(0)<count(1))
         { 
          printf("Bigger queue is q2\n");
          display(1);    
         } 
     //q1 = q2    
     else 
          printf("Size of both queue are same\n");   
     getch();     
     }	
