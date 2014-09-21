/*   *** If any error Found in the code ..Please Comment below...*****   */

/*
Author - Akash Lodha
Date - 9/14/13
Topic -   Eight Queen's Problem using stacks
          stacks using linked list
*/


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void push(int,int);
struct stack* pop();
int checkRow(int);
int checkColum(int);
void display();

int chessBoard[8][8];
struct stack
       {
       int x1,y1;
       struct stack *next;     
       }*top;
       
//Check If In any other colum of the row Queen is present
int checkRow(int pos)
    {
    for(int i=0;i<8;i++)
            if(chessBoard[pos][i]==1)
                   return 1;
    return 0;                         
    } 

//Check If In any other row of the colum Queen is present
int checkColum(int pos)
    {
    for(int i=0;i<8;i++)
            if(chessBoard[i][pos]==1)
                   return 1;
    return 0;                         
    }   
    
//Check Diagonally if any queen is present
int checkDiagonal(int x,int y)
    {
    int x1,y1;
    x1 = x;
    y1 = y;
    // Go top right diagonally
    while(x1<=7 && y1<=7)  
         if(chessBoard[x1++][y1++] == 1)
               return 1;
    x1 = x;
    y1 = y;
    // go bottom left diagonally
    while (x1>=0 && y1>=0)
           if(chessBoard[x1--][y1--] == 1)
               return 1; 
    x1 = x;
    y1 = y;
    //go bottom left diagonally
    while(x1<=7 && y1>=0)
           if(chessBoard[x1++][y1--] == 1)
               return 1;      
    x1 = x;
    y1 = y;
    //go bottom right diagonally
    while(x1>=0 && y1<=7)
           if(chessBoard[x1--][y1++] == 1)
               return 1;     
    return 0;                  
    }     
    
/*Logic of the program
   In a chess board a queen can move-rowwise
                                     colum wise
                                     diagonally
   Check in every colum of a row ,if no conflict arise
                        push the position to the stack
   when a queen cannot be placed anywhere ,
        pop the last position ,try in other coulms in the row(of the lat position)
   this prccess repeats ,till all the eight queens are placed
*/  

void eightQueen()
     {
     for(int i=0;i<8;i++)
         for(int j=0;j<8;j++)
            chessBoard[i][j] = 0;            
     printf("Enter x,y position to place the first queen:\n");   
     int x,y,k=0;
     scanf("%d",&x);
     scanf("%d",&y);     
     chessBoard[x-1][y-1] = 1;  //Inititilize the first queen position to 1
     for(int i=x;k<8;i=(i+1)%8,k++)
         {
         for(int j=0;j<8;j++)
                 { 
                 if(checkColum(j)==0 && checkRow(i)==0 && checkDiagonal(i,j)==0)
                       {
                       //If no Conflict push the queen position to the stack               
                       push(i,j); 
                       chessBoard[i][j] = 1;                          
                       break;         
                       }
                 // When a queen cannot be placed at any position        
                 if(j==7)   
                       {
                       struct stack *temp;
                       temp = pop();
                       i = temp->x1;
                       j = temp->y1;
                       free(temp);
                       chessBoard[i][j] = 0;  
                       k--;   
                       }   
                 }       
         }  
     display();         
     }   
     
//display the chess board
void display()
     {
     printf("Chess Board \n----------------------\n\n");         
     for(int i=0;i<8;i++)
        {
        for(int j=0;j<8;j++)
             {
             if(j==0)
                 {
                 if(chessBoard[i][j]==0)
                       printf("|   |");  
                 else      
                       printf("| %d |",chessBoard[i][j]);  
                 }                
             else
                 {
                 if(chessBoard[i][j]==0)
                      printf("   |",chessBoard[i][j]); 
                 else                 
                      printf(" %d |",chessBoard[i][j]); 
                 }                       
             }
        printf("  %d",(i+1));       
        printf("\n");
        for(int j=0;j<8*4;j++)
            printf("-");  
        printf("\n");         
        } 
     for(int i=1;i<=8;i++)
         printf("  %d ",i);                    
     }     
     
//Function To add a node to the stack
void push(int x1,int y1)
     {
     /*To add we store the new value in a temporary variable temp
       To the next pointer of temp assing the stack
       move the pointer of stack to temp     
       Linked List memory is dynamically allocated , therfor no need to check for oerflow
     */         
     struct stack *temp;
     temp = (struct stack*)malloc(sizeof(struct stack));
     temp->x1 = x1;
     temp->y1 = y1;
     temp->next = NULL;
     /*
       top==NULL
       It executes when we add the first element to the stack
       */
     if(top==NULL)
          {
          top = temp;
          top ->next = NULL;
          }
     else
         {
         temp ->next = top;
         top = temp;               
         }      
     }      


//Function to delete a node from the stack     
struct stack* pop()      
    {
    struct stack *lastpos;
    struct stack *temp=top;           
    if(top==NULL)
        //Underflow occurs when we try to remove a node from empty stack
        printf("Stack Underflow");
    else
        {     
        
        lastpos = temp;               
        temp = temp->next;
        top = temp;              
        } 
    return lastpos;                
    }
    
main()
      {
      eightQueen();    
      getch(); 
      }    
     
     
                                                                          
