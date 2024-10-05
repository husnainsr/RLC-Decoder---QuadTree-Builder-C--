#pragma once
#include "Node.h"
#include <iostream>
using namespace std;
class List
{
	Node* head;
public:
	List();
	void addAtHead(int data);
	void displayList();
	void addAtLast(int data);
	void deleting(int);
	void merge(List);
	Node* getHead();
};

