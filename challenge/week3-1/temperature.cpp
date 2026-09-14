#include <iostream>
#include <string>
using namespace std;

int main() {
    int c1;
    double f1;

    cout << "화씨 온도: ";
    cin >> c1;
    f1 = (5.0/9.0)*(c1 - 32);

    cout << "섭씨 온도: " << f1 << endl;
}