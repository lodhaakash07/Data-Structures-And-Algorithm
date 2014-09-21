/* Report errors in the comments below  */
/* Author - Akash Lodha
   Date - 20/9/2013
   Topic - Implementation Of Binary Search Tree
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void buildTree(struct tree *node,int number);
void preorder(struct tree *node);

struct tree
       {
       int data;
       tree *left;
       tree *right;    
       }*Tree=NULL;
       
void buildTree(struct tree *node,int number)
     {
     if(node==NULL)
                  { 
                   struct tree *temp =(struct tree*)malloc(sizeof(struct tree));
                   temp->data = number;
                   temp->left=temp->right=NULL;
                   if(Tree == NULL)
                           Tree = temp;
                   else
                           node = temp;
                   }
     else if(number<node->data)
           buildTree(node->left,number);                  
     else if(number>node->data)
           buildTree(node->right,number);                 
     else if(number==node->data)//Prevent duplicate input
          printf("Duplicate input");       
     }              
     
main()
      {
                  
      int n;   //Root of the tree     
      printf("ctr+z and enter to stop input:\n");              
      while(scanf("%d",&n)!=EOF)
           buildTree(Tree,n); // MAking of bst
      preorder(Tree);
      getch();     
      }     
      
void preorder(struct tree *node)
     {
     if(node!=NULL)
             {
             printf("%d ",node->data);      
             preorder(node->left);              
             preorder(node->right);     
             }               
     }
    
