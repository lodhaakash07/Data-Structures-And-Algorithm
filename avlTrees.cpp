struct node{
            int data;
            struct node *left;
            struct node *right;
            }
int find_height(struct node *node)
    {
    int height =0;
    if(node!=NULL)
        {
        int left_height = find_height(node->left);
        int right_height = find_height(node->right);
        int max = (left_height>right_height)?left_height:right_height;
        height = max+1;          
        }
    return height;    
    }            
int factor(struct node *node)
    {
    int left_height = find_height(node->left);
    int right_height = find_height(node_right);
    return (left_height-right_height);              
    }    
void left_rotate(struct node *node)
     {
     /*
     while(node!=null)
            node->data    
     */                   
     }
void right_rotate(struct node *node)
     {
     }
void insert()
     {
             
     }              
    
