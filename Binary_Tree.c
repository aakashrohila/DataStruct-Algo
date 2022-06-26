#include<stdio.h>
#include<stdlib.h>

int create();
void print_Tree();

struct node{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node node_t;

node_t *root = NULL;

int main()
{
    root = create();
    print_Tree();
    return 0;
}

int create()
{
    int x;
    node_t *newnode;
    newnode = (node_t*)malloc(sizeof(node_t));
    printf("\nEnter Data (-1 for no child or node) \n");
    scanf("%d",&x);
    if(x==-1)
    {
        newnode->left = NULL;
        newnode->right = NULL;
        return 0;
    }
    newnode->data = x;

    printf("Enter the left child of %d\n",x);
    newnode->left = create();

    printf("Enter the right child of %d",x);
    newnode->right = create();

    return newnode;
}
