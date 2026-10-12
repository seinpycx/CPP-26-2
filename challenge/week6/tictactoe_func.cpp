#include <iostream>
using namespace std;

// 3. 좌표의 유효성 체크
bool checkPosition(char board[][3], int x, int y) {
    // 범위를 벗어난 경우
    if (x < 0 || x >= 3 || y < 0 || y >= 3) {
        cout << "x와 y 중 하나가 판을 벗어났습니다." << endl;
        return false;
    }

    // 이미 돌이 놓여 있는 경우
    if (board[x][y] != ' ') {
        cout << x << ", " << y << " : 이미 돌이 차있습니다." << endl;
        return false;
    }

    return true;
}

// 5. 현재 보드판 출력
void printBoard(char board[][3]) {
    cout << endl;

    for (int i = 0; i < 3; i++) {
        cout << "---|---|---" << endl;

        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";

            if (j != 2) {
                cout << "|";
            }
        }

        cout << endl;
    }

    cout << "---|---|---" << endl;
}

// 6. 빙고 확인
bool checkWin(char board[][3]) {
    // 가로 확인
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' &&
            board[i][0] == board[i][1] &&
            board[i][1] == board[i][2]) {
            return true;
        }
    }

    // 세로 확인
    for (int j = 0; j < 3; j++) {
        if (board[0][j] != ' ' &&
            board[0][j] == board[1][j] &&
            board[1][j] == board[2][j]) {
            return true;
        }
    }

    // 우하향 대각선 확인
    if (board[0][0] != ' ' &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2]) {
        return true;
    }

    // 좌하향 대각선 확인
    if (board[0][2] != ' ' &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0]) {
        return true;
    }

    return false;
}

// 7. 모든 칸이 찼는지 확인
bool checkFull(char board[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }

    return true;
}


int main() {
    const int numCell = 3;
    char board[numCell][numCell]{}; // 2차원 배열로 게임판 만들기
    int x, y; // 사용자가 입력하는 좌표

    // 보드판 빈칸으로 초기화
    for (x = 0; x < numCell; x++) {
        for (y = 0; y < numCell; y++) {
            board[x][y] = ' ';
        }
    }

    // 게임 코드
    int k = 0; // 몇 번째 차례인지
    char currentUser = 'X'; // 현재 플레이어 저장을 위한 변수

    // 종료 전까지 무한반복
    while (true) {

        // 1. 누구의 차례인지 출력
        switch (k % 2) {
        case 0:
            cout << "1번 유저(X)의 차례입니다 -> ";
            currentUser = 'X';
            break;

        case 1:
            cout << "2번 유저(O)의 차례입니다 -> ";
            currentUser = 'O';
            break;
        }

        // 2. 좌표 입력받기
        cout << "(x, y) 좌표를 입력하세요: ";
        cin >> x >> y;

        // 3. 입력받은 좌표의 유효성 체크
        if (!checkPosition(board, x, y)) {
            continue;
        }

        // 4. 좌표에 현재 유저의 돌 놓기
        board[x][y] = currentUser;

        // 5. 현재 보드판 출력
        printBoard(board);

        // 6. 빙고 확인
        if (checkWin(board)) {
            cout << currentUser << " 유저가 승리했습니다!" << endl;
            break;
        }

        // 7. 모든 칸이 찼는지 확인
        if (checkFull(board)) {
            cout << "모든 칸이 찼습니다. 무승부입니다!" << endl;
            break;
        }

        // 모든 조건에 걸리는 것이 없다면 다음 차례로 넘어감
        k++;
    }

    return 0;
}