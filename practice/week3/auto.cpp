#include <iostream>
using namespace std;

auto add(int a, int b) {
    return a + b;
}

int main() {
    auto sum = add(5, 10);
    cout << sum << endl;
    return 0;
}