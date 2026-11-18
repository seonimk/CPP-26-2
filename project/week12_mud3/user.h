// User 클래스 선언부
#include <iostream>

class User {
private:
    // 유저의 체력 (클래스 밖에서 직접 바꾸지 못하도록 private)
    int user_hp;
    // 확장 숙제 할 일 2-1 : 아이템 먹은 횟수를 저장하는 변수
    int itemCnt;

public:
    User();                         // 생성자 : hp를 20으로 설정
    void DecreaseHP(int dec_hp);    // HP를 dec_hp만큼 감소시키는 멤버 함수
    void IncreaseHP(int inc_hp);    // HP를 inc_hp만큼 증가시키는 멤버 함수
    int GetHP();                    // 현재 HP를 반환하는 멤버 함수
    void IncreaseItemCnt();         // 먹은 아이템 개수를 1 증가시키는 멤버 함수

    // 확장 숙제 할 일 2-2 : 출력(<<) 연산자 중복 정의
    // friend로 선언해서 private인 hp, itemCnt에 직접 접근할 수 있게 함
    friend std::ostream& operator<<(std::ostream& os, const User& user);

    // User 클래스 확장 : doAttack 함수 ("공격합니다" 출력)
    void doAttack();
};

// User 클래스를 상속받는 Magician 클래스
class Magician : public User {
public:
    void doAttack();    // 부모의 doAttack 함수 재정의 ("마법 사용" 출력)
};

// User 클래스를 상속받는 Warrior 클래스
class Warrior : public User {
public:
    void doAttack();    // 부모의 doAttack 함수 재정의 ("베기 사용" 출력)
};
