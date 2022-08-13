/*
Write a function named insert_node() that inserts a value at the end of a singly linked list. If there are no nodes, it will insert a head.
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

int main(void)
{
    Node *head = NULL;
    insert_node(head, 1);
    insert_node(head, 2);
    insert_node(head, 3);
    insert_node(head, 4);
    display(head);
    return 0;
}