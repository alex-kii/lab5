#include "Deque_int.h"

Deque_int::Deque_int()
{
	size = 0;
}

Deque_int::Deque_int(const Deque_int& other)
{
	size = other.size;
	list = other.list;
}

Deque_int::~Deque_int() {}

int Deque_int::GetSize() const { return size; }

void Deque_int::PushFront(const int& element)
{
	list.push_front(element);
	++size;
}

void Deque_int::PushBack(const int& element)
{
	list.push_back(element);
	++size;
}

void Deque_int::PopFront()
{
	list.pop_front();
	--size;
}

void Deque_int::PopBack()
{
	list.pop_back();
	--size;
}

int Deque_int::PeekFront() const { return list.sel_el(0); }

int Deque_int::PeekBack() const { return list.sel_el(size - 1); }

Deque_int& Deque_int::operator=(const Deque_int& other)
{
	if (this == &other)
	{
		return *this;
	}

	list.clear();

	size = other.size;
	list = other.list;
}

std::ostream& operator<<(std::ostream& os, const Deque_int& obj)
{
	for (size_t i = 0; i < obj.size; i++)
	{
		os << obj.list.sel_el(i) << " ";
	}
	return os;
}