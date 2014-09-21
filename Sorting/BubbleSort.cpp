/*   *** If any error Found in the code ..Please Comment below...*****   */

/*
Author - Akash Lodha
Date - 9/13/13
Topic - Bubble Sort
*/

/* Bubble Sort Logic
   To sort N elements , N times data is accessed
      1.First time The smallest Element is in the 1st position
      2.Second time the 2nd smallest in 2nd position
      3.etc
      4.After N cycles All the values are sorted
              Each pair of element is compared and swaped according to condition
*/              
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void bubbleSort(int[],int);
void display(int[],int);

main()
      {
      int size,array[1000];            
      printf("Enter the Size of the Array:\n");
      scanf("%d",&size);
      printf("Enter the array Elemetns\n");
      for(int i=0;i<size;i++)
              scanf("%d",&array[i]);
      printf("Unsortd List\n"); 
      display(array,size);           
      bubbleSort(array,size);     
      getch();            
      }
      
//Bubble Sort 
void bubbleSort(int a[1000],int size)
     {
     for(int i=0;i<size;i++)
             {
             for(int j=0;j<size-1-i;j++)
                     {
                     if(a[j]>a[j+1])
                              {
                              /*Swapping Of Two Elements */
                              int temp = a[j];
                              a[j] = a[j+1];
                              a[j+1] = temp;      
                              }                 
                     }               
             }
     printf("Sortd List\n");                       
     display(a,size);        
     }     
     
//Function To Display The  List
void display(int a[1000],int size)
     {
     for(int i=0;i<size;i++)
           printf("%d ",a[i]);
     printf("\n");               
     }     
