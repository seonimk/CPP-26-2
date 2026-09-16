#include <iostream>
using namespace std;

int main() {
    int number;
    cout << "숫자를 입력하세요: ";
    cin >> number;

    if (number == 0) {
        cout << "Zero\n" << endl;
    }
    else if (number == 1) {
        cout << "One\n" << endl;
    }
    else {
        cout << "Many" << endl;
    }

    return 0;
}