#include <iostream>
using namespace std;

int main(){
    // 비밀 코드
    char secret_code = 'h';

    // 사용자 입력
    cout << "비밀 코드를 맞춰보세요: ";
    char code;
    cin >> code;

    if (code < secret_code) {
        cout << code <<  "뒤에 있음" << endl;
    }
    else if (code > secret_code) {
        cout << code << "앞에 있음" << endl;
    }
    else {
        cout << "맞추었습니다!" << endl;
    }
    return 0;
}