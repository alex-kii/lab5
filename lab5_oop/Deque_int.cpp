#include "Deque_int.h"

Deque_int::Deque_int() { }

Deque_int::Deque_int(const Deque_int& other)
{
	list = other.list;
}

Deque_int::~Deque_int() { }

int Deque_int::GetSize() const { return list.getsize(); }

void Deque_int::PushFront(const int& element)
{
	list.push_front(element);

}

void Deque_int::PushBack(const int& element)
{
	list.push_back(element);

}

int Deque_int::PopFront()
{
	return list.pop_front();
}

int Deque_int::PopBack()
{
	return list.pop_back();
}

int Deque_int::PeekFront() const { return list.sel_el(0); }

int Deque_int::PeekBack() const { return list.sel_el(list.getsize() - 1); }

Deque_int& Deque_int::operator=(const Deque_int& other)
{
	if (this == &other)
	{
		return *this;
	}

	list.clear();

	list = other.list;
}

std::ostream& operator<<(std::ostream& os, const Deque_int& obj)
{
	for (size_t i = 0; i < obj.list.getsize(); i++)
	{
		os << obj.list.sel_el(i) << " ";
	}

	os << std::endl;

	return os;
}