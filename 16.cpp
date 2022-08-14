
/*
Write a function named move_tail() which will move the tail to the first position of the list.
For example: If the list looks like this,
List: 2 -> 4 -> 1 -> 10 -> 5
After the operation the list will look like this,

*/

#include <iostream>
using namespace std;

class DoublyNode
{
public:
    int value;
    DoublyNode *next;
    DoublyNode *prev;

    DoublyNode(int value)
    {
        this->value = value;
        this->prev = NULL;
        this->next = NULL;
    }
};
//Initialisation
void insert_node(DoublyNode *&head, int value);

void insert_node(DoublyNode *&head, int value)
{
    DoublyNode *newNode = new DoublyNode(value);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        DoublyNode *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        newNode->prev = temp;
        temp->next = newNode;
    }
}

void display(DoublyNode *&head)
{
    DoublyNode *temp = head;

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
    DoublyNode *head = NULL;

    insert_node(head, 2);
    insert_node(head, 4);
    insert_node(head, 1);
    insert_node(head, 10);
    insert_node(head, 5);
    display(head);
    return 0;
}