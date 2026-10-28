#include <vector>
#include <iostream>
using namespace std;

void PrintVector(vector<int> v) {
    for (auto& e : v)
        cout << e << " ";
    cout << endl;
}

int main(void) {
    vector<int> v;

    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    cout << "현재의 v = ";
    PrintVector(v);

    auto it = v.begin() + 5;
    v.insert(it, 100);

    cout << "5번 인덱스에 값을 추가한 후 v = ";
    PrintVector(v);

    v.erase(v.begin() + 5);

    cout << "5번 인덱스를 제거한 후 v = ";
    PrintVector(v);

    return 0;
}