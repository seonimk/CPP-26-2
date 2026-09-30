#include <iostream>
using namespace std;

int main() {
    int a = 100, b = 200;

    cout << "a = " << a << " b = " << b << endl;

    int tmp;    // 임시 저장소
    tmp = a;
    a = b;
    b = tmp;

    cout << "a = " << a << " b = " << b << endl;
    return 0;
}