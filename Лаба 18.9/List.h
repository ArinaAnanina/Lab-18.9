#pragma once
#include <iostream>

using namespace std;
const int MaxSize = 3;
struct ListItem
{
	int data;
	ListItem* next;
};
class List
{
	int size;
	ListItem* first;
	ListItem* last;
	void addItem(int value);
public:
	List()
	{
		size = 0;
		first = 0;
		last = 0;
	}
	List(int size);
	List(List& list);
	~List();

	List& operator=(const List& list);
	int operator[](int index);
	List operator+(const int value);
	List operator-- ();

	friend ostream& operator<< (ostream& out, const List& list);
	friend istream& operator>> (istream& in, List& list);
};
