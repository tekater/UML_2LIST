#include "list.h"
#include "list.cpp"

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	int n;
	cout << "Введите размер списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	//list.push_back(123);
	list = list;
	list.print();

	/*int value;
	int index;
	cout << "Введите индекс элемента: "; cin >> index;
	cout << "Введите значение элемента: "; cin >> value;
	list.insert(value, index);
	list.print();

	cout << "Введите индекс элемента: "; cin >> index;
	list.erase(index);
	list.print();*/

	//ForwardList list2 = list;	//Copy constructor
	ForwardList list2;
	list2 = list;		//Copy assignment
	list2.print();
#endif // BASE_CHECK


#ifdef RANGE_BASED_FOR_ARRAY
	int arr[] = { 3, 5, 8, 13, 21 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;

	//https://legacy.cplusplus.com/doc/tutorial/control/#:~:text=equal%20to%2050.-,Range%2Dbased%20for%20loop,-The%20for%2Dloop
	for (int i : arr)
	{
		cout << i << tab;
	}
	cout << endl;
#endif // RANGE_BASED_FOR_ARRAY

#ifdef RANGE_BASED_FOR_LIST
	ForwardList list = { 3, 5, 8, 13, 21 };
	list.print();
	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;
#endif // RANGE_BASED_FOR_LIST

#ifdef MOVE_SEMANTIC_CHECK
	ForwardList<int> list1 = { 3, 5, 8, 13, 21 };
	for (int i : list1)cout << i << tab; cout << endl;

	ForwardList<int> list2 = { 34, 55, 89 };
	for (int i : list2)cout << i << tab; cout << endl;

	cout << delimiter << endl;
	//ForwardList list3 = list1 + list2;	//Move constructor
	ForwardList<int> list3;
	list3 = list1 + list2;
	cout << delimiter << endl;
	for (int i : list3)cout << i << tab; cout << endl;

#endif // MOVE_SEMANTIC_CHECK

}
