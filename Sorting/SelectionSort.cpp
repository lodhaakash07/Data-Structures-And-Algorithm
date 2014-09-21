/*   *** If any error Found in the code ..Please Comment below...*****   */

/*
Author - Akash Lodha
Date - 9/13/13
Topic - Selection Sort
*/

/* Seection Sort Logic
            1. Select the smallest of the array, put it in first position
            2.Take the next smallest put it in 2nd position
            3. Repeat this process for all the n elements 
*/              
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void selectionSort(int[],int);
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
      selectionSort(array,size);     
      getch();            
      }
      
//Selection Sort 
void selectionSort(int a[1000],int size)
     {
     int min_index;                  
     for(int i=0;i<size;i++)
             {
             //Assume the index of minimum to be the ith element                
             min_index = i;               
             for(int j=i+1;j<size;j++)
                     {
                     /*If we find any other element less than assumed minumum 
                     //change minimum index to the new found index*/                 
                     if(a[min_index]>a[j])
                          min_index = j;                                           
                     } 
             // Swap the ith minimum element in the ith place with new found minimum index        
             int temp = a[i];
             a[i] = a[min_index];
             a[min_index] = temp;                      
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
