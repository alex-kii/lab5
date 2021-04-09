#include "Deque_int.h"

Deque_int::Deque_int()
{
	list = new List<int>();
	size = 0;
}

Deque_int::Deque_int(const Deque_int& other)
{
	list = new List<int>();
	size = other.size;

	for (int i = 0; i < other.size; i++)
	{
		this->list->push_back(other.list->sel_el(i));
	}
}

Deque_int::~Deque_int() {
	delete list;
	size = 0;
}

int Deque_int::GetSize() const { return size; }

void Deque_int::PushFront(const int& element)
{
	list->push_front(element);
	++size;
}

void Deque_int::PushBack(const int& element)
{
	list->push_back(element);
	++size;
}

int Deque_int::PopFront()
{
	--size;
	return list->pop_front();
}

int Deque_int::PopBack()
{
	--size;
	return list->pop_back();
}

int Deque_int::PeekFront() const { return list->sel_el(0); }

int Deque_int::PeekBack() const { return list->sel_el(size - 1); }

Deque_int& Deque_int::operator=(const Deque_int& other)
{
	if (this == &other)
	{
		return *this;
	}

	list->clear();

	size = other.size;

	for (int i = 0; i < other.size; i++)
	{
		this->list->push_back(other.list->sel_el(i));
	}
}

std::ostream& operator<<(std::ostream& os, const Deque_int& obj)
{
	for (size_t i = 0; i < obj.size; i++)
	{
		os << obj.list->sel_el(i) << " ";
	}

	os << std::endl;

	return os;
}