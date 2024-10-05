#include "Hashing.h"
#include <string>
#include "List.h"
Hashing::Hashing(int size)
{
	hashTable = new Lisst[size];
	tableSize = size;
}

long long int Hashing::hashCalculate(List merge, int size)
{
	long long int sumTemp = 0;
	string tempData = "";
	Node* iterator = merge.getHead();
	for (int i = 0; i < size;)
	{
		tempData = "";
		for (int j = 0; j < 4; j++)
		{
			if (iterator != nullptr)
			{
				tempData= to_string(iterator->get_data())+ tempData;
				iterator = iterator->get_next();
			}
			else
				tempData+= "0";
		}
		sumTemp += stod(tempData);
		i += 4;
	}
	return (sumTemp%tableSize);
}
void Hashing::display()
{
	for (int i = 0; i < this->tableSize; i++)
	{
		if (!hashTable[i].IsEmpty())
		{
			cout << "\nList " << i << " :: ";
			hashTable[i].displayList();
		}
	}
}
void Hashing::insert(Image &obj)
{
	List horizental;
	List vertical;
	int count = 0;
	//to calculate horizental sum
	for (int i = 0; i < obj.getRow(); i++)
	{
		count = 0;
		for (int j = 0; j < obj.getCol(); j++)
		{
			if (obj.getPixel(i,j) == 0)
				count += 1;
		}
		horizental.addAtLast(count);
	}
	//to calculate vertical sum
	for (int i = 0; i < obj.getCol(); i++)
	{
		count = 0;
		for (int j = 0; j < obj.getRow(); j++)
		{
			if (obj.getPixel(j, i) == 0)
				count += 1;
		}
		vertical.addAtLast(count);
	}
	//merging both list into vertical
	vertical.merge(horizental);
	//calculate total Size including padding
	int mergeSize = obj.getCol() + obj.getRow();
	if ((obj.getCol() + obj.getRow()) % 4 != 0)
	{
		for (int i = 1; i < 100; i++)
		{
			if ((obj.getCol() + obj.getRow() + i) % 4 == 0)
			{
				int mergeSize = (obj.getCol() + obj.getRow() + i) % 4;
				break;
			}
		}
	}
	int hashIndex = hashCalculate(vertical, mergeSize);
	string name = obj.getFileName();
	hashTable[hashIndex].addAtLast(name);




}
bool Hashing::search(Image& obj)
{
	List horizental;
	List vertical;
	int count = 0;
	//to calculate horizental sum
	for (int i = 0; i < obj.getRow(); i++)
	{
		count = 0;
		for (int j = 0; j < obj.getCol(); j++)
		{
			if (obj.getPixel(i, j) == 0)
				count += 1;
		}
		horizental.addAtLast(count);
	}
	//to calculate vertical sum
	for (int i = 0; i < obj.getCol(); i++)
	{
		count = 0;
		for (int j = 0; j < obj.getRow(); j++)
		{
			if (obj.getPixel(j, i) == 0)
				count += 1;
		}
		vertical.addAtLast(count);
	}
	//merging both list into vertical
	vertical.merge(horizental);
	//calculate total Size including padding
	int mergeSize = obj.getCol() + obj.getRow();
	if ((obj.getCol() + obj.getRow()) % 4 != 0)
	{
		for (int i = 1; i < 100; i++)
		{
			if ((obj.getCol() + obj.getRow() + i) % 4 == 0)
			{
				int mergeSize = (obj.getCol() + obj.getRow() + i) % 4;
				break;
			}
		}
	}
	int hashIndex = hashCalculate(vertical, mergeSize);
	cout << "------------------------------------------------------------------------\n";
	cout << "HASH Index = " << hashIndex << endl;
	if (hashTable[hashIndex].search(obj.getFileName()))
	{
		cout << obj.getFileName() << "  is in the database\n";
		return 1;
	}
	else
		cout << obj.getFileName() << " is not in the database\n";
	return 0;
}