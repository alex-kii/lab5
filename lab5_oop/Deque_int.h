#pragma once
#include "List.h"

class Deque_int
{
private:

	List<int> list;

public:
	Deque_int();

	Deque_int(const Deque_int& other);

	template<typename T>
	Deque_int(Deque_int&& other);

	~Deque_int();

	int GetSize() const;

	void PushFront(const int& element);

	void PushBack(const int& element);

	int PopFront();

	int PopBack();

	int PeekFront() const;

	int PeekBack() const;

	Deque_int& operator=(const Deque_int& other);
	template<typename T> Deque_int& operator=(Deque_int&& other);

	friend std::ostream& operator<< (std::ostream& os, const Deque_int& obj);
};

template<typename T>
Deque_int::Deque_int(Deque_int&& other)
{
	list = std::move(other.list);
}

template<typename T>
Deque_int& Deque_int::operator=(Deque_int&& other)
{
	if (this == &other)
	{
		return *this;
	}

	list.clear();

	list = std::move(other.list);
}