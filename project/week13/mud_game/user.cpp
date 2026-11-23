// Magician, Warrior 클래스 내 함수 (멤버 함수 정의부)
#include "user.h"

// 출력(<<) 연산자 중복 정의 : cout << *user; 로 유저 정보를 출력할 수 있게 함
// User&로 받기 때문에 Magician, Warrior 어느 쪽이 들어와도 출력 가능
std::ostream& operator<<(std::ostream& os, User& user) {
    os << "현재 HP는 " << user.GetHP() << " 이고, 먹은 아이템은 총 " << user.GetItemCnt() << "개 입니다";
    return os;
}

// ---------------- Magician ----------------

// 생성자 : 객체가 만들어질 때 hp를 20, 먹은 아이템을 0개로 설정
Magician::Magician() {
    user_hp = 20;
    itemCnt = 0;
}

// HP를 dec_hp만큼 감소
void Magician::DecreaseHP(int dec_hp) {
    user_hp -= dec_hp;
}

// HP를 inc_hp만큼 증가
void Magician::IncreaseHP(int inc_hp) {
    user_hp += inc_hp;
}

// 현재 HP를 반환
int Magician::GetHP() {
    return user_hp;
}

// 먹은 아이템 개수를 1 증가
void Magician::IncreaseItemCnt() {
    itemCnt += 1;
}

// 먹은 아이템 개수를 반환
int Magician::GetItemCnt() {
    return itemCnt;
}

// Magician의 공격
void Magician::doAttack() {
    std::cout << "마법 사용" << std::endl;
}

// ---------------- Warrior ----------------

// 생성자 : 객체가 만들어질 때 hp를 20, 먹은 아이템을 0개로 설정
Warrior::Warrior() {
    user_hp = 20;
    itemCnt = 0;
}

// HP를 dec_hp만큼 감소
void Warrior::DecreaseHP(int dec_hp) {
    user_hp -= dec_hp;
}

// HP를 inc_hp만큼 증가
void Warrior::IncreaseHP(int inc_hp) {
    user_hp += inc_hp;
}

// 현재 HP를 반환
int Warrior::GetHP() {
    return user_hp;
}

// 먹은 아이템 개수를 1 증가
void Warrior::IncreaseItemCnt() {
    itemCnt += 1;
}

// 먹은 아이템 개수를 반환
int Warrior::GetItemCnt() {
    return itemCnt;
}

// Warrior의 공격
void Warrior::doAttack() {
    std::cout << "베기 사용" << std::endl;
}
