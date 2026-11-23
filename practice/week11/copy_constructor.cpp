#include <iostream>
using namespace std;

class MyArray {
public:
    int size;
    int* data;
    MyArray(int size);
    MyArray(const MyArray& other);
    ~MyArray();
};

// 생성자 : size만큼 배열을 동적 할당
MyArray::MyArray(int size) {
    this->size = size;
    data = new int[size];
}

MyArray::MyArray(const MyArray& other) {
    this->size = other.size;
    data = new int[size];
    for (int i = 0; i < size; i++) {
        this->data[i] = other.data[i];
    }
    cout << "복사 생성자 호출 ! " << endl;
}

MyArray::~MyArray() {
    if(data != nullptr) {
        delete[] this -> data;
    }
    data = nullptr;
}

int main() {
    MyArray buffer(10);
    buffer.data[0] = 1;
    {
        MyArray clone = buffer; // buffer가 clone에 복사됨
    }   // 블록이 끝나면서 clone이 사용했던 data만 사라짐
    
     return 0;
}

