/*   *** If any error Found in the code ..Please Comment below...*****   */

/*
Author - Akash Lodha
Date - 17/9/13
Topic - Non recursize binary search
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int a[1000];
int size;

int binarySearch(int);
/* Program Logic
           We use divide and conquere method
           The array to be searched should be sorted
              we assume the number to be found(number) will be in the middle
              array start =0 end = arraysize-1
              we have to find the position(of the number) between start and end, if exsists
       Step1  mid =(start+end)/2;
              until middle = number
                           if(number < middle )
                                         surely the number is in left side of middle (if sorted in ascending order)
                                         end = mid-1
                           else
                                      surely the number is in right side of middle (if sorted in ascending order)
                                      start = mid+1
                          goto step 1;
 */                                             
int binarySearch(int number)
    {
    int start =0;
    int end = size-1;
    int mid = (start+end)/2;
    while(a[mid]!=number)
          {
          if(number<a[mid])
                 end = mid-1;
          else
                 start = mid+1;
          mid = (start+end)/2;                          
          }                 
    if(a[mid]==number)
           return mid;
    else -1;             
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
       int position = binarySearch(n);
       if(position!=-1)// If the element found
           printf("The array element %d is fount at %d\n",n,position+1);
       else//If element not found
           printf("The number is not found\n");    
       getch();                    
      }    
