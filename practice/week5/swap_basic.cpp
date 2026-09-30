#include <iostream>
using namespace std;

void swap(int arr[]) {
    int tmp;
    tmp = arr[0];
    arr[0] = arr[1];
    arr[1] = tmp;
}

int main() {
    int arr[2] = {100, 200};

    cout << "a=" << arr[0] << " b=" << arr[1] << endl;

    // 두 변수의 값 변경
    swap(arr);

    cout << "a=" << arr[0] << " b=" << arr[1] << endl;

    return 0;
}