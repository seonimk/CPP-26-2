#include <iostream>
using namespace std;

class Circle
{
public:
    int x, y;
    int radius;
    Circle() {
        x = 0;
        y = 0;
        radius = 0;
    }
    Circle(int x, int y, int r) {
        // 같은 변수 이름일 때, 객체 내 속성과 매개변수를 구분짓기 위해
        this->x =x;
        this->y = y;
        this -> radius = r;
    }
    void Print() {
        cout << "반지름 : " << radius << "@(" << x << ", " << ")" << endl;
    }
};

int main(void) {
    Circle objArray[10];

    // 참조자 안하면 왜 모두 0인지 주석에 작성
    // auto 기능 !!
    for (Circle& c: objArray) {
        c.x = rand() % 500;
        c.y = rand() % 300;
        c.radius = rand() % 100;
    }
    for (Circle c : objArray) {
        c.Print();
    }
    return 0;
}