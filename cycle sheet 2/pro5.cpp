/*
Date - 28/10/2013
Topic - Complete Binary Tree using LL
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int count=1;
int flag=0;
struct tree* inorder(struct tree *temp);
struct tree{
       int data,val;
       tree *left,*right;
       }*Tree = NULL;
       
/*
Logic
     As we add node we number them(root is 1 and it follows)<-count
     the parent of a child is count/2
*/
       
void buildTree(struct tree *temp,int value)
       {
       struct tree *Temp = (struct tree*)malloc(sizeof(struct tree));         
       Temp->data = value;Temp->val = count;
       Temp->right = Temp->left = NULL;
       if(Tree==NULL){
              Tree = Temp;count++;   
              return; }
       if(temp==NULL)
           return;
       else if((count/2)==temp->val)
             {
             flag=1;
             Temp->val = count;
             if(!temp->left)
                     temp->left = Temp;
             else
                     temp->right =Temp;       
             count++;           
             return;
             }
       else{
            struct tree *t;
            t = temp;
            buildTree(temp->left,value);
            if(flag==0)
                       buildTree(t->right,value);
            }           
             
       }

main()
      {
      for(int i=1;i<=15;flag=0,i++)
              buildTree(Tree,i); 
      inorder(Tree);  
      getch();    
      }
      
struct tree* inorder(struct tree *temp)
       {
       if(temp!=NULL){
              printf("%d ",temp->data);
              inorder(temp->left);
              inorder(temp->right);        
              }      
       }
