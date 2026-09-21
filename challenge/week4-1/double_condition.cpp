#include <iostream>
using namespace std;

int main() {
    int number1, number2;

    cout << "두 양수를 입력하세요: ";
    cin >> number1 >> number2;

    if (number1 > 0) {
        if (number2 > 0) {
            cout << number1 << ", " << number2 << " 두 숫자 모두 양수입니다." << endl;
        }
        else {
            cout << number1 << "만 양수입니다." << endl;
        }
    }
    else {
        cout << number1 << "는 0이거나 음수입니다." << endl;
    }

    return 0;
}