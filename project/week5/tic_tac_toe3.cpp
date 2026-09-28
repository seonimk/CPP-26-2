#include <iostream>
#include <string>
using namespace std;

int main() {
    const int numCell = 3;
    string board[numCell][numCell]{};
    int x, y;   // 사용자에게 입력받는 x, y 좌표를 저장할 변수

    // 보드판 초기화
    for (x = 0; x < numCell; x++) {
        for (y = 0; y < numCell; y++) {
            board[x][y] = " ";
        }
    }

    // 게임하는 코드
    int k = 0;  // 누구 차례인지 확인하기 위한 변수
    string currentUser = "X"; // 현재 유저의 돌을 저장하기 위한 문자열 변수
    while(true) {
        // 1.  누구의 차례인지 출력 (3명이므로 k % 3)
        switch (k % 3) {
        case 0:
            cout << k % 3 + 1 << "번 유저(X)의 차례입니다." << endl;
            currentUser = "X";
            break;
        case 1:
            cout << k % 3 + 1 << "번 유저(O)의 차례입니다." << endl;
            currentUser = "O";
            break;
        case 2:
            cout << k % 3 + 1 << "번 유저(△)의 차례입니다." << endl;
            currentUser = "△";
            break;
        }

        // 2. 좌료 입력 받기
        cout << "(x, y) 좌표를 입력하세요: ";
        cin >> x >> y;

        // 3. 입력 받은 좌표 유효성 체크
        if ( x >= numCell || y >= numCell) {
            cout << x << ", " << y << ": ";
            cout << " x와 y 둘 중 하나가 칸을 벗어납니다." << endl;
            continue;
        }
        if ( board[x][y] != " ") {
            cout << x << ", " << y << ": 이미 돌이 차있습니다." << endl;
            continue;
        }

        // 4. 좌표에 O / X / △ 놓기
        board[x][y] = currentUser;

        // 5. 현재 보드판 출력
        for ( int i = 0; i < numCell; i++) {
            cout << "---|---|---" << endl;
            for ( int j = 0; j < numCell; j++) {
                cout << board[i][j];
                if ( j == numCell - 1) {
                    break;
                }
                cout << "  |";
            }
            cout << endl;
        }
        cout << "---|---|---" << endl;
        k++;

        // 6. 빙고 시 승자 출력 후 종료
        bool win = false;

        // 가로줄 체크
        for (int i = 0; i < numCell; i++) {
            if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser ) {
                cout << "가로에 모두 돌이 놓였습니다!";
                win = true;
            }
        }

        // 세로줄(y열) 체크
        for (int i = 0; i < numCell; i++) {
            if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser ) {
                cout << "세로에 모두 돌이 놓였습니다!";
                win = true;
            }
        }
        // 대각선 체크
        if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser ) {
                cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!";
                win = true;
        }

        // 반대 대각선 체크
        if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser ) {
                cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!";
                win = true;
        }

        if (win == true) {
            // 5번에서 k++를 이미 했으므로, 방금 둔 유저 번호는 (k - 1) % 3 + 1
            cout << (k - 1) % 3 + 1 << "번 유저" << currentUser << "의 승리! 게임을 종료합니다." << endl;
            break;
        }

        // 7. 모든 칸이 찼으면 종료
        int count = 0;   // 처음엔 놓인 돌이 0개
        for (int i = 0; i < numCell; i++)
            for (int j = 0; j < numCell; j++)
                if (board[i][j] != " ") {
                    count++;   // 빈 칸(" ")이 아니면 개수 증가
                }

        if (count == numCell * numCell) {
                cout << "모든 칸이 다 찼습니다. 종료합니다." << endl;
                break;
        }
    }

    return 0;
}
