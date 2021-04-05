#include <iostream>
#include "Deque.h"
#include "Deque_int.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	Deque<int> d;
	d.PushFront(4);
	d.PushBack(1);
	d.PushFront(11);
	d.PushBack(7);
	d.PushBack(2);

	Deque<int> d1(d);

	cout << d;
	cout << endl << "������ ������� c ������: " << d.PeekFront() << "; ������ ������� � �����: " << d.PeekBack() << ";  ����� ���������: " << d.GetSize() << endl;

	Deque_int d_i;
	d_i.PushFront(4);
	d_i.PushBack(1);
	d_i.PushFront(11);
	d_i.PushBack(7);
	d_i.PushBack(2);

	Deque_int d1_i(d_i);

	cout << d_i;
	cout << endl << "������ ������� c ������ : " << d_i.PeekFront() << "; ������ ������� � ����� : " << d_i.PeekBack() << ";  ����� ��������� : " << d_i.GetSize() << endl;

	return 0;
}