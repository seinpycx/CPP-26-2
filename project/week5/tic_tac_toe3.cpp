#include <iostream>
using namespace std;

int main() {
    const int numCell = 3;
    char board[numCell][numCell]{};
    int x, y; // 사용자에게 입력받는 x, y 좌표를 저장할 변수

    // 보드판 초기화
    for (x = 0; x < numCell; x++){
        for (y = 0; y < numCell; y++){
            board[x][y] = ' ';
        }
    }
    
}
