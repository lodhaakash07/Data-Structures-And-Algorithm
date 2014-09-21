/*
Write a program that takes the details of a person (name, age, and city) and sort it using 
Insertion sort based on names. Then search for a specific name using binary search. 
*/

#include<stdio.h>
#include<conio.h>
#include<string.h>

int size;

struct person{
       char name[20];
       int age;
       char city[20];
       }p[100];
       
void input()
     {
     for(int i=0;i<size;i++){
             printf("\nEnter the following\n");
             printf("Name\nage\nCity\n");
             scanf("%s%d%s",&p[i].name,&p[i].age,&p[i].city);}
     }    
     
void insertionSort()
     {
     for(int i=1;i<size;i++)
          {
          struct person key = p[i];
          int j=i-1;
          while(j>=0 && strcmp(key.name,p[j].name)<0){
                     p[j+1] = p[j];
                     j--;}                     
          p[j+1] = key;                          
          }               
     }   
     
void binarySearch()
     {
     int l = 0 , h = size-1 , mid = size/2;
     char n[20];
     printf("Enter the name to search\n");
     scanf("%s",&n);
     while(l<h && strcmp(p[mid].name,n)!=0){
               if(strcmp(p[mid].name,n)<0)
                   l = mid+1;
               else
                   h  = mid-1;
               }         
     if(strcmp(p[mid].name,n)==0)
            printf("%s found",n);
     else
         printf("Name not found");          
     }     
     
main()
      {
      printf("Enter the total size\n");
      scanf("%d",&size);        
      input();
      insertionSort();    
      binarySearch();
      getch();
      }     
