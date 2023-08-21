#pragma warning(disable:4996)

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>

#define tab "\t"
#define delimeter "\n===================================================\n"
using namespace std;

class List {

    class Element {
        int Data;
        Element* pNext;
        Element* pPrev;
    public:
        Element(int Data, Element* pNext = nullptr,
            Element* pPrev = nullptr) :Data(Data),
            pNext(pNext), pPrev(pPrev) {
            cout << "ECostructor:\t" << this << endl;
        }

        ~Element() {
            cout << "EDestructor:\t" << this << endl;
        }
        friend class List;
    } 

    *Head, * Tail;// -> Element* Head; Element* Tail;
    unsigned int size;
public:
    List() {
        Head = Tail = nullptr;
        cout << "LConstructor:\t" << this << endl;
    }
    List(const std::initializer_list<int>& il) :List() {
        for (int const* it = il.begin(); it != il.end(); ++it) {
            push_Back(*it);
        }
    }
    ~List() {
        /*while (Head) {
            pop_front();
        }*/
        while (Tail) {
            pop_back();
        }
        cout << "LDestructor\t" << this << endl;
    }

    //Add
    void push_Front(int Data) {
        if (Head == nullptr && Tail == nullptr) {
            Head = Tail = new Element(Data);
        }
        else {
            Head = Head->pPrev = new Element(Data, Head);
        }
        size++;
    }

    void push_Back(int Data) {
        if (Head == nullptr && Tail == nullptr) {
            Head = Tail = new Element(Data);
        }
        else {
            Tail = Tail->pNext = new Element(Data,nullptr,Tail);
        }
        size++;
    }

    void insert(int Data, int Index) {
        if (Index == 0) {
            return push_Front(Data);
        }
        if (Index >= size) {
            return push_Back(Data);
            
        }
        Element* Temp;
        if (Index < size / 2) {
            Temp = Head;
            for (int i = 0; i < Index; i++) {
                Temp = Temp->pNext;
            }
        }
        else {
            Temp = Tail;
            for (int i = 0; i < size - Index - 1; i++) {
                Temp = Temp->pPrev;
            }
        }
        Temp->pPrev = Temp->pPrev->pNext = new Element(Data, Temp, Temp->pPrev);
        size++;
    }

    //Remove

    void pop_front() {
        if (Head == nullptr && Tail == nullptr) {
            return;
        }
        if (Head == Tail) {
            delete Head;
            Head = Tail = nullptr;
            return;
        }
        Head = Head->pNext;
        delete Head->pPrev;
        Head->pPrev = nullptr;
        size--;
    }

    void pop_back() {
        if (Head == Tail) {
            return pop_front();
        }
        
        Tail = Tail->pPrev;
        delete Tail->pNext;
        Tail->pNext = nullptr;
        size--;
    }

    void erase(int Index) {

        if (Index == 0) {
            return pop_front();
        }
        if (Index >= size) {
            return;
        }

        Element* Temp;

        if (Index < size / 2) {
            Temp = Head;
            for (int i = 0; i < Index; i++) {
                Temp = Temp->pNext;
            }
        }
        else {
            Temp = Tail;
            for (int i = 0; i < size - Index - 1; i++) {
                Temp = Temp->pPrev;
            }
        }

        Temp->pPrev->pNext = Temp->pNext;
        Temp->pNext->pPrev = Temp->pPrev;

        delete Temp;
    }

    //Print
    void print() const {
        for (Element* Temp = Head; Temp; Temp = Temp->pNext) {
            cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
        }
    }

    void printTail() {
        for (Element* Temp = Tail; Temp!= nullptr; Temp = Temp->pPrev) {
            cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
        }
    }
    

};



int main() {

    setlocale(0, "");
    srand(time(NULL));

#ifdef BASE_CHECK
    List list;
    int n;
    cout << "Введите размер списка: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        list.push_Front(rand() % 100);
    }
    cout << delimeter << endl;
    list.print();
    cout << delimeter << endl;
    list.printTail();

    /*cout << delimeter << endl << "2\n";
    List list2;
    for (int i = 0; i < n; i++) {
        list2.push_Back(rand() % 100);
    }
    cout << delimeter << endl;
    list2.print();
    cout << delimeter << endl;
    list2.printTail();*/
    cout << delimeter << endl;
    int ind;
    int val;
    cout << "Введите индекс:\n";
    cin >> ind;
    cout << "Введите значение:\n";
    cin >> val;
    list.insert(val, ind);
    list.print();
    cout << delimeter << endl;
    list.printTail();
#endif

    List list = { 3,5,8,13,21 };
    cout << delimeter << endl;
    list.print(); cout << delimeter << endl;

    for (int i : list) {
        cout << i << tab;
        cout << endl;
    }

    /*
    Двусвязный список - это двунаправленный контейнер,
    а у любого направленного контейнера есть не только прямой(Iterator),
    но и обратный (ReverseIterator)
    */
}
