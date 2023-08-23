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
    class ConstBaseIterator {
    protected:
        Element* Temp;
    public:
        ConstBaseIterator(Element* Temp) : Temp(Temp) {
            cout << "BItConstructor:\t" << this << endl;
        }
        ~ConstBaseIterator() {
            cout << "BItDestructor:\t" << this << endl;
        }

        bool operator==(const ConstBaseIterator& other)const {
            return this->Temp == other.Temp;
        }
        bool operator!=(const ConstBaseIterator& other)const {
            return this->Temp != other.Temp;
        }

        const int& operator*()const {
            return Temp->Data;
        }
    };
public:
    class ConstIterator:public ConstBaseIterator {

    public:
        ConstIterator(Element* Temp = nullptr) : ConstBaseIterator(Temp) {
            cout << "ItConstructor:\t" << this << endl;
        }
        ~ConstIterator(){
            cout << "ItDestructor:\t" << this << endl;
        }

        ConstIterator& operator++() {
            Temp = Temp->pNext;
            return *this;
        }
        ConstIterator operator++(int) {
            ConstIterator old = *this;
            Temp = Temp->pNext;
            return old;
        }

        ConstIterator& operator--() {
            Temp = Temp->pPrev;
            return *this;
        }
        ConstIterator operator--(int) {
            ConstIterator old = *this;
            Temp = Temp->pPrev;
            return old;
        }

    };
    const ConstIterator cbegin()const {
        return Head;
    }
    const ConstIterator cend()const {
        return nullptr;
    }
    class Iterator :public ConstIterator {
    public:
        Iterator(Element* Temp = nullptr) :ConstIterator(Temp) {}
        int& operator*() {
            return Temp->Data;
        }
    };


    class ConstReverseIterator:public ConstBaseIterator {
    public:
        ConstReverseIterator(Element* Temp = nullptr) : ConstBaseIterator(Temp) {
            cout << "RItConstructor:\t" << this << endl;
        }
        ~ConstReverseIterator(){
            cout << "RItDestructor:\t" << this << endl;
        }
        ConstReverseIterator& operator++() {
            Temp = Temp->pPrev;
            return *this;
        }
        ConstReverseIterator operator++(int) {
            ConstReverseIterator old = *this;
            Temp = Temp->pPrev;
            return old;
        }

        ConstReverseIterator& operator--() {
            Temp = Temp->pNext;
            return *this;
        }
        ConstReverseIterator operator--(int) {
            ConstReverseIterator old = *this;
            Temp = Temp->pNext;
            return old;
        }

    }; 
    
    
    ConstReverseIterator crbegin() {
        return Tail;
    }
    ConstReverseIterator crend() {
        return nullptr;
    }

    
    class ReverseIterator :public ConstReverseIterator {
    public:
        ReverseIterator(Element* Temp = nullptr) :ConstReverseIterator(Temp) {
        }

        int& operator*() {
            return Temp->Data;
        }
    };
    Iterator begin() {
        return Head;
    }
    Iterator end() {
        return nullptr;
    }

    ReverseIterator rbegin() {
        return Tail;
    }
    ReverseIterator rend() {
        return nullptr;
    }

    List() {
        Head = Tail = nullptr;
        cout << "LConstructor:\t" << this << endl;
    }
    List(const std::initializer_list<int>& il) :List() {
        for (int const* it = il.begin(); it != il.end(); ++it) {
            push_Back(*it);
        }
    }
    List(const List& other):List() {
        *this = other;
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
    // Operators:
    
    List& operator=(const List& other) {
        if (this == &other) {
            return *this;
        }
        while (Head) {
            pop_front();
        }
        for (Element* Temp = other.Head; Temp; Temp = Temp->pNext) {
            push_Back(Temp->Data);
        }
        cout << "LCopyAssignment:\t" << this << endl;
        return *this;
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

List operator+(const List& left, List& right) {
    List cat = left;
    for (List::ConstIterator it = right.begin(); it != right.end(); ++it) {
        cat.push_Back(*it);
    }
    return cat;
}

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
    List list = { 1,2,3,5,6 };
    List list1 = { 3,5,8,13,21 };

    cout << delimeter << endl;
    list.print(); cout << delimeter << endl;

    /*for (int i : list) {
        cout << i << tab;
        cout << endl;
    }*/
    cout << endl;
    /*for (List::ConstReverseIterator it = list.rbegin(); it != list.rend(); ++it) {
        cout << *it << tab << endl;
    }*/

    List list2 = { 30,50,80,130,210 };
    for (int i : list) {
        cout << i << tab;
        cout << endl;
    }
    list2.print(); cout << delimeter << endl;

    List list3 = list1 + list2;
    list3.print(); cout << delimeter << endl;


    for (List::Iterator it = list1.begin(); it != list1.end(); ++it) {
        (*it) *= 10;
    }
    list1.print();

    /*
    Двусвязный список - это двунаправленный контейнер,
    а у любого направленного контейнера есть не только прямой(Iterator),
    но и обратный (ReverseIterator)
    */

}
