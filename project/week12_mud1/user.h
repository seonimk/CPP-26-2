// User 클래스 선언부

class User {
private:
    // 유저의 체력 (클래스 밖에서 직접 바꾸지 못하도록 private)
    int user_hp;

public:
    User();                         // 생성자 : hp를 20으로 설정
    void DecreaseHP(int dec_hp);    // HP를 dec_hp만큼 감소시키는 멤버 함수
    void IncreaseHP(int inc_hp);    // HP를 inc_hp만큼 증가시키는 멤버 함수
    int GetHP();                    // 현재 HP를 반환하는 멤버 함수
};