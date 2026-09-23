#include <iostream>
#include <string>
using namespace std;

int main() {
    int maxPeople;

    cout << "총 고객의 수를 입력하라: ";
    cin >> maxPeople;

    string names[maxPeople];
    int ages[maxPeople];

    // 고객의 이름과 나이 입력
    for (int i = 0; i < maxPeople; i++) {
        cout << "사람 " << i + 1 << "의 이름: ";
        cin >> names[i];

        cout << "사람 " << i + 1 << "의 나이: ";
        cin >> ages[i];
    }

    int ageThreshold;
    int count = 0;

    cout << "특정 나이 이상인 사람을 찾으려면 나이를 입력하세요: ";
    cin >> ageThreshold;

    cout << ageThreshold << "세 이상의 고객들:\n";

    // 특정 나이 이상인 고객 출력
    for (int i = 0; i < maxPeople; i++) {
        if (ages[i] >= ageThreshold) {
            cout << names[i] << " (" << ages[i] << "세)\n";
            count++;
        }
    }

    // 조건에 맞는 고객이 없는 경우
    if (count == 0) {
        cout << ageThreshold << "이상의 나이를 가진 고객이 없습니다." << endl;
    }

    return 0;
}