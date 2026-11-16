// User 클래스 내 함수 (멤버 함수 정의부)
#include "user.h"

// 생성자 : 객체가 만들어질 때 hp를 20으로 설정
User::User() {
    user_hp = 20;
}

// HP를 dec_hp만큼 감소
void User::DecreaseHP(int dec_hp) {
    user_hp -= dec_hp;
}

// HP를 inc_hp만큼 증가
void User::IncreaseHP(int inc_hp) {
    user_hp += inc_hp;
}

// 현재 HP를 반환 (hp가 private이므로 밖에서는 이 함수로만 값을 읽을 수 있음)
int User::GetHP() {
    return user_hp;
}
