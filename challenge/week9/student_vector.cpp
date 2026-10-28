#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> scores;

    while (true) {
        int score;        
        cout << "성적을 입력하시오 (종료는 -1) : ";
        cin >> score;
        if (score == -1) {
            break;          // -1이면 입력 종료
        }
        scores.push_back(score);
    }

    // 입력된 성적이 하나도 없으면 평균을 구할 수 없음 (0으로 나누기 방지)
    if (scores.size() == 0) {
        cout << "입력된 성적이 없습니다." << endl;
        return 0;
    }

    // 벡터에 저장된 모든 성적의 합계
    int sum = 0;
    for (auto& value : scores) {
        sum += value;
    }

    // 평균 구하고 출력
    double avg = (double)sum / scores.size();
    cout << "성적 평균 = " << avg << endl;

    return 0;
}
