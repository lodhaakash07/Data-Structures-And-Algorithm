/*
Write a program that takes the details of Buildings (name, years of existence, address, 
owner name and net worth) and sort it using Selection sort based on net worth. Then 
search for a specific building which is the worthiest among them using binary search. 
*/
#include<stdio.h>
#include<conio.h>
int size;

struct building{
                char name[10];
                int yoe;
                char add[20];
                char owner;
                float worth;
                }b[100];
                
void input()
     {            
     for(int i=0;i<size;i++){
             printf("\n\nEnter the following:\n");
             printf("Building Name\nYear Of Exsistence\nAddress\nOwner\nWorth\n");
             scanf("%s%d%s%s%f",&b[i].name,&b[i].yoe,&b[i].add,&b[i].owner,&b[i].worth);
             }                                 
     }     
     
void selectionSort()
     {
     for(int i=0;i<size;i++)
             {
             int min = i;
             for(int j=i+1;j<size;j++)
                     if(b[min].worth>b[j].worth)
                          j = min;
             struct building c = b[i];
             b[i] = b[min];
             b[min] = c;             
             }               
     }                
     
main()
      {
      printf("Enter the total no of data\n");
      scanf("%d",&size);                
      input();
      selectionSort(); 
      float w;               
      printf("Ente the NET WOTRH OF Building to search\n");
      scanf("%f",&w);
      int mid = size/2;
      int l = 0;
      int h = size-1;
      while(b[mid].worth!=w && l<h)
            {
            if(w>b[mid].worth)
                 l = mid+1;
            else if (w<b[mid].worth)
                 h = mid-1;
            }       
      if(b[mid].worth==w)
          printf("The building is %s\n",b[mid].name);
      else
          printf("Building not found\n");
      getch();    
      }     
