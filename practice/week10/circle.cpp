#include <iostream>
using namespace std;

class Circle {
private:
    int radius;

public:
    // 생성자와 소멸자
    Circle() { radius = 10; }
    ~Circle() {}

    // 멤버 함수
    // 반지름을 가져오고 설정하는 함수들
    void SetRadius(int radius) { this -> radius = radius; }
    int GetRadius() const { return radius; }
};

int main()
{
    Circle* p = new Circle();
    const Circle *pConstObj = new Circle();
    Circle *const pConstPtr = new Circle();

    cout << "pRect -> radius : " << p->GetRadius() << endl;
    cout << "pConstObj -> radius: " << pConstObj->GetRadius() << endl;
    cout << "pConstPtr -> radius: " << pConstPtr->GetRadius() << endl << endl;

    p -> SetRadius(30);
    //  pConstObj -> SetRadius(30); -> const 객체이므로 SetRadius() 호출 불가
    pConstPtr -> SetRadius(30);

    cout << "pRect -> radius: " << p->GetRadius() << endl;
    cout << "pConstObj -> radius: " << pConstObj->GetRadius() << endl;
    cout << "pConstPtr -> radius: " << pConstPtr->GetRadius() << endl;

    return 0;
}