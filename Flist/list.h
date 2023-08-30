#pragma once
//ForwardList
#include<iostream>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n--------------------------------------------\n"

template<typename T>
class ForwardList;

template<typename T>
typename ForwardList<T>::ForwardList ForwardList<T>::operator+(const ForwardList<T>& left, const ForwardList<T>& right);

class Element
{
	int Data;		//значение элемента
	Element* pNext;	//адрес следующего элемента
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		cout << "EDestructor:\t" << this << endl;
	}

	friend class ForwardList;
	friend class Iterator;
	friend ForwardList operator+(const ForwardList& left, const ForwardList& right);
};
class Iterator
{
	Element* Temp;
public:
	Iterator(Element* Temp = nullptr) :Temp(Temp)
	{
		cout << "ItConstructor:\t" << this << endl;
	}
	~Iterator()
	{
		cout << "ItDestructor:\t" << this << endl;
	}

	Iterator& operator++()
	{
		Temp = Temp->pNext;
		return *this;
	}

	bool operator==(const Iterator& other)const
	{
		return this->Temp == other.Temp;
	}
	bool operator!=(const Iterator& other)const
	{
		return this->Temp != other.Temp;
	}

	int operator*()
	{
		return Temp->Data;
	}
};

template<typename T>
class ForwardList
{
	Element* Head;
public:

	Iterator begin();
	Iterator end();

	ForwardList();
	ForwardList(const std::initializer_list<int>& il);
	ForwardList(const ForwardList& other);
	ForwardList(ForwardList&& other);
	~ForwardList();

	//					Operators:
	ForwardList& operator=(const ForwardList& other);
	ForwardList& operator=(ForwardList&& other);

	//					Adding elements:
	void push_front(T Data);
	void push_back(T Data);
	void insert(T Data, int Index);

	//					Delete elements:
	void pop_front();
	void pop_back();
	void erase(int Index);

	//					Methods:
	void print()const;

	friend ForwardList operator+(const ForwardList& left, const ForwardList& right);
};
