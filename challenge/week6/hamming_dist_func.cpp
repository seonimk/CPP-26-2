#include <iostream>
#include <string>
using namespace std;

// 2. 문자열의 대문자를 모두 소문자로 바꿔서 반환하는 함수
string toLowerStr(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';    // 대문자와 소문자의 아스키 코드 차이만큼 이동
        }
    }
    return str;
}

// 3. 문자열의 소문자를 모두 대문자로 바꿔서 반환하는 함수
string toUpperStr(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';    // 소문자와 대문자의 아스키 코드 차이만큼 이동
        }
    }
    return str;
}

// 4. 대소문자 관계없이 두 문자열의 해밍 거리를 구하는 함수
int calcHammingDist(string s1, string s2) {
    // 두 문자열을 모두 소문자로 바꾼 뒤 비교하면 대소문자 차이는 무시됨
    s1 = toLowerStr(s1);
    s2 = toLowerStr(s2);

    int count = 0;  // 서로 다른 문자의 개수
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) {
            count += 1;
        }
    }
    return count;
}

int main(){
    string s1, s2;

    // 1. 길이가 같은 문자열을 입력할 때까지 입력 요청 반복
    while (true) {
        cout << "DNA1: ";
        cin >> s1;
        cout << "DNA2: ";
        cin >> s2;

        if (s1.length() == s2.length()) {
            break;      // 길이가 같으면 반복 종료
        }
        cout << "오류: 길이가 다름" << endl;   // 길이가 다르면 다시 입력받기
    }

    // 4. 대소문자 관계없이 해밍 거리 계산
    int count = calcHammingDist(s1, s2);
    cout << "해밍 거리는 " << count << endl;

    return 0;
}
