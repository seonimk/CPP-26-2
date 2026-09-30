#include <iostream>
using namespace std;

// 피호출자
// 디폴트 매개변수 : value2 = 0 처럼 미리 기본값을 가지고 있음
int Sum(int value1, int value2 = 0) {
    int result = value1 + value2;
    return result;      // 반환값
}

// 호출자
int main() {
    int a = 2, b = 3;
    // 매개변수로 a, b 보냄
    int value = Sum(a, b);
    cout << value << endl;

    // 매개변수 a만 보냄
    value = Sum(a);
    cout << value << endl;

    return 0;
}