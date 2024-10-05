#include "queue.h"
void queue::push(int x)
{
    Node* newnode = new Node;
    newnode->data = x;
    newnode->Next = NULL;
    if (Head != NULL)
    {
        Node* currentnode = Head;
        while (currentnode->Next != NULL)
        {
            currentnode = currentnode->Next;
        }
        currentnode->Next = newnode;
        //cout << "Element " << x << " is pushed into the queue\n";

    }
    else
    {
        Head = newnode;
        //cout << "Element " << x << " is pushed into the queue\n";
    }
}

void queue::pop()
{
    int element;
    if (Head)
    {
        element = Head->data;

        Node* temp = Head;
        Head = Head->Next;
        delete temp;

        //cout << "Element " << element << " is popped out from the queue\n";
    }
}

int queue::top()
{
    int element;
    if (Head)
    {
        element = Head->data;
        return element;
    }
}

bool queue::isempty()
{
    return Head == nullptr;
}

bool queue::clear_queue()
{
    if (Head)
    {
        while (Head != NULL)
            pop();

        //cout << "Queue is cleared now\n";
        return 1;
    }
    else
    {
        //cout << "Queue is already cleared\n";
        return 0;
    }
}

void queue::display_list()
{
    Node* currentnode = Head;
    while (currentnode != NULL)
    {
        cout << currentnode->data << " ";
        currentnode = currentnode->Next;
    }
    delete currentnode;
}
