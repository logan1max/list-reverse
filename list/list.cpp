﻿// list.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

struct element
{
	int data;
	element* next;
};

class list
{
	element* head;

public:
	list();
	~list();
	void add(int x);
	void ShowList();
};

list::list()
{
	head = NULL;
}

list::~list()
{
	while (head != NULL)
	{
		element* temp = head->next;
		delete head;
		head = temp;
	}
}

void list::add(int data)
{
	element* temp = new element;

	temp->data = data;

	element* temp1 = new element;

	if (!head)
	{
		head = temp;
		head->next = NULL;
		return;
	}

	if (!head->next)
	{
		head->next = temp;
		return;
	}

	if (head->next)
	{
		temp1 = head;
		while (temp1->next)
		{
			temp1 = temp1->next;
		}
		temp1 = temp;
	}

}

void list::ShowList()
{
	if (head)
	{
		element* temp = new element;
		temp = head;
		while (temp)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	else return;
}

int main()
{
	list l;
	l.add(1);
	l.add(2);
	l.add(3);
	l.ShowList();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.