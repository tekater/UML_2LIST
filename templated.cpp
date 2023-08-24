#pragma warning(disable:4996) 

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>

using namespace std;

//List 1
template<typename T>
struct Node {
    T val;
    Node* next;
};

template<typename T>
class List {
    Node<T>* head;
    Node<T>* tail;
public:
    List() {

        head = tail = nullptr;
    }

    void Push(int x) {
        Node<T>* temp = new Node<T>;

        temp->val = x;
        temp->next = nullptr;

        if (head == nullptr) {
            head = temp;
        }
        else {
            tail->next = temp;
        }
        tail = temp;
    }

    void Pop() {
        if (head != nullptr) {
            Node<T>* copyhead = head;
            head = head->next;
            delete copyhead;
        }
    }

    void Clear() {
        while (head != nullptr) {
            Pop();
        }
        tail = nullptr;
    }

    void print() {
        cout << "\nPrint\n";
        Node<T>* copyhead = head;
        while (copyhead != nullptr) {
            cout << copyhead->val << " ";
            copyhead = copyhead->next;
        }
        cout << endl;
    }

    int getElem(int n) {
        int ind = 0;
        Node<T>* copyhead = head;
        while (copyhead != nullptr) {
            if (ind != n) {
                ind++;
                copyhead = copyhead->next;
            }
            else {
                return copyhead->val;
            }
        }
        return -1;
    }

    void setElem(int n, int x) {
        int ind = 0;
        Node<T>* copyhead = head;
        while (copyhead != nullptr) {
            if (ind != n) {
                ind++;
                copyhead = copyhead->next;
            }
            else {
                copyhead->val = x;
            }
        }
    }

    ~List() {
        Clear();
    }

    int operator[](int n) const {
        int ind = 0;
        Node<T>* copyhead = head;
        while (copyhead != nullptr) {
            if (ind != n) {
                ind++;
                copyhead = copyhead->next;
            }
            else {
                return copyhead->val;
            }
        }
        return -1;
    }

    int& operator[](int n) {
        int ind = 0;
        Node<T>* copyhead = head;
        while (copyhead != nullptr) {
            if (ind != n) {
                ind++;
                copyhead = copyhead->next;
            }
            else {
                return copyhead->val;
            }
        }
        int a = -1;
        return a;
    }

};
//List 2

template<typename T2>
struct Node2 {
    T2 val;
    Node2* next;
    Node2* back;
};

template<typename T2>
class List2 {
    Node2<T2>* head;
    Node2<T2>* tail;
public:
    List2() {

        head = tail = nullptr;
    }

    void PushTail(int x) {
        Node2<T2>* temp = new Node2<T2>;

        temp->val = x;
        temp->next = nullptr;
        temp->back = tail;

        if (head == nullptr) {
            head = temp;
        }
        else {
            tail->next = temp;
        }

        tail = temp;
    }

    void PushHead(int x) {
        Node2<T2>* temp = new Node2<T2>;

        temp->val = x;
        temp->next = head;
        temp->back = nullptr;

        if (tail == nullptr) {
            tail = temp;
        }
        else {
            head->back = temp;
        }

        head = temp;
    }

    void PopHead() {
        if (head != nullptr) {
            Node2<T2>* copyhead = head;
            head = head->next;
            delete copyhead;
            if (head != nullptr) {
                head->back = nullptr;
            }
            else {
                tail = nullptr;
            }
        }
    }

    void PopTail() {
        if (tail != nullptr) {
            Node2<T2>* copytail = tail;
            tail = tail->back;
            delete copytail;
            if (tail != nullptr) {
                tail->next = nullptr;
            }
            else {
                head = nullptr;
            }
        }
    }

    void Clear() {
        while (head != nullptr) {
            PopHead();
        }
        tail = nullptr;
    }

    void printHead() {
        cout << "\nPrintHead\n";
        Node2<T2>* copyhead = head; 
        while (copyhead != nullptr) {
            cout << copyhead->val << " ";
            copyhead = copyhead->next;
        }
        cout << endl;
    }

    void printTail() {
        cout << "\nPrintTail\n";
        Node2<T2>* copytail = tail;
        while (copytail != nullptr) {
            cout << copytail->val << " ";
            copytail = copytail->back;
        }
        cout << endl;
    }

    int getElem(int n) {
        int ind = 0;
        Node2<T2>* copyhead = head;
        while (copyhead != nullptr) {
            if (ind != n) {
                ind++;
                copyhead = copyhead->next;
            }
            else {
                return copyhead->val;
            }
        }
        return -1;
    }

    void setElem(int n, int x) {
        int ind = 0;
        Node2<T2>* copyhead = head;
        while (copyhead != nullptr) {
            if (ind != n) {
                ind++;
                copyhead = copyhead->next;
            }
            else {
                copyhead->val = x;
            }
        }
    }

    void Del(int pos) {
        if (pos == 0) {
            PopHead();
            return;
        }

        Node2<T2>* copyhead = head;

        for (int i = 0; i < pos; i++) {
            copyhead = copyhead->next;
        }

        Node2<T2>* Next = copyhead->next;
        Node2<T2>* Back = copyhead->back;

        Back->next = Next;

        if (Next != nullptr) {
            Next->back = Back;
        }
        else {
            tail = Back;
        }

        delete copyhead;
    }


    ~List2() {
        Clear();
    }

    int operator[](int n) const {
        int ind = 0;
        Node2<T2>* copyhead = head;
        while (copyhead != nullptr) {
            if (ind != n) {
                ind++;
                copyhead = copyhead->next;
            }
            else {
                return copyhead->val;
            }
        }
        return -1;
    }

    int& operator[](int n) {
        int ind = 0;
        Node2<T2>* copyhead = head;
        while (copyhead != nullptr) {
            if (ind != n) {
                ind++;
                copyhead = copyhead->next;
            }
            else {
                return copyhead->val;
            }
        }
        int a = -1;
        return a;
    }



};



int main() {

    setlocale(0, "");
    srand(time(NULL));

    

    List<int> l1;

    for (int i = 0; i < 5; i++) {
        l1.Push(rand() % 20);
    }

    l1.print();

    l1.Pop(); l1.print();
    l1.Pop(); l1.print();

    l1.Clear(); l1.print();

    for (int i = 0; i < 20; i++) {
        l1.Push(rand() % 20);
    }
    l1.print();
    cout << "(10) - " << l1.getElem(10) << endl;
    l1[2] = 5;
    l1.print();




    cout << "\n\n\n\nList 2\n\n\n\n";




    List2<int> l2;

    for (int i = 0; i < 5; i++) {
        l2.PushHead(rand() % 20);
    }
    l2.printHead();
    l2.printTail(); cout << endl;

    l2.PopTail(); l2.printHead(); l2.printTail(); cout << endl;
    //l2.PopHead(); l2.printHead();

    l2.Clear(); l2.printHead();

    for (int i = 0; i < 20; i++) {
        l2.PushTail(rand() % 20);
    }
    l2.printHead();
    cout << "(10) - " << l2.getElem(10) << endl;
    l2[2] = 5;
    l2.printHead();
    l2.Del(2);
    l2.printHead();
}
