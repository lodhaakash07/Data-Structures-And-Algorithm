/* Report errors in the comments below  */
/* Author - Akash Lodha
   Date - 20/9/2013
   Topic - General tree to paranthetical Notation
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void buildTree(struct tree *node,int number);
void paranthetical(struct tree *node);

struct tree
       {
       int data;
       tree *left;
       tree *right;    
       }*Tree=NULL;
       
void buildTree(struct tree *node,int number)
     {
     struct tree *temp =(struct tree*)malloc(sizeof(struct tree));
     temp->data = number;
     temp->left=temp->right=NULL;
     if(number<node->data)   // If number less than root move left
            {
            if(node->left==NULL)
                  node->left = temp;
            else
                buildTree(node->left,number);                    
            }           
     else if(number>node->data)//If number more than root move right
            {
            if(node->right==NULL)
                 node->right = temp;
            else 
                 buildTree(node->right,number);                        
            }             
     else if(number==node->data)//Prevent duplicate input
          printf("Duplicate input");       
     }              
     
void paranthetical(struct tree *node)
     {
     if(node->right!=NULL && node->left!=NULL) // iF PARENT
              {
              printf(" %d (",node->data); 
              paranthetical(node->left);
              paranthetical(node->right);
              printf(")");           
              }          
     else if(node->left==NULL || node->right==NULL) // lEAF NODES
          printf(" %d ",node->data);                    
     }     
     
main()
      {
      Tree =(struct tree*)malloc(sizeof(struct tree));
      Tree->left=Tree->right=NULL;              
      int n;      
      printf("Enter the root\n");
      scanf("%d",&n);
      Tree->data = n;   //Root of the tree     
      printf("ctr+z and enter to stop input:\n");              
      while(scanf("%d",&n)!=EOF)
           buildTree(Tree,n); // MAking of bst
      paranthetical(Tree);     
      getch();     
      }     
      
    
