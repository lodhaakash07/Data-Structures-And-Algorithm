/*   *** If any error Found in the code ..Please Comment below...*****   */

/*
Author - Akash Lodha
Date - 17/9/13
Topic - Linear Search
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int a[1000];
int size;

int lineraSearch(int);
/* Program Logic
           scan through the array[0.....size] <-i
                if(number found at a[i])
                   return pos
           end loop
           if number not found
              return error
*/                      

int linearSearch(int number)
    {              
    for(int i=0;i<size;i++)
          if(a[i]==number) 
                return i; //
    return -1; //-1 signifies the array element is not found                         
    }
    
main()    
   {
   printf("Enter the array Size:\n");
   scanf("%d",&size);
   printf("Enter the array elements:\n");
   for(int i=0;i<size;i++)       
           scanf("%d",&a[i]);//Input for the array
   printf("Enter the value to search in the array:\n");
   int n;
   scanf("%d",&n);
   int position = linearSearch(n);
   if(position!=-1)// If the element found
       printf("The array element %d is fount at %d\n",n,position+1);
   else//If element not found
       printf("The number is not found\n");    
   getch();    
   }   
   
