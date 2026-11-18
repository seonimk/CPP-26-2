// User 클래스 내 함수 (멤버 함수 정의부)
#include "user.h"

// 생성자 : 객체가 만들어질 때 hp를 20으로 설정
User::User() {
    user_hp = 20;
    // 아이템 먹는 횟수를 저장하는 변수
    itemCnt = 0;    // 처음에는 먹은 아이템이 없음
}

// HP를 dec_hp만큼 감소
void User::DecreaseHP(int dec_hp) {
    user_hp -= dec_hp;
}

// HP를 inc_hp만큼 증가
void User::IncreaseHP(int inc_hp) {
    user_hp += inc_hp;
}

// 현재 HP를 반환
int User::GetHP() {
    return user_hp;
}

// 먹은 아이템 개수를 1 증가
void User::IncreaseItemCnt() {
    itemCnt += 1;
}

std::ostream& operator<<(std::ostream& os, const User& user) {
    os << "현재 HP는 " << user.user_hp << " 이고, 먹은 아이템은 총 " << user.itemCnt << "개 입니다";
    return os;
}

// User 클래스 확장 : doAttack 함수 만들기 ("공격합니다" 출력)
void User::doAttack() {
    std::cout << "공격합니다" << std::endl;
}

// mud3 확장 : Magician이 재정의한 공격 (부모의 doAttack 대신 이 함수가 실행됨)
void Magician::doAttack() {
    std::cout << "마법 사용" << std::endl;
}

// mud3 확장 : Warrior가 재정의한 공격
void Warrior::doAttack() {
    std::cout << "베기 사용" << std::endl;
}
