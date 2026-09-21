#include <iostream>
#include <time.h>
using namespace std;

int main(){
    srand(time(NULL));

    int answer = rand()% 100;
    int tries = 0;

    int guess;
    
    do {
        cout << "0~99 사이의 숫자를 입력하세요: ";
        cin >> guess;
        tries++; // 시도 횟수 1 증가

        if (guess > answer)
            cout << "더 작은 숫자입니다." << endl;
        else if (guess < answer)
            cout << "더 큰 숫자입니다." << endl;
    } while (guess != answer); // 정답을 맞히면 반복 종료

    cout << "축하합니다. 시도 횟수=" << tries << endl;
    return 0;
}
