#include <iostream>
using namespace std;

class MyVector {
private:
    double x, y;
public:
    MyVector(double xvalue = 0.0, double yvalue = 0.0) : x(xvalue), y(yvalue) {}
    // ostream : 출력 스트림. 출력 장치로 데이터를 보내기 위한 클래스
    // & : os를 복사하는 것이 아닌 참조할 수 있도록 받고 반환 하기 위해 사용
    friend ostream& operator<<(ostream &os, const MyVector &v) { // cout << v 지원을 위해 비멤버함수로 정의
        os << "(" << v.x << ", " << v.y << ")" << endl;
        return os;
    }
};

int main() {
    MyVector v1(1.0, 2.0), v2(3.0, 4.0), v3;
    cout << v1 << v2 << v3;
    return 0;
}