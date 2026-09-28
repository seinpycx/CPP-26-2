#include <iostream>
using namespace std;

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
        // 범위를 벗어난 경우
        if (x < 0 || x >= numCell || y < 0 || y >= numCell) {
            cout << "x와 y 중 하나가 판을 벗어났습니다." << endl;
            continue; // k++이 continue보다 뒤에 위치하고 있기 때문에 같은 사람의 차례로 반복문의 처음으로 되돌아감
        }

        // 이미 돌이 놓여 있는 경우
        if (board[x][y] != ' ') {
            cout << x << ", " << y << " : 이미 돌이 차있습니다." << endl;
            continue; // k++이 continue보다 뒤에 위치하고 있기 때문에 같은 사람의 차례로 반복문의 처음으로 되돌아감
        }

        // 4. 좌표에 현재 유저의 돌 놓기
        board[x][y] = currentUser;

        // 5. 현재 보드판 출력
        cout << endl;

        for (int i = 0; i < numCell; i++) {
            cout << "---|---|---" << endl;

            for (int j = 0; j < numCell; j++) {
                cout << " " << board[i][j] << " ";

                if (j != numCell - 1) {
                    cout << "|";
                }
            }

            cout << endl;
        }

        cout << "---|---|---" << endl;

        // 6. 빙고 확인
        bool win = false; // false로 초기화하고 시작 후 win(true)이 되면 종료

        // 가로 확인
        for (int i = 0; i < numCell; i++) { // &&를 통해 중간에 조건이 거짓이면 중간에 종료됨 (단락평가)
            if (board[i][0] != ' ' && // 가로줄 전부 빈칸일 경우 빙고로 판정되는 것 방지
                board[i][0] == board[i][1] && // 각각 조건 만족 판정 후 모든 결과를 만족하는가(&&)
                board[i][1] == board[i][2]) {
                win = true;
            }
        }

        // 세로 확인(가로와 동일한 방법)
        for (int j = 0; j < numCell; j++) {
            if (board[0][j] != ' ' && 
                board[0][j] == board[1][j] &&
                board[1][j] == board[2][j]) {
                win = true;
            }
        }

        // 우하향 대각선 확인 (대각선 좌표는 정해져있음 -> 반복문 필요 x)
        if (board[0][0] != ' ' && // &&를 통해 중간에 조건이 거짓이면 중간에 종료됨 (단락평가)
            board[0][0] == board[1][1] &&
            board[1][1] == board[2][2]) {
            win = true;
        }

        // 좌하향 대각선 확인 (대각선 좌표는 정해져있음 -> 반복문 필요 x)
        if (board[0][2] != ' ' &&
            board[0][2] == board[1][1] &&
            board[1][1] == board[2][0]) {
            win = true;
        }

        // 빙고가 만들어졌으면 종료
        if (win) {
            cout << currentUser << " 유저가 승리했습니다!" << endl;
            break;
        }

        // 7. 모든 칸이 찼는지 확인 (칸이 다 찼는데 빙고가 만들어지지 않았을 경우)
        bool full = true;

        for (int i = 0; i < numCell; i++) { // 행 순회
            for (int j = 0; j < numCell; j++) { // 열 순회
                if (board[i][j] == ' ') { // 빈칸이 존재할 경우
                    full = false; // full을 false로 바꿈
                }
            }
        }

        if (full) { // 위의 반복문을 거쳤는데도 ture로 유지될 경우
            cout << "모든 칸이 찼습니다. 무승부입니다!" << endl;
            break;
        }

        // 모든 조건에 걸리는 것이 없다면 다음 차례로 넘어감
        k++;
    }

    return 0;
}