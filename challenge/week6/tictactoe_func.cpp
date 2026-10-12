#include <iostream>
using namespace std;

const int numCell = 3;  // 보드 가로/세로 칸 개수

// 3. 입력 받은 좌표 유효성 체크
// 좌표가 보드를 벗어나거나 이미 돌이 있으면 이유를 출력하고 false, 놓을 수 있으면 true를 반환
bool isValid(char board[numCell][numCell], int x, int y) {
    if ( x >= numCell || y >= numCell) {
        cout << x << ", " << y << ": ";
        cout << " x와 y 둘 중 하나가 칸을 벗어납니다." << endl;
        return false;
    }
    if ( board[x][y] != ' ') {
        cout << x << ", " << y << ": 이미 돌이 차있습니다." << endl;
        return false;
    }
    return true;
}

// 5. 현재 보드판 출력
// 구분선과 함께 보드의 모든 칸을 출력
void printBoard(char board[numCell][numCell]) {
    for ( int i = 0; i < numCell; i++) {
        cout << "---|---|---" << endl;
        for ( int j = 0; j < numCell; j++) {
            cout << board[i][j];
            if ( j == numCell - 1) {
                break;      // 마지막 칸 뒤에는 구분선(|)을 출력하지 않음
            }
            cout << "  |";
        }
        cout << endl;
    }
    cout << "---|---|---" << endl;
}

// 6. 빙고 체크
// 가로, 세로, 대각선 중 한 줄이라도 currentUser의 돌로 채워졌으면 true를 반환
bool checkWin(char board[numCell][numCell], char currentUser) {
    bool win = false;

    // 가로줄 체크
    for (int i = 0; i < numCell; i++) {
        if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser ) {
            cout << "가로에 모두 돌이 놓였습니다!";
            win = true;
        }
    }

    // 세로줄 체크
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

    return win;
}

// 7. 모든 칸이 찼는지 체크
// 돌이 놓인 칸의 개수를 세어 전체 칸 수와 같으면 true를 반환
bool isFull(char board[numCell][numCell]) {
    int count = 0;   // 돌이 놓인 칸의 개수
    for (int i = 0; i < numCell; i++)
        for (int j = 0; j < numCell; j++)
            if (board[i][j] != ' ') {
                count++;   // 빈 칸(' ')이 아니면 개수 증가
            }

    return count == numCell * numCell;
}

int main() {
    char board[numCell][numCell]{};
    int x, y;   // 사용자에게 입력받는 x, y 좌표를 저장할 변수

    // 보드판 초기화
    for (x = 0; x < numCell; x++) {
        for (y = 0; y < numCell; y++) {
            board[x][y] = ' ';
        }
    }

    // 게임하는 코드
    int k = 0;  // 누구 차례인지 확인하기 위한 변수
    char currentUser = 'X'; // 현재 유저의 돌을 저장하기 위한 문자 변수
    while(true) {
        // 1.  누구의 차례인지 출력
        switch (k % 2) {
        case 0:
            cout << k % 2 + 1 << "번 유저(X)의 차례입니다." << endl;
            currentUser = 'X';
            break;
        case 1:
            cout << k % 2 + 1 << "번 유저(O)의 차례입니다." << endl;
            currentUser = 'O';
            break;
        }

        // 2. 좌표 입력 받기
        cout << "(x, y) 좌표를 입력하세요: ";
        cin >> x >> y;

        // 3. 입력 받은 좌표 유효성 체크 (놓을 수 없으면 다시 입력받기)
        if (!isValid(board, x, y)) {
            continue;
        }

        // 4. 좌표에 O / X 놓기
        board[x][y] = currentUser;

        // 5. 현재 보드판 출력
        printBoard(board);
        k++;

        // 6. 빙고 시 승자 출력 후 종료
        if (checkWin(board, currentUser)) {
            // 위에서 k++를 이미 했으므로, 방금 둔 유저 번호는 (k - 1) % 2 + 1
            cout << (k - 1) % 2 + 1 << "번 유저" << currentUser << "의 승리! 게임을 종료합니다." << endl;
            break;
        }

        // 7. 모든 칸이 찼으면 종료
        if (isFull(board)) {
            cout << "모든 칸이 다 찼습니다. 종료합니다." << endl;
            break;
        }
    }

    return 0;
}
