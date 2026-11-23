#include <iostream>

using namespace std;

int main()
{
    int two = 2;
    int eight = 8;
    int sum1 = 2;
    int sum2 = 2;

    sum1 = sum1 + two;  // 일반 식 : sum1에 two를 더해서 다시 sum1에 저장 (2 + 2 = 4)
    sum2 += eight;      // 축약식 : sum2 = sum2 + eight 와 같음 (2 + 8 = 10)
    cout << "sum1 = " << sum1 << endl;
    cout << "sum2 = " << sum2 << endl;
}
