#include <iostream>
#include <string>
using namespace std;

int main() {
    int money;
    cout << "현재 가지고 있는 돈: ";
    cin >> money;

    int how_much;
    cout << "캔디의 가격: ";
    cin >> how_much;

    cout << "최대로 살 수 있는 캔디: " << money / how_much << endl;
    cout << "캔디 구입 후 남은 돈: " << money % how_much << endl;

    return 0;
}