#pragma once
#include "List.h"

template<typename T>
class Deque
{
private:

	List<T>* list;
	int size;

public:
	Deque();

	Deque(const Deque& other);

	Deque(Deque&& other);

	~Deque();

	int GetSize() const;

	void PushFront(const T& element);

	void PushBack(const T& element);

	T PopFront();

	T PopBack();

	T PeekFront() const;

	T PeekBack() const;

	Deque& operator=(const Deque& other);
	Deque& operator=(Deque&& other);

	template<typename T>
	friend std::ostream& operator<< (std::ostream& os, const Deque<T>& obj);
};

template<typename T>
Deque<T>::Deque()
{
	list = new List<T>();
	size = 0;
}

template<typename T>
Deque<T>::Deque(const Deque& other)
{
	list = new List<T>();
	size = other.size;

	for (int i = 0; i < other.size; i++)
	{
		this->list->push_back(other.list->sel_el(i));
	}
}

template<typename T>
Deque<T>::Deque(Deque&& other)
{
	size = other.size;
	list = other.list;
	other.size = NULL;
	other.list = nullptr;
}

template<typename T>
Deque<T>::~Deque() {
	delete list;
	size = 0;
}

template<typename T>
int Deque<T>::GetSize() const { return size; }

template<typename T>
void Deque<T>::PushFront(const T& element)
{
	list->push_front(element);
	++size;
}

template<typename T>
void Deque<T>::PushBack(const T& element)
{
	list->push_back(element);
	++size;
}

template<typename T>
T Deque<T>::PopFront()
{
	--size;
	return list->pop_front();
}

template<typename T>
T Deque<T>::PopBack()
{
	--size;
	return list->pop_back();
}

template<typename T>
T Deque<T>::PeekFront() const { return list->sel_el(0); }

template<typename T>
T Deque<T>::PeekBack() const { return list->sel_el(size - 1); }

template<typename T>
Deque<T>& Deque<T>::operator=(const Deque<T>& other)
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

template<typename T>
Deque<T>& Deque<T>::operator=(Deque<T>&& other)
{
	if (this == &other)
	{
		return *this;
	}

	list.clear();

	size = other.size;
	list = other.list;
	other.size = NULL;
	other.list = nullptr;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Deque<T>& obj)
{
	for (size_t i = 0; i < obj.size; i++)
	{
		os << obj.list->sel_el(i) << " ";
	}

	os << std::endl;

	return os;
}