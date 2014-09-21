/*
Author - Akash Lodha
Date - 9/12/13
Topic - Implementation of queue using array
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max_size 50
int queue[max_size];
int front=-1;
int rear = -1;

void enqueue(int);
int dequeue();
void display();

//This Function Adds an element to the queue
void enqueue(int value)
	{
	if(rear==max_size-1)
		printf("Queue Overflow\n");//Overflow occurs when max_size is excceded
	else
		{
		// When adding the first element initilizse front to 0
		if(front==-1)
			front=0;
		queue[++rear] = value;	//Adding the element to the queue
		}
	}

//This function removes the element at the front of the queue
int dequeue()
	{
	/* Underflow Occurs if- Queue is empty (when run for the first time)
							There is no element in the queue(front>rear) 
	*/
	if(front==-1 || front>rear)
		printf("Queue Underflow\n");
	else
		return queue[front++];	
	}	

void display()
	{
	printf("\nThe queue elements are \n");
	for(int i=front;i<=rear;i++)
		printf("%d ",queue[i]);
	printf("\n");	
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
