#include<stdio.h>
#include <stdlib.h>


typedef struct node
{
    int data;
    struct node *next; // self referential structure

}node_t;

node_t* create_node(int data);
int count_nodes();
void add_node_at_first_position(int data);
void add_node_at_last_position(int data);
void add_node_at_specific_position(int data,int pos);
void delete_node_at_last_position(void);
void delete_node_at_first_position(void);
void delete_node_at_specific_position(int pos);

void display_list( void );
node_t *head = NULL;

int main()
{   
    int pos;
    int data;
    // add_node_at_last_position(10);
    // add_node_at_last_position(20);
    // add_node_at_last_position(30);
    
    add_node_at_first_position(30);
    add_node_at_first_position(20); 
    add_node_at_first_position(10); 
    // display_list();

    while(1)
    {
        printf("Enter the pos\n");
        scanf("%d",&pos);

        if(pos>0 && pos <= count_nodes())
        {
            break;
        }

        printf("Invalid Position \n");
    }
    // printf("Enter data\n");
    // scanf("%d",&data);
    // add_node_at_specific_position(data,pos);
    //delete_node_at_first_position();
    //delete_node_at_last_position();
    delete_node_at_specific_position(pos);
    display_list();

    return 0;
}


node_t* create_node(int data)
{
    node_t *temp = (node_t*)malloc(sizeof(node_t));

    temp->data = data;
    temp->next = NULL;

    return temp;
}

void add_node_at_first_position(int data)
{
    node_t *newnode = create_node(data);

    if(head == NULL)
    {
        head = newnode;
    }

    else
    {
        newnode->next = head;
        head = newnode;
    }
    
}

void add_node_at_last_position(int data)
{
    node_t* newnode = create_node(data);
    if(head == NULL)
    {
        head = newnode;
    }

    else
    {
        node_t *trav = head;

        while(trav->next != NULL)
        {
            trav = trav->next;
        }

        trav->next = newnode;

    }
}

int count_nodes()
{
    int count = 0;

    node_t* trav = head;

    while(trav!= NULL)
    {
        count++;
        trav = trav->next;
    }

    return count;
}

void add_node_at_specific_position(int data,int pos)
{
    
    if(pos==1)
        add_node_at_first_position(data);

    else if(pos == count_nodes()+1)
        add_node_at_last_position(data);

    else
    {
        node_t* newnode = create_node(data);
        node_t *trav = head;

        int i = 1;

        while(i<pos-1)
        {
            i++;
            trav = trav->next;
        }

        newnode->next = trav->next;
        trav->next = newnode;
    }
    
}


void display_list()
{
    node_t *trav = head;

    if(trav!= NULL)
    {
    printf("head-> ");

    while(trav != NULL)
    {
        printf("%d ->",trav->data);

        trav = trav->next;

    }
    printf("NULL \n");

    }
}


void delete_node_at_first_position(void)
{
    if(head!= NULL)
    {
        if(head->next == NULL)
        {
            free(head);
            head = NULL;
        }

        else
        {
            node_t *temp = head;
            head = head->next;
            free(temp);
        }
        
    }
    else
    {
        printf("List is empty");
    }
    

}

void delete_node_at_last_position(void)
{
    if(head!=NULL)
    {
        if(head->next == NULL)
        {
            free(head);
            head = NULL;
        }

        else
        {
            node_t *trav = head;

            while(trav->next->next != NULL)
                trav = trav->next;
            
            free(trav->next);
            trav->next = NULL;
        }
        
    }
    else
    {
        printf("List is Empty");
    }
    
}

void delete_node_at_specific_position(int pos)
{
    if(pos==1)
        delete_node_at_first_position();
    
    else if(pos == count_nodes())
        delete_node_at_last_position();

    else
    {
        node_t *trav = head;
        int i = 1;
        while(i < pos-1)
        {
            i++;
            trav = trav->next;
        } 

        node_t *temp = trav->next;
        trav->next = trav->next->next;
        free(temp);
        temp = NULL;

    }
    
}