#include <iostream>
using namespace std;

int Sum(int valuel, int value2 = 0){
    int result = valuel + value2;
    return result;
}
int main(){
    int a = 2, b = 3;
    // 1. 매개변수로 a, b 보냄
    int value = Sum(a, b);
    cout << value << endl;

    // 2. 매개변수 a만 보냄
    value = Sum(a);
    cout << value << endl;

    return 0;
}