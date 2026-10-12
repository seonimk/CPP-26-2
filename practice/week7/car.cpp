#include <iostream>
#include <string>
using namespace std;

// 자동차를 추상화한 클래스 (상태: 속도, 기어, 색상 / 동작: 속도 증가, 속도 감소)
class Car {
public:
    // 멤버 변수 선언
    int speed; // 속도
    int gear; // 기어
    string color; // 색상

    // 멤버 함수 선언
    void SpeedUp() { // 속도 증가 멤버 함수
        speed += 10;
    }

    void SpeedDown() { // 속도 감소 멤버 함수
        speed -= 10;
    }
};

int main ()
{
    Car myCar;      // Car 클래스로 myCar 객체 생성

    // 객체의 멤버 변수에 초기값 저장
    myCar.speed = 100;
    myCar.gear = 3;
    myCar.color = "red";

    cout << "1st speed: " << myCar.speed << endl;   // 100

    myCar.SpeedUp();    // 멤버 함수 호출로 속도 10 증가
    cout << "2nd speed: " << myCar.speed << endl;   // 110

    myCar.SpeedDown();  // 멤버 함수 호출로 속도 10 감소
    cout << "3rd speed: " << myCar.speed << endl;   // 100

    return 0;
}
