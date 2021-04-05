#pragma once
#include "List.h"

template<typename T>
class Deque
{
private:

	List<T> list;
	int size;

public:
	Deque(); // конструктор по умолчанию

	Deque(const Deque& other); // конструктор копирования

	Deque(Deque&& other); // конструктор перемещения

	~Deque(); // деструктор

	int GetSize() const;

	void PushFront(const T& element);

	void PushBack(const T& element);

	void PopFront();

	void PopBack();

	T PeekFront() const;

	T PeekBack() const;

	Deque& operator=(const Deque& other);
	Deque& operator=(Deque&& other);

	template<typename T>
	friend std::ostream& operator<< (std::ostream& os, const Deque<T>& obj); // перегрузка вывода
};

template<typename T>
Deque<T>::Deque()
{
	size = 0;
}

template<typename T>
Deque<T>::Deque(const Deque& other)
{
	size = other.size;
	list = other.list;
}

template<typename T>
Deque<T>::Deque(Deque&& other)
{
	size = other.size;
	list = other.list;
	other.size = NULL;
	other.list.size = NULL;
	other.list = nullptr;
}

template<typename T>
Deque<T>::~Deque() {}

template<typename T>
int Deque<T>::GetSize() const { return size; }

template<typename T>
void Deque<T>::PushFront(const T& element)
{
	list.push_front(element);
	++size;
}

template<typename T>
void Deque<T>::PushBack(const T& element)
{
	list.push_back(element);
	++size;
}

template<typename T>
void Deque<T>::PopFront()
{
	list.pop_front();
	--size;
}

template<typename T>
void Deque<T>::PopBack()
{
	list.pop_back();
	--size;
}

template<typename T>
T Deque<T>::PeekFront() const { return list.sel_el(0); }

template<typename T>
T Deque<T>::PeekBack() const { return list.sel_el(size - 1); }

template<typename T>
Deque<T>& Deque<T>::operator=(const Deque<T>& other)
{
	if (this == &other)
	{
		return *this;
	}

	list.clear();

	size = other.size;
	list = other.list;
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
	other.list.size = NULL;
	other.list = nullptr;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Deque<T>& obj)
{
	for (size_t i = 0; i < obj.size; i++)
	{
		os << obj.list.sel_el(i) << " ";
	}
	return os;
}