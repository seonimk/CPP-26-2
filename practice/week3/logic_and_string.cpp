#include <iostream>
#include <string>
using namespace std;

// 문자열 연습
int main() {
    char ch = 'a';
    char ch2 = 'b';

    string s1 = "Good";
    string s2 = "Bad";

    bool b = (s1 == s2);
    cout << b << endl;
    
    s2 = "Good";
    b = (s1 == s2);
    cout << b << endl;
}