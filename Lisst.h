#pragma once
#include <iostream>
#include <string>
using namespace std;
struct node
{
	node* next;
	node* prev;
	string data;
	node(string d = "") {
		next = nullptr;
		prev = nullptr;
		this->data = d;
	}
};
class Lisst
{
public:
	node* head;
	Lisst()
	{
		head = nullptr;
	}
	void addAtHead(string data)
	{
		node* temp = new node(data);
		if (head == nullptr)
		{
			head = temp;
		}
		else
		{
			head->prev = temp;
			temp->next = head;
			head = temp;
		}
	}
	void addAtLast(string data)
	{
		node* iterator = head;
		node* temp = new node(data);
		if (head == nullptr)
		{
			head = temp;
		}
		else
		{
			while (iterator->next != nullptr)
			{
				iterator = iterator->next;
			}
			iterator->next = temp;
			temp->prev = iterator;
		}
	}
	void displayList()
	{
		node* iterator = head;
		while (iterator != nullptr)
		{
			cout << " "  << iterator->data;
			iterator = iterator->next;
		}
		cout << endl;
	}
	bool IsEmpty()
	{
		if (head == NULL)
			return true;
		return false;
	}
	bool search(string n)
	{
		node* iterator = head;
		while (iterator != nullptr)
		{
			if (iterator->data == n)
			{
				return 1;
			}
			iterator = iterator->next;
		}
		return 0;
	}
};



