
/*
Write a function named delete_node_by_position() that deletes a node from the singly linked list. If there is only one node left, it will delete the head.
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
void deletionAtHead(Node *&head);
void deletionAtTail(Node *&head);
void delete_node_by_position(Node *&head, int position);

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
        }
        newNode->next = temp->next;
        temp->next = newNode;
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

void deletionAtHead(Node *&head)
{
    if (head != NULL)
    {
        Node *temp = head;
        head = temp->next;

        delete temp;
    }
    else
    {
        cout << "The LinkedList is already empty" << endl;
    }
}

void deletionAtTail(Node *&head)
{
    if (head->next == NULL)
    {
        deletionAtHead(head);
    }
    else if (head != NULL)
    {
        Node *temp = head;

        while ((temp->next)->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    else
    {
        cout << "The LinkedList is already empty" << endl;
    }
};

void delete_node_by_position(Node *&head, int position)
{
    if (position == 0)
    {
        deletionAtHead(head);
    }
    else if (position == countNodes(head))
    {
        deletionAtTail(head);
    }
    else if (position < 0 || position > countNodes(head))
    {
        cout << "Position is out of LinkedList" << endl;
    }
    else
    {
        Node *temp = head;
        int i = 1;

        while (i != position)
        {
            temp = temp->next;
            i++;
        }
        Node *nodeAfterDeletedNode = temp->next->next;
        delete temp->next;
        temp->next = nodeAfterDeletedNode;
    }
};

int main(void)
{
    Node *head = NULL;

    insert_node(head, 1);
    delete_node_by_position(head, 0);
    insert_node(head, 2);
    insert_node(head, 3);
    insert_node(head, 4);
    insert_node_by_position(head, 2, 99);
    delete_node_by_position(head, 2);
    display(head);
    return 0;
}