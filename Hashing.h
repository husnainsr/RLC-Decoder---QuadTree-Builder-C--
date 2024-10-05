#pragma once
#include "Lisst.h"
#include "Image.h"
class Hashing
{
	int tableSize;
	Lisst* hashTable;
public:
	Hashing(int);
	void insert(Image&);
	bool search(Image&);
	long long int hashCalculate(List, int);
	void display();
};