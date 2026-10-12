#include <iostream>
#include <string>
using namespace std;

// 문자열을 모두 소문자로 변환하는 함수
string toLowerStr(string str) {
    string newStr = str; // 원래 문자열을 복사
    for (char& c : newStr) {
        c = tolower(c); // 각 문자를 소문자로 변환
    }
    return newStr;
}

// 문자열을 모두 대문자로 변환하는 함수
string toUpperStr(string str) {
    string newStr = str; // 원래 문자열을 복사
    for (char& c : newStr) {
        c = toupper(c); // 각 문자를 대문자로 변환
    }
    return newStr;
}

// 두 문자열의 해밍 거리를 구하는 함수
int calChammingDist(string s1, string s2) {
    s1 = toLowerStr(s1); // 대소문자 구분 없이 비교하기 위해 소문자로 변환
    s2 = toLowerStr(s2);
    int count = 0; // 다른 문자의 개수

    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) // 같은 위치의 문자가 다르면
            count += 1; // 개수 증가
    }
    return count; // 해밍 거리 반환
}

int main() {
    string s1, s2;

    while (1) { // 올바른 입력을 받을 때까지 반복
        cout << "DNA1: ";
        cin >> s1;
        cout << "DNA2: ";
        cin >> s2;

        if (s1.length() != s2.length()) { // 두 문자열의 길이가 다르면
            cout << "오류: 길이가 다름" << endl;
            continue; // 다시 입력받기
        }
        else {
            int count = calChammingDist(s1, s2); // 해밍 거리 계산
            cout << "해밍 거리는 " << count << endl;
            break; // 계산이 끝나면 반복문 종료
        }
    }

    return 0;
}