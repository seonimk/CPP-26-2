#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    cout << argc << endl;

    for ( int i = 0; i < argc; i++) {
        cout << i << ":" << argv[i] << endl;
    }
    // 왜 안될까? : argv 갯수를 미리 알 수 없음 !
    // for (auto arg : argv) {
    //      cout << arg << endl;
    // }

    return 0;
}