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
		cout << "���������� ������ �� 3 ��������" << endl;
		List a(3);
		List b;
		cout << a << endl;
		cout << "������� ������ �������� ��������: ";
		int i;
		cin >> i;
		cout << "������� �������: ";
		cout << a[i] << endl;
		b = a;
		
		cout << "������������� ��������� = (b = a) " << endl;
		cout << b << endl;
		cout << "����������� � ����� ������ ����� 3" << endl;
		a + 3;
		cout << a << endl;

		cout << "������� ������� �� ������������ ������� " << endl;
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