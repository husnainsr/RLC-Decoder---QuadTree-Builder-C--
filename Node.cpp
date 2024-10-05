#include "Node.h"
Node::Node(int data)
{
	this->data = data;
	prev = nullptr;
	next = nullptr;
}
void Node::set_next(Node* next)
{
	this->next = next;
}
void Node::set_prev(Node* prev)
{
	this->prev = prev;
}
Node* Node::get_next()
{
	return next;
}
Node* Node::get_prev()
{
	return prev;
}
void Node::set_data(int data)
{
	this->data = data;
}
int Node::get_data()
{
	return data;
}