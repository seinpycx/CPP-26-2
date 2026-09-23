#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {

    int numCell = 10; // 배열의 크기
    int numList[numCell][numCell]; // 10×10 2차원 배열


    // 배열에 난수 저장
    for (int i = 0; i < numCell; i++) { //행    
        for (int j = 0; j < numCell; j++) { //열

            numList[i][j] = rand() % 1000;    // 0~999 난수 저장

            cout << i << ", " << j << " : "
                 << numList[i][j] << endl;
        }
    }

    int max = 0; // 가장 큰 값
    int maxI; // 가장 큰 값의 행
    int maxJ; // 가장 큰 값의 열

    // 가장 큰 값 찾기
    for (int i = 0; i < numCell; i++) { //행    
        for (int j = 0; j < numCell; j++) { //열

            if (numList[i][j] > max) {
                max = numList[i][j]; // 최대값 갱신
                maxI = i; // 행 저장
                maxJ = j; // 열 저장
            }
        }
    }

    cout << endl;

    cout << "가장 큰 값은 " << max << "이고,"; 
    cout << "i와 j는 각각 " << maxI << ", " << maxJ << "입니다." << endl;

    cout << "검증 결과: " << numList[maxI][maxJ] << endl;

    return 0;
}