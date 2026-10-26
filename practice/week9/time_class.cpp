#include <iostream>
using namespace std;

class Time {
public:
    int hour;       // 시를 나타낸다. 0 ~ 23가 가능
    int minute;     // 분을 나타낸ㄴ다. 0 ~ 59가 가능
    Time(){}        // 오버로딩
    Time(int h, int m) {
        hour = h;
        minute = m;
    }

    void Print() {
        cout << hour << " : " << minute << endl;
    }
};

int main() {
    // Time a;          // 초기화값이 없어 원래 오류가 발생
    Time a;             // 오버로딩으로 해결 !
    Time b (10, 30);    // OK 하지만 예전의 방법이다.
    Time c {10, 40};    // OK 최신의 방법이다.
    Time d = {10, 50};  // OK 하지만 간결하지 않다.

    a.Print();
    b.Print();
    c.Print();
    d.Print();

    return 0;
}