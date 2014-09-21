/*
Author - Akash Lodha
Date - 8/11/2013
Topic - Solving 9*9 sudoku using stacks(implemented using linked lists)
*/
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string>
using namespace std;
int check_row(int[9][9],int,int);
int check_colum(int[9][9],int,int);
int check_block(int[9][9],int,int,int);
void solve_sudoku();
void pop();
void push(int,int,int);
int a[3];
void display(int[9][9]);
void display1(int[9][9]);
/*
Node is a linked linear linked list
value contains the grid value of a solved box
x,y are the coordinates of the solved box ,corrosponding to value
*/
struct Node
    {
    int value,x,y;
    struct Node *next;
    }*top;
/*
push()-
It pushes an element to the top of the stack 
*/    
void push(int v,int x,int y)
    {
    struct Node *temp;//temporary variable
    temp=(struct Node *)malloc(sizeof(struct Node));// dynamic memory allocation
    temp->value=v;
    temp->x = x;
    temp->y = y;
    //Initiliazing of first node
    if (top == NULL)
         {
         top=temp;
         top->next=NULL;
         }
    //Executes always after the first node initilization     
    else
        {
        temp->next=top;
        top=temp;
        }
    }
/*
pop()
This function deletes an entry from the stack
*/    
void pop()
    {
    struct Node *temp, *var=top;
    if(var==top)
       {
        //the array a[] stores the last nodes that are to be popped
        a[0] = var->value;
        a[1] = var->x ;
        a[2] = var->y ;        
        top = top->next;
        free(var);
       }
    else{
        //Executed when stack is empty and pop() function is called 
        cout<<"This puzzle cannot be solved"<<endl;
        exit(0);
        }
    }    
 /* chec_row()
 It checks if value is present anywhere else in the row(pos)
 returns 1 if present
 */   
int check_row(int matrix[9][9],int value,int pos)
     {
     for(int i=0;i<8;i++)
             if(value==matrix[pos][i])
                 return 1;
     return 0;                            
     }
 /* chec_colum()
 It checks if value is present anywhere else in the colum(pos)
 returns 1 if present
 */    
int check_colum(int matrix[9][9],int value,int pos)
     {
     for(int i=0;i<8;i++)
             if(value==matrix[i][pos])
                 return 1;
     return 0;                            
     }     
/*
 check_block()
 Checks in the 3x3 grid if value is present
*/    
int check_block(int matrix[9][9],int value,int xpos,int ypos)
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
                     if(matrix[j][i]==value)
                         return 1;
     return 0;                    
     } 
/*solve_sudoku()
  This function makes use of the stack and all the other functions to solve the sudoku
*/         
void solve_sudoku()
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
     cout<<"Input Example"<<endl<<"-------------------------"<<endl;
     cout<<"If the  matrix to be solved is: "<<endl;
     display(example);
     cout<<endl<<"Here 0 is unsolved boxes "<<endl<<"------------------------"<<endl;
     cout<<"Then the Input should be:"<<endl<<endl;
     display1(example);
     cout<<endl<<"--------------------"<<endl<<"Press 1 to continue"<<endl;
     int kk;
     cin>>kk;
     if(kk=1){                   
     int matrix [9][9]={
                    {1,0,0,0,7,0,0,3,0},
                    {8,3,0,6,0,0,0,0,0},
                    {0,0,2,9,0,0,6,0,8},
                    {6,0,0,0,0,4,9,0,7},
                    {0,9,0,0,0,0,0,5,0},
                    {3,0,7,5,0,0,0,0,4},
                    {2,0,3,0,0,9,1,0,0},
                    {0,0,0,0,0,2,0,4,3},
                    {0,4,0,0,8,0,0,0,9},                
                     };;
     cout<<"Input Format"<<endl<<"---------------"<<endl;               
     cout<<endl<<"1.Enter as it is in rows and coulms"<<endl;
     cout<<"2.If box is to be solved , enter 0 instead of the empty box"<<endl;
     cout<<"3.Enter only Integers "<<endl;   
     cout<<"4.Integer should be <=9"<<endl;
     // Input for the program
  /*   for(int i=0;i<9;i++)
          {
          string n;
          L2:cin>>n;
          if(n.length()>9)
                  cout<<"Invalid INput"<<endl;
          else 
             for(int j=0;j<9;j++)
                 {
                 int k= n[j]-48;
                 if(k>=0 && k<=9)
                    matrix[i][j] = k;
                 else
                     {
                     cout<<"Invalid Input"<<endl<<"Try Again"<<endl;
                     goto L2;
                     }      
                 }                       
          }  
         */
     cout<<"Given sudoku"<<endl<<"---------------------------------"<<endl;
     display(matrix);                         
     int k=1;
     int flag = 0;           
     //Main logic of the program        
     for(int i=0;i<9;i++)
         {
         if(flag==1)
             flag=0;
         else        
             k=1;    
         for(int j=0;j<9;)    
             {
             if(matrix[i][j]==0)
                    {  
                    if(check_row(matrix,k,i)==1 || check_colum(matrix,k,j)==1 || check_block(matrix,k,i,j)==1)
                       k++;
                    else
                     {
                     matrix[i][j]=k; 
                     push(k,i,j);
                     j++;
                     k=1;
                     }
                    L1:if(k>=10)
                         {
                         pop();
                         i = a[1];
                         j = a[2];
                         matrix[i][j] = 0;
                         k = a[0];
                         k++;
                         goto L1;
                         flag = 1;     
                         }     
                    }
               else if(matrix[i][j]!=0)
                   j++;                                         
             }             
         }
     cout<<"Solved "<<endl<<"-----------------"<<endl;    
     display(matrix);}              
     }
     
void display(int matrix[9][9])
     {
     for(int i=0;i<9;i++)
        {
        for(int j=0;j<9;j++)
            {
            if(j==2 || j==5 || j==8)
               cout<<matrix[i][j]<<" |";
            else
               cout<<matrix[i][j]<<" ";        
            } 
        cout<<endl;  
        if(i==2 || i==5 || i==8){
             for(int j=0;j<=9;j++)
               cout<<"- " ;       
        cout<<endl;      }
        }         
     cout<<endl;        
     }
void display1(int matrix[9][9])
     {
     for(int i=0;i<9;i++)
         {
         for(int j=0;j<9;j++)
                 cout<<matrix[i][j];
         cout<<endl;           
         }          
     }          
    
main()
     {                   
     solve_sudoku();
     system("pause");           
     }          
//end of program
