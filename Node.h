#pragma once
class Node
{
	int data;
	Node* next;
	Node* prev;
public:
	Node(int data);
	void set_next(Node* next);
	void set_prev(Node* prev);
	Node* get_next();
	Node* get_prev();
	int get_data();
	void set_data(int);
};

