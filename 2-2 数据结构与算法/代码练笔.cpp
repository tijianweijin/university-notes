#include <stdexcept>

/*

代码练笔

本文为了练习数据结构与算法编写代码，可作示例使用。

使用C++语言标准版本：本项目使用C++语言标准版本。

*/

// 顺序表
// 建立

template <class T, int N>
class SeqList {
public:
    SeqList();
    SeqList(T a[], int n);
    int GetLength();
    T Get(int i);
    int Locate(T x);
    void Insert(int i, T x);
    T Delete(int i);
    void PrintList();
private:
    T data[N];
    int length;
};

template <class T, int N>
SeqList<T, N>::SeqList(): data{}, length(0) {
}

template <class T, int N>
SeqList<T, N>::SeqList(T a[], int n): length(n) {
    if (n < 0 || n > N) {
        throw std::out_of_range("Invalid length");
    }
    
    for (int i = 0; i < n; i++) {
        data[i] = a[i];
    }
}

template <class T, int N>
int SeqList<T, N>::GetLength() {
    return length;
}

template <class T, int N>
T SeqList<T, N>::Get(int i) {
    if (i < 0 ||  i> length) throw std::out_of_range("Index out of range");
    return data[i];
}

template <class T, int N>
int SeqList<T, N>::Locate(T x) {
    if (length == 0) throw std::out_of_range("List is empty");
    for (int i = 0; i < length; i++) {
        if (data[i] == x) return i;
    }
    throw std::out_of_range("Element not found");
}

template <class T, int N>
void SeqList<T, N>::Insert(int i, T x) {
    for (int j = length; j > i; j--) {
        data[j] = data[j - 1];
    }
    data[i] = x;
    length++;
}

// 节点

template <class T>
struct Node {
    T data;
    Node<T>* next;
};

// 初始化节点

Node<T> *p = new Node<T>;
p->data = x;
p->next = nullptr;
delete p;

// 单链表
template <class T>
class LinkList {
public:
    LinkList();
    ~LinkList();
    void Insert(T x, int i);
    int GetLength();
    T Get(int i);
    int Locate(T x);
    T Delete(int i);
private:
    Node<T>* first;
    int length;
};

// 不带头节点的单链表初始化
template <class T>
LinkList<T>::LinkList():first(nullptr), length(0) {
}

// 带头节点的单链表初始化
template<class T>
LinkList<T>::LinkList(): first(new Node<T>), length(0) {
    first->next = nullptr;
}

template <class T>
LinkList<T>::LinkList() {
    first = new Node<T>;
    first->next = nullptr;
}

// 头插法

Node<T> *p = new Node<T>;
p->data = x;
p->next = first->next;
first->next = p;

// 尾插法

Node<T> *r = first;

for (int i = 0; i < n; ++i) {
    Node<T> *p = new Node<T>;
    p->data = a[i];
    p->next = nullptr;
    r->next = p;
    r = p;
}

// 若从1到n插入，则头插法建立倒序链表，而尾插法建立顺序链表。

// 析构函数

template <class T>
LinkList<T>::~LinkList() {
    while (first != nullptr) {
        Node<T>* p = first;
        first = first->next;
        delete p;
    }
}

// 按位查找
template <class T>
T LinkList<T>::Get(int i) {
    if (i < 0 || i >= length) throw std::out_of_range("Index out of range");
    for (Node<T>* p = first->next; p != nullptr; p = p->next) {
        if (i == 0) return p->data;
        i--;
    }
    throw std::out_of_range("Index out of range");
}

// 按值查找
template <class T>
int LinkList<T>::Locate(T x) {
    int i = 0;
    for (Node<T>* p = first->next; p != nullptr; p = p->next) {
        if (p->data == x) return i;
        i++;
    }
    return -1;
}

// 删除节点

template <class T>
T LinkList<T>::Delete(int i) {
    if (i < 0 || i >= length) throw std::out_of_range("Index out of range");
    Node<T>* p = first;
    for (int j = 0; j < i; j++) {
        p = p->next;
    }
    Node<T>* q = p->next;
    T data = q->data;
    p->next = q->next;
    delete q;
    length--;
    return data;
}

// 小技巧：遍历有效数据节点时，若不带头节点应从first开始，若带头节点应从first->next开始。

// 循环链表

// 若不带头节点，则p->next=first；若带头节点，则p->next=first->next。

// 双链表
// 节点
template <class T>
struct DulNode {
    T data;
    DulNode<T>* prior, next;
};

// 在节点p前插入

template <class T>
void InsertBefore(DulNode<T>* p, T x) {
    DulNode<T>* s = new DulNode<T>;
    s->data = x;
    s->next = p;
    s->prior = p->prior;
    s->prior->next = s;
    p->prior = s;
}

// 后插

template <class T>
void InsertAfter(DulNode<T>* p, T x) {
    DulNode<T>* s = new DulNode<T>;
    s->data = x;
    s->next = p->next;
    s->prior = p;
    s->next->prior = s;
    p->next = s;
}

// 删除节点p
template <class T>
T DeleteNode(DulNode<T>* p) {
    T data = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    delete p;
    return data;
}