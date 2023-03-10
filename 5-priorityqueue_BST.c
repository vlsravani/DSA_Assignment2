// Write a program to maintain a priority queue using a binary search tree

#include<stdio.h>
#include<stdlib.h>

typedef struct tree_node
{
   int data;
   struct tree_node * lchild;
   struct tree_node * rchild;
}node;

 node * insert_node(node *root, int data)
{
     node *new_node;

     if(root==NULL)   // if tree is empty, create new node and set it as the root node
     {
        new_node =(node*)malloc(sizeof(node*));
        new_node->data = data;
        new_node->lchild = NULL;
        new_node->rchild = NULL;

        return new_node;
     }

     // insert new node at appropriate position in binary tree
     if(data > root->data)
        root->rchild=insert_node(root->rchild, data);  //data > root --> insert at right side
     else
        root->lchild=insert_node(root->lchild, data);  //data < root --> insert at left side

    return root;

}

void display(node *root)
{
  //In-order Traversal  (Left-Data-Right)
  if(root!=NULL)
  {
    display(root->lchild);
    printf("%d ",root->data);
    display(root->rchild);
  }
}

//In-order successor
node* get_min(node* root)
{
    while (root->lchild != NULL)  //min value should present in the left most node
     {
        root = root->lchild;
    }
    return root;
}

node* delete_node(node* root, int data)
{
     /*
     * If the node becomes NULL, it will return NULL
     * Two possible ways which can trigger this case
     * 1. If we send the empty tree. i.e root == NULL
     * 2. If the given node is not present in the tree.
     */
   if (root == NULL) return NULL;
     /*
     * If root->data < data. data must be present in the right subtree
     * So, call the above remove function with root->right
     */
    if (data < root->data)
        root->lchild= delete_node(root->lchild, data);
         /*
        * if root->data > data. val must be present in the left subtree
        * So, call the above function with root->left
        */
    else if (data > root->data)
        root->rchild= delete_node(root->rchild,data);
         /*
         * This part will be executed only if the root->data == data
        * The actual removal starts from here
        */
    else
    {
         /*
         * Case 1: Leaf node. Both left and right reference is NULL
         * replace the node with NULL by returning NULL to the calling pointer and free the node
         */
        if (root->lchild == NULL && root->rchild == NULL) {
            free(root);
            root=NULL;
        }

        // Case 2 - Node has left child: replace the node with root->left and free the left node
        else if (root->lchild == NULL)
         {
            node* temp = root;
            root=root->rchild;
            free(temp);
         }

        // Case 3 - Node has right child: replace the root node with root->right and free the right node
        else if (root->rchild == NULL)
         {
            node* temp = root;
            root=root->lchild;
            free(root);
         }

         /*
         Case 4 - Node has both left and right children:
         * Find the min value in the right subtree
         * replace node value with min.
         * And again call the remove function to delete the node which has the min value.
         * Since we find the min value from the right subtree call the remove function with root->right.
         */
        else
        {
            node* temp= get_min(root->rchild);
            root->data = temp->data;
            root->rchild = delete_node(root->rchild, temp->data);
        }
    }
    return root;
}

void main()
{
    node *root=NULL;

    //Insert node into tree
    root= insert_node(root,15);
    root= insert_node(root,25);
    root= insert_node(root,5);
    root= insert_node(root,35);
    root= insert_node(root,40);
    root= insert_node(root,55);

    //display BST
    display(root);

    //delete node
    root=delete_node(root,35);

    printf("\nAfter deletion , the new tree :\n");
    display(root);
}
