#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct queue
	{
	int value;
	struct queue *next;
	}*front,*rear;

//This Function Adds an element to the queue
void enqueue(int value)
	{
	if(front==NULL && rear==NULL)
		{
		front = (struct queue*)malloc(sizeof(struct queue));
		front->value = value;
		front->next = NULL;
		rear=front;		
		}
	else
		{
		rear = (struct queue*)malloc(sizeof(struct queue));
		rear->value = value;		
		}
	rear = rear ->next;
	rear->next= NULL;	
	}
main()
      {
      enqueue(5); 
      enqueue(5); 
      enqueue(5); 
      enqueue(5);          
      }	
