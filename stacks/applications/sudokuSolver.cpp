/*   *** If any error Found in the code ..Please Comment below...*****   */

/*

/*
Author - Akash Lodha
Date - 9/12/13
Topic - Sudoku solver using Stacks
        Stacks Implemented Using Linked List
        Program is not so efficient as it uses brute force method
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void push(int,int,int);
struct stack* pop();
void display(int[9][9]);
void display1(int[9][9]);
int sudoku[9][9];
int check_block(int,int,int);   
int check_colum(int,int);
int check_row(int,int);

struct stack
       {
       int x,y,value;
       struct stack *next;     
       }*top;
       
void sudokuSolver()
     {
     //Exmple of how the program input should be given                
     int example[9][9] = {
                    {1,0,0,0,7,0,0,3,0},
                    {8,3,0,6,0,0,0,0,0},
                    {0,0,2,9,0,0,6,0,8},
                    {6,0,0,0,0,4,9,0,7},
                    {0,9,0,0,0,0,0,5,0},
                    {3,0,7,5,0,0,0,0,4},
                    {2,0,3,0,0,9,1,0,0},
                    {0,0,0,0,0,2,0,4,3},
                    {0,4,0,0,8,0,0,0,9},                
                     };
     printf("Input Example\n-------------------------\n");
     printf("If the  matrix to be solved is: \n");
     display(example);
     printf("\nHere 0 is unsolved boxes \n------------------------\n");
     printf("Then the Input should be:\n\n");
     display1(example);
     printf("\n--------------------\nPress 1 to continue\n");              
     int n;
     scanf("%d",&n);
    if(n==1)
         {
         //Input For the program
         char input[9];
         for(int i=0;i<9;i++)
              {
              scanf(" %s",&input);
              for(int j=0;j<9;j++)
                    sudoku[i][j] = input[j]-48;              
              } 
         for(int i=0;i<9;i++)
              {
              int k=1;               
              for(int j=0;j<9;)
                   {
                   if(sudoku[i][j]==0) 
                           {           
                           if(check_row(k,i)==0 && check_colum(k,j)==0 && check_block(k,i,j)==0)   
                                 {
                                 push(k,i,j); 
                                 sudoku[i][j] = k; 
                                 k=0;
                                 j++;             
                                 }            
                           if(k>=9)
                                  {
                                  struct stack *temp = pop();
                                  i = temp->x;
                                  j = temp->y;
                                  k = temp->value;                                  
                                  sudoku[i][j] = 0;
                                  }
                           k++;
                           }
                    else
                        j++;                    
                    }               
              } 
         printf("Solved \n-----------------\n");    
         display(sudoku);      
         }
     else
         exit(1);    
     } 
     
 /* chec_row()
 It checks if value is present anywhere else in the row(pos)
 returns 1 if present
 */

int check_row(int value,int pos)
     {
     for(int i=0;i<9;i++)
             if(value==sudoku[pos][i])
                 return 1;
     return 0;                            
     }
 /* chec_colum()
 It checks if value is present anywhere else in the colum(pos)
 returns 1 if present
 */    
int check_colum(int value,int pos)
     {
     for(int i=0;i<9;i++)
             if(value==sudoku[i][pos])
                 return 1;
     return 0;                            
     }     
/*
 check_block()
 Checks in the 3x3 grid if value is present
*/    
int check_block(int value,int xpos,int ypos)
     {
     int start,end;                
     if((xpos>=0 && xpos<=2)) 
                 start=0;
     if((xpos>=3 && xpos<=5)) 
                 start=3;
     if((xpos>=6 && xpos<=8)) 
                 start=6;
     if((ypos>=0 && ypos<=2))
                 end=0;
     if((ypos>=3 && ypos<=5)) 
                 end=3;
     if((ypos>=6 && ypos<=8)) 
                 end=6;                
     for(int i=end;i<=end+2;i++)
             for(int j=start;j<=start+2;j++)
                     if(sudoku[j][i]==value)
                         return 1;
     return 0;                    
     }        
     
void display(int matrix[9][9])
     {
     for(int i=0;i<9;i++)
        {
        for(int j=0;j<9;j++)
            {
            if(j==2 || j==5 || j==8)
               printf("%d |",matrix[i][j]);
            else
               printf("%d ",matrix[i][j]);        
            } 
        printf("\n");  
        if(i==2 || i==5 || i==8){
             for(int j=0;j<=9;j++)
              printf("- ") ;       
        printf("\n");      }
        }         
     printf("\n");        
     }
     
void display1(int matrix[9][9])
     {
     for(int i=0;i<9;i++)
         {
         for(int j=0;j<9;j++)
                 printf("%d",matrix[i][j]);
         printf("\n");           
         }          
     }         

//Function To add a node to the stack
void push(int value,int x,int y)
     {
     /*To add we store the new value in a temporary variable temp
       To the next pointer of temp assing the stack
       move the pointer of stack to temp     
       Linked List memory is dynamically allocated , therfor no need to check for oerflow
     */         
     struct stack *temp;
     temp = (struct stack*)malloc(sizeof(struct stack));
     temp->value = value;
     temp->x = x;
     temp->y = y;
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
         top->next = NULL;         
         }      
     }      


//Function to delete a node from the stack     
struct stack* pop()      
    {
    struct stack *temp=top,*temp1;           
    if(top==NULL){
        //Underflow occurs when we try to remove a node from empty stack
        
        printf("Cannot be solved");
        getch();
        exit(1);
        }
    else
        {   
        temp1 =(struct stack*)malloc(sizeof(struct stack));     
        temp1->value = temp->value;
        temp1->x = temp->x;
        temp1->y =temp->y;
        temp1 -> next = NULL;        
        if(temp->next!=NULL)       
            temp = temp->next;
        else
            temp=NULL;    
        top = temp;              
        }     
    return temp1;              
    }

main()
     {
     sudokuSolver(); 
     }     
