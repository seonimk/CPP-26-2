#include <iostream>
using namespace std;

class Time {
private:
    int hour;       // 시를 나타낸다. 0 ~ 23가 가능
    int minute;     // 분을 나타낸ㄴ다. 0 ~ 59가 가능
public:
    Time(int h, int m);
    void IncHour();
    void Print();

    int GetHour() { return hour; }
    int GetMinute() { return minute; }
    void SetHour(int h) { hour = h; }
    void SetMinute(int m) { minute = m; }
};

Time::Time(int h, int m) {  // 외부 작성
    hour = h;
    minute = m;
}

void Time::IncHour() {  // 외부 작성
    ++hour;
    if (hour > 23) { 
        hour = 0; 
    }
}

void Time::Print() {    // 외부 작성
    cout << hour << " : " << minute << endl;
}

int main() {
    Time a{ 0, 0 };
    // a.hour = 10;   // 에러 -> 'int Time::hour' is private within this context
    a.SetHour(6);
    a.SetMinute(30);

    a.Print();
    return 0;
}