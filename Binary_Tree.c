#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node node_t;

int create();
int inOrder(node_t *root);
int postOrder(node_t *root);
int preOrder(node_t *root);


node_t *root = NULL;

int main()
{
    root = create();
    printf("\nInOrder\n");
    inOrder(root);
    printf("\npostOrder\n");
    postOrder(root);
    printf("\nPreOrder\n");
    preOrder(root);
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


int inOrder(node_t *root)//LVR
{
    if(root == NULL)
    {
        return 0;
    }
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
    return 0;
}
int postOrder(node_t *root)//LRV
{
    if(root == NULL)
    {
        return 0;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);

    return 0;
}
int preOrder(node_t *root)//VLR
{
    if(root == NULL)
    {
        return 0;
    }

    printf("%d ",root->data);
    postOrder(root->left);
    postOrder(root->right);


    return 0;
}