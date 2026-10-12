#include <iostream>
#include <string>
using namespace std;

class Circle {
public:
    double calcArea();  // 멤버 함수는 선언만 하고, 구현은 클래스 밖에서 함

    int radius;     // 반지름
    string color;   // 색상
};

// 클래스 외부에서 멤버 함수들이 정의된다.
double Circle::calcArea() {
    return 3.14 * radius * radius;
}

int main ()
{
    Circle c;           // Circle 객체 생성
    c.radius = 10;
    cout << c.calcArea() << endl;   // 클래스 밖에서 정의한 멤버 함수 호출 → 314
    return 0;
}
