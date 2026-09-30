#include <iostream>

// 두 숫자의 합 계산
int add(int a, int b) {
return a + b;
}
// 세 숫자의 합 계산
int add(int a, int b, int c) {
return a + b + c;
}

int main() {
    std :: cout << "2 + 3 = " << add(2, 3) << std :: endl;
    std :: cout << "2 + 3 + 4 = " << add(2, 3, 4) << std :: endl;
    return 0;
} 
