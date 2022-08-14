
/*
Write a function named move_tail() which will move the tail to the first position of the list.
For example: If the list looks like this,
List: 2 -> 4 -> 1 -> 10 -> 5
After the operation the list will look like this,

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

void move_tail(Node *&head)
{
    Node *temp = head;
    if (temp == NULL)
    {
        cout << "Linked List is empty" << endl;
    }
    else
    {
        if (temp->next != NULL)
        {
            while ((temp->next->next) != NULL)
            {
                temp = temp->next;
            }
            Node *nodeToMove = temp->next;
            temp->next = NULL;
            nodeToMove->next = head;
            head = nodeToMove;
        }
    }
}

int main(void)
{
    Node *head = NULL;

    insert_node(head, 2);
    insert_node(head, 4);
    insert_node(head, 1);
    insert_node(head, 10);
    insert_node(head, 5);
    move_tail(head);
    display(head);
    return 0;
}