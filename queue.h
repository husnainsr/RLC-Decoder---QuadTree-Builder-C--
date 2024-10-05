#pragma once
#include <iostream>
using namespace std;
class queue
{
    struct Node
    {
        int data;
        Node* Next;
    };
    Node* Head = NULL;
public:
    queue() { Head = NULL; }
    ~queue() { }
    void push(int);
    void pop();
    int top();
    bool isempty();
    bool clear_queue();
    void display_list();
};
