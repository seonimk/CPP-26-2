#include <vector>
#include <iostream>
using namespace std;

void Print(const vector<int> v) {
    for (auto& e : v) {
        cout << e << " ";   
    }
    cout << endl;
}

int main(void) {
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);     // 0 ~ 9를 벡터 끝에 차례로 추가
    }

    cout << "현재의 v = ";
    Print(v);

    v.erase(v.begin() + 5);     // 5번 인덱스 요소 삭제
    cout << "5번 인덱스를 제거한 후 v = ";
    
    Print(v);

    // it의 타입은 vector<int>::iterator
    auto it = v.begin() + 5;
    v.insert(it, 100);      // 5번 인덱스 위치에 100 삽입
    cout << "5번 인덱스에 값을 추가한 후 v = ";
    Print(v);

    return 0;
}