#include <iostream>
#include <string>
using namespace std;

int main() {
    double f;

    cout << "화씨 온도: ";
    cin >> f;

    double c = (5.0 / 9.0) * (f - 32);

    cout << "섭씨 온도: " << c << endl;

    return 0;
}