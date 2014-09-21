/*
Take a list of fifteen numbers and perform Quick-sort.
*/

#include<stdio.h>
#include<conio.h>

void quickSort(int a[15],int first,int last)
     {
     int pivot,j;
     if(first<last){
            pivot = first;
            int i = first;
            j = last;
            while(i<j){
                 while(a[i]<=a[pivot] && i<last)
                       i++;
                 while(a[j]>a[pivot])      
                       j--;
                 if(i<j){
                     int temp = a[i];
                     a[i] = a[j];
                     a[j] = temp;
                     }                            
                 }
             int temp = a[pivot];
             a[pivot] = a[j];
             a[j] = temp;
             quickSort(a,first,j-1);
             quickSort(a,j+1,last);         
            }         
        
     }
     
main()
      {
      int a[15];
      printf("Enter the 15 digits\n");
      for(int i=0;i<15;i++)
              scanf("%d",&a[i]);
      quickSort(a,0,15);
      for(int i=0;i<15;i++)
              printf("%d ",a[i]);
      getch();                                    
      }     
