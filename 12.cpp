/*
Write a function named insert_node_by_position() that inserts a value at any position of the singly linked list. You can assume that if there are 5 nodes in the list, the positions are 0, 1, 2, 3 and 4.
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;

    //Constructor
    Node(int value)
    {
        this->value = value;
        this->next = NULL;
    }
};

// Function Initialisation
void insert_node(Node *&head, int value);
void insert_node_by_position(Node *&head, int position, int value);
int countNodes(Node *&head);

void insert_node(Node *&head, int value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
};

void display(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->value;
        if (temp->next != NULL)
        {
            cout << " --> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

void insert_node_by_position(Node *&head, int position, int value)
{
    Node *newNode = new Node(value);

    if (head == NULL)
    {
        head = newNode;
    }
    else if (position >= countNodes(head))
    {
        cout << "Position out of linked list range" << endl;
    }
    else
    {
        int pos = 0;
        Node *temp = head;

        while (pos != position - 1)
        {
            temp = temp->next;
            pos++;
            if (pos == position - 1)
            {
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }
}

int countNodes(Node *&head)
{
    Node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        length++;
    }
    return length;
}

int main(void)
{
    Node *head = NULL;
    insert_node(head, 1);
    insert_node(head, 2);
    insert_node(head, 3);
    insert_node(head, 4);
    insert_node_by_position(head, 2, 99);
    display(head);
    return 0;
}