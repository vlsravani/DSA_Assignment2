// Write a program to evaluate an arithmetic expression using binary tree

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define a union to represent a node in the binary tree
union NodeData
{
    char op;
    int value;
};

struct Node
{
    union NodeData data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with given operator and operands
struct Node* newNode(char op, struct Node* left, struct Node* right)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data.op = op;
    node->left = left;
    node->left->right = right;
    return node;
}

// Function to create a new node with given integer value
struct Node* newLeaf(int value)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data.value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to parse an arithmetic expression string and build the corresponding expression tree
struct Node* buildTree(char* expr)
{
    int i = 0;
    struct Node* stack[100];
    int top = -1;

    while (expr[i] != '\0')
    {
        if (isdigit(expr[i]))     //checking if the input is operator or operand
        {
            int value = 0;
            while (isdigit(expr[i]))
            {
                value = value * 10 + (expr[i] - '0');  //converting the integer stored as string to int format
                i++;
            }
            struct Node* node = newLeaf(value);
            stack[++top] = node;
        }
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')    //if the value is an operator
        {
            struct Node* right = NULL;
            if(top > 0)               //if stack has more than two items, insert the value to the right of the tree
            {
                right = stack[top--];
            }
            struct Node* left = stack[top--];         //if stack is empty, insert the node to the left of the tree
            struct Node* node = newNode(expr[i], left, right);
            stack[++top] = node;
            i++;
        }
        else
        {
            i++;
        }
    }
    struct Node* right = stack[top--];
    struct Node* root = stack[top--];
    root->right = right;
    return root;
}

// Function to evaluate the expression tree rooted at the given node
int evaluate(struct Node* root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return root->data.value;
    }
    int leftVal = evaluate(root->left);
    int rightVal = evaluate(root->right);
    switch (root->data.op)
    {
        case '+': return leftVal + rightVal;
        case '-': return leftVal - rightVal;
        case '*': return leftVal * rightVal;
        case '/': return leftVal / rightVal;
        default: return 0;
    }
}

int main()
{
    // Read an arithmetic expression string from the user
    char expr[100];
    printf("Enter an arithmetic expression: ");
    scanf("%s", expr);

    // Build the expression tree from the expression string
    struct Node* root = buildTree(expr);

    // Evaluate the expression tree and print the result
    int result = evaluate(root);
    printf("Result of the evaluation: %d\n", result);

    return 0;
}
