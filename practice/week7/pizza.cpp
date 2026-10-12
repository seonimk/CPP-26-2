#include <iostream>
#include <string>
using namespace std;

// 원을 표현하는 클래스 (설계도)
class Circle {
public:
    int radius;     // 반지름 (멤버 변수)
    string color;   // 색상 (멤버 변수)

    // 원의 면적을 계산해서 반환하는 멤버 함수
    double CalcArea() {
        return 3.14 * radius * radius;
    }
};

int main()
{
    // 하나의 Circle 클래스로 두 개의 객체 생성
    Circle pizza1, pizza2;

    // pizza1 객체의 멤버 변수에 값 저장 후 면적 출력
    pizza1.radius = 100;
    pizza1.color = "yellow";
    cout << "피자의 면적 = " << pizza1.CalcArea() << endl;

    // pizza2 객체는 pizza1과 별개이므로 멤버 변수 값이 서로 다름
    pizza2.radius = 200;
    pizza2.color = "white";
    cout << "피자의 면적 = " << pizza2.CalcArea() << endl;

    return 0;
}
