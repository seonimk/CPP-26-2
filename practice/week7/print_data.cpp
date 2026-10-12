#include <iostream>
#include <string>
using namespace std;

// 멤버 함수 중복 정의(오버로딩) 예제
// 이름이 같은 print 함수를 매개변수 자료형만 다르게 여러 개 정의
class PrintData {
public:
    void print(int i) { cout << i << endl; }        // 정수를 출력
    void print(double f) { cout << f << endl; }     // 실수를 출력
    void print(string s = "No Data!") { cout << s << endl; }  // 문자열을 출력 (인자가 없으면 기본값 "No Data!")
};

int main() {
    PrintData obj;

    // 넘기는 인자의 자료형에 따라 알맞은 print 함수가 호출됨
    obj.print(1);                   // print(int) 호출
    obj.print(3.14);                // print(double) 호출
    obj.print("C++14 is cool.");    // print(string) 호출
    obj.print();                    // 인자가 없으므로 기본값을 쓰는 print(string) 호출
    return 0;
}
