#include "List.h"
#include <iostream>
#include <exception>
using namespace std;
int main()
{
	system("color F0");
	setlocale(LC_ALL, "rus");
	try
	{
		cout << "Заполнение списка на 3 элемента" << endl;
		List a(3);
		List b;
		cout << a << endl;
		cout << "Введите индекс искомого элемента: ";
		int i;
		cin >> i;
		cout << "Искомый элемент: ";
		cout << a[i] << endl;
		b = a;
		
		cout << "Использование оператора = (b = a) " << endl;
		cout << b << endl;
		cout << "Прибавление в конец списка числа 3" << endl;
		a + 3;
		cout << a << endl;

		cout << "Попытка удалить не существующий элемент " << endl;
		--a;
		cout << a << endl;
		--a;
		cout << a << endl;
		--a;
		cout << a << endl;
		--a;
		cout << a << endl;
		--a;
	}
	catch (int)
	{
		cout << "Error!" << endl;
	}
	return 0;
}