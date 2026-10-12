#include <iostream>
using namespace std;

// 원을 표현하는 클래스
class Circle {
public:
    int radius;     // 반지름
    string color;   // 색상

    // 원의 면적을 계산해서 반환하는 멤버 함수
    double CalcArea() {
        return 3.14 * radius * radius;
    }
};

int main()
{
    Circle obj;     // Circle 클래스로 obj 객체 생성

    // 점 연산자로 객체의 멤버 변수에 접근해서 값 저장
    obj.radius = 100;
    obj.color = "blue";

    // 멤버 함수를 호출해서 면적 출력
    cout << "원의 면적 = " << obj.CalcArea() << endl;
    return 0;
}