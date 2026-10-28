#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 영화 한 편의 정보(이름, 평점)를 저장하는 클래스
class Movie {
public:
    string title;
    double rating;

    Movie(string t, double r) {
        title = t;
        rating = r;
    }

    void Print() {
        cout << title << " : " << rating << endl;
    }
};

int main() {
    vector<Movie> movies;

    movies.push_back(Movie("titanic", 9.9));
    movies.push_back(Movie("gone with the wind", 9.6));
    movies.push_back(Movie("terminator", 9.7));

    for (auto& m : movies) {
        m.Print();
    }

    return 0;
}
