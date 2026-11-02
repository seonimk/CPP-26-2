#include <iostream>
#include <string>
using namespace std;

const int mapX = 5;
const int mapY = 5;

// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
bool checkOutOfMap(int user_x, int mapX, int user_y, int mapY);
void decreaseHP(int& currentHP);

// 메인  함수
int main() {
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };


	// 유저의 위치를 저장할 변수
	int user_x = 0; // 가로 번호
	int user_y = 0; // 세로 번호

	// 유저의 현재 HP
	int currentHP = 20;

	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프

		// 사용자의 입력을 저장할 변수
		string user_input = "";

		cout << "현재 HP : " << currentHP << " " << "명령어를 입력하세요 (상, 하, 좌, 우, 지도, 종료) : ";
		cin >> user_input;

		// 이동 명령어 처리
		if (user_input == "상") {
			// 위로 한 칸 올라가기
			user_y -= 1;
			checkOutOfMap(user_x, mapX, user_y, mapY);
			if (!checkOutOfMap(user_x, mapX, user_y, mapY)) {
				cout << "위로 한 칸 올라갑니다." << endl;
				decreaseHP(currentHP);
				displayMap(map, user_x, user_y);
			}
			
		}
		else if (user_input == "하") {
			// TODO: 아래로 한 칸 내려가기
			user_y += 1;
			checkOutOfMap(user_x, mapX, user_y, mapY);
			if (!checkOutOfMap(user_x, mapX, user_y, mapY)) {
				cout << "위로 한 칸 내려갑니다." << endl;
				decreaseHP(currentHP);
				displayMap(map, user_x, user_y);
		}
		else if (user_input == "좌") {
			// TODO: 왼쪽으로 이동하기
			user_x -= 1;
			checkOutOfMap(user_x, mapX, user_y, mapY);

			if (!checkOutOfMap(user_x, mapX, user_y, mapY)) {
				cout << "왼쪽으로 이동합니다." << endl;
				decreaseHP(currentHP);
				displayMap(map, user_x, user_y);
			}
		}
		else if (user_input == "우") {
			// TODO: 오른쪽으로 이동하기
			user_x += 1;
			checkOutOfMap(user_x, mapX, user_y, mapY);

			if (!checkOutOfMap(user_x, mapX, user_y, mapY)) {
				cout << "오른쪽으로 이동합니다." << endl;
				decreaseHP(currentHP);
				displayMap(map, user_x, user_y);
			}
		}
		else if (user_input == "지도") {
			// TODO: 지도 보여주기 함수 호출
			displayMap(map, user_x, user_y);
		}
		else if (user_input == "종료") {
			cout << "종료합니다.";
			break;
		}
		else {
			cout << "잘못된 입력입니다." << endl;
			continue;
		}

		// 목적지에 도달했는지 체크
		bool finish = checkGoal(map, user_x, user_y);
		if (finish == true) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}

		// 현재 위치에 아이템, 적, 포션이 있는지 체크
		int posState = map[user_y][user_x];
		if (posState == 1 || posState == 2 || posState == 3) {
			switch (posState) {
				case 1:
					cout << "아이템이 있습니다." << endl;
					break;
				case 2:
					cout << "적이 있습니다. HP가 2 줄어듭니다." << endl;
					currentHP -= 2; // 적을 만나면 체력 2 감소
					break;
				case 3:
					cout << "포션이 있습니다. HP가 2 회복됩니다." << endl;
					currentHP += 2; // 포션을 만나면 체력 2 회복
					break;
			}
		}

	}
	return 0;
}


// 지도와 사용자 위치 출력하는 함수
void displayMap(int map[][mapX], int user_x, int user_y) {
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
bool checkGoal(int map[][mapX], int user_x, int user_y) {
	// 목적지 도착하면
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}
// 사용자가 맵을 벗어났다고 출력해주고 다시 돌아가는 함수
bool checkOutOfMap(int user_x, int mapX, int user_y, int mapY) {
	bool inMap = checkXY(user_x, mapX, user_y, mapY);
	if (!inMap) {
		cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
		user_x = (user_x < 0) ? 0 : (user_x >= mapX) ? mapX - 1 : user_x;
		user_y = (user_y < 0) ? 0 : (user_y >= mapY) ? mapY - 1 : user_y;
	};
	return inMap;
}

// 사용자가 이동할 때 마다 사용자 체력 1씩 감소하는 함수
void decreaseHP(int& currentHP) {
	currentHP -= 1;
	if (currentHP <= 0) {
		currentHP = 0;
		cout << "HP가 0이 되었습니다. 실패했습니다." << endl;
		cout << "게임을 종료합니다." << endl;
	}
}