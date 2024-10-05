#include "List.h"
List::List()
{
	head = nullptr;
}
void List::addAtHead(int data)
{
	if (head == nullptr)
	{
		Node* temp = new Node(data);
		head = temp;
	}
	else
	{
		Node* temp = new Node(data);
		head->set_prev(temp);
		temp->set_next(head);
		head = temp;
	}
}
void List::addAtLast(int data)
{
	Node* iterator = head;
	Node* temp = new Node(data);
	if (head == nullptr)
	{
		head = temp;
	}
	else
	{
		while (iterator->get_next() != nullptr)
		{
			iterator = iterator->get_next();
		}
		iterator->set_next(temp);
		temp->set_prev(iterator);
	}
}
void List::displayList()
{
	Node* iterator = head;
	while (iterator != nullptr)
	{
		cout << " " << iterator->get_data();
		iterator = iterator->get_next();
	}
	cout << endl;
}
void List::deleting(int data)
{
	Node* temp = head;
	while (temp->get_next()->get_data() != data)
	{
		temp = temp->get_next();
	}
	Node* tobedelete = temp->get_next();
	temp->set_next(temp->get_next()->get_next());
	delete tobedelete;

}
Node* List::getHead()
{
	return head;
}

void List::merge(List obj)
{
	Node* iterator = obj.getHead();
	while (iterator != nullptr)
	{
		this->addAtLast(iterator->get_data());
		iterator = iterator->get_next();
	}
}
