//Write a program to maintain a priority queue using a binary search tree

#include<stdio.h>
#include<stdlib.h>

typedef struct tree_node
{
   int data;
   struct tree_node* lchild;
   struct tree_node* rchild;
}node;

node* insert_node(node *root, int data)
{
     node *new_node;
     if(root==NULL)     //if tree is empty, to create new node and set it as the root node
     {
        new_node =(node*)malloc(sizeof(node*));
        new_node->data = data;
        new_node->lchild = NULL;
        new_node->rchild = NULL;

     return new_node;
     }

     //Inserting new node at appropriate position in binary tree
     if(data > root->data)
        root->rchild=insert_node(root->rchild,data); //if data > root, insert new node to the right
     else
        root->lchild=insert_node(root->lchild,data); //if data < root, insert new node to the left

    return root;
}

void display(node *root)
{
  if(root!=NULL)
  {
      display(root->lchild);     //performing in-order traversal (Left-Data-Right)
      printf("%d ",root->data);
      display(root->rchild);
  }
}

//in-order successor
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
    if (root == NULL)    //If the node becomes NULL, it will return NULL
        return NULL;    //in case of empty tree (root is NULL) or when given data to delete is not in the tree

    if (data < root->data)  //if root->data > data, then data to delete must be present in the left subtree
        root->lchild= delete_node(root->lchild, data);

    else if (data > root->data)  //if root->data < data, then data to delete must be present in the right subtree
        root->rchild= delete_node(root->rchild,data);

    else        //if the root->data == data i.e., the actual deletion requirement
        {
            //Case 1: Leaf node i.e., Both left and right reference is NULL
            if (root->lchild == NULL && root->rchild == NULL)
            {
                free(root);  //replace the node with NULL and free the node
                root=NULL;
            }
            else if (root->lchild == NULL)  //Case 2: Node has left child
            {
                node* temp = root;
                root=root->rchild;  //replace the node with root->left and free the left node
                free(temp);
            }
            else if (root->rchild == NULL)  //Case 3: Node has right child
            {
                node* temp = root;
                root=root->lchild;  //replace the root node with root->right and free the right node
                free(root);
            }
            else   //Case 4: Node has both left and right children
            {
                node* temp= get_min(root->rchild);  //Find the min value in the right subtree and replace node value with min (in-order successor)
                root->data = temp->data;
                root->rchild = delete_node(root->rchild, temp->data);  //now we call the remove function to delete the node which has the min value
            }
        }
    return root;
}

//Driver Code
void main()
{
    node *root=NULL;

    //Inserting nodes into the tree
    root= insert_node(root,15);
    root= insert_node(root,25);
    root= insert_node(root,50);
    root= insert_node(root,35);
    root= insert_node(root,60);
    root= insert_node(root,5);

    //displaying BST
    display(root);

    //deleting a node from the tree
    root=delete_node(root,35);
    printf("\nAfter deletion, the new tree :\n");

    //displaying BST after deletion
    display(root);
}
