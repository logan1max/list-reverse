// list.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

struct element
{
	int data;
	element* next;
	element() { data = 0; next = NULL; }
	element(int Data, element* Next) 
	{
		data = Data;
		next = Next;
	}
};

class list
{
	element* head;
	int size;

public:
	list();
	~list();

	int GetSize() { return size; }

	void add(int x);
	void ShowList();
	void ReverseList(list &l);
	void ListDouble(list& l);
	void delByIndex(int index);
};

list::list()
{
	head = NULL;
	size = 0;
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

	element *temp1=new element;
	//temp1 = head;

	if (head==NULL)
	{
		head = temp;
		head->next = NULL;
		size++;
		return;
	}
	
	if (head->next==NULL)
	{
		head->next = temp;
		size++;
		return;
	}

	if (head->next!=NULL)
	{
		temp1 = head;
		while (temp1->next!=NULL)
		{
			temp1 = temp1->next;
		}
		temp1->next = temp;
		size++;
	}
}

void list::ShowList()
{
	if (head!=NULL)
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

void list::ReverseList(list &l)
{
	element* prev = NULL;
	for (element* curr = l.head; curr != NULL;) 
	{
		element* next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	l.head = prev;
}

void list::ListDouble(list& l)
{
	for (element* curr = l.head; curr != NULL;)
	{
		element* next = curr->next;
		element* newElement = new element(curr->data,next);
		curr->next = newElement;
		curr = curr->next->next;
		size++;		
	}
//	l.head = temp;
}

void list::delByIndex(int index)
{
	if (index == 0)
	{
		delete head;
	}
	else
	{
		element* prev = head;

		for (int i = 0; i < index - 1; i++)
		{
			prev = prev->next;
		}

		element* elemDelete = prev->next;

		prev->next = elemDelete->next;

		delete elemDelete;
		size--;
		cout << "Prev: " << prev->data << endl;
	}	
}

int main()
{
	list l;
	l.add(1);
	l.add(2);
	l.add(3);
	l.add(4);
	l.ShowList();
	l.delByIndex(2);
	l.ShowList();
	cout << endl << l.GetSize();
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
