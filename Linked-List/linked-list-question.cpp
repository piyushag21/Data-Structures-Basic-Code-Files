#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};

// adding a node at  the front
void addfront(Node** head_ref , int new_value)
{
    Node* new_node = new Node();
    new_node->data = new_value;
    new_node->next = (*head_ref);
    *head_ref = new_node;
}

// adding element at the end of linked list
void addlast(Node** head_ref , int new_value)
{
    Node *new_node = new Node();
    new_node->data = new_value;
    new_node->next = NULL;
    Node *last = *head_ref;
    if( *head_ref == NULL )
    {
        *head_ref = new_node;
        return;
    }

    while( last->next != NULL )
    {
        last = last->next;
    }
    last->next = new_node;
}

//function to insert befor a key

void insert(Node** head_ref , int new_value, int key)
{
    Node *new_node = new Node();
    new_node->data = new_value;
    Node *prev;
    Node *temp = *head_ref;
    while(temp->data != key)
    {
        //cout << "heloo";
        prev = temp;
        temp = temp->next;
    }
    new_node->next = temp;
    prev->next = new_node;
}

// functiom to delete a given key

void deletekey(Node** head_ref , int key)
{
    Node *temp  = *head_ref , *prev;

    if(temp == NULL)
    {
        cout <<"hey list do not exist" << "\n";
        return;
    }
    if(temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }


    while( temp->data != key && temp != NULL )
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
}

// deleting complete linked list

void deletelist(Node** head_ref)
{
    Node *current = *head_ref;
    Node *next;
    while(current != NULL)
    {
        next = current->next;
        free(current);
        current = current->next;
    }
    *head_ref = NULL;
}

// searching in linked list

void serach(Node** head_ref , int value)
{
    Node *temp = *head_ref;
    while(temp != NULL)
    {
        if(temp->data == value)
        {
            cout << "Element Found" <<"\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Element not found" << '\n';
}

// function to get nth node in linked list

void getnode(Node** head_ref , int pos)
{
    Node *temp = *head_ref;
    for(int i = 0; i <= pos; i++)
    {
        if( i == pos )
        {
            cout << temp->data;
        }
        else
        {
            temp = temp->next;
        }
    }
}

// Nth node from the end of the list

void getfromlast(Node** head_ref , int pos_fromlast)
{
    int count = 0;
    Node *temp  = *head_ref;
    Node *prev = *head_ref;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    for(int i = 1 ; i <= count-pos_fromlast+1; i++)
    {
        if(i == count-pos_fromlast+1)
        {
            cout << prev->data;
        }
        else
        {
            prev = prev->next;
        }
        
    }
}

// function to find length of linked list

int len_link( Node** head_ref )
{
    Node *temp = *head_ref;
    int count = 0;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

//function to reverse linked list

void reverse(Node **head_ref)
{
    Node *prev = NULL;
    Node *next = NULL;
    Node *current = *head_ref;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

// function to detect loop in a linked list

bool detect_loop(Node **head_ref)
{
    Node *temp = *head_ref;
    Node *slow = *head_ref;
    Node *fast = *head_ref;
    while(temp != NULL && slow != NULL && fast != NULL)
    {
        if(temp == NULL)
        {
            return false;
        }
        temp = temp->next;
        slow = slow->next;
        fast = (fast->next)->next;
        if(slow == fast)
        {
            return true;
        }
    }
    return false;
}

// function to print the list

void print( Node *head_ref )
{
    while(head_ref != NULL)
    {
        cout << head_ref->data << " ";
        head_ref = head_ref->next;
    }
}

int main()
{
    int arr[111];
    Node* head = NULL;
    addfront(&head , 7);
    addfront(&head , 5);
    addfront(&head , 99);
    addfront(&head , 12);
    print(head);
    cout << "\n";

    addlast(&head , 34);
    insert(&head , 56 , 7);
    print(head);
    cout << "\n";
    getnode(&head , 3);
    cout << "\n";
    serach(&head , 56);
    getfromlast(&head , 7);
    int length = 0;
    length = len_link(&head);
    cout << "Length of linked list is " << length << "\n";
    reverse(&head);
    print(head);
    cout << "\n";
  //  check_palin(&head , length);

    
  //  deletekey(&head , 5);
 //   deletelist(&head);
   // print(head);
   head->next->next->next->next->next->next = head;
   if(detect_loop(&head))
   {
       cout << "Loop detected" << "\n";
   }
   else
   {
       cout << "No loop found" << "\n";
   }
   Node* temp = NULL;
   temp->data = 12;
   cout << temp->data; 

}
/*
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << n;
}*/