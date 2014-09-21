/*   *** If any error Found in the code ..Please Comment below...*****   */

/*
Author - Akash Lodha
Date - 9/13/13
Topic - Insertion Sort
*/

/* Insertion Sort Logic
            In insertion sort the list can be thought to be devided into sorted and unsorted list
            key - the element we wish to sort
            all element before key index are sorted
            all elements after key index are unsorted
            go through array[1 to n] <- i 
                key = array[i];
                Insert key in the right position in the already sorted array[0,i-1]
*/              
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void insertionSort(int[],int);
void display(int[],int);

main()
      {
      int size,array[1000];            
      printf("Enter the Size of the Array:\n");
      // Get the list Size from the user
      scanf("%d",&size);
      printf("Enter the array Elemetns\n");
      // Get the size number of element as input from the user
      for(int i=0;i<size;i++)
              //store it in the array
              scanf("%d",&array[i]);
      printf("Unsortd List\n"); 
      display(array,size);           
      insertionSort(array,size);     
      getch();            
      }
      
//Insertion Sort 
void insertionSort(int a[1000],int size)
     {
     //the element that we wish to sort is stored in key                  
     int key;
     for(int i=1;i<size;i++)
          {
          key = a[i];// key is the element we wish to sort
          int j = i-1;
          /*
          we go through the sorted list of i-1
          move all the element to +1 position  till we find the right position for key;
          insert it in the right position
          continue
          */
          while(j>=0 && key<a[j])
                 {
                 a[j+1] = a[j];
                 j--;    
                 } 
          a[j+1] = key;                        
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
