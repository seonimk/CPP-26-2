// User 인터페이스 및 Magician, Warrior 클래스 선언부
#include <iostream>

// 1. User를 인터페이스로 변경
//    인터페이스 : 멤버 변수 없이 순수 가상 함수(= 0)로만 이루어진 클래스
//    -> User 객체는 직접 만들 수 없고, 상속받은 자식 클래스가 모든 함수를 반드시 구현해야 함
class User {
public:
    virtual void DecreaseHP(int dec_hp) = 0;    // HP를 dec_hp만큼 감소
    virtual void IncreaseHP(int inc_hp) = 0;    // HP를 inc_hp만큼 증가
    virtual int GetHP() = 0;                    // 현재 HP를 반환
    virtual void IncreaseItemCnt() = 0;         // 먹은 아이템 개수를 1 증가
    virtual int GetItemCnt() = 0;               // 먹은 아이템 개수를 반환 (<< 연산자에서 사용)
    virtual void doAttack() = 0;                // 공격 (직업마다 다르게 구현)

    // 가상 소멸자 : User* 포인터로 delete할 때 자식 클래스의 소멸자까지 제대로 호출되게 함
    virtual ~User() {}
};

// 출력(<<) 연산자 중복 정의
// 인터페이스에는 멤버 변수가 없으므로 friend 대신 GetHP(), GetItemCnt()로 값을 가져와서 출력
std::ostream& operator<<(std::ostream& os, User& user);

// User 인터페이스를 구현하는 Magician 클래스
class Magician : public User {
private:
    int user_hp;    // 유저의 체력 (인터페이스에는 변수가 없으므로 자식 클래스가 직접 가짐)
    int itemCnt;    // 아이템 먹은 횟수

public:
    Magician();                         // 생성자 : hp 20, 아이템 0개로 설정
    void DecreaseHP(int dec_hp);
    void IncreaseHP(int inc_hp);
    int GetHP();
    void IncreaseItemCnt();
    int GetItemCnt();
    void doAttack();                    // "마법 사용" 출력
};

// User 인터페이스를 구현하는 Warrior 클래스
class Warrior : public User {
private:
    int user_hp;    // 유저의 체력
    int itemCnt;    // 아이템 먹은 횟수

public:
    Warrior();                          // 생성자 : hp 20, 아이템 0개로 설정
    void DecreaseHP(int dec_hp);
    void IncreaseHP(int inc_hp);
    int GetHP();
    void IncreaseItemCnt();
    int GetItemCnt();
    void doAttack();                    // "베기 사용" 출력
};
