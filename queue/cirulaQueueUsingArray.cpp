/*
Author - Akash Lodha
Date - 9/12/13
Topic - Implementation of circular queue using array
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int max_size;
int queue[1000];
int front=-1;
int rear = -1;

void enqueue(int);
int dequeue(void);
void display();

//This Function Adds an element to the queue
void enqueue(int value)
	{
	int size;
	if(front>rear)
		size = front -rear;
	else
		size = rear - front;	
	if(size==max_size-1)
		printf("Queue Overflow\n");//Overflow occurs when max_size is excceded
	else
		{
		if(front==rear==-1)
			front=rear=0;
		queue[rear] = value;
		rear = (rear+1)%max_size;	
		}
	}

//This function removes the element at the front of the queue
int dequeue()
	{
	/* Underflow Occurs if- Queue is empty (when run for the first time)
							There is no element in the queue(front>rear) 
	*/
	if(front==rear)
		printf("Queue Underflow\n");
	else
		{
		int k = queue[front];
		front = (front+1)%max_size;
		return k;
		}	
	}	

void display()
	{
	int i = front;
	while(i!=rear)
		{
		printf("%d ",queue[i]);
		i = (i+1)%max_size;
		}
	}	

main()
	{
	int n;
	printf("Enter the Maximum Size of the queue\n");
	scanf("%d",&max_size);
	max_size = max_size+1;
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
