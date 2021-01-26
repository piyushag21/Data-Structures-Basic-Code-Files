#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};
// function to add element at the start of list 

void push(Node** head_ref , int new_value)
{
    Node *new_node = new Node();
    Node *temp = *head_ref;
    new_node->data = new_value;
    new_node->next = *head_ref;
    if( temp != NULL )
    {
        while( temp->next != *head_ref)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    else
    {
        new_node->next = new_node;
    }
    *head_ref = new_node;
}

// deletion in circular linked list

void deletecl(Node **head_ref , int key)
{
    Node *temp = *head_ref , *prev;
    Node *temp1 = *head_ref;
    if(temp == NULL)
    {
        cout << "hey list dont exist";
        
        return;
    }
    
    if(temp != NULL && temp->data == key)
    {
        *head_ref = NULL;
        free(temp);
        return;
    }

    do
    {
        prev = temp;
        temp = temp->next;

    } while (temp->data != key && temp->next != *head_ref );

    if(temp->data == key)
    {
        prev->next = temp->next;
        free(temp);
    }
    else
    {
        cout << "key not found"  << "\n" ;
    }
}

// function to count the nodes or finding length of list

int countnode(Node **head_ref)
{
    int count = 0;
    Node *temp = *head_ref;
    if(*head_ref == NULL)
    {
        return 0;
    }

    do
    {
        temp = temp->next;
        count++;
    } while(temp != *head_ref);
    return count;
}

// function to convert liner to cirular linked list

Node *tocirular(Node *head)
{
    Node *start = head;
    while(head->next != NULL)
    {
        head = head->next;
    }
    head->next  =  start;
    return start;
}

// function to print the list
void print(Node *head_ref)
{
    Node *temp = head_ref;
    if(head_ref != NULL)
    {
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while(temp != head_ref);
    }
    else
    {
        cout << "hey list is empty";
    }
    
}

int main()
{
    Node* head = NULL;
    push(&head , 1);
    push(&head , 2);
    push(&head , 4);
    print(head);
    cout << "\n";
    deletecl(&head , 10);
    print(head);
    cout << "\n";
    cout << "Number of nodes in circular linked list are " << countnode(&head) << "\n";
}
#in