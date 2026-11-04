#include <iostream>
using namespace std;

class Dog {
private:
    // 동적 메모리 사용
    int *pWeight;
    int *pAge;

public:
    // 생성자와 소멸자
    Dog() {
        pAge = new int(1);
        pWeight = new int(10);
    }
    ~Dog() {
        delete pAge;
        delete pWeight;
    }

    // 멤버 함수
    // 나이와 몸무게를 가져오고 설정하는 함수들
    int GetAge() { return *pAge; }
    void SetAge(int age) { *pAge = age; }
    int GetWeight() { return *pWeight; }
    void SetWeight(int weight) { *pWeight = weight; }

};

int main()
{
    Dog* pDog = new Dog;
    cout << "강아지의 나이 :" << pDog -> GetAge() << endl;

    pDog -> SetAge(5);
    cout << "강아지의 나이 :" << pDog -> GetAge() << endl;

    delete pDog;    // 안하면 소멸자 호출 안됨. 종료 후 OS가 알아서 회수

    return 0;
}