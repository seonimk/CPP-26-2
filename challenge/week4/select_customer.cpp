#include <iostream>
#include <string>
using namespace std;

int main(){
    const int maxPeople = 3;
    string names[maxPeople];
    int ages[maxPeople];

    for (int i = 1; i < maxPeople; i++) {
        cout << "사람" << i << "의 이름: ";
        cin >> names[i];
        cout << "사람" << i << "의 나이: ";
        cin >> ages[i];
    }
    int ageThreshold;
    cout << "특정 나이 이상인 사람을 찾으려면 나이를 입력하세요: ";
    cin >> ageThreshold;

    cout << ageThreshold << "세 이상인 고객들:\n";
    for (int j = 0; j < maxPeople; j++){
        if (ages[j] >= ageThreshold){
            cout << names[j] << "(" << ages[j] << "세 )";
        }
        else 
        cout << ageThreshold << "이상의 나이를 가진 고객이 없습니다." << endl;
    }
    return 0;

}