#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;
};

// function to push element in doubly linked list

void push(Node **head_ref , int new_value)
{
    Node *new_node = new Node();
    new_node->data  = new_value;
    new_node->prev = NULL;
    new_node->next = (*head_ref);

    if( *head_ref != NULL )
    {
        (*head_ref)->prev = new_node;
    }

    *head_ref = new_node;
}

// function to insert after a given key in list

void insertafter(Node **head_ref , int key , int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    Node *temp = *head_ref;
    Node *after;
    if(*head_ref == NULL)
    {
        cout << "LIST IS EMPTY" << "\n";
        return;
    }

    if(temp->data == key && temp->next != NULL)
    {
        new_node->next = temp->next;
        (temp->next)->prev = new_node;
        new_node->prev = temp;
        temp->next = new_node;
        return;
    }

    if(temp->data == key && temp->next == NULL)
    {
        temp->next = new_node;
        new_node->prev = temp;
        new_node->next = NULL;
        return;
    }

    while(temp != NULL && temp->data != key)
    {
        temp = temp->next;
        if(temp == NULL)
        {
            cout << "Hey key does not exist in list" << "\n";
            return;
        }

        after = temp->next;
    }


    if(temp->next == NULL)
    {
        temp->next = new_node;
        new_node->prev = temp;
        new_node->next = NULL;
        return;
    }

    new_node->next = after;
    after->prev = new_node;
    new_node->prev = temp;
    temp->next = new_node;
}

// function to append element at the end of linked list

void append(Node **head_ref , int new_value)
{
    Node *new_node = new Node();
    new_node->data = new_value;
    Node *temp = *head_ref;

    if(*head_ref == NULL)
    {
        new_node->next = NULL;
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = NULL;
}

void reverse(Node** head)
{
    Node *prev_node = NULL;
    Node *next_node = NULL;
    Node *current_node = *head;
    while(current_node != NULL)
    {
        next_node = current_node->next;
        current_node->next = prev_node;
        prev_node = current_node;
        prev_node->prev = current_node;
        current_node = next_node;
    }
    *head = prev_node;
}

/*void reverse_list(struct Node **head)
{
    struct Node *prev_node = NULL;
    struct Node *next_node = NULL;
    struct Node *current_node = *head;
    while(current_node != NULL)
    {
        next_node = current_node->link;
        current_node->link = prev_node;
        prev_node = current_node;
        current_node = next_node;
    }
    *head = prev_node;
} */
// function to print and transverse the list

void print(Node *head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

int main()
{
    Node *head = NULL;
    push(&head , 1);
    push(&head , 2);
    push(&head , 4);
    print(head);
    insertafter(&head , 4 , 3);
    cout << "Elements after insertion are " ;
    print(head);
    append(&head , 10);
    cout << "Elements after append are ";
    print(head);
    reverse(&head);
    print(head);
}