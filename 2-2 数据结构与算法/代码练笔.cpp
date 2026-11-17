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
