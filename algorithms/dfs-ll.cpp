// Date - 17/10/2013
// Topic - LL implementation of dsf

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int size; //Stores the number of nodes
int i;

struct node{
       int data;
       int flag;
       node *horizontal;
       node *vertical;
       }*graph;

void dfs(struct node *temp)
     {
     if(i==size || temp==NULL)
                return;
     else
             {
             if(temp->flag==1 && temp->vertical->flag == 1){
                              temp->vertical->flag =2;
                              i++;
                              dfs(temp->horizontal);   
                              printf("%d\n",temp->data);
                              dfs(temp->vertical->horizontal);    
                              } 
             if(temp->vertical->flag == 2)
                           dfs(temp->horizontal);                 
             }               
                        
     }

void create_nodes()
     {
     struct node *temp = (struct node*)malloc(sizeof(struct node));
     graph = temp;
     for(int i=1;i<=size;i++)
             {
             temp->data = i;
             temp->flag =1;
             if(i==size){
                     temp->vertical = NULL;
                     break;
                     }                
             temp->vertical = (struct node*)malloc(sizeof(struct node));  
             temp = temp->vertical;           
             }
     }      
     
void create_graph()
     {
     printf("Enter the adjacency list\n\n");  
     struct node *vert = graph;          
     for(int i=1;i<=size;i++)
             { 
             struct node *hor = vert;            
             for(int j=1;j<=size;j++)
                     {
                     int n;
                     scanf("%d",&n);
                     if(n==1){
                              hor->horizontal =  (struct node*)malloc(sizeof(struct node));
                              hor =  hor->horizontal;
                              hor->data = j;
                              hor->flag = 1;
                              hor->horizontal = NULL;
                              struct node *ver = graph;
                              for(int k=1;k<j;k++)
                                      ver = ver->vertical;
                              hor->vertical = ver;         
                             }
                     }
             vert = vert->vertical;          
             }              
     }      
     

void display()
     {
     struct node *vert = graph;        
     for(int i=1;i<=size;i++)
         {
         struct node *hor = vert;
         printf("%d :",hor->data);
         hor = hor->horizontal;
         for(;hor!=NULL;hor = hor->horizontal)
               printf("%d ",hor->data);
         vert =vert->vertical;  
         printf("\n");                 
         }
     }  

  
       
main()
      {
      printf("Enter the number of nodes\n\n");
      scanf("%d",&size);
      i=1;
      create_nodes(); 
      create_graph();
      printf("\nPAth\n");
      graph->flag = 2;
      printf("%d\n",graph->data);
      
      dfs(graph->horizontal);
      printf("\nGraph\n");
      display();
      getch();       
      }       
