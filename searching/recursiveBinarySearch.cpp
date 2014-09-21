/*   *** If any error Found in the code ..Please Comment below...*****   */

/*
Author - Akash Lodha
Date - 17/9/13
Topic - Non recursive binary search
*/

#include<stdio.h>
#include<conio.h>

int a[1000];
int size;

int binarySearch(int,int,int);

                                          
int binarySearch(int number,int start,int end)
    {    
    if(start>end)   
         return -1; 
    else
        {
        int mid = (start+end)/2;        
        if(a[mid]==number)
           return mid;        
        else if(a[mid]>number)
               return (binarySearch(number,start,mid-1));
        else
               return (binarySearch(number,mid+1,end));                 
        }                  
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
       int position = binarySearch(n,0,size-1);
       if(position!=-1)// If the element found
           printf("The array element %d is fount at %d",n,position+1);
       else//If element not found
           printf("The number is not found\n");    
       getch();                    
      }    
