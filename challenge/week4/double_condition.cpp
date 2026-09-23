#include <iostream>
using namespace std;

int main() {
    int num1, num2;

    cout << "두 양수를 입력하세요 : ";
    cin >> num1, num2;

    if (num1 > 0) {
        if (num2 > 0) {
            cout << num1 << num2 << "두 숫자 모두 양수입나다.\n" << endl;
        }
        else {
            cout << num1 << "만 양수입나다.\n" << endl;
        }
    }
    else {
        cout << num1 << "0이거나 음수입니다.\n" << endl;
    }
    return 0;
}