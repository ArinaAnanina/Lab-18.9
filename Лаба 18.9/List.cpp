#include <iostream>
#include <exception>
#include "List.h"
using namespace std;
List::List(int size)
{
	if (size > MaxSize)
	{
		throw 1;
	}
	this->last = 0;
	this->first = 0;
	this->size = 0;
	for (int i = 0; i < size; i++) {
		int* data = new int;
		cout << "Введите "<< i<< " элемент: ";
		cin >> (*data);
		this->addItem(*data);
	}
}

List::List(List& list)
{
	this->last = 0;
	this->first = 0;
	this->size = 0;
	*this = list;
}

List::~List()
{
	ListItem* current = this->first;
	while (current) {
		ListItem* rem = current;
		current = current->next;
		delete rem;
	}
}

void List::addItem(int value)
{
	ListItem* item = new ListItem;
	item->data = value;
	item->next = 0;

	if (!this->first) {
		this->first = item;
	}
	if (this->last) {
		this->last->next = item;
		this->last = item;
	}
	else {
		this->last = item;
	}

	this->size++;
}

List& List::operator=(const List& list)
{
	if (this == &list)
	{
		return *this;
	}

	// Очистка
	if (this->size) {
		this->~List();
		this->size = 0;
		this->last = 0;
		this->first = 0;
	}

	// Наполнение
	ListItem* item = list.first;
	while (item) {
		this->addItem(item->data);
		item = item->next;
	}

	return *this;
}

int List::operator[](int index)
{
	if (index < 0) {
		throw 2;
	}
	if (index >= size) {
		throw 3;
		return this->first->data;
	}
	int i = 0;
	ListItem* item = this->first;
	while (i < index ) {
		item = item->next;
		i++;
	}

	return item->data;
}

List List::operator+(const int value)
{
	if (size + 1 == MaxSize)
	{
		throw 4;
	}
	ListItem* item = new ListItem;
	item->data = value;
	item->next = 0;

	if (!this->first) {
		this->first = item;
	}
	if (this->last) {
		this->last->next = item;
		this->last = item;
	}
	else {
		this->last = item;
	}

	this->size++;
	return *this;
}

List List::operator-- ()
{
	if (size == 0)
	{
		throw 5;
	}
	if (size == 1)
	{
		ListItem* current = this->first;
		delete current;
		this->first = 0;
		this->last = 0;
		this->size = 0;
		return *this;
	}
	ListItem* current = this->first;
	this->first = this->first->next;
	this->size--;
	delete current;
	return *this;
}

ostream& operator<<(ostream& out, const List& list)
{
	ListItem* item = list.first;
	while (item) {
		out << item->data << endl;
		item = item->next;
	}

	return out;
}

istream& operator>>(istream& in, List& list)
{
	ListItem* item = list.first;
	while (item) {
		in >> item->data;
		item = item->next;
	}
	return in;
}