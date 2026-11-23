// 머드게임 메인부
#include <iostream>
#include <string>
#include <vector>
#include "user.h"
using namespace std;

// 맵의 가로, 세로 크기
const int mapX = 5;
const int mapY = 5;

// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(const vector<vector<int>>& map, int user_x, int user_y);
bool checkGoal(const vector<vector<int>>& map, int user_x, int user_y);
bool checkOutOfMap(int& user_x, int mapX, int& user_y, int mapY);
void checkState(const vector<vector<int>>& map, int user_x, int user_y, User* user);
bool CheckUser(User* user);

// 메인 함수
int main() {
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	// 확장 숙제 할 일 1 : 2차원 배열 대신 2차원 벡터로 지도 선언
	vector<vector<int>> map = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };


	// 유저의 위치를 저장할 변수
	int user_x = 0; // 가로 번호
	int user_y = 0; // 세로 번호

	// 2. 게임 시작 시 직업(Magician, Warrior) 선택
	string job = "";
	while (1) {	// 올바른 직업 이름을 입력할 때까지 다시 입력받기
		cout << "직업을 선택하세요 (Magician, Warrior) : ";
		cin >> job;
		if (job == "Magician" || job == "Warrior") {
			break;
		}
		cout << "잘못된 입력입니다." << endl;
	}

	// 2. 선택에 따라 상향 형변환(업캐스팅) 후 게임 진행
	//    자식 객체(Magician, Warrior)를 부모 인터페이스 포인터(User*)로 가리킴
	//    -> 이후 user->doAttack()을 호출하면 실제 객체의 타입에 따라 다른 함수가 실행됨
	User* user;
	if (job == "Magician") {
		user = new Magician();
		cout << "Magician으로 게임을 시작합니다." << endl;
	}
	else {
		user = new Warrior();
		cout << "Warrior로 게임을 시작합니다." << endl;
	}

	// 게임 시작
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프

		// 사용자의 입력을 저장할 변수
		string user_input = "";

		// 확장 숙제 할 일 3-1 : hp 출력은 객체의 GetHP 멤버 함수 호출로 진행
		cout << "현재 HP : " << user->GetHP() << " " << "명령어를 입력하세요 (상, 하, 좌, 우, 지도, 정보, 종료) : ";
		cin >> user_input;

		// 이동 명령어 처리
		if (user_input == "상") {
			// 위로 한 칸 올라가기
			user_y -= 1;
			if (!checkOutOfMap(user_x, mapX, user_y, mapY)) {	// 맵 안이면 이동 성공
				cout << "위로 한 칸 올라갑니다." << endl;
				// 확장 당일 2 : 이동하면 객체의 DecreaseHP로 hp 1 감소
				user->DecreaseHP(1);
				displayMap(map, user_x, user_y);
				checkState(map, user_x, user_y, user);
			}
		}
		else if (user_input == "하") {
			// 아래로 한 칸 내려가기
			user_y += 1;
			if (!checkOutOfMap(user_x, mapX, user_y, mapY)) {
				cout << "아래로 한 칸 내려갑니다." << endl;
				// 확장 당일 2 : 이동하면 객체의 DecreaseHP로 hp 1 감소
				user->DecreaseHP(1);
				displayMap(map, user_x, user_y);
				checkState(map, user_x, user_y, user);
			}
		}
		else if (user_input == "좌") {
			// 왼쪽으로 이동하기
			user_x -= 1;
			if (!checkOutOfMap(user_x, mapX, user_y, mapY)) {
				cout << "왼쪽으로 이동합니다." << endl;
				// 확장 당일 2 : 이동하면 객체의 DecreaseHP로 hp 1 감소
				user->DecreaseHP(1);
				displayMap(map, user_x, user_y);
				checkState(map, user_x, user_y, user);
			}
		}
		else if (user_input == "우") {
			// 오른쪽으로 이동하기
			user_x += 1;
			if (!checkOutOfMap(user_x, mapX, user_y, mapY)) {
				cout << "오른쪽으로 이동합니다." << endl;
				// 확장 당일 2 : 이동하면 객체의 DecreaseHP로 hp 1 감소
				user->DecreaseHP(1);
				displayMap(map, user_x, user_y);
				checkState(map, user_x, user_y, user);
			}
		}
		else if (user_input == "지도") {
			// 지도 보여주기 함수 호출 (이동하지 않으므로 HP 변화 없음)
			displayMap(map, user_x, user_y);
		}
		else if (user_input == "정보") {
			// 확장 숙제 할 일 3-2 : 중복 정의한 << 연산자로 현재 유저 정보 출력 (이동하지 않으므로 HP 변화 없음)
			cout << *user << endl;
		}
		else if (user_input == "종료") {
			cout << "종료합니다.";
			break;
		}
		else {
			cout << "잘못된 입력입니다." << endl;
			continue;
		}

		// 확장 당일 6 : CheckUser() 함수를 적절한 위치에서 사용
		// CheckUser()로 유저가 살아있는지 확인, false면 실패 후 종료
		if (CheckUser(user) == false) {
			cout << "HP가 0 이하가 되었습니다. 실패했습니다." << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}

		// 목적지에 도달했는지 체크
		bool finish = checkGoal(map, user_x, user_y);
		if (finish == true) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}
	}
	// new로 만든 유저 객체 메모리 해제
	delete user;
	return 0;
}


// 지도와 사용자 위치 출력하는 함수
void displayMap(const vector<vector<int>>& map, int user_x, int user_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |"; // 양 옆 1칸 공백
			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6칸 공백
					break;
				case 1:
					cout << "아이템|";
					break;
				case 2:
					cout << "  적  |"; // 양 옆 2칸 공백
					break;
				case 3:
					cout << " 포션 |"; // 양 옆 1칸 공백
					break;
				case 4:
					cout << "목적지|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
	bool checkFlag = false;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(const vector<vector<int>>& map, int user_x, int user_y) {
	// 목적지 도착하면
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

// 맵을 벗어났으면 메시지를 출력하고 맵 안으로 되돌리는 함수
bool checkOutOfMap(int& user_x, int mapX, int& user_y, int mapY) {
	bool inMap = checkXY(user_x, mapX, user_y, mapY);
	if (!inMap) {
		cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
		user_x = (user_x < 0) ? 0 : (user_x >= mapX) ? mapX - 1 : user_x;
		user_y = (user_y < 0) ? 0 : (user_y >= mapY) ? mapY - 1 : user_y;
	}
	return !inMap;
}

// 유저가 이동한 칸에 무엇이 있는지 확인해서 메시지를 출력하고 HP를 바꾸는 함수
void checkState(const vector<vector<int>>& map, int user_x, int user_y, User* user) {
	switch (map[user_y][user_x]) {
	case 1:     // 확장 숙제 할 일 3-3 : 아이템: 먹은 아이템 개수 1 증가
		user->IncreaseItemCnt();
		cout << "아이템이 있습니다. 아이템을 먹었습니다." << endl;
		break;
	case 2:     // 적: HP 2 감소
		user->DecreaseHP(2);
		cout << "적이 있습니다. HP가 2 줄어듭니다." << endl;
		// 적을 만나면 공격 : 가상 함수라서 실제 객체에 따라 "마법 사용" 또는 "베기 사용" 출력
		user->doAttack();
		break;
	case 3:     // 확장 당일 4 : 포션: 객체의 IncreaseHP로 HP 2 증가
		user->IncreaseHP(2);
		cout << "포션이 있습니다. HP가 2 회복됩니다." << endl;
		break;
	}
}

// 확장 당일 5 : bool CheckUser(User user) 함수 생성
// 	            User 객체를 넣으면 hp가 0인지 체크하고, 0이라면 false를 반환, 그렇지 않다면 true를 반환
// 1. 인터페이스(User)는 객체로 만들 수 없어서 값으로 받을 수 없으므로 User* 포인터로 받도록 수정
bool CheckUser(User* user) {
	if (user->GetHP() <= 0) {
		return false;
	}
	return true;
}
