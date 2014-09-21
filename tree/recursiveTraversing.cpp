/* Report errors in the comments below  */
/* Author - Akash Lodha
   Date - 20/9/2013
   Topic - Implementation Of Binary Search Tree
           Recursive Inorder,Preorder,Postorder Traversal
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void buildTree(struct tree *node,int number);
void preorder(struct tree *node);
void inorder(struct tree *node);
void postorder(struct tree *node);

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
      while(1)
           {            
              printf("\n1.Preorder\n2.Postorder\n3.Inorder\n4.Exit\n");
              scanf("%d",&n);         
              switch(n)
                 {
                 case 1:
                      preorder(Tree);
                      break;
                 case 2:
                      postorder(Tree);
                      break;
                 case 3:
                      inorder(Tree);                
                      break;
                 case 4:
                      exit(1);
                      break;
                 default:
                         printf("Wrong Input\n");          
                 }
           }     
      getch();     
      }     
      
//inorder traversal      
void inorder(struct tree *node)
     {
     if(node!=NULL)
             {
             inorder(node->left);
             printf("%d ",node->data); 
             inorder(node->right);     
             }               
     }    

//preorder traversal      
void preorder(struct tree *node)
     {
     if(node!=NULL)
             {
             printf("%d ",node->data);      
             preorder(node->left);              
             preorder(node->right);     
             }               
     } 
     
//postorder traversal      
void postorder(struct tree *node)
     {
     if(node!=NULL)
             {      
             postorder(node->left);              
             postorder(node->right);
             printf("%d ",node->data);     
             }               
     }      
