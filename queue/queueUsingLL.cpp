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
	int value;
	struct queue *next;
	}*front,*rear;

//This function removes the element at the front of the queue
int dequeue()
	{
	// Underflow Occurs if- There is no element in the queue
	if(front==NULL)
		printf("Queue UnderFlow");
	else
		{
		int k = front->value;
		front = front->next;
		return k;
		}			
	}

//This Function Adds an element to the queue
void enqueue(int value)
	{
    //Store the value in a new temporary node             
	struct queue *temp;
	temp = (struct queue*)malloc(sizeof(struct queue));
	temp ->value = value;
	temp ->next = NULL;
	// if condition executes when first value is added
	if(front==NULL)
		front = rear = temp;
	else
		{
		rear->next = temp;
		rear = temp;
		}	
	}

void display()
	{
    struct queue *temp=front;          
	while(temp!=NULL)
		{
		printf("%d ",temp->value);
		temp = temp->next;
		}
	}	

main()
	{
	int n;
    printf("Chose from the options:\n");
    while(1)
           {
           printf("1.Enqueue\n");
           printf("2.Dequeue\n");
           printf("3.Display\n");
           printf("4.Exit\n");
           scanf("%d",&n);
           switch(n)
                {
                case 1:{
                      int value;
                      printf("Enter the value:\n");                     
                      scanf("%d",&value);                     
                      enqueue(value);
                      break;}
                case 2:{
                      printf("%d is removed from the queue \n",dequeue());
                      break;}
                case 3:{
                      display();
                      break;}
                case 4:
                       exit(1);
                default:
                       printf("Wrong input, Try Again");                     
                }   
           printf("\n\n");       
           }      
	}
