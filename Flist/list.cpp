#include "list.h"


template<typename T>
typename ForwardList<T>::Iterator begin()
{
	return Head;
}

template<typename T>
typename ForwardList<T>::Iterator end()
{
	return nullptr;
}

template<typename T>
ForwardList<T>::ForwardList()
{
	Head = nullptr;	//Если список пуст, то его голова указывает на 0
	cout << "LConstructor:\t" << this << endl;
}

template<typename T>
ForwardList<T>::ForwardList(const std::initializer_list<T>& il) :ForwardList()
{
	cout << typeid(il.begin()).name() << endl;
	cout << typeid(T*).name() << endl;
	cout << typeid(const T*).name() << endl;

	for (T const* it = il.begin(); it != il.end(); it++)
	{
		push_back(*it);
	}
}
template<typename T>
ForwardList<T>::ForwardList(const ForwardList& other) :ForwardList()
{
	cout << "LCopyConstructor:\t" << this << endl;
	*this = other;
}

template<typename T>
ForwardList<T>::ForwardList(ForwardList&& other) :ForwardList() {
	*this = std::move(other);
}

template<typename T>
ForwardList<T>::~ForwardList()
{
	while (Head)pop_front();
	cout << "LDestructor:\t" << this << endl;
}


template<typename T>
typename ForwardList<T>::ForwardList ForwardList<T>::operator+(const ForwardList<T>& left, const ForwardLis<T>t& right)
{
	ForwardList cat = left;
	for (Element* Temp = right.Head; Temp; Temp = Temp->pNext)cat.push_back(Temp->Data);
	return cat;
}


//					Operators:
template<typename T>
typename ForwardList<T>::ForwardList& ForwardList<T>::operator=(const ForwardList<T>& other)
{
	if (this == &other)return *this;
	while (Head)pop_front();
	cout << "LCopyAssignment:\t" << this << endl;
	//Deep copy:
	for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
		push_back(Temp->Data);
	return *this;
}


template<typename T>
typename ForwardList<T>::ForwardList& ForwardList<T>::operator=(ForwardList<T>&& other)
{
	while (Head)pop_front();
	this->Head = other.Head;
	other.Head = nullptr;
	cout << "LMoveAssignment:\t" << this << endl;
	return *this;
}

//					Adding elements:
template<typename T>
void ForwardList<T>::push_front(T Data)
{
	Head = new Element(Data, Head);
}

template<typename T>
void ForwardList<T>::push_back(T Data)
{
	if (Head == nullptr)return push_front(Data);
	Element* Temp = Head;
	while (Temp->pNext)
		Temp = Temp->pNext;
	Temp->pNext = new Element(Data);
}

template<typename T>
void ForwardList<T>::insert(T Data, int Index)
{
	if (Index == 0) return push_front(Data);
	Element* Temp = Head;
	for (int i = 0; i < Index - 1; i++)
		if (Temp->pNext)
			Temp = Temp->pNext;
	//1) Создаем новый элемент:
	Element* New = new Element(Data);
	//2) 
	New->pNext = Temp->pNext;
	//3)
	Temp->pNext = New;
}

//					Delete elements:
template<typename T>
void ForwardList<T>::pop_front()
{
	Element* erased = Head;
	Head = Head->pNext;
	delete erased;
}
template<typename T>
void ForwardList<T>::pop_back()
{
	Element* Temp = Head;
	while (Temp->pNext->pNext)Temp = Temp->pNext;
	delete Temp->pNext;
	Temp->pNext = 0;
}
template<typename T>
void ForwardList<T>::erase(int Index)
{
	if (Index == 0)return pop_front();
	Element* Temp = Head;
	for (int i = 0; i < Index - 1; i++)
		if (Temp->pNext)
			Temp = Temp->pNext;
	Element* erased = Temp->pNext;
	Temp->pNext = Temp->pNext->pNext;
	delete erased;
}

//					Methods:
template<typename T>
void ForwardList<T>::print()const
{
	cout << "Head: " << Head << endl;
	for (Element* Temp = Head; Temp; Temp = Temp->pNext)
		cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;

}





#define MOVE_SEMANTIC_CHECK

